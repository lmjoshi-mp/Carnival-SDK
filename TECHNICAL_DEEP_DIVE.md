# Carnival SDK - Technical Deep Dive

This document is intended for engineering managers, architects, and senior developers.

## 1) Architecture Intent

The SDK is implemented as a KMM shared module with no presentation layer.  
Primary goals:
- deterministic business behavior,
- offline-first reliability,
- and explicit, testable synchronization.

Core principle: **Domain is pure and independent; Data implements domain contracts.**

## 2) Module and Layering

### Project
- `:shared` KMM module is the production SDK artifact.

### Layer responsibilities
- `domain/*`: business entities, repository contracts, use cases, domain errors.
- `data/*`: remote/local data sources, mappers, repository implementations, sync engine.
- `core/*`: infrastructure abstractions for dispatching, networking, storage, utilities.

Dependency direction:
- `domain` -> no inward dependencies.
- `data` -> depends on `domain` + `core`.
- `CruiseSDK` composes all dependencies and exposes the public API.

## 3) Public SDK API Contract

Entry point:
- `CruiseSDK.initialize(config: CruiseSDKConfig)`

Feature APIs:
- `CruiseSDK.auth.login(...)`
- `CruiseSDK.preferences.save(...)`
- `CruiseSDK.itinerary.get(...)`
- `CruiseSDK.order.place(...)`
- `CruiseSDK.chat.send(...)`
- `CruiseSDK.sync.trigger()`

All operations return:
- `Flow<ResultState<T>>`
  - `Loading`
  - `Success(data)`
  - `Error(DomainError)`

## 4) Domain Model and Error Semantics

### Domain entities
- `UserSession`, `UserPreferences`, `ItineraryItem`, `KitchenOrder`, `ChatMessage`, `SyncQueueItem`.

### Errors
- `NetworkError`
- `CacheError`
- `SyncError`
- `UnauthorizedError`

This keeps error mapping stable across features and platforms.

## 5) Data Layer Mechanics

## 5.1 Local Source (SSOT)

`LocalStore` is the persistence contract used for reads/writes.  
Current implementation uses `InMemoryLocalStore`; it is intentionally interface-driven so SQLDelight can replace it without touching domain contracts.

Read rule:
- Consumer-facing reads always come from local state.

Write rule:
- Persist local first.
- Attempt remote update if online.
- On failure/offline, enqueue sync operation.

## 5.2 Remote Source

`CruiseRemoteDataSource` encapsulates all Ktor endpoint interactions:
- auth
- preferences
- itinerary
- orders
- chat
- sync pull/push

DTOs are isolated in `data/remote/dto/*`.  
Domain mapping is centralized in `data/mapper/Mappers.kt`.

## 5.3 Repository Implementations

Repositories enforce offline-first behavior while honoring domain contracts:
- `AuthRepositoryImpl`
- `PreferencesRepositoryImpl`
- `ItineraryRepositoryImpl`
- `OrderRepositoryImpl`
- `ChatRepositoryImpl`

Common behavior pattern:
1. Emit `Loading`
2. Emit local state (`Success`)
3. Attempt remote refresh/write if conditions allow
4. Queue for sync on failure/offline

## 6) Sync Engine Design

`SyncEngine` is both:
- a `SyncRepository` implementation (manual trigger),
- and a background worker (auto trigger while online).

Sync cycle:
1. Pull remote changes since `lastPullEpochMillis`
2. Merge changes into local store (conflict policy)
3. Push local queued operations
4. Update queue entries or retry metadata

Queue payload metadata:
- operation type
- payload
- timestamp
- retry count
- next retry epoch

Retry strategy:
- exponential backoff (`ExponentialBackoff`)

Conflict strategy:
- default `LastWriteWinsConflictResolver`
- pluggable via `ConflictResolver` interface

## 7) Feature-by-Feature Runtime Paths

### Authentication
- Online login via remote API.
- Session/token cached for offline continuity.
- Offline login allowed when cached session remains valid.

### Preferences
- Save locally first.
- Remote save attempted when online.
- Sync queue fallback for delayed consistency.

### Itinerary
- Local pagination read first.
- Remote fetch refreshes cache when TTL is stale.
- Merged data persisted into local SSOT.

### Ordering
- Orders/status updates committed locally immediately.
- Pending sync marker tracks unpushed changes.
- Queue + sync engine eventually converges with backend.

### Chat
- Outbound messages written local-first.
- Polling-based receive path updates local stream.
- Failed sends are queued for retry sync.

## 8) Concurrency and Threading

- Coroutines + `Flow` are used throughout.
- Dispatchers are abstracted via `DispatcherProvider` for portability/testing.
- Sync runs in background scope and responds to connectivity events.

## 9) Testing Posture

Current test file validates:
- use case emission behavior,
- sync success path,
- sync retry increment on push failure.

Current limitation:
- coverage tooling is not yet configured for hard gating.

## 10) Engineering Risks and Hardening Plan

### Present gaps
1. Local store is in-memory (non-persistent across app restart).
2. Coverage threshold (`>=90%`) is not yet enforced.
3. Chat is polling-only (no WebSocket optimization layer).
4. Security store is abstraction + in-memory default (needs production binding).

### Hardening roadmap
1. Integrate SQLDelight-backed `LocalStore`.
2. Integrate secure token storage (Keychain/Keystore adapters).
3. Add `Kover` and enforce `koverVerify` threshold in CI.
4. Expand test matrix:
   - per-repository online/offline paths
   - sync conflict resolution permutations
   - pagination and cache expiry scenarios

## 11) Suggested Deep-Dive Review Agenda (30-45 min)

1. `CruiseSDK.kt` composition and consumer contracts
2. `domain/*` contracts and model boundaries
3. `data/repository/RepositoryImpl.kt` flow patterns
4. `data/sync/SyncEngine.kt` internals and conflict policy
5. Test strategy and coverage hardening plan
