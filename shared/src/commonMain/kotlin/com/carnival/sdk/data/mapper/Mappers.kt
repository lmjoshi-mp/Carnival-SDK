package com.carnival.sdk.data.mapper

import com.carnival.sdk.data.remote.dto.ChatMessageDto
import com.carnival.sdk.data.remote.dto.ItineraryItemDto
import com.carnival.sdk.data.remote.dto.OrderDto
import com.carnival.sdk.data.remote.dto.PreferencesDto
import com.carnival.sdk.data.remote.dto.UserSessionDto
import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.ItineraryItem
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.UserPreferences
import com.carnival.sdk.domain.model.UserSession
import kotlinx.datetime.Instant

fun UserSessionDto.toDomain(): UserSession = UserSession(
    userId = userId,
    email = email,
    token = token,
    refreshToken = refreshToken,
    expiresAtEpochMillis = expiresAtEpochMillis,
    lastLoginAtEpochMillis = lastLoginAtEpochMillis,
)

fun UserSession.toDto(): UserSessionDto = UserSessionDto(
    userId = userId,
    email = email,
    token = token,
    refreshToken = refreshToken,
    expiresAtEpochMillis = expiresAtEpochMillis,
    lastLoginAtEpochMillis = lastLoginAtEpochMillis,
)

fun PreferencesDto.toDomain(): UserPreferences = UserPreferences(
    userId = userId,
    favoriteFoods = favoriteFoods,
    preferredActivities = preferredActivities,
    roomTemperature = roomTemperature,
    updatedAtEpochMillis = updatedAtEpochMillis,
)

fun UserPreferences.toDto(): PreferencesDto = PreferencesDto(
    userId = userId,
    favoriteFoods = favoriteFoods,
    preferredActivities = preferredActivities,
    roomTemperature = roomTemperature,
    updatedAtEpochMillis = updatedAtEpochMillis,
)

fun ItineraryItemDto.toDomain(): ItineraryItem = ItineraryItem(
    id = id,
    day = day,
    title = title,
    description = description,
    startAt = Instant.fromEpochMilliseconds(startAtEpochMillis),
    endAt = Instant.fromEpochMilliseconds(endAtEpochMillis),
    location = location,
    updatedAtEpochMillis = updatedAtEpochMillis,
)

fun ItineraryItem.toDto(): ItineraryItemDto = ItineraryItemDto(
    id = id,
    day = day,
    title = title,
    description = description,
    startAtEpochMillis = startAt.toEpochMilliseconds(),
    endAtEpochMillis = endAt.toEpochMilliseconds(),
    location = location,
    updatedAtEpochMillis = updatedAtEpochMillis,
)

fun OrderDto.toDomain(pendingSync: Boolean = false): KitchenOrder = KitchenOrder(
    id = id,
    userId = userId,
    items = items,
    notes = notes,
    status = OrderStatus.entries.firstOrNull { it.name == status } ?: OrderStatus.QUEUED,
    totalAmount = totalAmount,
    updatedAtEpochMillis = updatedAtEpochMillis,
    pendingSync = pendingSync,
)

fun KitchenOrder.toDto(): OrderDto = OrderDto(
    id = id,
    userId = userId,
    items = items,
    notes = notes,
    status = status.name,
    totalAmount = totalAmount,
    updatedAtEpochMillis = updatedAtEpochMillis,
)

fun ChatMessageDto.toDomain(pendingSync: Boolean = false): ChatMessage = ChatMessage(
    id = id,
    roomId = roomId,
    senderId = senderId,
    senderRole = senderRole,
    content = content,
    createdAtEpochMillis = createdAtEpochMillis,
    pendingSync = pendingSync,
)

fun ChatMessage.toDto(): ChatMessageDto = ChatMessageDto(
    id = id,
    roomId = roomId,
    senderId = senderId,
    senderRole = senderRole,
    content = content,
    createdAtEpochMillis = createdAtEpochMillis,
)
