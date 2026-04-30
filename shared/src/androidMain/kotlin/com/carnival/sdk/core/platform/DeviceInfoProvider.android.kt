package com.carnival.sdk.core.platform

import android.os.Build

private class AndroidDeviceInfoProvider : DeviceInfoProvider {
    override fun getDeviceInfo(): DeviceInfo = DeviceInfo(
        platform = "Android",
        osVersion = Build.VERSION.RELEASE ?: "unknown",
        deviceModel = Build.MODEL ?: "unknown",
        appVersion = "1.0.0",
    )
}

actual fun createDeviceInfoProvider(): DeviceInfoProvider = AndroidDeviceInfoProvider()
