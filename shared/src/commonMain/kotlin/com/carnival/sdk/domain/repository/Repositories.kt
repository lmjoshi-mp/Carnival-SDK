package com.carnival.sdk.domain.repository

import com.carnival.sdk.core.util.ResultState
import com.carnival.sdk.domain.model.ChatMessage
import com.carnival.sdk.domain.model.ItineraryItem
import com.carnival.sdk.domain.model.KitchenOrder
import com.carnival.sdk.domain.model.OrderStatus
import com.carnival.sdk.domain.model.UserPreferences
import com.carnival.sdk.domain.model.UserSession
import kotlinx.coroutines.flow.Flow

interface AuthRepository {
    fun login(email: String, password: String): Flow<ResultState<UserSession>>
    fun getCachedSession(): Flow<ResultState<UserSession?>>
}

interface PreferencesRepository {
    fun savePreferences(preferences: UserPreferences): Flow<ResultState<UserPreferences>>
    fun fetchPreferences(userId: String): Flow<ResultState<UserPreferences?>>
}

interface ItineraryRepository {
    fun fetchItinerary(page: Int, pageSize: Int): Flow<ResultState<List<ItineraryItem>>>
}

interface OrderRepository {
    fun placeOrder(order: KitchenOrder): Flow<ResultState<KitchenOrder>>
    fun updateOrderStatus(orderId: String, status: OrderStatus): Flow<ResultState<KitchenOrder>>
    fun observeOrders(userId: String): Flow<ResultState<List<KitchenOrder>>>
}

interface ChatRepository {
    fun sendMessage(message: ChatMessage): Flow<ResultState<ChatMessage>>
    fun receiveMessages(roomId: String): Flow<ResultState<List<ChatMessage>>>
}

interface SyncRepository {
    fun triggerSync(): Flow<ResultState<Unit>>
}
