package com.carnival.sdk

import com.carnival.sdk.core.network.MutableNetworkMonitor
import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.UserPreferences
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.flow.collectLatest
import kotlinx.coroutines.launch

@Suppress("unused")
fun sampleSdkUsage() {
    val networkMonitor = MutableNetworkMonitor(initialOnline = true)
    CruiseSDK.initialize(
        CruiseSDKConfig(
            baseUrl = "https://api.carnival-cruise.com",
            networkMonitor = networkMonitor,
            enableNetworkLogs = true,
        ),
    )

    val scope = CoroutineScope(Dispatchers.Default)
    scope.launch {
        CruiseSDK.auth.login("guest@ship.com", "securePassword")
            .collectLatest { println("Login state: $it") }
    }

    scope.launch {
        CruiseSDK.preferences.save(
            UserPreferences(
                userId = "guest-1",
                favoriteFoods = listOf("Sushi", "Pasta"),
                preferredActivities = listOf("Diving", "Live Music"),
                roomTemperature = 22,
                updatedAtEpochMillis = 1_713_150_000_000,
            ),
        ).collectLatest { println("Preferences state: $it") }
    }

    scope.launch {
        CruiseSDK.itinerary.get(page = 0, pageSize = 20)
            .collectLatest { println("Itinerary state: $it") }
    }

    scope.launch {
        CruiseSDK.order.place(
            KitchenOrder(
                id = "order-1001",
                userId = "guest-1",
                items = listOf("Burger", "Lime Soda"),
                notes = "No onions",
                status = OrderStatus.QUEUED,
                totalAmount = 24.50,
                updatedAtEpochMillis = 1_713_150_000_000,
                pendingSync = false,
            ),
        ).collectLatest { println("Order state: $it") }
    }

    scope.launch {
        CruiseSDK.chat.send(
            ChatMessage(
                id = "msg-1",
                roomId = "admin-room",
                senderId = "guest-1",
                senderRole = "GUEST",
                content = "Can I reschedule tonight's excursion?",
                createdAtEpochMillis = 1_713_150_000_000,
                pendingSync = false,
            ),
        ).collectLatest { println("Send chat state: $it") }
    }

    scope.launch {
        CruiseSDK.chat.receive("admin-room")
            .collectLatest { println("Chat stream state: $it") }
    }
}
