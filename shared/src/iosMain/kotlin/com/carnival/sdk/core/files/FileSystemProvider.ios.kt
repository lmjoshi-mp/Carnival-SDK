package com.carnival.sdk.core.files

import kotlinx.cinterop.ExperimentalForeignApi
import kotlinx.cinterop.BetaInteropApi
import platform.Foundation.NSFileManager
import platform.Foundation.NSString
import platform.Foundation.NSUTF8StringEncoding
import platform.Foundation.NSTemporaryDirectory
import platform.Foundation.create
import platform.Foundation.stringByAppendingPathComponent
import platform.Foundation.writeToFile

@OptIn(ExperimentalForeignApi::class, BetaInteropApi::class)
private class IosFileSystemProvider : FileSystemProvider {
    override fun writeText(path: String, content: String) {
        val filePath = resolvePath(path)
        (content as NSString).writeToFile(
            filePath,
            atomically = true,
            encoding = NSUTF8StringEncoding,
            error = null,
        )
    }

    override fun readText(path: String): String? {
        val filePath = resolvePath(path)
        if (!NSFileManager.defaultManager.fileExistsAtPath(filePath)) return null
        return NSString.create(
            contentsOfFile = filePath,
            encoding = NSUTF8StringEncoding,
            error = null,
        ) as String?
    }

    override fun exists(path: String): Boolean = NSFileManager.defaultManager.fileExistsAtPath(resolvePath(path))

    override fun delete(path: String): Boolean = NSFileManager.defaultManager.removeItemAtPath(resolvePath(path), null)

    private fun resolvePath(path: String): String {
        if (path.startsWith("/")) return path
        return (NSTemporaryDirectory() as NSString).stringByAppendingPathComponent(path)
    }
}

actual fun createFileSystemProvider(): FileSystemProvider = IosFileSystemProvider()
