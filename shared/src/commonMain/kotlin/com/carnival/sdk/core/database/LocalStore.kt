package com.carnival.sdk.core.database

import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.ItineraryItem
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.SyncQueueItem
import com.carnival.sdk.domain.model.UserPreferences
import com.carnival.sdk.domain.model.UserSession
import kotlinx.coroutines.flow.Flow

interface LocalStore {
    suspend fun upsertSession(session: UserSession)
    suspend fun getSession(): UserSession?
    fun observeSession(): Flow<UserSession?>

    suspend fun upsertPreferences(preferences: UserPreferences)
    suspend fun getPreferences(userId: String): UserPreferences?
    fun observePreferences(userId: String): Flow<UserPreferences?>

    suspend fun upsertItinerary(items: List<ItineraryItem>)
    suspend fun getItinerary(page: Int, pageSize: Int): List<ItineraryItem>
    fun observeItinerary(): Flow<List<ItineraryItem>>

    suspend fun upsertOrder(order: KitchenOrder)
    suspend fun getOrder(orderId: String): KitchenOrder?
    suspend fun getOrders(userId: String): List<KitchenOrder>
    fun observeOrders(userId: String): Flow<List<KitchenOrder>>

    suspend fun upsertMessage(message: ChatMessage)
    suspend fun upsertMessages(messages: List<ChatMessage>)
    suspend fun getMessage(messageId: String): ChatMessage?
    suspend fun getMessages(roomId: String): List<ChatMessage>
    fun observeMessages(roomId: String): Flow<List<ChatMessage>>

    suspend fun enqueueSync(item: SyncQueueItem)
    suspend fun updateSyncItem(item: SyncQueueItem)
    suspend fun removeSyncItem(syncItemId: String)
    suspend fun getSyncQueue(limit: Int = 50): List<SyncQueueItem>
    fun observeSyncQueue(): Flow<List<SyncQueueItem>>
}
