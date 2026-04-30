# Carnival SDK Architecture Walkthrough

This document is designed for stakeholders to understand:
- what each file does,
- how requests move through the SDK,
- and how Clean Architecture is enforced in production.

## 1) What We Built

`Carnival-SDK` is a Kotlin Multiplatform SDK (`Android + iOS`) for cruise app capabilities:
- Authentication
- Preferences
- Itinerary
- Kitchen ordering
- Admin chat

The implementation follows Clean Architecture with:
- **Domain layer**: business rules and contracts (pure Kotlin)
- **Data layer**: repository implementations, remote/local data sources, sync orchestration
- **Core layer**: shared infrastructure (network, storage abstraction, threading, utils)

There is **no presentation/UI layer** in this SDK.

## 2) Clean Architecture Boundaries

### Dependency Direction

`domain` has no dependency on `data` or `core`.
`data` depends on `domain` contracts and `core` infrastructure.
`CruiseSDK` composes all pieces and exposes a consumer API.

```text
SDK Consumer
   |
   v
CruiseSDK facade/API
   |
   v
UseCases (domain)
   |
   v
Repository Interfaces (domain contracts)
   |
   v
Repository Implementations (data)
   |                    |
   v                    v
Local Data Source    Remote Data Source
   |
   v
Local Store (SSOT)
```

## 3) File-by-File Responsibility Map

### Root Build and Module Files

- `settings.gradle.kts`: project wiring and dependency repositories; includes `:shared`.
- `build.gradle.kts`: root plugin versions for Android/Kotlin/serialization.
- `gradle.properties`: Gradle and Android defaults.
- `shared/build.gradle.kts`: KMM targets, dependencies, Android compile options.
- `README.md`: quick-start and architecture summary.

### Domain Layer (Pure Business Contracts)

- `shared/src/commonMain/kotlin/com/carnival/sdk/domain/error/DomainError.kt`
  - sealed domain errors (`NetworkError`, `CacheError`, `SyncError`, `UnauthorizedError`).

- `shared/src/commonMain/kotlin/com/carnival/sdk/domain/model/DomainModels.kt`
  - business entities: session, preferences, itinerary, order, chat, sync queue.

- `shared/src/commonMain/kotlin/com/carnival/sdk/domain/repository/Repositories.kt`
  - repository interfaces used by use cases.

- `shared/src/commonMain/kotlin/com/carnival/sdk/domain/usecase/UseCases.kt`
  - use case/interactor classes (`LoginUseCase`, `PlaceOrderUseCase`, `TriggerSyncUseCase`, etc.).

### Core Layer (Cross-Cutting Infrastructure)

- `shared/src/commonMain/kotlin/com/carnival/sdk/core/util/ResultState.kt`
  - API result contract: `Loading`, `Success`, `Error`.

- `shared/src/commonMain/kotlin/com/carnival/sdk/core/util/SupportUtils.kt`
  - shared utilities: `TimeProvider`, secure token store abstraction, JSON codec, exponential backoff.

- `shared/src/commonMain/kotlin/com/carnival/sdk/core/dispatcher/DispatcherProvider.kt`
  - coroutine dispatcher abstraction for testability and threading control.

- `shared/src/commonMain/kotlin/com/carnival/sdk/core/network/NetworkMonitor.kt`
  - connectivity state abstraction (`StateFlow<Boolean>`).

- `shared/src/commonMain/kotlin/com/carnival/sdk/core/network/NetworkModule.kt`
  - Ktor `HttpClient` factory with serialization and optional logging.

- `shared/src/commonMain/kotlin/com/carnival/sdk/core/database/LocalStore.kt`
  - storage contract for SSOT operations.

- `shared/src/commonMain/kotlin/com/carnival/sdk/core/database/InMemoryLocalStore.kt`
  - in-memory implementation of `LocalStore` (acts like DB abstraction for now).

### Data Layer (Concrete Implementations)

- `shared/src/commonMain/kotlin/com/carnival/sdk/data/remote/dto/RemoteDtos.kt`
  - network DTOs for all features + sync changes.

- `shared/src/commonMain/kotlin/com/carnival/sdk/data/mapper/Mappers.kt`
  - DTO <-> domain conversions.

- `shared/src/commonMain/kotlin/com/carnival/sdk/data/remote/CruiseRemoteDataSource.kt`
  - Ktor remote calls (auth/preferences/itinerary/orders/chat/sync endpoints).

- `shared/src/commonMain/kotlin/com/carnival/sdk/data/remote/SyncRemoteGateway.kt`
  - interface used by sync engine for push/pull sync operations.

- `shared/src/commonMain/kotlin/com/carnival/sdk/data/local/CruiseLocalDataSource.kt`
  - orchestrates local persistence, queue insertions, and local state mutations.

- `shared/src/commonMain/kotlin/com/carnival/sdk/data/cache/CachePolicy.kt`
  - TTL-based staleness for cache refresh decisions (used in itinerary).

- `shared/src/commonMain/kotlin/com/carnival/sdk/data/repository/RepositoryImpl.kt`
  - feature repository implementations with offline-first behavior.
  - write path uses local-first updates and queues sync when needed.

- `shared/src/commonMain/kotlin/com/carnival/sdk/data/sync/SyncEngine.kt`
  - automatic/manual sync orchestration:
    - pull remote changes,
    - push local pending changes,
    - apply conflict strategy (default Last Write Wins),
    - retry with exponential backoff.

### SDK Entry and Consumer API

- `shared/src/commonMain/kotlin/com/carnival/sdk/CruiseSDK.kt`
  - SDK configuration, dependency composition (manual DI), startup/shutdown.
  - exposes consumer-facing APIs: `auth`, `preferences`, `itinerary`, `order`, `chat`, `sync`.

- `shared/src/commonMain/kotlin/com/carnival/sdk/SampleUsage.kt`
  - sample integration showing initialize/login/save/get/place/send/receive flows.

### Testing

- `shared/src/commonTest/kotlin/com/carnival/sdk/CruiseSdkUseCaseAndSyncTests.kt`
  - unit tests for use case output behavior and sync success/retry logic.

## 4) Process Flow Through Clean Architecture

## 4.1 Authentication (Online + Offline)

1. Consumer calls `CruiseSDK.auth.login(email, password)`.
2. `AuthApi` delegates to `LoginUseCase`.
3. `LoginUseCase` calls `AuthRepository` contract.
4. `AuthRepositoryImpl` checks connectivity:
   - **online**: calls remote login, stores session locally + token store.
   - **offline**: attempts cached session login if session is still valid.
5. Returns `Flow<ResultState<UserSession>>`.

## 4.2 Preferences Save (Offline-First)

1. `CruiseSDK.preferences.save(preferences)` -> `SavePreferencesUseCase`.
2. `PreferencesRepositoryImpl` writes preferences to local store first.
3. If online, it tries remote save and refreshes local with remote response.
4. If offline/failure, it enqueues a sync operation (`SyncQueueItem`).
5. Consumer still gets immediate local success and eventual consistency.

## 4.3 Itinerary Read with Cache + Pagination

1. `CruiseSDK.itinerary.get(page, pageSize)` -> `FetchItineraryUseCase`.
2. Repository returns cached local page first.
3. If online and cache expired by policy, fetches remote page.
4. Mapped results are persisted locally and emitted again from local source.

## 4.4 Kitchen Order Write + Status Update

1. `CruiseSDK.order.place(order)` / `updateStatus(orderId, status)`.
2. Order is saved locally immediately and marked pending sync.
3. If online, remote call is attempted; on success local pending flag is cleared.
4. If offline/failure, operation is enqueued in sync queue.
5. `observe(userId)` streams local SSOT order state changes.

## 4.5 Chat Send + Receive (Polling Fallback)

1. `CruiseSDK.chat.send(message)` writes local first.
2. If online, remote send is attempted; on success pending flag clears.
3. If offline/failure, chat send operation is queued for sync.
4. `CruiseSDK.chat.receive(roomId)` always streams local messages.
5. If online, periodic polling fetches remote messages and stores locally.

## 5) Offline + Sync Strategy (SSOT in Practice)

- **Single Source of Truth:** local store (`LocalStore`) is always read source.
- **Write path:** local-first, then remote attempt or queue.
- **Sync queue schema concept:** operation type, payload, timestamp, retryCount, nextRetry.
- **Auto-sync trigger:** network status transition to online + periodic background loop.
- **Conflict strategy:** Last Write Wins by default; swappable via `ConflictResolver`.
- **Retry policy:** exponential backoff prevents hot-loop failures.

## 6) Why This Is Production-Friendly

- Clear separation of concerns and testable boundaries.
- Deterministic API contract (`Flow<ResultState<T>>`) for all features.
- Offline continuity for critical onboard scenarios.
- Sync behavior is explicit, observable, and resilient.
- KMM shared logic reduces platform drift across Android and iOS.

## 7) Suggested Stakeholder Demo Script (10 Minutes)

1. Start with `CruiseSDK.kt` to show SDK API surface and initialization.
2. Open one domain file (`Repositories.kt`) to show contract-first design.
3. Open one use case file (`UseCases.kt`) to show business entry points.
4. Open one repository implementation (`RepositoryImpl.kt`) to show local-first writes.
5. Open `SyncEngine.kt` to show online recovery and conflict handling.
6. Open test file to show behavior validation strategy.
7. Close with sample usage and explain SDK consumer simplicity.
