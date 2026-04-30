package com.carnival.sdk

import com.carnival.sdk.core.util.ResultState
import com.carnival.sdk.domain.error.DomainError
import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.ItineraryItem
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.UserPreferences
import com.carnival.sdk.domain.model.UserSession
import com.carnival.sdk.domain.repository.AuthRepository
import com.carnival.sdk.domain.repository.ChatRepository
import com.carnival.sdk.domain.repository.ItineraryRepository
import com.carnival.sdk.domain.repository.OrderRepository
import com.carnival.sdk.domain.repository.PreferencesRepository
import com.carnival.sdk.domain.repository.SyncRepository
import com.carnival.sdk.domain.usecase.FetchItineraryUseCase
import com.carnival.sdk.domain.usecase.FetchPreferencesUseCase
import com.carnival.sdk.domain.usecase.GetCachedSessionUseCase
import com.carnival.sdk.domain.usecase.LoginUseCase
import com.carnival.sdk.domain.usecase.ObserveOrdersUseCase
import com.carnival.sdk.domain.usecase.PlaceOrderUseCase
import com.carnival.sdk.domain.usecase.ReceiveMessagesUseCase
import com.carnival.sdk.domain.usecase.SavePreferencesUseCase
import com.carnival.sdk.domain.usecase.SendMessageUseCase
import com.carnival.sdk.domain.usecase.TriggerSyncUseCase
import com.carnival.sdk.domain.usecase.UpdateOrderStatusUseCase
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.flowOf
import kotlinx.coroutines.flow.toList
import kotlinx.coroutines.test.runTest
import kotlinx.datetime.Instant
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertIs
import kotlin.test.assertTrue

class UseCaseAndApiCoverageTests {
    @Test
    fun useCases_delegateToRepositories() = runTest {
        val session = UserSession("u1", "guest@ship.com", "t1", null, Long.MAX_VALUE, 1)
        val preferences = UserPreferences("u1", listOf("Soup"), listOf("Dance"), 20, 2)
        val itinerary = listOf(ItineraryItem("i1", 1, "Drill", "Safety", Instant.fromEpochMilliseconds(1), Instant.fromEpochMilliseconds(2), "Deck", 1))
        val order = KitchenOrder("o1", "u1", listOf("Burger"), null, OrderStatus.QUEUED, 10.0, 3, false)
        val message = ChatMessage("m1", "room", "u1", "GUEST", "Hello", 4, false)

        val authRepo = object : AuthRepository {
            override fun login(email: String, password: String): Flow<ResultState<UserSession>> = flowOf(ResultState.Success(session))
            override fun getCachedSession(): Flow<ResultState<UserSession?>> = flowOf(ResultState.Success(session))
        }
        val prefRepo = object : PreferencesRepository {
            override fun savePreferences(preferences: UserPreferences): Flow<ResultState<UserPreferences>> = flowOf(ResultState.Success(preferences))
            override fun fetchPreferences(userId: String): Flow<ResultState<UserPreferences?>> = flowOf(ResultState.Success(preferences))
        }
        val itineraryRepo = object : ItineraryRepository {
            override fun fetchItinerary(page: Int, pageSize: Int): Flow<ResultState<List<ItineraryItem>>> = flowOf(ResultState.Success(itinerary))
        }
        val orderRepo = object : OrderRepository {
            override fun placeOrder(order: KitchenOrder): Flow<ResultState<KitchenOrder>> = flowOf(ResultState.Success(order))
            override fun updateOrderStatus(orderId: String, status: OrderStatus): Flow<ResultState<KitchenOrder>> =
                flowOf(ResultState.Success(order.copy(status = status)))
            override fun observeOrders(userId: String): Flow<ResultState<List<KitchenOrder>>> = flowOf(ResultState.Success(listOf(order)))
        }
        val chatRepo = object : ChatRepository {
            override fun sendMessage(message: ChatMessage): Flow<ResultState<ChatMessage>> = flowOf(ResultState.Success(message))
            override fun receiveMessages(roomId: String): Flow<ResultState<List<ChatMessage>>> = flowOf(ResultState.Success(listOf(message)))
        }
        val syncRepo = object : SyncRepository {
            override fun triggerSync(): Flow<ResultState<Unit>> = flowOf(ResultState.Success(Unit))
        }

        assertEquals(session, LoginUseCase(authRepo)("a", "b").toList().single().let { (it as ResultState.Success).data })
        assertEquals(session, GetCachedSessionUseCase(authRepo)().toList().single().let { (it as ResultState.Success).data })
        assertEquals(preferences, SavePreferencesUseCase(prefRepo)(preferences).toList().single().let { (it as ResultState.Success).data })
        assertEquals(preferences, FetchPreferencesUseCase(prefRepo)("u1").toList().single().let { (it as ResultState.Success).data })
        assertEquals(itinerary, FetchItineraryUseCase(itineraryRepo)(0, 1).toList().single().let { (it as ResultState.Success).data })
        assertEquals(order, PlaceOrderUseCase(orderRepo)(order).toList().single().let { (it as ResultState.Success).data })
        assertEquals(OrderStatus.CONFIRMED, UpdateOrderStatusUseCase(orderRepo)("o1", OrderStatus.CONFIRMED).toList().single().let { (it as ResultState.Success).data.status })
        assertEquals(1, ObserveOrdersUseCase(orderRepo)("u1").toList().single().let { (it as ResultState.Success).data.size })
        assertEquals(message, SendMessageUseCase(chatRepo)(message).toList().single().let { (it as ResultState.Success).data })
        assertEquals(1, ReceiveMessagesUseCase(chatRepo)("room").toList().single().let { (it as ResultState.Success).data.size })
        assertTrue(TriggerSyncUseCase(syncRepo)().toList().single() is ResultState.Success)
    }

    @Test
    fun domainErrors_areConstructible() {
        assertIs<DomainError.NetworkError>(DomainError.NetworkError("n"))
        assertIs<DomainError.CacheError>(DomainError.CacheError("c"))
        assertIs<DomainError.SyncError>(DomainError.SyncError("s"))
        assertIs<DomainError.UnauthorizedError>(DomainError.UnauthorizedError())
    }
}
