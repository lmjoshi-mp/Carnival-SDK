package com.carnival.sdk.core.logging

import android.util.Log

private class AndroidLogger(private val tag: String) : PlatformLogger {
    override fun d(message: String) {
        runCatching { Log.d(tag, message) }
            .onFailure { println("DEBUG [$tag] $message") }
    }

    override fun i(message: String) {
        runCatching { Log.i(tag, message) }
            .onFailure { println("INFO [$tag] $message") }
    }

    override fun w(message: String) {
        runCatching { Log.w(tag, message) }
            .onFailure { println("WARN [$tag] $message") }
    }

    override fun e(message: String, throwable: Throwable?) {
        runCatching { Log.e(tag, message, throwable) }
            .onFailure {
                println("ERROR [$tag] $message")
                throwable?.printStackTrace()
            }
    }
}

actual fun createPlatformLogger(tag: String): PlatformLogger = AndroidLogger(tag)
