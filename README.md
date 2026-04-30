# Carnival Cruise SDK (KMM)

Production-oriented Kotlin Multiplatform SDK with strict Clean Architecture and an offline-first sync model.

## Folder Structure

```text
shared/
 ├── src/commonMain/kotlin/com/carnival/sdk/
 │    ├── domain/
 │    │    ├── model/
 │    │    ├── repository/
 │    │    ├── usecase/
 │    │    └── error/
 │    ├── data/
 │    │    ├── repository/
 │    │    ├── remote/
 │    │    ├── local/
 │    │    ├── mapper/
 │    │    ├── sync/
 │    │    └── cache/
 │    └── core/
 │         ├── network/
 │         ├── database/
 │         ├── util/
 │         └── dispatcher/
 └── src/commonTest/kotlin/com/carnival/sdk/
```

## Offline-First Guarantees

- Local store is the **single source of truth**.
- Writes are persisted locally first.
- Offline writes are queued in `SyncQueue` via `SyncQueueItem`.
- Connectivity restoration triggers automatic sync (`SyncEngine`).
- Sync retries use exponential backoff.
- Default conflict strategy is Last-Write-Wins with pluggable `ConflictResolver`.

## SDK Entry Point

```kotlin
CruiseSDK.initialize(CruiseSDKConfig(baseUrl = "https://api.carnival-cruise.com"))

CruiseSDK.auth.login(email, password)
CruiseSDK.preferences.save(preferences)
CruiseSDK.itinerary.get(page = 0, pageSize = 20)
CruiseSDK.order.place(order)
CruiseSDK.chat.send(message)
CruiseSDK.sync.trigger()
```

All APIs return `Flow<ResultState<T>>` where `ResultState` is `Loading`, `Success`, or `Error`.

## Publish `shared` on GitHub and use it in sample app

1. Initialize git and push this project to a GitHub repo (example: `Carnival-SDK`).
2. Create a release tag (example: `v1.0.0`).
3. Update `gradle.properties`:
   - `useLocalShared=false`
   - `sharedLibCoordinate=com.github.<github-username>.Carnival-SDK:shared:v1.0.0`
4. Sync/build `sample-android-app`; dependency will be resolved from JitPack.

For local development, set `useLocalShared=true` to use `project(":shared")` directly.
