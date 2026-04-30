package com.carnival.sdk

import com.carnival.sdk.core.database.InMemoryLocalStore
import com.carnival.sdk.core.database.LocalStore
import com.carnival.sdk.core.dispatcher.DefaultDispatcherProvider
import com.carnival.sdk.core.dispatcher.DispatcherProvider
import com.carnival.sdk.core.network.NetworkMonitor
import com.carnival.sdk.core.network.createPlatformNetworkMonitor
import com.carnival.sdk.core.network.createCruiseHttpClient
import com.carnival.sdk.core.platform.createDeviceInfoProvider
import com.carnival.sdk.core.logging.createPlatformLogger
import com.carnival.sdk.core.util.JsonCodec
import com.carnival.sdk.core.util.ResultState
import com.carnival.sdk.core.util.SecureTokenStore
import com.carnival.sdk.core.util.SystemTimeProvider
import com.carnival.sdk.core.util.TimeProvider
import com.carnival.sdk.core.util.createSecureTokenStore
import com.carnival.sdk.data.cache.CachePolicy
import com.carnival.sdk.data.local.CruiseLocalDataSource
import com.carnival.sdk.data.repository.AuthRepositoryImpl
import com.carnival.sdk.data.repository.ChatRepositoryImpl
import com.carnival.sdk.data.repository.ItineraryRepositoryImpl
import com.carnival.sdk.data.repository.OrderRepositoryImpl
import com.carnival.sdk.data.repository.PreferencesRepositoryImpl
import com.carnival.sdk.data.remote.CruiseRemoteDataSource
import com.carnival.sdk.data.sync.SyncEngine
import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.UserPreferences
import com.carnival.sdk.domain.model.UserSession
import com.carnival.sdk.domain.usecase.FetchItineraryUseCase
import com.carnival.sdk.domain.usecase.FetchPreferencesUseCase
import com.carnival.sdk.domain.usecase.GetCachedSessionUseCase
import com.carnival.sdk.domain.usecase.LoginUseCase
import com.carnival.sdk.domain.usecase.ObserveOrdersUseCase
import com.carnival.sdk.domain.usecase.PlaceOrderUseCase
import com.carnival.sdk.domain.usecase.ReceiveMessagesUseCase
import com.carnival.sdk.domain.usecase.SavePreferencesUseCase
import com.carnival.sdk.domain.usecase.SendMessageUseCase
import com.carnival.sdk.domain.usecase.TriggerSyncUseCase
import com.carnival.sdk.domain.usecase.UpdateOrderStatusUseCase
import io.ktor.client.HttpClient
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.SupervisorJob
import kotlinx.coroutines.flow.Flow

data class CruiseSDKConfig(
    val baseUrl: String,
    val enableNetworkLogs: Boolean = false,
    val networkMonitor: NetworkMonitor = createPlatformNetworkMonitor(),
    val localStore: LocalStore = InMemoryLocalStore(),
    val secureTokenStore: SecureTokenStore = createSecureTokenStore(),
    val dispatcherProvider: DispatcherProvider = DefaultDispatcherProvider(),
    val pollingIntervalMillis: Long = 5_000L,
    val timeProvider: TimeProvider = SystemTimeProvider(),
    val externalScope: CoroutineScope? = null,
    val httpClient: HttpClient? = null,
)

object CruiseSDK {
    private var components: SDKComponents? = null

    fun initialize(config: CruiseSDKConfig) {
        components?.close()
        components = SDKComponents(config).also { it.start() }
    }

    val auth: AuthApi
        get() = requireComponents().authApi

    val preferences: PreferencesApi
        get() = requireComponents().preferencesApi

    val itinerary: ItineraryApi
        get() = requireComponents().itineraryApi

    val order: OrderApi
        get() = requireComponents().orderApi

    val chat: ChatApi
        get() = requireComponents().chatApi

    val sync: SyncApi
        get() = requireComponents().syncApi

    fun shutdown() {
        components?.close()
        components = null
    }

    private fun requireComponents(): SDKComponents =
        components ?: error("CruiseSDK is not initialized. Call CruiseSDK.initialize(config) first.")
}

class AuthApi internal constructor(
    private val loginUseCase: LoginUseCase,
    private val cachedSessionUseCase: GetCachedSessionUseCase,
) {
    fun login(email: String, password: String): Flow<ResultState<UserSession>> = loginUseCase(email, password)
    fun cachedSession(): Flow<ResultState<UserSession?>> = cachedSessionUseCase()
}

class PreferencesApi internal constructor(
    private val saveUseCase: SavePreferencesUseCase,
    private val fetchUseCase: FetchPreferencesUseCase,
) {
    fun save(preferences: UserPreferences): Flow<ResultState<UserPreferences>> = saveUseCase(preferences)
    fun get(userId: String): Flow<ResultState<UserPreferences?>> = fetchUseCase(userId)
}

class ItineraryApi internal constructor(
    private val fetchUseCase: FetchItineraryUseCase,
) {
    fun get(page: Int, pageSize: Int): Flow<ResultState<List<com.carnival.sdk.domain.model.ItineraryItem>>> =
        fetchUseCase(page, pageSize)
}

class OrderApi internal constructor(
    private val placeUseCase: PlaceOrderUseCase,
    private val updateStatusUseCase: UpdateOrderStatusUseCase,
    private val observeOrdersUseCase: ObserveOrdersUseCase,
) {
    fun place(order: KitchenOrder): Flow<ResultState<KitchenOrder>> = placeUseCase(order)
    fun updateStatus(orderId: String, status: OrderStatus): Flow<ResultState<KitchenOrder>> =
        updateStatusUseCase(orderId, status)

    fun observe(userId: String): Flow<ResultState<List<KitchenOrder>>> = observeOrdersUseCase(userId)
}

class ChatApi internal constructor(
    private val sendMessageUseCase: SendMessageUseCase,
    private val receiveMessagesUseCase: ReceiveMessagesUseCase,
) {
    fun send(message: ChatMessage): Flow<ResultState<ChatMessage>> = sendMessageUseCase(message)
    fun receive(roomId: String): Flow<ResultState<List<ChatMessage>>> = receiveMessagesUseCase(roomId)
}

class SyncApi internal constructor(
    private val triggerSyncUseCase: TriggerSyncUseCase,
) {
    fun trigger(): Flow<ResultState<Unit>> = triggerSyncUseCase()
}

private class SDKComponents(config: CruiseSDKConfig) {
    private val logger = createPlatformLogger("CruiseSDK")
    private val scope = config.externalScope ?: CoroutineScope(SupervisorJob() + config.dispatcherProvider.io)
    private val httpClient = config.httpClient ?: createCruiseHttpClient(config.enableNetworkLogs)
    private val jsonCodec = JsonCodec()
    private val localDataSource = CruiseLocalDataSource(config.localStore, config.timeProvider)
    private val remoteDataSource = CruiseRemoteDataSource(httpClient, config.baseUrl)
    private val itineraryCachePolicy = CachePolicy(config.timeProvider, ttlMillis = 5 * 60 * 1000)

    private val authRepository = AuthRepositoryImpl(
        remoteDataSource = remoteDataSource,
        localDataSource = localDataSource,
        networkMonitor = config.networkMonitor,
        secureTokenStore = config.secureTokenStore,
        dispatcherProvider = config.dispatcherProvider,
    )

    private val preferencesRepository = PreferencesRepositoryImpl(
        remoteDataSource = remoteDataSource,
        localDataSource = localDataSource,
        networkMonitor = config.networkMonitor,
        secureTokenStore = config.secureTokenStore,
        jsonCodec = jsonCodec,
        dispatcherProvider = config.dispatcherProvider,
    )

    private val itineraryRepository = ItineraryRepositoryImpl(
        remoteDataSource = remoteDataSource,
        localDataSource = localDataSource,
        networkMonitor = config.networkMonitor,
        secureTokenStore = config.secureTokenStore,
        cachePolicy = itineraryCachePolicy,
        dispatcherProvider = config.dispatcherProvider,
    )

    private val orderRepository = OrderRepositoryImpl(
        remoteDataSource = remoteDataSource,
        localDataSource = localDataSource,
        networkMonitor = config.networkMonitor,
        secureTokenStore = config.secureTokenStore,
        jsonCodec = jsonCodec,
        dispatcherProvider = config.dispatcherProvider,
    )

    private val chatRepository = ChatRepositoryImpl(
        remoteDataSource = remoteDataSource,
        localDataSource = localDataSource,
        networkMonitor = config.networkMonitor,
        secureTokenStore = config.secureTokenStore,
        jsonCodec = jsonCodec,
        dispatcherProvider = config.dispatcherProvider,
        pollingIntervalMillis = config.pollingIntervalMillis,
    )

    private val syncEngine = SyncEngine(
        localDataSource = localDataSource,
        remoteDataSource = remoteDataSource,
        secureTokenStore = config.secureTokenStore,
        networkMonitor = config.networkMonitor,
        jsonCodec = jsonCodec,
        dispatcherProvider = config.dispatcherProvider,
        timeProvider = config.timeProvider,
    )

    private val loginUseCase = LoginUseCase(authRepository)
    private val getCachedSessionUseCase = GetCachedSessionUseCase(authRepository)
    private val savePreferencesUseCase = SavePreferencesUseCase(preferencesRepository)
    private val fetchPreferencesUseCase = FetchPreferencesUseCase(preferencesRepository)
    private val fetchItineraryUseCase = FetchItineraryUseCase(itineraryRepository)
    private val placeOrderUseCase = PlaceOrderUseCase(orderRepository)
    private val updateOrderStatusUseCase = UpdateOrderStatusUseCase(orderRepository)
    private val observeOrdersUseCase = ObserveOrdersUseCase(orderRepository)
    private val sendMessageUseCase = SendMessageUseCase(chatRepository)
    private val receiveMessagesUseCase = ReceiveMessagesUseCase(chatRepository)
    private val triggerSyncUseCase = TriggerSyncUseCase(syncEngine)

    val authApi = AuthApi(loginUseCase, getCachedSessionUseCase)
    val preferencesApi = PreferencesApi(savePreferencesUseCase, fetchPreferencesUseCase)
    val itineraryApi = ItineraryApi(fetchItineraryUseCase)
    val orderApi = OrderApi(placeOrderUseCase, updateOrderStatusUseCase, observeOrdersUseCase)
    val chatApi = ChatApi(sendMessageUseCase, receiveMessagesUseCase)
    val syncApi = SyncApi(triggerSyncUseCase)

    fun start() {
        val info = createDeviceInfoProvider().getDeviceInfo()
        logger.i("Initializing on ${info.platform} ${info.osVersion} (${info.deviceModel})")
        syncEngine.start(scope)
    }

    fun close() {
        syncEngine.stop()
        httpClient.close()
    }
}
