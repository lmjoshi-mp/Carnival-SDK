package com.carnival.sdk.data.sync

import com.carnival.sdk.core.dispatcher.DispatcherProvider
import com.carnival.sdk.core.network.NetworkMonitor
import com.carnival.sdk.core.util.ExponentialBackoff
import com.carnival.sdk.core.util.JsonCodec
import com.carnival.sdk.core.util.TimeProvider
import com.carnival.sdk.data.local.CruiseLocalDataSource
import com.carnival.sdk.data.mapper.toDomain
import com.carnival.sdk.data.remote.SyncRemoteGateway
import com.carnival.sdk.data.remote.dto.ChatMessageDto
import com.carnival.sdk.data.remote.dto.OrderDto
import com.carnival.sdk.data.remote.dto.PreferencesDto
import com.carnival.sdk.domain.error.DomainError
import com.carnival.sdk.domain.model.SyncQueueItem
import com.carnival.sdk.domain.repository.SyncRepository
import com.carnival.sdk.core.util.ResultState
import com.carnival.sdk.core.util.SecureTokenStore
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Job
import kotlinx.coroutines.CancellationException
import kotlinx.coroutines.delay
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.flow
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.onEach
import kotlinx.coroutines.launch

interface ConflictResolver {
    fun shouldApplyRemote(localUpdatedAt: Long, remoteUpdatedAt: Long): Boolean
}

class LastWriteWinsConflictResolver : ConflictResolver {
    override fun shouldApplyRemote(localUpdatedAt: Long, remoteUpdatedAt: Long): Boolean =
        remoteUpdatedAt >= localUpdatedAt
}

class SyncEngine(
    private val localDataSource: CruiseLocalDataSource,
    private val remoteDataSource: SyncRemoteGateway,
    private val secureTokenStore: SecureTokenStore,
    private val networkMonitor: NetworkMonitor,
    private val jsonCodec: JsonCodec,
    private val dispatcherProvider: DispatcherProvider,
    private val timeProvider: TimeProvider,
    private val backoff: ExponentialBackoff = ExponentialBackoff(),
    private val conflictResolver: ConflictResolver = LastWriteWinsConflictResolver(),
) : SyncRepository {
    private var workerJob: Job? = null
    private var lastPullEpochMillis: Long = 0L

    fun start(scope: CoroutineScope) {
        if (workerJob != null) return
        workerJob = scope.launch(dispatcherProvider.io) {
            networkMonitor.isOnline.onEach { online ->
                if (online) {
                    syncNowInternal()
                }
            }.launchIn(this)

            while (true) {
                if (networkMonitor.isOnline.value) {
                    syncNowInternal()
                }
                delay(15_000)
            }
        }
    }

    fun stop() {
        workerJob?.cancel()
        workerJob = null
    }

    override fun triggerSync(): Flow<ResultState<Unit>> = flow {
        emit(ResultState.Loading)
        try {
            syncNowInternal()
            emit(ResultState.Success(Unit))
        } catch (throwable: Throwable) {
            if (throwable is CancellationException) throw throwable
            emit(ResultState.Error(DomainError.SyncError("Manual sync failed", throwable)))
        }
    }

    private suspend fun syncNowInternal() {
        val token = secureTokenStore.getToken() ?: return
        pullRemoteChanges(token)
        pushLocalChanges(token)
    }

    private suspend fun pushLocalChanges(token: String) {
        val now = timeProvider.nowEpochMillis()
        val queue = localDataSource.getSyncQueue()
        queue.forEach { item ->
            if (item.nextRetryEpochMillis > now) return@forEach

            try {
                remoteDataSource.pushSyncChange(item.payload, token)
                localDataSource.removeSyncItem(item.id)
                markEntitySynced(item)
            } catch (throwable: Throwable) {
                val newRetry = item.retryCount + 1
                localDataSource.updateSyncItem(
                    item.copy(
                        retryCount = newRetry,
                        nextRetryEpochMillis = now + backoff.nextDelayMillis(newRetry),
                    ),
                )
            }
        }
    }

    private suspend fun pullRemoteChanges(token: String) {
        val changes = remoteDataSource.pullRemoteChanges(token, lastPullEpochMillis)
        for (change in changes) {
            when (change.entityType) {
                "preferences" -> {
                    val remote = jsonCodec.decode(PreferencesDto.serializer(), change.payload).toDomain()
                    val local = localDataSource.getPreferences(remote.userId)
                    if (local == null || conflictResolver.shouldApplyRemote(local.updatedAtEpochMillis, remote.updatedAtEpochMillis)) {
                        localDataSource.savePreferences(remote)
                    }
                }

                "order" -> {
                    val remote = jsonCodec.decode(OrderDto.serializer(), change.payload).toDomain(pendingSync = false)
                    val local = localDataSource.getOrder(remote.id)
                    if (local == null || conflictResolver.shouldApplyRemote(local.updatedAtEpochMillis, remote.updatedAtEpochMillis)) {
                        localDataSource.saveOrder(remote.copy(pendingSync = false))
                    }
                }

                "chat" -> {
                    val remote = jsonCodec.decode(ChatMessageDto.serializer(), change.payload).toDomain(pendingSync = false)
                    val local = localDataSource.getMessages(remote.roomId).firstOrNull { it.id == remote.id }
                    if (local == null || conflictResolver.shouldApplyRemote(local.createdAtEpochMillis, remote.createdAtEpochMillis)) {
                        localDataSource.saveMessage(remote)
                    }
                }
            }
        }
        if (changes.isNotEmpty()) {
            lastPullEpochMillis = changes.maxOf { it.updatedAtEpochMillis }
        }
    }

    private suspend fun markEntitySynced(item: SyncQueueItem) {
        when (item.entityType) {
            "order" -> localDataSource.markOrderPending(item.entityId, pendingSync = false)
            "chat" -> {
                val message = localDataSource.getMessage(item.entityId) ?: return
                localDataSource.saveMessage(message.copy(pendingSync = false))
            }
        }
    }
}
