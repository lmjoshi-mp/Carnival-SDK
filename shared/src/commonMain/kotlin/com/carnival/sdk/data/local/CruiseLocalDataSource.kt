package com.carnival.sdk.data.local

import com.carnival.sdk.core.database.LocalStore
import com.carnival.sdk.core.util.TimeProvider
import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.ItineraryItem
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.SyncOperationType
import com.carnival.sdk.domain.model.SyncQueueItem
import com.carnival.sdk.domain.model.UserPreferences
import com.carnival.sdk.domain.model.UserSession
import kotlinx.coroutines.flow.Flow
import kotlin.random.Random

class CruiseLocalDataSource(
    private val localStore: LocalStore,
    private val timeProvider: TimeProvider,
) {
    suspend fun saveSession(session: UserSession) = localStore.upsertSession(session)
    suspend fun getSession(): UserSession? = localStore.getSession()
    fun observeSession(): Flow<UserSession?> = localStore.observeSession()

    suspend fun savePreferences(preferences: UserPreferences) = localStore.upsertPreferences(preferences)
    suspend fun getPreferences(userId: String): UserPreferences? = localStore.getPreferences(userId)
    fun observePreferences(userId: String): Flow<UserPreferences?> = localStore.observePreferences(userId)

    suspend fun saveItinerary(items: List<ItineraryItem>) = localStore.upsertItinerary(items)
    suspend fun getItinerary(page: Int, pageSize: Int): List<ItineraryItem> = localStore.getItinerary(page, pageSize)
    fun observeItinerary(): Flow<List<ItineraryItem>> = localStore.observeItinerary()

    suspend fun saveOrder(order: KitchenOrder) = localStore.upsertOrder(order)
    suspend fun getOrder(orderId: String): KitchenOrder? = localStore.getOrder(orderId)
    suspend fun getOrders(userId: String): List<KitchenOrder> = localStore.getOrders(userId)
    fun observeOrders(userId: String): Flow<List<KitchenOrder>> = localStore.observeOrders(userId)

    suspend fun saveMessage(message: ChatMessage) = localStore.upsertMessage(message)
    suspend fun saveMessages(messages: List<ChatMessage>) = localStore.upsertMessages(messages)
    suspend fun getMessage(messageId: String): ChatMessage? = localStore.getMessage(messageId)
    suspend fun getMessages(roomId: String): List<ChatMessage> = localStore.getMessages(roomId)
    fun observeMessages(roomId: String): Flow<List<ChatMessage>> = localStore.observeMessages(roomId)

    suspend fun enqueueSync(
        entityType: String,
        entityId: String,
        operationType: SyncOperationType,
        payload: String,
    ) {
        val now = timeProvider.nowEpochMillis()
        localStore.enqueueSync(
            SyncQueueItem(
                id = buildSyncId(),
                entityType = entityType,
                entityId = entityId,
                operationType = operationType,
                payload = payload,
                timestampEpochMillis = now,
                retryCount = 0,
                nextRetryEpochMillis = now,
            ),
        )
    }

    suspend fun getSyncQueue(limit: Int = 50): List<SyncQueueItem> = localStore.getSyncQueue(limit)
    suspend fun updateSyncItem(item: SyncQueueItem) = localStore.updateSyncItem(item)
    suspend fun removeSyncItem(syncItemId: String) = localStore.removeSyncItem(syncItemId)
    fun observeSyncQueue(): Flow<List<SyncQueueItem>> = localStore.observeSyncQueue()

    suspend fun markOrderPending(orderId: String, pendingSync: Boolean) {
        val existing = getOrder(orderId) ?: return
        saveOrder(existing.copy(pendingSync = pendingSync, updatedAtEpochMillis = timeProvider.nowEpochMillis()))
    }

    suspend fun updateOrderStatus(orderId: String, status: OrderStatus, pendingSync: Boolean) {
        val existing = getOrder(orderId) ?: return
        saveOrder(
            existing.copy(
                status = status,
                pendingSync = pendingSync,
                updatedAtEpochMillis = timeProvider.nowEpochMillis(),
            ),
        )
    }

    private fun buildSyncId(): String = "${timeProvider.nowEpochMillis()}-${Random.nextInt(1, Int.MAX_VALUE)}"
}
