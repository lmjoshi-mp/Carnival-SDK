package com.carnival.sdk.data.remote

import com.carnival.sdk.data.remote.dto.ChatMessageDto
import com.carnival.sdk.data.remote.dto.ItineraryPageDto
import com.carnival.sdk.data.remote.dto.LoginRequestDto
import com.carnival.sdk.data.remote.dto.OrderDto
import com.carnival.sdk.data.remote.dto.PreferencesDto
import com.carnival.sdk.data.remote.dto.RemoteSyncChangeDto
import com.carnival.sdk.data.remote.dto.UserSessionDto
import io.ktor.client.HttpClient
import io.ktor.client.call.body
import io.ktor.client.request.bearerAuth
import io.ktor.client.request.get
import io.ktor.client.request.parameter
import io.ktor.client.request.post
import io.ktor.client.request.setBody
import io.ktor.http.ContentType
import io.ktor.http.contentType
import kotlinx.coroutines.delay
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.flow

class CruiseRemoteDataSource(
    private val client: HttpClient,
    private val baseUrl: String,
) : SyncRemoteGateway {
    suspend fun login(email: String, password: String): UserSessionDto =
        client.post("$baseUrl/auth/login") {
            contentType(ContentType.Application.Json)
            setBody(LoginRequestDto(email, password))
        }.body()

    suspend fun fetchPreferences(userId: String, token: String): PreferencesDto =
        client.get("$baseUrl/preferences/$userId") {
            bearerAuth(token)
        }.body()

    suspend fun savePreferences(preferences: PreferencesDto, token: String): PreferencesDto =
        client.post("$baseUrl/preferences") {
            bearerAuth(token)
            contentType(ContentType.Application.Json)
            setBody(preferences)
        }.body()

    suspend fun fetchItinerary(page: Int, pageSize: Int, token: String): ItineraryPageDto =
        client.get("$baseUrl/itinerary") {
            bearerAuth(token)
            parameter("page", page)
            parameter("pageSize", pageSize)
        }.body()

    suspend fun placeOrder(order: OrderDto, token: String): OrderDto =
        client.post("$baseUrl/orders") {
            bearerAuth(token)
            contentType(ContentType.Application.Json)
            setBody(order)
        }.body()

    suspend fun updateOrderStatus(orderId: String, status: String, token: String): OrderDto =
        client.post("$baseUrl/orders/$orderId/status") {
            bearerAuth(token)
            contentType(ContentType.Application.Json)
            setBody(mapOf("status" to status))
        }.body()

    suspend fun sendMessage(message: ChatMessageDto, token: String): ChatMessageDto =
        client.post("$baseUrl/chat/messages") {
            bearerAuth(token)
            contentType(ContentType.Application.Json)
            setBody(message)
        }.body()

    suspend fun fetchMessages(roomId: String, token: String): List<ChatMessageDto> =
        client.get("$baseUrl/chat/messages") {
            bearerAuth(token)
            parameter("roomId", roomId)
        }.body()

    fun pollMessages(roomId: String, token: String, intervalMillis: Long): Flow<List<ChatMessageDto>> = flow {
        while (true) {
            val messages = fetchMessages(roomId, token)
            emit(messages)
            delay(intervalMillis)
        }
    }

    override suspend fun pullRemoteChanges(token: String, sinceEpochMillis: Long): List<RemoteSyncChangeDto> =
        client.get("$baseUrl/sync/changes") {
            bearerAuth(token)
            parameter("since", sinceEpochMillis)
        }.body()

    override suspend fun pushSyncChange(payload: String, token: String) {
        client.post("$baseUrl/sync/push") {
            bearerAuth(token)
            contentType(ContentType.Application.Json)
            setBody(payload)
        }
    }
}
