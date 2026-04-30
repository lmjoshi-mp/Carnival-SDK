package com.carnival.sdk.domain.usecase

import com.carnival.sdk.core.util.ResultState
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
import kotlinx.coroutines.flow.Flow

class LoginUseCase(private val repository: AuthRepository) {
    operator fun invoke(email: String, password: String): Flow<ResultState<UserSession>> =
        repository.login(email, password)
}

class GetCachedSessionUseCase(private val repository: AuthRepository) {
    operator fun invoke(): Flow<ResultState<UserSession?>> = repository.getCachedSession()
}

class SavePreferencesUseCase(private val repository: PreferencesRepository) {
    operator fun invoke(preferences: UserPreferences): Flow<ResultState<UserPreferences>> =
        repository.savePreferences(preferences)
}

class FetchPreferencesUseCase(private val repository: PreferencesRepository) {
    operator fun invoke(userId: String): Flow<ResultState<UserPreferences?>> =
        repository.fetchPreferences(userId)
}

class FetchItineraryUseCase(private val repository: ItineraryRepository) {
    operator fun invoke(page: Int, pageSize: Int): Flow<ResultState<List<ItineraryItem>>> =
        repository.fetchItinerary(page, pageSize)
}

class PlaceOrderUseCase(private val repository: OrderRepository) {
    operator fun invoke(order: KitchenOrder): Flow<ResultState<KitchenOrder>> =
        repository.placeOrder(order)
}

class UpdateOrderStatusUseCase(private val repository: OrderRepository) {
    operator fun invoke(orderId: String, status: OrderStatus): Flow<ResultState<KitchenOrder>> =
        repository.updateOrderStatus(orderId, status)
}

class ObserveOrdersUseCase(private val repository: OrderRepository) {
    operator fun invoke(userId: String): Flow<ResultState<List<KitchenOrder>>> =
        repository.observeOrders(userId)
}

class SendMessageUseCase(private val repository: ChatRepository) {
    operator fun invoke(message: ChatMessage): Flow<ResultState<ChatMessage>> =
        repository.sendMessage(message)
}

class ReceiveMessagesUseCase(private val repository: ChatRepository) {
    operator fun invoke(roomId: String): Flow<ResultState<List<ChatMessage>>> =
        repository.receiveMessages(roomId)
}

class TriggerSyncUseCase(private val repository: SyncRepository) {
    operator fun invoke(): Flow<ResultState<Unit>> = repository.triggerSync()
}
