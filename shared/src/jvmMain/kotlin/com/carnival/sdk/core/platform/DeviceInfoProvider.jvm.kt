package com.carnival.sdk.core.platform

private class JvmDeviceInfoProvider : DeviceInfoProvider {
    override fun getDeviceInfo(): DeviceInfo = DeviceInfo(
        platform = "JVM",
        osVersion = System.getProperty("os.version") ?: "unknown",
        deviceModel = System.getProperty("os.name") ?: "unknown",
        appVersion = "1.0.0",
    )
}

actual fun createDeviceInfoProvider(): DeviceInfoProvider = JvmDeviceInfoProvider()
