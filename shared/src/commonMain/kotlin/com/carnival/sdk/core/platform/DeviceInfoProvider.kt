package com.carnival.sdk.core.platform

data class DeviceInfo(
    val platform: String,
    val osVersion: String,
    val deviceModel: String,
    val appVersion: String,
)

interface DeviceInfoProvider {
    fun getDeviceInfo(): DeviceInfo
}

expect fun createDeviceInfoProvider(): DeviceInfoProvider
