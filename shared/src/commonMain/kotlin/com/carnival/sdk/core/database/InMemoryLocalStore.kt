package com.carnival.sdk.core.database

import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.ItineraryItem
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.SyncQueueItem
import com.carnival.sdk.domain.model.UserPreferences
import com.carnival.sdk.domain.model.UserSession
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.map
import kotlinx.coroutines.sync.Mutex
import kotlinx.coroutines.sync.withLock

class InMemoryLocalStore : LocalStore {
    private val lock = Mutex()

    private val sessionFlow = MutableStateFlow<UserSession?>(null)
    private val preferencesFlow = MutableStateFlow<Map<String, UserPreferences>>(emptyMap())
    private val itineraryFlow = MutableStateFlow<List<ItineraryItem>>(emptyList())
    private val orderFlow = MutableStateFlow<Map<String, KitchenOrder>>(emptyMap())
    private val messageFlow = MutableStateFlow<Map<String, ChatMessage>>(emptyMap())
    private val syncQueueFlow = MutableStateFlow<List<SyncQueueItem>>(emptyList())

    override suspend fun upsertSession(session: UserSession) {
        lock.withLock { sessionFlow.value = session }
    }

    override suspend fun getSession(): UserSession? = lock.withLock { sessionFlow.value }

    override fun observeSession(): Flow<UserSession?> = sessionFlow

    override suspend fun upsertPreferences(preferences: UserPreferences) {
        lock.withLock {
            preferencesFlow.value = preferencesFlow.value + (preferences.userId to preferences)
        }
    }

    override suspend fun getPreferences(userId: String): UserPreferences? =
        lock.withLock { preferencesFlow.value[userId] }

    override fun observePreferences(userId: String): Flow<UserPreferences?> =
        preferencesFlow.map { it[userId] }

    override suspend fun upsertItinerary(items: List<ItineraryItem>) {
        lock.withLock {
            val merged = (itineraryFlow.value.associateBy { it.id } + items.associateBy { it.id })
                .values
                .sortedBy { it.day }
            itineraryFlow.value = merged
        }
    }

    override suspend fun getItinerary(page: Int, pageSize: Int): List<ItineraryItem> = lock.withLock {
        val start = (page * pageSize).coerceAtLeast(0)
        val all = itineraryFlow.value
        if (start >= all.size) return@withLock emptyList()
        val end = (start + pageSize).coerceAtMost(all.size)
        all.subList(start, end)
    }

    override fun observeItinerary(): Flow<List<ItineraryItem>> = itineraryFlow

    override suspend fun upsertOrder(order: KitchenOrder) {
        lock.withLock {
            orderFlow.value = orderFlow.value + (order.id to order)
        }
    }

    override suspend fun getOrder(orderId: String): KitchenOrder? = lock.withLock { orderFlow.value[orderId] }

    override suspend fun getOrders(userId: String): List<KitchenOrder> = lock.withLock {
        orderFlow.value.values.filter { it.userId == userId }.sortedByDescending { it.updatedAtEpochMillis }
    }

    override fun observeOrders(userId: String): Flow<List<KitchenOrder>> = orderFlow.map { map ->
        map.values.filter { it.userId == userId }.sortedByDescending { it.updatedAtEpochMillis }
    }

    override suspend fun upsertMessage(message: ChatMessage) {
        lock.withLock {
            messageFlow.value = messageFlow.value + (message.id to message)
        }
    }

    override suspend fun upsertMessages(messages: List<ChatMessage>) {
        lock.withLock {
            messageFlow.value = messageFlow.value + messages.associateBy { it.id }
        }
    }

    override suspend fun getMessage(messageId: String): ChatMessage? = lock.withLock {
        messageFlow.value[messageId]
    }

    override suspend fun getMessages(roomId: String): List<ChatMessage> = lock.withLock {
        messageFlow.value.values.filter { it.roomId == roomId }.sortedBy { it.createdAtEpochMillis }
    }

    override fun observeMessages(roomId: String): Flow<List<ChatMessage>> = messageFlow.map { map ->
        map.values.filter { it.roomId == roomId }.sortedBy { it.createdAtEpochMillis }
    }

    override suspend fun enqueueSync(item: SyncQueueItem) {
        lock.withLock { syncQueueFlow.value = syncQueueFlow.value + item }
    }

    override suspend fun updateSyncItem(item: SyncQueueItem) {
        lock.withLock {
            syncQueueFlow.value = syncQueueFlow.value.map { existing ->
                if (existing.id == item.id) item else existing
            }
        }
    }

    override suspend fun removeSyncItem(syncItemId: String) {
        lock.withLock {
            syncQueueFlow.value = syncQueueFlow.value.filterNot { it.id == syncItemId }
        }
    }

    override suspend fun getSyncQueue(limit: Int): List<SyncQueueItem> = lock.withLock {
        syncQueueFlow.value.sortedBy { it.timestampEpochMillis }.take(limit)
    }

    override fun observeSyncQueue(): Flow<List<SyncQueueItem>> = syncQueueFlow
}
