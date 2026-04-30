package com.carnival.sdk.data.remote.dto

import kotlinx.serialization.Serializable

@Serializable
data class LoginRequestDto(
    val email: String,
    val password: String,
)

@Serializable
data class UserSessionDto(
    val userId: String,
    val email: String,
    val token: String,
    val refreshToken: String? = null,
    val expiresAtEpochMillis: Long,
    val lastLoginAtEpochMillis: Long,
)

@Serializable
data class PreferencesDto(
    val userId: String,
    val favoriteFoods: List<String>,
    val preferredActivities: List<String>,
    val roomTemperature: Int,
    val updatedAtEpochMillis: Long,
)

@Serializable
data class ItineraryPageDto(
    val page: Int,
    val pageSize: Int,
    val items: List<ItineraryItemDto>,
)

@Serializable
data class ItineraryItemDto(
    val id: String,
    val day: Int,
    val title: String,
    val description: String,
    val startAtEpochMillis: Long,
    val endAtEpochMillis: Long,
    val location: String,
    val updatedAtEpochMillis: Long,
)

@Serializable
data class OrderDto(
    val id: String,
    val userId: String,
    val items: List<String>,
    val notes: String? = null,
    val status: String,
    val totalAmount: Double,
    val updatedAtEpochMillis: Long,
)

@Serializable
data class ChatMessageDto(
    val id: String,
    val roomId: String,
    val senderId: String,
    val senderRole: String,
    val content: String,
    val createdAtEpochMillis: Long,
)

@Serializable
data class RemoteSyncChangeDto(
    val entityType: String,
    val entityId: String,
    val operationType: String,
    val payload: String,
    val updatedAtEpochMillis: Long,
)
