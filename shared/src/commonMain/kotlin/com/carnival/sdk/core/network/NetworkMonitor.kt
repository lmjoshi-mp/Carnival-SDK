package com.carnival.sdk.core.network

import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow

interface NetworkMonitor {
    val isOnline: StateFlow<Boolean>
}

class MutableNetworkMonitor(initialOnline: Boolean = true) : NetworkMonitor {
    private val _isOnline = MutableStateFlow(initialOnline)
    override val isOnline: StateFlow<Boolean> = _isOnline.asStateFlow()

    fun update(isOnline: Boolean) {
        _isOnline.value = isOnline
    }
}
