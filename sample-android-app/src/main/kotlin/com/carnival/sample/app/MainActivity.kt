package com.carnival.sample.app

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.lazy.rememberLazyListState
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.HorizontalDivider
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Switch
import androidx.compose.material3.Text
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.Composable
import androidx.compose.runtime.mutableStateListOf
import androidx.compose.runtime.mutableStateMapOf
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp
import androidx.lifecycle.lifecycleScope
import com.carnival.sdk.CruiseSDK
import com.carnival.sdk.CruiseSDKConfig
import com.carnival.sdk.core.network.MutableNetworkMonitor
import com.carnival.sdk.core.util.ResultState
import com.carnival.sdk.data.remote.dto.ChatMessageDto
import com.carnival.sdk.data.remote.dto.ItineraryItemDto
import com.carnival.sdk.data.remote.dto.ItineraryPageDto
import com.carnival.sdk.data.remote.dto.OrderDto
import com.carnival.sdk.data.remote.dto.PreferencesDto
import com.carnival.sdk.data.remote.dto.RemoteSyncChangeDto
import com.carnival.sdk.data.remote.dto.UserSessionDto
import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.UserPreferences
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
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.first
import kotlinx.coroutines.launch
import kotlinx.datetime.Clock
import kotlinx.serialization.KSerializer
import kotlinx.serialization.builtins.ListSerializer
import kotlinx.serialization.encodeToString
import kotlinx.serialization.json.Json
import kotlinx.serialization.json.JsonObject
import kotlinx.serialization.json.JsonPrimitive
import kotlin.random.Random

class MainActivity : ComponentActivity() {
    private lateinit var networkMonitor: MutableNetworkMonitor
    private val logs = mutableStateListOf("Carnival SDK Demo Logs")
    private val stepStatuses = mutableStateMapOf<DemoStep, StepStatus>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        networkMonitor = MutableNetworkMonitor(initialOnline = true)
        initializeSdk()
        DemoStep.entries.forEach { stepStatuses[it] = StepStatus.IDLE }
        appendLog("SDK initialized. Network ONLINE.")

        setContent {
            MaterialTheme {
                Surface(modifier = Modifier.fillMaxSize()) {
                    DemoScreen(
                        logs = logs,
                        stepStatuses = stepStatuses,
                        onLogin = { lifecycleScope.launch { runLogin() } },
                        onSavePreferences = { lifecycleScope.launch { runPreferences() } },
                        onFetchItinerary = { lifecycleScope.launch { runItinerary() } },
                        onGoOffline = { runOffline() },
                        onPlaceOrderOffline = { lifecycleScope.launch { runOrderOffline() } },
                        onSendChatOffline = { lifecycleScope.launch { runChatOffline() } },
                        onGoOnlineAndSync = { lifecycleScope.launch { runGoOnlineAndSync() } },
                        onObserveOrders = { lifecycleScope.launch { runObserveOrders() } },
                        onReceiveChat = { lifecycleScope.launch { runReceiveChat() } },
                        onRunFullScenario = { lifecycleScope.launch { runFullScenario() } },
                        onResetDemo = { resetDemoState() },
                    )
                }
            }
        }
    }

    override fun onDestroy() {
        CruiseSDK.shutdown()
        super.onDestroy()
    }

    private fun initializeSdk() {
        CruiseSDK.initialize(
            CruiseSDKConfig(
                baseUrl = "https://mock.carnival",
                networkMonitor = networkMonitor,
                httpClient = MockCruiseBackend().createHttpClient(),
            ),
        )
    }

    private fun resetDemoState() {
        networkMonitor.update(true)
        initializeSdk()
        logs.clear()
        logs += "Carnival SDK Demo Logs"
        DemoStep.entries.forEach { stepStatuses[it] = StepStatus.IDLE }
        appendLog("Demo reset complete. Network ONLINE.")
    }

    private suspend fun runLogin() = executeStep(DemoStep.LOGIN, "Login") {
        CruiseSDK.auth.login("guest@ship.com", "secret")
    }

    private suspend fun runPreferences() = executeStep(DemoStep.PREFERENCES, "Save Preferences") {
        CruiseSDK.preferences.save(
            UserPreferences(
                userId = "guest-1",
                favoriteFoods = listOf("Pasta", "Sushi"),
                preferredActivities = listOf("Pool Games", "Jazz Night"),
                roomTemperature = 22,
                updatedAtEpochMillis = Clock.System.now().toEpochMilliseconds(),
            ),
        )
    }

    private suspend fun runItinerary() = executeStep(DemoStep.ITINERARY, "Fetch Itinerary") {
        CruiseSDK.itinerary.get(page = 0, pageSize = 2)
    }

    private fun runOffline() {
        networkMonitor.update(false)
        appendLog("Network switched OFFLINE")
        markStatus(DemoStep.GO_OFFLINE, StepStatus.SUCCESS)
    }

    private suspend fun runOrderOffline() = executeStep(DemoStep.ORDER_OFFLINE, "Place Order") {
        CruiseSDK.order.place(
            KitchenOrder(
                id = "order-${Random.nextInt(1000, 9999)}",
                userId = "guest-1",
                items = listOf("Veg Burger", "Fries"),
                notes = "No mayo",
                status = OrderStatus.QUEUED,
                totalAmount = 15.99,
                updatedAtEpochMillis = Clock.System.now().toEpochMilliseconds(),
                pendingSync = false,
            ),
        )
    }

    private suspend fun runChatOffline() = executeStep(DemoStep.CHAT_OFFLINE, "Send Chat") {
        CruiseSDK.chat.send(
            ChatMessage(
                id = "msg-${Random.nextInt(1000, 9999)}",
                roomId = "admin-room",
                senderId = "guest-1",
                senderRole = "GUEST",
                content = "Need help with excursion booking.",
                createdAtEpochMillis = Clock.System.now().toEpochMilliseconds(),
                pendingSync = false,
            ),
        )
    }

    private suspend fun runGoOnlineAndSync() {
        markStatus(DemoStep.GO_ONLINE_SYNC, StepStatus.RUNNING)
        networkMonitor.update(true)
        appendLog("Network switched ONLINE")
        executeStep(DemoStep.GO_ONLINE_SYNC, "Trigger Sync") { CruiseSDK.sync.trigger() }
    }

    private suspend fun runObserveOrders() = executeStep(DemoStep.OBSERVE_ORDERS, "Observe Orders") {
        CruiseSDK.order.observe("guest-1")
    }

    private suspend fun runReceiveChat() = executeStep(DemoStep.RECEIVE_CHAT, "Receive Chat") {
        CruiseSDK.chat.receive("admin-room")
    }

    private suspend fun runFullScenario() {
        appendLog("Running full scenario...")
        DemoStep.entries.forEach { stepStatuses[it] = StepStatus.IDLE }
        runLogin()
        runPreferences()
        runItinerary()
        runOffline()
        runOrderOffline()
        runChatOffline()
        runGoOnlineAndSync()
        runObserveOrders()
        runReceiveChat()
        appendLog("Full scenario complete.")
    }

    private suspend fun <T> executeStep(
        step: DemoStep,
        label: String,
        flowProvider: () -> Flow<ResultState<T>>,
    ): Boolean {
        markStatus(step, StepStatus.RUNNING)
        val success = collectAndLog(label, flowProvider())
        markStatus(step, if (success) StepStatus.SUCCESS else StepStatus.ERROR)
        return success
    }

    private suspend fun <T> collectAndLog(step: String, flow: Flow<ResultState<T>>): Boolean {
        val result = flow.first { it !is ResultState.Loading }
        return when (result) {
            is ResultState.Success -> {
                appendLog("$step -> SUCCESS: ${result.data}")
                true
            }
            is ResultState.Error -> {
                appendLog("$step -> ERROR: ${result.error.message}")
                false
            }
            ResultState.Loading -> {
                appendLog("$step -> LOADING")
                false
            }
        }
    }

    private fun markStatus(step: DemoStep, status: StepStatus) {
        stepStatuses[step] = status
    }

    private fun appendLog(line: String) {
        logs += line
    }
}

private enum class StepStatus {
    IDLE, RUNNING, SUCCESS, ERROR
}

private enum class DemoStep(val title: String) {
    LOGIN("1) Login"),
    PREFERENCES("2) Save Preferences"),
    ITINERARY("3) Fetch Itinerary"),
    GO_OFFLINE("4) Switch Offline"),
    ORDER_OFFLINE("5) Place Order Offline"),
    CHAT_OFFLINE("6) Send Chat Offline"),
    GO_ONLINE_SYNC("7) Go Online + Sync"),
    OBSERVE_ORDERS("8) Observe Orders"),
    RECEIVE_CHAT("9) Receive Chat")
}

@Composable
private fun DemoScreen(
    logs: List<String>,
    stepStatuses: Map<DemoStep, StepStatus>,
    onLogin: () -> Unit,
    onSavePreferences: () -> Unit,
    onFetchItinerary: () -> Unit,
    onGoOffline: () -> Unit,
    onPlaceOrderOffline: () -> Unit,
    onSendChatOffline: () -> Unit,
    onGoOnlineAndSync: () -> Unit,
    onObserveOrders: () -> Unit,
    onReceiveChat: () -> Unit,
    onRunFullScenario: () -> Unit,
    onResetDemo: () -> Unit,
) {
    var autoScrollLogs by remember { mutableStateOf(true) }
    val logListState = rememberLazyListState()

    LaunchedEffect(logs.size, autoScrollLogs) {
        if (autoScrollLogs && logs.isNotEmpty()) {
            logListState.animateScrollToItem(logs.lastIndex)
        }
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        verticalArrangement = Arrangement.spacedBy(8.dp),
    ) {
        Text("Carnival SDK - Compose Consumer Demo", style = MaterialTheme.typography.titleMedium)
        Text("Tap individual actions or run one-click full scenario.")
        Row(horizontalArrangement = Arrangement.spacedBy(8.dp), modifier = Modifier.fillMaxWidth()) {
            Button(onClick = onRunFullScenario, modifier = Modifier.weight(1f)) {
                Text("Run Full Scenario")
            }
            Button(onClick = onResetDemo, modifier = Modifier.weight(1f)) {
                Text("Reset Demo State")
            }
        }

        Column(verticalArrangement = Arrangement.spacedBy(6.dp)) {
            DemoStep.entries.forEach { step ->
                StatusCard(step.title, stepStatuses[step] ?: StepStatus.IDLE)
            }
        }

        Row(horizontalArrangement = Arrangement.spacedBy(8.dp), modifier = Modifier.fillMaxWidth()) {
            Button(onClick = onLogin, modifier = Modifier.weight(1f)) { Text("1) Login") }
            Button(onClick = onSavePreferences, modifier = Modifier.weight(1f)) { Text("2) Preferences") }
        }
        Row(horizontalArrangement = Arrangement.spacedBy(8.dp), modifier = Modifier.fillMaxWidth()) {
            Button(onClick = onFetchItinerary, modifier = Modifier.weight(1f)) { Text("3) Itinerary") }
            Button(onClick = onGoOffline, modifier = Modifier.weight(1f)) { Text("4) Offline") }
        }
        Row(horizontalArrangement = Arrangement.spacedBy(8.dp), modifier = Modifier.fillMaxWidth()) {
            Button(onClick = onPlaceOrderOffline, modifier = Modifier.weight(1f)) { Text("5) Order") }
            Button(onClick = onSendChatOffline, modifier = Modifier.weight(1f)) { Text("6) Chat") }
        }
        Row(horizontalArrangement = Arrangement.spacedBy(8.dp), modifier = Modifier.fillMaxWidth()) {
            Button(onClick = onGoOnlineAndSync, modifier = Modifier.weight(1f)) { Text("7) Sync") }
            Button(onClick = onObserveOrders, modifier = Modifier.weight(1f)) { Text("8) Orders") }
        }
        Button(onClick = onReceiveChat, modifier = Modifier.fillMaxWidth()) { Text("9) Receive Chat") }

        HorizontalDivider()
        Row(
            modifier = Modifier.fillMaxWidth(),
            horizontalArrangement = Arrangement.SpaceBetween,
        ) {
            Text("Logs", style = MaterialTheme.typography.titleSmall)
            Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                Text("Auto-scroll", style = MaterialTheme.typography.labelMedium)
                Switch(
                    checked = autoScrollLogs,
                    onCheckedChange = { autoScrollLogs = it },
                )
            }
        }
        LazyColumn(
            modifier = Modifier
                .fillMaxWidth()
                .weight(1f),
            state = logListState,
            verticalArrangement = Arrangement.spacedBy(4.dp),
        ) {
            items(logs) { line ->
                Text(
                    text = line,
                    style = MaterialTheme.typography.bodySmall,
                    modifier = Modifier
                        .fillMaxWidth()
                        .padding(vertical = 1.dp),
                )
            }
        }
    }
}

@Composable
private fun StatusCard(title: String, status: StepStatus) {
    val (label, color) = when (status) {
        StepStatus.IDLE -> "IDLE" to Color.Gray
        StepStatus.RUNNING -> "RUNNING" to Color(0xFF1565C0)
        StepStatus.SUCCESS -> "SUCCESS" to Color(0xFF2E7D32)
        StepStatus.ERROR -> "ERROR" to Color(0xFFC62828)
    }
    Card(
        colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surfaceVariant),
        modifier = Modifier.fillMaxWidth(),
    ) {
        Row(
            modifier = Modifier
                .fillMaxWidth()
                .padding(horizontal = 12.dp, vertical = 8.dp),
            horizontalArrangement = Arrangement.SpaceBetween,
        ) {
            Text(title, style = MaterialTheme.typography.bodyMedium)
            Row(horizontalArrangement = Arrangement.spacedBy(6.dp)) {
                Box(
                    modifier = Modifier
                        .size(8.dp)
                        .padding(top = 4.dp)
                        .let { base -> Modifier.then(base) },
                ) {
                    Surface(color = color, shape = MaterialTheme.shapes.small, modifier = Modifier.fillMaxSize()) {}
                }
                Text(label, style = MaterialTheme.typography.labelSmall, color = color)
            }
        }
    }
}

private class MockCruiseBackend {
    private val json = Json { ignoreUnknownKeys = true; encodeDefaults = true }
    private val now = Clock.System.now().toEpochMilliseconds()
    private var preferences = PreferencesDto(
        userId = "guest-1",
        favoriteFoods = listOf("Pasta"),
        preferredActivities = listOf("Welcome Party"),
        roomTemperature = 23,
        updatedAtEpochMillis = now,
    )
    private val orders = mutableMapOf<String, OrderDto>()
    private val chatMessages = mutableListOf(
        ChatMessageDto(
            id = "msg-1000",
            roomId = "admin-room",
            senderId = "admin-1",
            senderRole = "ADMIN",
            content = "Welcome onboard! Need anything?",
            createdAtEpochMillis = now - 1000,
        ),
    )
    private val remoteChanges = mutableListOf<RemoteSyncChangeDto>()

    fun createHttpClient(): HttpClient {
        val engine = MockEngine { request ->
            fun okJson(body: String) = respond(
                content = body,
                status = HttpStatusCode.OK,
                headers = headersOf(HttpHeaders.ContentType, ContentType.Application.Json.toString()),
            )

            fun errorJson(message: String, status: HttpStatusCode = HttpStatusCode.BadRequest) = respond(
                content = """{"message":"$message"}""",
                status = status,
                headers = headersOf(HttpHeaders.ContentType, ContentType.Application.Json.toString()),
            )

            when {
                request.url.encodedPath == "/auth/login" && request.method == HttpMethod.Post ->
                    okJson(
                        json.encodeToString(
                            UserSessionDto.serializer(),
                            UserSessionDto(
                                userId = "guest-1",
                                email = "guest@ship.com",
                                token = "token-abc",
                                refreshToken = "refresh-abc",
                                expiresAtEpochMillis = now + 60 * 60 * 1000,
                                lastLoginAtEpochMillis = now,
                            ),
                        ),
                    )

                request.url.encodedPath.startsWith("/preferences/") && request.method == HttpMethod.Get ->
                    okJson(json.encodeToString(PreferencesDto.serializer(), preferences))

                request.url.encodedPath == "/preferences" && request.method == HttpMethod.Post -> {
                    parseBody(request, PreferencesDto.serializer())?.let { preferences = it }
                    okJson(json.encodeToString(PreferencesDto.serializer(), preferences))
                }

                request.url.encodedPath == "/itinerary" && request.method == HttpMethod.Get -> {
                    val page = request.url.parameters["page"]?.toIntOrNull() ?: 0
                    val pageSize = request.url.parameters["pageSize"]?.toIntOrNull() ?: 2
                    val all = listOf(
                        ItineraryItemDto("it-1", 1, "Safety Drill", "Mandatory drill", now + 10_000, now + 20_000, "Deck 1", now),
                        ItineraryItemDto("it-2", 1, "Captain Dinner", "Formal dinner", now + 25_000, now + 50_000, "Main Hall", now),
                        ItineraryItemDto("it-3", 2, "Island Excursion", "Morning excursion", now + 70_000, now + 100_000, "Port Gate", now),
                    )
                    val start = (page * pageSize).coerceAtMost(all.size)
                    val end = (start + pageSize).coerceAtMost(all.size)
                    okJson(
                        json.encodeToString(
                            ItineraryPageDto.serializer(),
                            ItineraryPageDto(page, pageSize, all.subList(start, end)),
                        ),
                    )
                }

                request.url.encodedPath == "/orders" && request.method == HttpMethod.Post -> {
                    val order = parseBody(request, OrderDto.serializer())
                        ?: return@MockEngine errorJson("Invalid order payload")
                    orders[order.id] = order
                    okJson(json.encodeToString(OrderDto.serializer(), order))
                }

                request.url.encodedPath.startsWith("/orders/") &&
                    request.url.encodedPath.endsWith("/status") &&
                    request.method == HttpMethod.Post -> {
                    val orderId = request.url.encodedPath.split("/")[2]
                    val status = runCatching {
                        val jsonObj = json.parseToJsonElement(extractRequestBody(request)) as JsonObject
                        (jsonObj["status"] as? JsonPrimitive)?.content
                    }.getOrNull() ?: return@MockEngine errorJson("Missing status")
                    val existing = orders[orderId] ?: return@MockEngine errorJson("Order not found", HttpStatusCode.NotFound)
                    val updated = existing.copy(
                        status = status,
                        updatedAtEpochMillis = Clock.System.now().toEpochMilliseconds(),
                    )
                    orders[orderId] = updated
                    okJson(json.encodeToString(OrderDto.serializer(), updated))
                }

                request.url.encodedPath == "/chat/messages" && request.method == HttpMethod.Post -> {
                    val msg = parseBody(request, ChatMessageDto.serializer())
                        ?: return@MockEngine errorJson("Invalid message payload")
                    chatMessages += msg
                    okJson(json.encodeToString(ChatMessageDto.serializer(), msg))
                }

                request.url.encodedPath == "/chat/messages" && request.method == HttpMethod.Get -> {
                    val roomId = request.url.parameters["roomId"]
                    val result = if (roomId == null) chatMessages else chatMessages.filter { it.roomId == roomId }
                    okJson(json.encodeToString(ListSerializer(ChatMessageDto.serializer()), result))
                }

                request.url.encodedPath == "/sync/changes" && request.method == HttpMethod.Get ->
                    okJson(json.encodeToString(ListSerializer(RemoteSyncChangeDto.serializer()), remoteChanges))

                request.url.encodedPath == "/sync/push" && request.method == HttpMethod.Post -> {
                    val payload = extractRequestBody(request)
                    remoteChanges += RemoteSyncChangeDto(
                        entityType = "unknown",
                        entityId = "unknown",
                        operationType = "PUSHED",
                        payload = payload,
                        updatedAtEpochMillis = Clock.System.now().toEpochMilliseconds(),
                    )
                    okJson("{}")
                }

                else -> errorJson("No route for ${request.method.value} ${request.url.encodedPath}", HttpStatusCode.NotFound)
            }
        }

        return HttpClient(engine) {
            install(ContentNegotiation) { json(json) }
        }
    }

    private fun extractRequestBody(request: HttpRequestData): String {
        val body = request.body
        return when (body) {
            is OutgoingContent.ByteArrayContent -> body.bytes().decodeToString()
            else -> ""
        }
    }

    private fun <T> parseBody(request: HttpRequestData, serializer: KSerializer<T>): T? {
        val raw = extractRequestBody(request)
        if (raw.isBlank()) return null
        return runCatching { json.decodeFromString(serializer, raw) }.getOrNull()
    }
}
