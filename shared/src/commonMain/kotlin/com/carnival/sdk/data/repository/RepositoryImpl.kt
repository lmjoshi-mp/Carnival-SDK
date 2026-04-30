package com.carnival.sdk.data.repository

import com.carnival.sdk.core.dispatcher.DispatcherProvider
import com.carnival.sdk.core.network.NetworkMonitor
import com.carnival.sdk.core.util.JsonCodec
import com.carnival.sdk.core.util.ResultState
import com.carnival.sdk.core.util.SecureTokenStore
import com.carnival.sdk.data.cache.CachePolicy
import com.carnival.sdk.data.local.CruiseLocalDataSource
import com.carnival.sdk.data.mapper.toDomain
import com.carnival.sdk.data.mapper.toDto
import com.carnival.sdk.data.remote.CruiseRemoteDataSource
import com.carnival.sdk.data.remote.dto.ChatMessageDto
import com.carnival.sdk.data.remote.dto.OrderDto
import com.carnival.sdk.data.remote.dto.PreferencesDto
import com.carnival.sdk.domain.error.DomainError
import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.ItineraryItem
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.SyncOperationType
import com.carnival.sdk.domain.model.UserPreferences
import com.carnival.sdk.domain.model.UserSession
import com.carnival.sdk.domain.repository.AuthRepository
import com.carnival.sdk.domain.repository.ChatRepository
import com.carnival.sdk.domain.repository.ItineraryRepository
import com.carnival.sdk.domain.repository.OrderRepository
import com.carnival.sdk.domain.repository.PreferencesRepository
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.channels.awaitClose
import kotlinx.coroutines.delay
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.channelFlow
import kotlinx.coroutines.flow.collect
import kotlinx.coroutines.flow.flow
import kotlinx.coroutines.flow.flowOn
import kotlinx.coroutines.isActive
import kotlinx.coroutines.launch

class AuthRepositoryImpl(
    private val remoteDataSource: CruiseRemoteDataSource,
    private val localDataSource: CruiseLocalDataSource,
    private val networkMonitor: NetworkMonitor,
    private val secureTokenStore: SecureTokenStore,
    private val dispatcherProvider: DispatcherProvider,
) : AuthRepository {
    override fun login(email: String, password: String): Flow<ResultState<UserSession>> = flow {
        emit(ResultState.Loading)
        val cachedSession = localDataSource.getSession()

        if (!networkMonitor.isOnline.value) {
            if (cachedSession != null && !cachedSession.isExpired) {
                emit(ResultState.Success(cachedSession))
            } else {
                emit(ResultState.Error(DomainError.UnauthorizedError("No valid offline session found")))
            }
            return@flow
        }

        try {
            val session = remoteDataSource.login(email, password).toDomain()
            localDataSource.saveSession(session)
            secureTokenStore.saveToken(session.token)
            emit(ResultState.Success(session))
        } catch (throwable: Throwable) {
            if (cachedSession != null && !cachedSession.isExpired) {
                emit(ResultState.Success(cachedSession))
            } else {
                emit(ResultState.Error(DomainError.NetworkError("Login failed", throwable)))
            }
        }
    }.flowOn(dispatcherProvider.io)

    override fun getCachedSession(): Flow<ResultState<UserSession?>> = flow {
        emit(ResultState.Loading)
        emit(ResultState.Success(localDataSource.getSession()))
    }.flowOn(dispatcherProvider.io)
}

class PreferencesRepositoryImpl(
    private val remoteDataSource: CruiseRemoteDataSource,
    private val localDataSource: CruiseLocalDataSource,
    private val networkMonitor: NetworkMonitor,
    private val secureTokenStore: SecureTokenStore,
    private val jsonCodec: JsonCodec,
    private val dispatcherProvider: DispatcherProvider,
) : PreferencesRepository {
    override fun savePreferences(preferences: UserPreferences): Flow<ResultState<UserPreferences>> = flow {
        emit(ResultState.Loading)
        localDataSource.savePreferences(preferences)
        emit(ResultState.Success(preferences))
        val token = secureTokenStore.getToken() ?: run {
            emit(ResultState.Error(DomainError.UnauthorizedError()))
            return@flow
        }

        val payload = jsonCodec.encode(PreferencesDto.serializer(), preferences.toDto())
        if (!networkMonitor.isOnline.value) {
            localDataSource.enqueueSync("preferences", preferences.userId, SyncOperationType.UPDATE, payload)
            return@flow
        }

        try {
            val updated = remoteDataSource.savePreferences(preferences.toDto(), token).toDomain()
            localDataSource.savePreferences(updated)
            emit(ResultState.Success(updated))
        } catch (throwable: Throwable) {
            localDataSource.enqueueSync("preferences", preferences.userId, SyncOperationType.UPDATE, payload)
            emit(ResultState.Error(DomainError.NetworkError("Preferences sync failed; queued for retry", throwable)))
        }
    }.flowOn(dispatcherProvider.io)

    override fun fetchPreferences(userId: String): Flow<ResultState<UserPreferences?>> = flow {
        emit(ResultState.Loading)
        val cached = localDataSource.getPreferences(userId)
        emit(ResultState.Success(cached))
        if (!networkMonitor.isOnline.value) return@flow
        val token = secureTokenStore.getToken() ?: return@flow
        try {
            val remote = remoteDataSource.fetchPreferences(userId, token).toDomain()
            localDataSource.savePreferences(remote)
            emit(ResultState.Success(remote))
        } catch (throwable: Throwable) {
            emit(ResultState.Error(DomainError.NetworkError("Failed to refresh preferences", throwable)))
        }
    }.flowOn(dispatcherProvider.io)
}

class ItineraryRepositoryImpl(
    private val remoteDataSource: CruiseRemoteDataSource,
    private val localDataSource: CruiseLocalDataSource,
    private val networkMonitor: NetworkMonitor,
    private val secureTokenStore: SecureTokenStore,
    private val cachePolicy: CachePolicy,
    private val dispatcherProvider: DispatcherProvider,
) : ItineraryRepository {
    override fun fetchItinerary(page: Int, pageSize: Int): Flow<ResultState<List<ItineraryItem>>> = flow {
        emit(ResultState.Loading)
        val cachedPage = localDataSource.getItinerary(page, pageSize)
        emit(ResultState.Success(cachedPage))

        if (!networkMonitor.isOnline.value || !cachePolicy.isExpired()) return@flow
        val token = secureTokenStore.getToken() ?: return@flow

        try {
            val pageDto = remoteDataSource.fetchItinerary(page, pageSize, token)
            val mapped = pageDto.items.map { it.toDomain() }
            localDataSource.saveItinerary(mapped)
            cachePolicy.markUpdated()
            emit(ResultState.Success(localDataSource.getItinerary(page, pageSize)))
        } catch (throwable: Throwable) {
            emit(ResultState.Error(DomainError.NetworkError("Failed to refresh itinerary", throwable)))
        }
    }.flowOn(dispatcherProvider.io)
}

class OrderRepositoryImpl(
    private val remoteDataSource: CruiseRemoteDataSource,
    private val localDataSource: CruiseLocalDataSource,
    private val networkMonitor: NetworkMonitor,
    private val secureTokenStore: SecureTokenStore,
    private val jsonCodec: JsonCodec,
    private val dispatcherProvider: DispatcherProvider,
) : OrderRepository {
    override fun placeOrder(order: KitchenOrder): Flow<ResultState<KitchenOrder>> = flow {
        emit(ResultState.Loading)
        localDataSource.saveOrder(order.copy(pendingSync = true))
        emit(ResultState.Success(order.copy(pendingSync = true)))

        val payload = jsonCodec.encode(OrderDto.serializer(), order.toDto())
        if (!networkMonitor.isOnline.value) {
            localDataSource.enqueueSync("order", order.id, SyncOperationType.CREATE, payload)
            return@flow
        }

        val token = secureTokenStore.getToken() ?: run {
            localDataSource.enqueueSync("order", order.id, SyncOperationType.CREATE, payload)
            emit(ResultState.Error(DomainError.UnauthorizedError()))
            return@flow
        }

        try {
            val remoteOrder = remoteDataSource.placeOrder(order.toDto(), token).toDomain(pendingSync = false)
            localDataSource.saveOrder(remoteOrder)
            emit(ResultState.Success(remoteOrder))
        } catch (throwable: Throwable) {
            localDataSource.enqueueSync("order", order.id, SyncOperationType.CREATE, payload)
            emit(ResultState.Error(DomainError.NetworkError("Order queued for sync", throwable)))
        }
    }.flowOn(dispatcherProvider.io)

    override fun updateOrderStatus(orderId: String, status: OrderStatus): Flow<ResultState<KitchenOrder>> = flow {
        emit(ResultState.Loading)
        localDataSource.updateOrderStatus(orderId, status, pendingSync = true)
        val updated = localDataSource.getOrder(orderId)
        if (updated == null) {
            emit(ResultState.Error(DomainError.CacheError("Order not found: $orderId")))
            return@flow
        }
        emit(ResultState.Success(updated))

        val payload = jsonCodec.encode(OrderDto.serializer(), updated.toDto())
        if (!networkMonitor.isOnline.value) {
            localDataSource.enqueueSync("order", orderId, SyncOperationType.UPDATE, payload)
            return@flow
        }

        val token = secureTokenStore.getToken() ?: run {
            localDataSource.enqueueSync("order", orderId, SyncOperationType.UPDATE, payload)
            emit(ResultState.Error(DomainError.UnauthorizedError()))
            return@flow
        }

        try {
            val remoteOrder = remoteDataSource.updateOrderStatus(orderId, status.name, token).toDomain(pendingSync = false)
            localDataSource.saveOrder(remoteOrder)
            emit(ResultState.Success(remoteOrder))
        } catch (throwable: Throwable) {
            localDataSource.enqueueSync("order", orderId, SyncOperationType.UPDATE, payload)
            emit(ResultState.Error(DomainError.NetworkError("Status update queued for sync", throwable)))
        }
    }.flowOn(dispatcherProvider.io)

    override fun observeOrders(userId: String): Flow<ResultState<List<KitchenOrder>>> = flow {
        emit(ResultState.Loading)
        emit(ResultState.Success(localDataSource.getOrders(userId)))
        localDataSource.observeOrders(userId).collect { orders ->
            emit(ResultState.Success(orders))
        }
    }.flowOn(dispatcherProvider.io)
}

class ChatRepositoryImpl(
    private val remoteDataSource: CruiseRemoteDataSource,
    private val localDataSource: CruiseLocalDataSource,
    private val networkMonitor: NetworkMonitor,
    private val secureTokenStore: SecureTokenStore,
    private val jsonCodec: JsonCodec,
    private val dispatcherProvider: DispatcherProvider,
    private val pollingIntervalMillis: Long = 5_000,
) : ChatRepository {
    override fun sendMessage(message: ChatMessage): Flow<ResultState<ChatMessage>> = flow {
        emit(ResultState.Loading)
        val localMessage = message.copy(pendingSync = true)
        localDataSource.saveMessage(localMessage)
        emit(ResultState.Success(localMessage))
        val payload = jsonCodec.encode(ChatMessageDto.serializer(), localMessage.toDto())

        if (!networkMonitor.isOnline.value) {
            localDataSource.enqueueSync("chat", localMessage.id, SyncOperationType.CREATE, payload)
            return@flow
        }
        val token = secureTokenStore.getToken() ?: return@flow

        try {
            val remote = remoteDataSource.sendMessage(localMessage.toDto(), token).toDomain(pendingSync = false)
            localDataSource.saveMessage(remote)
            emit(ResultState.Success(remote))
        } catch (throwable: Throwable) {
            localDataSource.enqueueSync("chat", localMessage.id, SyncOperationType.CREATE, payload)
            emit(ResultState.Error(DomainError.NetworkError("Message will be retried by sync engine", throwable)))
        }
    }.flowOn(dispatcherProvider.io)

    override fun receiveMessages(roomId: String): Flow<ResultState<List<ChatMessage>>> = channelFlow {
        send(ResultState.Loading)
        send(ResultState.Success(localDataSource.getMessages(roomId)))

        val localJob = launch {
            localDataSource.observeMessages(roomId).collect { messages ->
                send(ResultState.Success(messages))
            }
        }

        val pollingJob = CoroutineScope(dispatcherProvider.io).launch {
            while (isActive) {
                if (networkMonitor.isOnline.value) {
                    val token = secureTokenStore.getToken()
                    if (token != null) {
                        try {
                            val remoteMessages = remoteDataSource.fetchMessages(roomId, token)
                            localDataSource.saveMessages(remoteMessages.map { it.toDomain() })
                        } catch (_: Throwable) {
                            // Keep local stream active; next poll will retry.
                        }
                    }
                }
                delay(pollingIntervalMillis)
            }
        }

        awaitClose {
            localJob.cancel()
            pollingJob.cancel()
        }
    }.flowOn(dispatcherProvider.io)
}
