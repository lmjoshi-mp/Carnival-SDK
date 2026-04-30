package com.carnival.sdk.core.files

interface FileSystemProvider {
    fun writeText(path: String, content: String)
    fun readText(path: String): String?
    fun exists(path: String): Boolean
    fun delete(path: String): Boolean
}

expect fun createFileSystemProvider(): FileSystemProvider
