package com.carnival.consumer.app

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.input.PasswordVisualTransformation
import androidx.compose.ui.unit.dp
import androidx.lifecycle.lifecycleScope
import com.carnival.sdk.CruiseSDK
import com.carnival.sdk.CruiseSDKConfig
import com.carnival.sdk.core.network.MutableNetworkMonitor
import com.carnival.sdk.core.util.ResultState
import com.carnival.sdk.data.remote.dto.ItineraryItemDto
import com.carnival.sdk.data.remote.dto.ItineraryPageDto
import com.carnival.sdk.data.remote.dto.RemoteSyncChangeDto
import com.carnival.sdk.data.remote.dto.UserSessionDto
import com.carnival.sdk.domain.model.ItineraryItem
import io.ktor.client.HttpClient
import io.ktor.client.engine.mock.MockEngine
import io.ktor.client.engine.mock.respond
import io.ktor.client.plugins.contentnegotiation.ContentNegotiation
import io.ktor.http.ContentType
import io.ktor.http.HttpHeaders
import io.ktor.http.HttpMethod
import io.ktor.http.HttpStatusCode
import io.ktor.http.headersOf
import io.ktor.serialization.kotlinx.json.json
import kotlinx.coroutines.flow.first
import kotlinx.coroutines.launch
import kotlinx.datetime.Clock
import kotlinx.serialization.encodeToString
import kotlinx.serialization.json.Json

class MainActivity : ComponentActivity() {
    private val networkMonitor = MutableNetworkMonitor(initialOnline = true)
    private var currentScreen by mutableStateOf(Screen.Login)
    private var loginEmail by mutableStateOf("guest@ship.com")
    private var loginPassword by mutableStateOf("secret")
    private var loading by mutableStateOf(false)
    private var message by mutableStateOf("Please login to continue.")
    private var userName by mutableStateOf("")
    private var itinerary by mutableStateOf<List<ItineraryItem>>(emptyList())
    private var dashboardStats by mutableStateOf<List<DashboardStat>>(emptyList())
    private var notifications by mutableStateOf<List<String>>(emptyList())
    private var activities by mutableStateOf<List<String>>(emptyList())

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        CruiseSDK.initialize(
            CruiseSDKConfig(
                baseUrl = "https://mock.carnival",
                networkMonitor = networkMonitor,
                httpClient = ConsumerMockBackend().createHttpClient(),
            ),
        )

        setContent {
            MaterialTheme {
                Surface(modifier = Modifier.fillMaxSize()) {
                    when (currentScreen) {
                        Screen.Login -> LoginScreen(
                            email = loginEmail,
                            password = loginPassword,
                            loading = loading,
                            message = message,
                            onEmailChange = { loginEmail = it },
                            onPasswordChange = { loginPassword = it },
                            onLoginClick = { login() },
                        )
                        Screen.Dashboard -> DashboardScreen(
                            userName = userName,
                            loading = loading,
                            message = message,
                            itinerary = itinerary,
                            stats = dashboardStats,
                            notifications = notifications,
                            activities = activities,
                            onRefresh = { loadDashboard() },
                            onLogout = { logout() },
                        )
                    }
                }
            }
        }
    }

    override fun onDestroy() {
        CruiseSDK.shutdown()
        super.onDestroy()
    }

    private fun login() {
        lifecycleScope.launch {
            loading = true
            message = "Logging in..."
            val result = CruiseSDK.auth.login(loginEmail, loginPassword).first { it !is ResultState.Loading }
            when (result) {
                is ResultState.Success -> {
                    userName = result.data.email
                    currentScreen = Screen.Dashboard
                    message = "Login successful"
                    loadDashboard()
                }
                is ResultState.Error -> {
                    message = "Login failed: ${result.error.message}"
                    loading = false
                }
                ResultState.Loading -> Unit
            }
        }
    }

    private fun loadDashboard() {
        lifecycleScope.launch {
            loading = true
            message = "Loading dashboard..."
            val result = CruiseSDK.itinerary.get(page = 0, pageSize = 5).first { it !is ResultState.Loading }
            when (result) {
                is ResultState.Success -> {
                    itinerary = result.data
                    dashboardStats = buildDummyStats(result.data.size)
                    notifications = buildDummyNotifications()
                    activities = buildDummyActivities()
                    message = "Dashboard ready"
                }
                is ResultState.Error -> {
                    message = "Could not load itinerary: ${result.error.message}"
                }
                ResultState.Loading -> Unit
            }
            loading = false
        }
    }

    private fun logout() {
        currentScreen = Screen.Login
        itinerary = emptyList()
        dashboardStats = emptyList()
        notifications = emptyList()
        activities = emptyList()
        message = "Logged out"
    }

    private fun buildDummyStats(itineraryCount: Int): List<DashboardStat> = listOf(
        DashboardStat("Loyalty Tier", "Gold"),
        DashboardStat("Reward Points", "12,480"),
        DashboardStat("Upcoming Events", itineraryCount.toString()),
        DashboardStat("Onboard Wallet", "$245.30"),
    )

    private fun buildDummyNotifications(): List<String> = listOf(
        "Special dinner offer available at Ocean Grill tonight.",
        "Excursion check-in opens in 2 hours.",
        "Spa slot confirmed for tomorrow 10:30 AM.",
    )

    private fun buildDummyActivities(): List<String> = listOf(
        "Room service order delivered - 6:40 PM",
        "Shore excursion booked - Coral Island Tour",
        "Welcome package redeemed from loyalty wallet",
    )
}

private enum class Screen {
    Login,
    Dashboard,
}

private data class DashboardStat(
    val label: String,
    val value: String,
)

@Composable
private fun LoginScreen(
    email: String,
    password: String,
    loading: Boolean,
    message: String,
    onEmailChange: (String) -> Unit,
    onPasswordChange: (String) -> Unit,
    onLoginClick: () -> Unit,
) {
    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(24.dp),
        verticalArrangement = Arrangement.Center,
    ) {
        Text("Carnival Consumer App", style = MaterialTheme.typography.headlineSmall)
        Spacer(modifier = Modifier.height(8.dp))
        Text("Login", style = MaterialTheme.typography.titleMedium)
        Spacer(modifier = Modifier.height(12.dp))
        OutlinedTextField(
            value = email,
            onValueChange = onEmailChange,
            label = { Text("Email") },
            modifier = Modifier.fillMaxWidth(),
            singleLine = true,
        )
        Spacer(modifier = Modifier.height(8.dp))
        OutlinedTextField(
            value = password,
            onValueChange = onPasswordChange,
            label = { Text("Password") },
            modifier = Modifier.fillMaxWidth(),
            visualTransformation = PasswordVisualTransformation(),
            singleLine = true,
        )
        Spacer(modifier = Modifier.height(16.dp))
        Button(
            onClick = onLoginClick,
            enabled = !loading,
            modifier = Modifier.fillMaxWidth(),
        ) {
            Text(if (loading) "Please wait..." else "Sign In")
        }
        Spacer(modifier = Modifier.height(12.dp))
        Text(message, style = MaterialTheme.typography.bodyMedium)
    }
}

@Composable
private fun DashboardScreen(
    userName: String,
    loading: Boolean,
    message: String,
    itinerary: List<ItineraryItem>,
    stats: List<DashboardStat>,
    notifications: List<String>,
    activities: List<String>,
    onRefresh: () -> Unit,
    onLogout: () -> Unit,
) {
    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        verticalArrangement = Arrangement.spacedBy(10.dp),
    ) {
        Text("Dashboard", style = MaterialTheme.typography.headlineSmall)
        Text("Welcome, $userName", style = MaterialTheme.typography.titleMedium)
        Row(horizontalArrangement = Arrangement.spacedBy(8.dp)) {
            Button(onClick = onRefresh, enabled = !loading) { Text("Refresh") }
            Button(onClick = onLogout, enabled = !loading) { Text("Logout") }
        }
        Text(message, style = MaterialTheme.typography.bodyMedium)
        Text("Quick Stats", style = MaterialTheme.typography.titleMedium)
        LazyColumn(
            modifier = Modifier.height(180.dp),
            verticalArrangement = Arrangement.spacedBy(8.dp),
        ) {
            items(stats) { stat ->
                Card(modifier = Modifier.fillMaxWidth()) {
                    Row(
                        modifier = Modifier
                            .fillMaxWidth()
                            .padding(12.dp),
                        horizontalArrangement = Arrangement.SpaceBetween,
                    ) {
                        Text(stat.label, style = MaterialTheme.typography.bodyMedium)
                        Spacer(modifier = Modifier.width(12.dp))
                        Text(stat.value, style = MaterialTheme.typography.titleSmall)
                    }
                }
            }
        }
        Text("Notifications", style = MaterialTheme.typography.titleMedium)
        LazyColumn(
            modifier = Modifier.height(120.dp),
            verticalArrangement = Arrangement.spacedBy(6.dp),
        ) {
            items(notifications) { note ->
                Card(modifier = Modifier.fillMaxWidth()) {
                    Text(note, modifier = Modifier.padding(12.dp), style = MaterialTheme.typography.bodySmall)
                }
            }
        }
        Text("Recent Activity", style = MaterialTheme.typography.titleMedium)
        LazyColumn(
            modifier = Modifier.height(120.dp),
            verticalArrangement = Arrangement.spacedBy(6.dp),
        ) {
            items(activities) { line ->
                Card(modifier = Modifier.fillMaxWidth()) {
                    Text(line, modifier = Modifier.padding(12.dp), style = MaterialTheme.typography.bodySmall)
                }
            }
        }
        Text("Upcoming Itinerary", style = MaterialTheme.typography.titleMedium)
        LazyColumn(verticalArrangement = Arrangement.spacedBy(8.dp)) {
            items(itinerary) { item ->
                Card(modifier = Modifier.fillMaxWidth()) {
                    Column(modifier = Modifier.padding(12.dp)) {
                        Text(item.title, style = MaterialTheme.typography.titleSmall)
                        Spacer(modifier = Modifier.height(2.dp))
                        Text(item.description, style = MaterialTheme.typography.bodySmall)
                        Spacer(modifier = Modifier.height(2.dp))
                        Text("Location: ${item.location}", style = MaterialTheme.typography.bodySmall)
                    }
                }
            }
        }
    }
}

private class ConsumerMockBackend {
    private val json = Json { ignoreUnknownKeys = true; encodeDefaults = true }
    private val now = Clock.System.now().toEpochMilliseconds()
    private val remoteChanges = mutableListOf<RemoteSyncChangeDto>()
    private val itinerary = listOf(
        ItineraryItemDto("it-1", 1, "Safety Drill", "Mandatory onboard safety drill.", now + 60000, now + 120000, "Deck 1", now),
        ItineraryItemDto("it-2", 1, "Captain's Welcome", "Meet and greet with the captain.", now + 200000, now + 260000, "Main Atrium", now),
        ItineraryItemDto("it-3", 2, "Island Excursion", "Half-day guided island tour.", now + 600000, now + 900000, "Port Exit", now),
    )

    fun createHttpClient(): HttpClient {
        val engine = MockEngine { request ->
            fun okJson(body: String) = respond(
                content = body,
                status = HttpStatusCode.OK,
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
                                expiresAtEpochMillis = now + 3600000,
                                lastLoginAtEpochMillis = now,
                            ),
                        ),
                    )

                request.url.encodedPath == "/itinerary" && request.method == HttpMethod.Get ->
                    okJson(
                        json.encodeToString(
                            ItineraryPageDto.serializer(),
                            ItineraryPageDto(page = 0, pageSize = itinerary.size, items = itinerary),
                        ),
                    )

                request.url.encodedPath == "/sync/changes" && request.method == HttpMethod.Get ->
                    okJson(
                        json.encodeToString(
                            kotlinx.serialization.builtins.ListSerializer(RemoteSyncChangeDto.serializer()),
                            remoteChanges,
                        ),
                    )

                request.url.encodedPath == "/sync/push" && request.method == HttpMethod.Post ->
                    okJson("{}")

                else ->
                    respond(
                        content = """{"message":"No route for ${request.method.value} ${request.url.encodedPath}"}""",
                        status = HttpStatusCode.NotFound,
                        headers = headersOf(HttpHeaders.ContentType, ContentType.Application.Json.toString()),
                    )
            }
        }
        return HttpClient(engine) {
            install(ContentNegotiation) { json(json) }
        }
    }

}
