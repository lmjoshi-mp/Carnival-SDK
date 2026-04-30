package com.carnival.sdk.core.util

import kotlinx.serialization.KSerializer
import kotlinx.serialization.json.Json
import kotlinx.datetime.Clock
import kotlin.math.pow

interface TimeProvider {
    fun nowEpochMillis(): Long
}

class SystemTimeProvider : TimeProvider {
    override fun nowEpochMillis(): Long = Clock.System.now().toEpochMilliseconds()
}

interface SecureTokenStore {
    suspend fun saveToken(token: String)
    suspend fun getToken(): String?
    suspend fun clear()
}

class InMemorySecureTokenStore : SecureTokenStore {
    private var token: String? = null

    override suspend fun saveToken(token: String) {
        this.token = token
    }

    override suspend fun getToken(): String? = token

    override suspend fun clear() {
        token = null
    }
}

class JsonCodec(
    private val json: Json = Json {
        ignoreUnknownKeys = true
        encodeDefaults = true
    },
) {
    fun <T> encode(serializer: KSerializer<T>, value: T): String = json.encodeToString(serializer, value)

    fun <T> decode(serializer: KSerializer<T>, raw: String): T = json.decodeFromString(serializer, raw)
}

class ExponentialBackoff(
    private val baseDelayMillis: Long = 1_000,
    private val maxDelayMillis: Long = 60_000,
) {
    fun nextDelayMillis(retryCount: Int): Long {
        val delay = (baseDelayMillis * 2.0.pow(retryCount.toDouble())).toLong()
        return delay.coerceAtMost(maxDelayMillis)
    }
}
