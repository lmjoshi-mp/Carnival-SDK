package com.carnival.sdk.core.util

actual fun createSecureTokenStore(): SecureTokenStore = InMemorySecureTokenStore()
