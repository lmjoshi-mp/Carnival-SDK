package com.carnival.sdk.core.platform

import platform.Foundation.NSBundle
import platform.UIKit.UIDevice

private class IosDeviceInfoProvider : DeviceInfoProvider {
    override fun getDeviceInfo(): DeviceInfo {
        val device = UIDevice.currentDevice
        val appVersion = NSBundle.mainBundle.infoDictionary?.get("CFBundleShortVersionString") as? String ?: "1.0.0"
        return DeviceInfo(
            platform = "iOS",
            osVersion = device.systemVersion ?: "unknown",
            deviceModel = device.model ?: "unknown",
            appVersion = appVersion,
        )
    }
}

actual fun createDeviceInfoProvider(): DeviceInfoProvider = IosDeviceInfoProvider()
