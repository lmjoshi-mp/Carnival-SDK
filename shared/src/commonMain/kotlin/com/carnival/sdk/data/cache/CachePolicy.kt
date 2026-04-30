package com.carnival.sdk.data.cache

import com.carnival.sdk.core.util.TimeProvider

class CachePolicy(
    private val timeProvider: TimeProvider,
    private val ttlMillis: Long,
) {
    private var lastUpdatedAt: Long = 0L

    fun markUpdated() {
        lastUpdatedAt = timeProvider.nowEpochMillis()
    }

    fun isExpired(): Boolean {
        if (lastUpdatedAt == 0L) return true
        return timeProvider.nowEpochMillis() - lastUpdatedAt > ttlMillis
    }
}
