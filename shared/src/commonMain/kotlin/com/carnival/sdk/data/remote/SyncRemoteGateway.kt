package com.carnival.sdk.data.remote

import com.carnival.sdk.data.remote.dto.RemoteSyncChangeDto

interface SyncRemoteGateway {
    suspend fun pullRemoteChanges(token: String, sinceEpochMillis: Long): List<RemoteSyncChangeDto>
    suspend fun pushSyncChange(payload: String, token: String)
}
