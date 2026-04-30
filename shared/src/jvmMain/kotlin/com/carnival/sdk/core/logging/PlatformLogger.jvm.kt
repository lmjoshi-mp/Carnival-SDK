package com.carnival.sdk.core.logging

private class JvmLogger(private val tag: String) : PlatformLogger {
    override fun d(message: String) = println("DEBUG [$tag] $message")
    override fun i(message: String) = println("INFO [$tag] $message")
    override fun w(message: String) = println("WARN [$tag] $message")
    override fun e(message: String, throwable: Throwable?) {
        println("ERROR [$tag] $message")
        throwable?.printStackTrace()
    }
}

actual fun createPlatformLogger(tag: String): PlatformLogger = JvmLogger(tag)
