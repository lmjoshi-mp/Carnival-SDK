package com.carnival.sdk.domain.model

import kotlinx.datetime.Clock
import kotlinx.datetime.Instant

data class UserSession(
    val userId: String,
    val email: String,
    val token: String,
    val refreshToken: String?,
    val expiresAtEpochMillis: Long,
    val lastLoginAtEpochMillis: Long = Clock.System.now().toEpochMilliseconds(),
) {
    val isExpired: Boolean
        get() = Clock.System.now().toEpochMilliseconds() >= expiresAtEpochMillis
}

data class UserPreferences(
    val userId: String,
    val favoriteFoods: List<String>,
    val preferredActivities: List<String>,
    val roomTemperature: Int,
    val updatedAtEpochMillis: Long,
)

data class ItineraryItem(
    val id: String,
    val day: Int,
    val title: String,
    val description: String,
    val startAt: Instant,
    val endAt: Instant,
    val location: String,
    val updatedAtEpochMillis: Long,
)

enum class OrderStatus {
    QUEUED,
    CONFIRMED,
    PREPARING,
    READY,
    DELIVERED,
    CANCELLED,
}

data class KitchenOrder(
    val id: String,
    val userId: String,
    val items: List<String>,
    val notes: String?,
    val status: OrderStatus,
    val totalAmount: Double,
    val updatedAtEpochMillis: Long,
    val pendingSync: Boolean,
)

data class ChatMessage(
    val id: String,
    val roomId: String,
    val senderId: String,
    val senderRole: String,
    val content: String,
    val createdAtEpochMillis: Long,
    val pendingSync: Boolean,
)

enum class SyncOperationType {
    CREATE,
    UPDATE,
    DELETE,
}

data class SyncQueueItem(
    val id: String,
    val entityType: String,
    val entityId: String,
    val operationType: SyncOperationType,
    val payload: String,
    val timestampEpochMillis: Long,
    val retryCount: Int,
    val nextRetryEpochMillis: Long,
)
