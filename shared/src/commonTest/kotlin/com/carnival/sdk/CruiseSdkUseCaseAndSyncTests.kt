package com.carnival.sdk

import com.carnival.sdk.core.database.InMemoryLocalStore
import com.carnival.sdk.core.dispatcher.DefaultDispatcherProvider
import com.carnival.sdk.core.network.MutableNetworkMonitor
import com.carnival.sdk.core.util.InMemorySecureTokenStore
import com.carnival.sdk.core.util.JsonCodec
import com.carnival.sdk.core.util.ResultState
import com.carnival.sdk.core.util.SystemTimeProvider
import com.carnival.sdk.data.local.CruiseLocalDataSource
import com.carnival.sdk.data.remote.SyncRemoteGateway
import com.carnival.sdk.data.remote.dto.RemoteSyncChangeDto
import com.carnival.sdk.data.sync.SyncEngine
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.SyncOperationType
import com.carnival.sdk.domain.model.UserSession
import com.carnival.sdk.domain.repository.AuthRepository
import com.carnival.sdk.domain.usecase.LoginUseCase
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.flow
import kotlinx.coroutines.flow.toList
import kotlinx.coroutines.test.runTest
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class CruiseSdkUseCaseAndSyncTests {
    @Test
    fun loginUseCase_emitsLoadingThenSuccess() = runTest {
        val expected = UserSession(
            userId = "u-1",
            email = "guest@ship.com",
            token = "token-1",
            refreshToken = null,
            expiresAtEpochMillis = Long.MAX_VALUE,
        )
        val repo = object : AuthRepository {
            override fun login(email: String, password: String): Flow<ResultState<UserSession>> = flow {
                emit(ResultState.Loading)
                emit(ResultState.Success(expected))
            }

            override fun getCachedSession(): Flow<ResultState<UserSession?>> = flow {
                emit(ResultState.Success(expected))
            }
        }

        val states = LoginUseCase(repo)("guest@ship.com", "pwd").toList()
        assertTrue(states.first() is ResultState.Loading)
        assertEquals(expected, (states.last() as ResultState.Success).data)
    }

    @Test
    fun syncEngine_pushesQueuedOrderAndClearsQueue() = runTest {
        val local = CruiseLocalDataSource(InMemoryLocalStore(), SystemTimeProvider())
        val tokenStore = InMemorySecureTokenStore().apply { saveToken("token-123") }
        val remote = FakeSyncRemoteGateway()
        val networkMonitor = MutableNetworkMonitor(initialOnline = true)
        val engine = SyncEngine(
            localDataSource = local,
            remoteDataSource = remote,
            secureTokenStore = tokenStore,
            networkMonitor = networkMonitor,
            jsonCodec = JsonCodec(),
            dispatcherProvider = DefaultDispatcherProvider(),
            timeProvider = SystemTimeProvider(),
        )

        local.enqueueSync(
            entityType = "order",
            entityId = "order-1",
            operationType = SyncOperationType.CREATE,
            payload = """{"id":"order-1","status":"${OrderStatus.QUEUED.name}"}""",
        )

        val states = engine.triggerSync().toList()
        assertTrue(states.last() is ResultState.Success)
        assertEquals(1, remote.pushedPayloads.size)
        assertTrue(local.getSyncQueue().isEmpty())
    }

    @Test
    fun syncEngine_retriesWhenPushFails() = runTest {
        val local = CruiseLocalDataSource(InMemoryLocalStore(), SystemTimeProvider())
        val tokenStore = InMemorySecureTokenStore().apply { saveToken("token-123") }
        val remote = FakeSyncRemoteGateway(failPush = true)
        val engine = SyncEngine(
            localDataSource = local,
            remoteDataSource = remote,
            secureTokenStore = tokenStore,
            networkMonitor = MutableNetworkMonitor(initialOnline = true),
            jsonCodec = JsonCodec(),
            dispatcherProvider = DefaultDispatcherProvider(),
            timeProvider = SystemTimeProvider(),
        )

        local.enqueueSync(
            entityType = "order",
            entityId = "order-2",
            operationType = SyncOperationType.UPDATE,
            payload = """{"id":"order-2","status":"${OrderStatus.CONFIRMED.name}"}""",
        )

        engine.triggerSync().toList()
        val queue = local.getSyncQueue()
        assertEquals(1, queue.size)
        assertEquals(1, queue.first().retryCount)
    }
}

private class FakeSyncRemoteGateway(
    private val failPush: Boolean = false,
) : SyncRemoteGateway {
    val pushedPayloads: MutableList<String> = mutableListOf()

    override suspend fun pullRemoteChanges(token: String, sinceEpochMillis: Long): List<RemoteSyncChangeDto> =
        emptyList()

    override suspend fun pushSyncChange(payload: String, token: String) {
        if (failPush) error("simulated push failure")
        pushedPayloads += payload
    }
}
