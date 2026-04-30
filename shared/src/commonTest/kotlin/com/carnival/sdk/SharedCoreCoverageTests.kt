package com.carnival.sdk

import com.carnival.sdk.core.database.InMemoryLocalStore
import com.carnival.sdk.core.network.MutableNetworkMonitor
import com.carnival.sdk.core.util.ExponentialBackoff
import com.carnival.sdk.core.util.InMemorySecureTokenStore
import com.carnival.sdk.core.util.JsonCodec
import com.carnival.sdk.data.cache.CachePolicy
import com.carnival.sdk.data.local.CruiseLocalDataSource
import com.carnival.sdk.data.remote.dto.PreferencesDto
import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.ItineraryItem
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.SyncOperationType
import com.carnival.sdk.domain.model.UserPreferences
import com.carnival.sdk.domain.model.UserSession
import kotlinx.coroutines.flow.first
import kotlinx.coroutines.test.runTest
import kotlinx.datetime.Instant
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertFalse
import kotlin.test.assertNotNull
import kotlin.test.assertNull
import kotlin.test.assertTrue

class SharedCoreCoverageTests {
    @Test
    fun secureTokenStore_saveGetAndClear() = runTest {
        val store = InMemorySecureTokenStore()
        assertNull(store.getToken())
        store.saveToken("abc")
        assertEquals("abc", store.getToken())
        store.clear()
        assertNull(store.getToken())
    }

    @Test
    fun jsonCodec_roundTripsPayload() {
        val codec = JsonCodec()
        val dto = PreferencesDto("u1", listOf("Pasta"), listOf("Dance"), 22, 100)
        val encoded = codec.encode(PreferencesDto.serializer(), dto)
        val decoded = codec.decode(PreferencesDto.serializer(), encoded)
        assertEquals(dto, decoded)
    }

    @Test
    fun exponentialBackoff_capsAtMaximum() {
        val backoff = ExponentialBackoff(baseDelayMillis = 100, maxDelayMillis = 500)
        assertEquals(100, backoff.nextDelayMillis(0))
        assertEquals(200, backoff.nextDelayMillis(1))
        assertEquals(400, backoff.nextDelayMillis(2))
        assertEquals(500, backoff.nextDelayMillis(5))
    }

    @Test
    fun cachePolicy_expiresAfterTtl() {
        val time = MutableTimeProvider(100)
        val policy = CachePolicy(time, ttlMillis = 50)
        assertTrue(policy.isExpired())
        policy.markUpdated()
        assertFalse(policy.isExpired())
        time.now = 151
        assertTrue(policy.isExpired())
    }

    @Test
    fun networkMonitor_updatesState() {
        val monitor = MutableNetworkMonitor(initialOnline = false)
        assertFalse(monitor.isOnline.value)
        monitor.update(true)
        assertTrue(monitor.isOnline.value)
    }

    @Test
    fun inMemoryLocalStore_supportsCrudAndObservation() = runTest {
        val store = InMemoryLocalStore()
        val session = UserSession("u1", "a@b.com", "t1", null, Long.MAX_VALUE, 10)
        val preferences = UserPreferences("u1", listOf("Soup"), listOf("Swim"), 21, 11)
        val itinerary = listOf(
            ItineraryItem("i2", 2, "Dinner", "Desc", Instant.fromEpochMilliseconds(2), Instant.fromEpochMilliseconds(3), "Hall", 3),
            ItineraryItem("i1", 1, "Drill", "Desc", Instant.fromEpochMilliseconds(1), Instant.fromEpochMilliseconds(2), "Deck", 2),
        )
        val order = KitchenOrder("o1", "u1", listOf("Burger"), null, OrderStatus.QUEUED, 10.0, 12, true)
        val message = ChatMessage("m1", "room", "u1", "GUEST", "Hello", 13, true)

        store.upsertSession(session)
        store.upsertPreferences(preferences)
        store.upsertItinerary(itinerary)
        store.upsertOrder(order)
        store.upsertMessage(message)

        assertEquals(session, store.observeSession().first())
        assertEquals(preferences, store.observePreferences("u1").first())
        assertEquals(listOf("i1"), store.getItinerary(0, 1).map { it.id })
        assertEquals(order, store.getOrder("o1"))
        assertEquals(listOf(order), store.observeOrders("u1").first())
        assertEquals(message, store.getMessage("m1"))
        assertEquals(listOf(message), store.observeMessages("room").first())

        val syncItem = sampleSyncQueueItem()
        store.enqueueSync(syncItem)
        assertEquals(syncItem.id, store.observeSyncQueue().first().single().id)
        store.updateSyncItem(syncItem.copy(retryCount = 2))
        assertEquals(2, store.getSyncQueue().single().retryCount)
        store.removeSyncItem(syncItem.id)
        assertTrue(store.getSyncQueue().isEmpty())
    }

    @Test
    fun localDataSource_updatesOrderAndSyncQueue() = runTest {
        val time = MutableTimeProvider(1000)
        val dataSource = CruiseLocalDataSource(InMemoryLocalStore(), time)
        val order = KitchenOrder("o1", "u1", listOf("Burger"), null, OrderStatus.QUEUED, 15.0, 1000, true)
        val message = ChatMessage("m1", "room", "u1", "GUEST", "Hi", 1000, true)

        dataSource.saveOrder(order)
        dataSource.markOrderPending("o1", pendingSync = false)
        assertFalse(dataSource.getOrder("o1")!!.pendingSync)

        time.now = 1100
        dataSource.updateOrderStatus("o1", OrderStatus.CONFIRMED, pendingSync = true)
        assertEquals(OrderStatus.CONFIRMED, dataSource.getOrder("o1")!!.status)

        dataSource.saveMessage(message)
        assertNotNull(dataSource.getMessage("m1"))

        dataSource.enqueueSync("order", "o1", SyncOperationType.UPDATE, "{}")
        val queued = dataSource.getSyncQueue().single()
        assertEquals("order", queued.entityType)
        assertEquals(0, queued.retryCount)
    }
}

private fun sampleSyncQueueItem() = com.carnival.sdk.domain.model.SyncQueueItem(
    id = "s1",
    entityType = "order",
    entityId = "o1",
    operationType = SyncOperationType.CREATE,
    payload = "{}",
    timestampEpochMillis = 1,
    retryCount = 0,
    nextRetryEpochMillis = 1,
)

