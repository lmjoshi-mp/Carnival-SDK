package com.carnival.sdk

import com.carnival.sdk.core.database.InMemoryLocalStore
import com.carnival.sdk.core.dispatcher.DefaultDispatcherProvider
import com.carnival.sdk.core.network.MutableNetworkMonitor
import com.carnival.sdk.core.util.InMemorySecureTokenStore
import com.carnival.sdk.core.util.JsonCodec
import com.carnival.sdk.core.util.ResultState
import com.carnival.sdk.data.cache.CachePolicy
import com.carnival.sdk.data.local.CruiseLocalDataSource
import com.carnival.sdk.data.remote.CruiseRemoteDataSource
import com.carnival.sdk.data.remote.dto.ChatMessageDto
import com.carnival.sdk.data.remote.dto.ItineraryItemDto
import com.carnival.sdk.data.remote.dto.ItineraryPageDto
import com.carnival.sdk.data.remote.dto.OrderDto
import com.carnival.sdk.data.remote.dto.PreferencesDto
import com.carnival.sdk.data.remote.dto.RemoteSyncChangeDto
import com.carnival.sdk.data.remote.dto.UserSessionDto
import com.carnival.sdk.data.repository.AuthRepositoryImpl
import com.carnival.sdk.data.repository.ChatRepositoryImpl
import com.carnival.sdk.data.repository.ItineraryRepositoryImpl
import com.carnival.sdk.data.repository.OrderRepositoryImpl
import com.carnival.sdk.data.repository.PreferencesRepositoryImpl
import com.carnival.sdk.data.sync.SyncEngine
import com.carnival.sdk.domain.error.DomainError
import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.SyncOperationType
import com.carnival.sdk.domain.model.UserPreferences
import com.carnival.sdk.domain.model.UserSession
import io.ktor.client.HttpClient
import io.ktor.client.engine.mock.MockEngine
import io.ktor.client.engine.mock.respond
import io.ktor.client.plugins.contentnegotiation.ContentNegotiation
import io.ktor.client.request.HttpRequestData
import io.ktor.http.ContentType
import io.ktor.http.HttpHeaders
import io.ktor.http.HttpMethod
import io.ktor.http.HttpStatusCode
import io.ktor.http.content.OutgoingContent
import io.ktor.http.headersOf
import io.ktor.serialization.kotlinx.json.json
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.SupervisorJob
import kotlinx.coroutines.flow.first
import kotlinx.coroutines.flow.toList
import kotlinx.coroutines.test.runTest
import kotlinx.datetime.Clock
import kotlinx.serialization.KSerializer
import kotlinx.serialization.builtins.ListSerializer
import kotlinx.serialization.encodeToString
import kotlinx.serialization.json.Json
import kotlinx.serialization.json.JsonObject
import kotlinx.serialization.json.JsonPrimitive
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertFalse
import kotlin.test.assertIs
import kotlin.test.assertNotNull
import kotlin.test.assertTrue
import kotlin.test.fail

class RepositoryAndSdkCoverageTests {
    @Test
    fun authRepository_supportsOnlineAndOfflineFallback() = runTest {
        val env = TestEnvironment(online = true)
        val repository = env.authRepository()
        val onlineStates = repository.login("guest@ship.com", "secret").toList()
        assertTrue(onlineStates.last() is ResultState.Success)
        assertEquals("token-abc", env.tokenStore.getToken())

        env.networkMonitor.update(false)
        val offlineStates = repository.login("guest@ship.com", "secret").toList()
        assertTrue(offlineStates.last() is ResultState.Success)
    }

    @Test
    fun authRepository_returnsUnauthorizedWithoutOfflineSession() = runTest {
        val env = TestEnvironment(online = false)
        val states = env.authRepository().login("guest@ship.com", "secret").toList()
        assertIs<ResultState.Error>(states.last())
        assertIs<DomainError.UnauthorizedError>((states.last() as ResultState.Error).error)
    }

    @Test
    fun preferencesRepository_queuesOfflineSaveAndRefreshesOnlineFetch() = runTest {
        val env = TestEnvironment(online = true)
        env.tokenStore.saveToken("token-abc")
        val repository = env.preferencesRepository()
        val prefs = UserPreferences("guest-1", listOf("Pasta"), listOf("Swim"), 22, 100)

        env.networkMonitor.update(false)
        val offlineSave = repository.savePreferences(prefs).toList()
        assertTrue(offlineSave.any { it is ResultState.Success })
        assertEquals(1, env.local.getSyncQueue().size)

        env.networkMonitor.update(true)
        val fetched = repository.fetchPreferences("guest-1").toList()
        assertTrue(fetched.last() is ResultState.Success)
        assertNotNull(env.local.getPreferences("guest-1"))
    }

    @Test
    fun itineraryRepository_refreshesExpiredCache() = runTest {
        val env = TestEnvironment(online = true)
        env.tokenStore.saveToken("token-abc")
        val repository = env.itineraryRepository(ttlMillis = 10)
        val states = repository.fetchItinerary(0, 2).toList()
        assertTrue(states.any { it is ResultState.Success && it.data.isNotEmpty() })
    }

    @Test
    fun orderRepository_handlesOfflineQueueAndStatusError() = runTest {
        val env = TestEnvironment(online = false)
        env.tokenStore.saveToken("token-abc")
        val repository = env.orderRepository()
        val order = sampleOrder()

        val placed = repository.placeOrder(order).toList()
        assertTrue(placed.any { it is ResultState.Success })
        assertEquals(1, env.local.getSyncQueue().size)

        val missing = repository.updateOrderStatus("missing", OrderStatus.CONFIRMED).toList()
        assertIs<ResultState.Error>(missing.last())
        assertIs<DomainError.CacheError>((missing.last() as ResultState.Error).error)
    }

    @Test
    fun orderRepository_updatesStatusOnline() = runTest {
        val env = TestEnvironment(online = true)
        env.tokenStore.saveToken("token-abc")
        val repository = env.orderRepository()
        env.local.saveOrder(sampleOrder())

        val updated = repository.updateOrderStatus("order-1", OrderStatus.CONFIRMED).toList()
        assertTrue(updated.last() is ResultState.Success)
        assertEquals(OrderStatus.CONFIRMED, env.local.getOrder("order-1")!!.status)
    }

    @Test
    fun orderRepository_placesOrderOnline() = runTest {
        val env = TestEnvironment(online = true)
        env.tokenStore.saveToken("token-abc")
        val states = env.orderRepository().placeOrder(sampleOrder()).toList()
        assertTrue(states.last() is ResultState.Success)
        assertFalse(env.local.getOrder("order-1")!!.pendingSync)
    }

    @Test
    fun chatRepository_sendsOfflineAndReceivesLocalMessages() = runTest {
        val env = TestEnvironment(online = false)
        env.tokenStore.saveToken("token-abc")
        val repository = env.chatRepository(pollingIntervalMillis = 1)
        val message = sampleMessage()

        val sent = repository.sendMessage(message).toList()
        assertTrue(sent.any { it is ResultState.Success })
        assertEquals(1, env.local.getSyncQueue().size)

        env.local.saveMessage(message.copy(id = "m-local", pendingSync = false))
        val received = repository.receiveMessages("admin-room").first { it is ResultState.Success && it.data.isNotEmpty() }
        assertTrue(received is ResultState.Success && received.data.isNotEmpty())
    }

    @Test
    fun chatRepository_sendsOnlineSuccessfully() = runTest {
        val env = TestEnvironment(online = true)
        env.tokenStore.saveToken("token-abc")
        val states = env.chatRepository(pollingIntervalMillis = 1).sendMessage(sampleMessage()).toList()
        assertTrue(states.last() is ResultState.Success)
        assertFalse(env.local.getMessage("msg-1")!!.pendingSync)
    }

    @Test
    fun syncEngine_pullsRemoteChangesAndMarksEntitiesSynced() = runTest {
        val env = TestEnvironment(online = true)
        env.tokenStore.saveToken("token-abc")
        env.local.saveOrder(sampleOrder())
        env.local.saveMessage(sampleMessage())
        env.local.enqueueSync("order", "order-1", SyncOperationType.UPDATE, """{"id":"order-1","status":"CONFIRMED"}""")
        env.local.enqueueSync("chat", "msg-1", SyncOperationType.CREATE, """{"id":"msg-1"}""")

        val engine = SyncEngine(
            localDataSource = env.local,
            remoteDataSource = env.remoteGateway(),
            secureTokenStore = env.tokenStore,
            networkMonitor = env.networkMonitor,
            jsonCodec = JsonCodec(),
            dispatcherProvider = DefaultDispatcherProvider(),
            timeProvider = env.timeProvider,
        )

        val states = engine.triggerSync().toList()
        assertTrue(states.last() is ResultState.Success)
        assertFalse(env.local.getOrder("order-1")!!.pendingSync)
        assertFalse(env.local.getMessage("msg-1")!!.pendingSync)
        assertEquals("Salad", env.local.getPreferences("guest-1")!!.favoriteFoods.first())
        assertEquals(OrderStatus.CONFIRMED, env.local.getOrder("remote-order")!!.status)
        assertEquals("Admin update", env.local.getMessage("remote-chat")!!.content)
    }

    @Test
    fun syncEngine_startStopAndCancellationAreSafe() = runTest {
        val env = TestEnvironment(online = true)
        env.tokenStore.saveToken("token-abc")
        val engine = SyncEngine(
            localDataSource = env.local,
            remoteDataSource = env.remoteGateway(),
            secureTokenStore = env.tokenStore,
            networkMonitor = env.networkMonitor,
            jsonCodec = JsonCodec(),
            dispatcherProvider = DefaultDispatcherProvider(),
            timeProvider = env.timeProvider,
        )
        val scope = CoroutineScope(SupervisorJob())
        engine.start(scope)
        engine.start(scope)
        engine.stop()
        engine.stop()
    }

    @Test
    fun cruiseSdk_requiresInitializationAndExposesFeatureApis() = runTest {
        CruiseSDK.shutdown()
        runCatching { CruiseSDK.auth }.onSuccess { fail("Expected uninitialized SDK to throw") }

        val env = TestEnvironment(online = true)
        CruiseSDK.initialize(
            CruiseSDKConfig(
                baseUrl = "https://mock.carnival",
                networkMonitor = env.networkMonitor,
                localStore = InMemoryLocalStore(),
                secureTokenStore = env.tokenStore,
                dispatcherProvider = DefaultDispatcherProvider(),
                timeProvider = env.timeProvider,
                httpClient = env.httpClient,
            ),
        )

        val login = CruiseSDK.auth.login("guest@ship.com", "secret").toList()
        assertTrue(login.last() is ResultState.Success)
        val cached = CruiseSDK.auth.cachedSession().toList()
        assertTrue(cached.last() is ResultState.Success)
        val prefs = CruiseSDK.preferences.get("guest-1").toList()
        assertTrue(prefs.last() is ResultState.Success)
        val savedPrefs = CruiseSDK.preferences.save(UserPreferences("guest-1", listOf("Soup"), listOf("Dance"), 22, 100)).toList()
        assertTrue(savedPrefs.last() is ResultState.Success)
        val itinerary = CruiseSDK.itinerary.get(0, 2).toList()
        assertTrue(itinerary.any { it is ResultState.Success })
        val order = CruiseSDK.order.place(sampleOrder()).toList()
        assertTrue(order.last() is ResultState.Success)
        val updatedOrder = CruiseSDK.order.updateStatus("order-1", OrderStatus.CONFIRMED).toList()
        assertTrue(updatedOrder.last() is ResultState.Success)
        val observed = CruiseSDK.order.observe("guest-1").first { it is ResultState.Success }
        assertTrue(observed is ResultState.Success)
        val sentChat = CruiseSDK.chat.send(sampleMessage()).toList()
        assertTrue(sentChat.last() is ResultState.Success)
        val receivedChat = CruiseSDK.chat.receive("admin-room").first { it is ResultState.Success }
        assertTrue(receivedChat is ResultState.Success)
        val sync = CruiseSDK.sync.trigger().toList()
        assertTrue(sync.last() is ResultState.Success)
        CruiseSDK.shutdown()
    }
}

private class TestEnvironment(online: Boolean) {
    val timeProvider = MutableTimeProvider(1000)
    val networkMonitor = MutableNetworkMonitor(online)
    val tokenStore = InMemorySecureTokenStore()
    val local = CruiseLocalDataSource(InMemoryLocalStore(), timeProvider)
    val backend = MockBackend(timeProvider)
    val httpClient: HttpClient = backend.client()
    private val remote = CruiseRemoteDataSource(httpClient, "https://mock.carnival")

    fun authRepository() = AuthRepositoryImpl(remote, local, networkMonitor, tokenStore, DefaultDispatcherProvider())
    fun preferencesRepository() = PreferencesRepositoryImpl(remote, local, networkMonitor, tokenStore, JsonCodec(), DefaultDispatcherProvider())
    fun itineraryRepository(ttlMillis: Long) = ItineraryRepositoryImpl(
        remote, local, networkMonitor, tokenStore, CachePolicy(timeProvider, ttlMillis), DefaultDispatcherProvider()
    )
    fun orderRepository() = OrderRepositoryImpl(remote, local, networkMonitor, tokenStore, JsonCodec(), DefaultDispatcherProvider())
    fun chatRepository(pollingIntervalMillis: Long) = ChatRepositoryImpl(
        remote, local, networkMonitor, tokenStore, JsonCodec(), DefaultDispatcherProvider(), pollingIntervalMillis
    )
    fun remoteGateway() = remote
}

private class MockBackend(private val time: MutableTimeProvider) {
    private val json = Json { ignoreUnknownKeys = true; encodeDefaults = true }
    private var preferences = PreferencesDto("guest-1", listOf("Salad"), listOf("Dance"), 21, time.now)
    private val orders = mutableMapOf<String, OrderDto>()
    private val chatMessages = mutableListOf(ChatMessageDto("server-1", "admin-room", "admin", "ADMIN", "Welcome", time.now))
    private val remoteChanges = mutableListOf(
        RemoteSyncChangeDto(
            "preferences",
            "guest-1",
            "UPDATE",
            json.encodeToString(PreferencesDto.serializer(), preferences),
            time.now,
        ),
        RemoteSyncChangeDto(
            "order",
            "remote-order",
            "UPDATE",
            json.encodeToString(OrderDto.serializer(), OrderDto("remote-order", "guest-1", listOf("Salad"), null, "CONFIRMED", 11.0, time.now)),
            time.now + 1,
        ),
        RemoteSyncChangeDto(
            "chat",
            "remote-chat",
            "CREATE",
            json.encodeToString(ChatMessageDto.serializer(), ChatMessageDto("remote-chat", "admin-room", "admin", "ADMIN", "Admin update", time.now + 2)),
            time.now + 2,
        ),
    )

    fun client(): HttpClient {
        val engine = MockEngine { request ->
            fun ok(body: String) = respond(
                body,
                HttpStatusCode.OK,
                headersOf(HttpHeaders.ContentType, ContentType.Application.Json.toString()),
            )
            fun error(message: String) = respond(
                """{"message":"$message"}""",
                HttpStatusCode.BadRequest,
                headersOf(HttpHeaders.ContentType, ContentType.Application.Json.toString()),
            )
            when {
                request.url.encodedPath == "/auth/login" && request.method == HttpMethod.Post ->
                    ok(json.encodeToString(UserSessionDto.serializer(), UserSessionDto("guest-1", "guest@ship.com", "token-abc", null, Long.MAX_VALUE, time.now)))

                request.url.encodedPath.startsWith("/preferences/") && request.method == HttpMethod.Get ->
                    ok(json.encodeToString(PreferencesDto.serializer(), preferences))

                request.url.encodedPath == "/preferences" && request.method == HttpMethod.Post -> {
                    parseBody(request, PreferencesDto.serializer())?.let { preferences = it }
                    ok(json.encodeToString(PreferencesDto.serializer(), preferences))
                }

                request.url.encodedPath == "/itinerary" && request.method == HttpMethod.Get ->
                    ok(
                        json.encodeToString(
                            ItineraryPageDto.serializer(),
                            ItineraryPageDto(
                                0,
                                2,
                                listOf(
                                    ItineraryItemDto("i1", 1, "Drill", "Safety", 1, 2, "Deck", time.now),
                                    ItineraryItemDto("i2", 1, "Dinner", "Meal", 3, 4, "Hall", time.now),
                                ),
                            ),
                        ),
                    )

                request.url.encodedPath == "/orders" && request.method == HttpMethod.Post -> {
                    val order = parseBody(request, OrderDto.serializer()) ?: return@MockEngine error("bad order")
                    orders[order.id] = order
                    ok(json.encodeToString(OrderDto.serializer(), order))
                }

                request.url.encodedPath.startsWith("/orders/") && request.url.encodedPath.endsWith("/status") -> {
                    val id = request.url.encodedPath.split("/")[2]
                    val existing = orders[id] ?: OrderDto(id, "guest-1", listOf("Burger"), null, "QUEUED", 10.0, time.now)
                    val status = (((json.parseToJsonElement(extractRequestBody(request))) as JsonObject)["status"] as JsonPrimitive).content
                    val updated = existing.copy(status = status, updatedAtEpochMillis = time.now)
                    orders[id] = updated
                    ok(json.encodeToString(OrderDto.serializer(), updated))
                }

                request.url.encodedPath == "/chat/messages" && request.method == HttpMethod.Post -> {
                    val msg = parseBody(request, ChatMessageDto.serializer()) ?: return@MockEngine error("bad msg")
                    chatMessages += msg
                    ok(json.encodeToString(ChatMessageDto.serializer(), msg))
                }

                request.url.encodedPath == "/chat/messages" && request.method == HttpMethod.Get ->
                    ok(json.encodeToString(ListSerializer(ChatMessageDto.serializer()), chatMessages.filter { it.roomId == request.url.parameters["roomId"] }))

                request.url.encodedPath == "/sync/changes" && request.method == HttpMethod.Get ->
                    ok(json.encodeToString(ListSerializer(RemoteSyncChangeDto.serializer()), remoteChanges))

                request.url.encodedPath == "/sync/push" && request.method == HttpMethod.Post ->
                    respond("{}", HttpStatusCode.OK, headersOf(HttpHeaders.ContentType, ContentType.Application.Json.toString()))

                else -> error("route")
            }
        }
        return HttpClient(engine) { install(ContentNegotiation) { json(json) } }
    }

    private fun <T> parseBody(request: HttpRequestData, serializer: KSerializer<T>): T? {
        val raw = extractRequestBody(request)
        if (raw.isBlank()) return null
        return runCatching { json.decodeFromString(serializer, raw) }.getOrNull()
    }

    private fun extractRequestBody(request: HttpRequestData): String {
        val body = request.body
        return when (body) {
            is OutgoingContent.ByteArrayContent -> body.bytes().decodeToString()
            else -> ""
        }
    }
}

private fun sampleOrder() = KitchenOrder("order-1", "guest-1", listOf("Burger"), null, OrderStatus.QUEUED, 10.0, 1000, true)
private fun sampleMessage() = ChatMessage("msg-1", "admin-room", "guest-1", "GUEST", "Need help", 1000, true)
