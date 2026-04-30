package com.carnival.sdk.core.logging

interface PlatformLogger {
    fun d(message: String)
    fun i(message: String)
    fun w(message: String)
    fun e(message: String, throwable: Throwable? = null)
}

expect fun createPlatformLogger(tag: String): PlatformLogger
