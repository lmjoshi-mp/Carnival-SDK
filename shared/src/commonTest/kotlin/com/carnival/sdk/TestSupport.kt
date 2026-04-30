package com.carnival.sdk

internal class MutableTimeProvider(var now: Long) : com.carnival.sdk.core.util.TimeProvider {
    override fun nowEpochMillis(): Long = now
}
