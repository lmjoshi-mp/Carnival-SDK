package com.carnival.sdk.core.files

import java.io.File

private class JvmFileSystemProvider : FileSystemProvider {
    override fun writeText(path: String, content: String) {
        File(path).writeText(content)
    }

    override fun readText(path: String): String? {
        val file = File(path)
        return if (file.exists()) file.readText() else null
    }

    override fun exists(path: String): Boolean = File(path).exists()

    override fun delete(path: String): Boolean = File(path).delete()
}

actual fun createFileSystemProvider(): FileSystemProvider = JvmFileSystemProvider()
