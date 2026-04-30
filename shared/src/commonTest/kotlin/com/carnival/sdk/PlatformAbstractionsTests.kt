package com.carnival.sdk

import com.carnival.sdk.core.files.createFileSystemProvider
import com.carnival.sdk.core.logging.createPlatformLogger
import com.carnival.sdk.core.network.createPlatformNetworkMonitor
import com.carnival.sdk.core.platform.createDeviceInfoProvider
import com.carnival.sdk.core.util.createSecureTokenStore
import kotlinx.coroutines.test.runTest
import kotlin.random.Random
import kotlin.test.Test
import kotlin.test.assertFalse
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

class PlatformAbstractionsTests {
    @Test
    fun deviceInfoProvider_returnsValues() {
        val info = createDeviceInfoProvider().getDeviceInfo()
        assertTrue(info.platform.isNotBlank())
        assertTrue(info.osVersion.isNotBlank())
        assertTrue(info.deviceModel.isNotBlank())
        assertTrue(info.appVersion.isNotBlank())
    }

    @Test
    fun platformLogger_acceptsAllLevels() {
        val logger = createPlatformLogger("PlatformAbstractionsTests")
        logger.d("debug")
        logger.i("info")
        logger.w("warn")
        logger.e("error", null)
    }

    @Test
    fun fileSystemProvider_readsWritesAndDeletes() {
        val fs = createFileSystemProvider()
        val file = "kmm-test-${Random.nextInt(1, Int.MAX_VALUE)}.txt"
        fs.writeText(file, "hello")
        assertTrue(fs.exists(file))
        assertNotNull(fs.readText(file))
        assertTrue(fs.delete(file))
        assertFalse(fs.exists(file))
    }

    @Test
    fun secureTokenStoreFactory_returnsWorkingStore() = runTest {
        val store = createSecureTokenStore()
        store.saveToken("abc")
        assertTrue(store.getToken() == "abc")
        store.clear()
        assertTrue(store.getToken() == null)
    }

    @Test
    fun platformNetworkMonitor_hasState() {
        val monitor = createPlatformNetworkMonitor()
        assertNotNull(monitor.isOnline.value)
    }
}
