package com.carnival.sdk.core.network

actual fun createPlatformNetworkMonitor(): NetworkMonitor = MutableNetworkMonitor(initialOnline = true)
