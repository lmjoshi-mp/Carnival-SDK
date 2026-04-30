# CruiseSDK 10-Minute Engineering Walkthrough Script

Use this as a speaking script while screen-sharing the codebase.

## 0:00 - 0:45 | Context and Objective

“This SDK is a Kotlin Multiplatform CruiseSDK with strict Clean Architecture.  
It supports auth, preferences, itinerary, kitchen ordering, and chat with offline-first behavior and automated sync.”

Key value points to speak:
- KMM shared logic for Android + iOS consistency
- Local-first reads/writes for unstable onboard connectivity
- Deterministic sync strategy with retries and conflict handling

---

## 0:45 - 1:30 | Show Project Structure

Open:
- `settings.gradle.kts`
- `shared/build.gradle.kts`

Talk track:
- `:shared` is the SDK module
- `:sample-android-app` is demo consumer
- Kover gate enforces quality threshold

Message:
“The SDK is designed as a reusable library; demo app proves integration.”

---

## 1:30 - 2:40 | Domain Layer (Contracts First)

Open:
- `shared/src/commonMain/kotlin/com/carnival/sdk/domain/model/DomainModels.kt`
- `shared/src/commonMain/kotlin/com/carnival/sdk/domain/repository/Repositories.kt`
- `shared/src/commonMain/kotlin/com/carnival/sdk/domain/usecase/UseCases.kt`
- `shared/src/commonMain/kotlin/com/carnival/sdk/domain/error/DomainError.kt`

Talk track:
- Models represent business entities (session, preferences, orders, chat, sync queue)
- Repositories are interfaces only (no implementation leakage)
- Use cases are business entry points
- Unified domain errors for predictable handling

Message:
“Domain stays pure and platform-agnostic; implementations can evolve without changing contracts.”

---

## 2:40 - 4:20 | Data Layer (Real Behavior)

Open:
- `shared/src/commonMain/kotlin/com/carnival/sdk/data/repository/RepositoryImpl.kt`

Walk through one read + one write:
- Read: itinerary fetch emits cache first, then refreshes if stale and online
- Write: order save persists locally first, marks pending sync, queues if offline/failure

Message:
“All repositories are offline-first by construction, not by consumer discipline.”

---

## 4:20 - 5:10 | Local Source of Truth

Open:
- `shared/src/commonMain/kotlin/com/carnival/sdk/core/database/LocalStore.kt`
- `shared/src/commonMain/kotlin/com/carnival/sdk/core/database/InMemoryLocalStore.kt`
- `shared/src/commonMain/kotlin/com/carnival/sdk/data/local/CruiseLocalDataSource.kt`

Talk track:
- Local store contract abstracts persistence
- Current impl is in-memory (swap with SQLDelight implementation later)
- SDK reads from local always; remote updates local

Message:
“SSOT ensures deterministic behavior even during network transitions.”

---

## 5:10 - 6:20 | Remote + Mapping

Open:
- `shared/src/commonMain/kotlin/com/carnival/sdk/data/remote/CruiseRemoteDataSource.kt`
- `shared/src/commonMain/kotlin/com/carnival/sdk/data/remote/dto/RemoteDtos.kt`
- `shared/src/commonMain/kotlin/com/carnival/sdk/data/mapper/Mappers.kt`

Talk track:
- Remote data source encapsulates HTTP contract
- DTOs isolate transport schema from business models
- Mappers decouple API evolution from domain stability

Message:
“Transport changes do not cascade into business logic.”

---

## 6:20 - 7:50 | Sync Engine (Core Reliability)

Open:
- `shared/src/commonMain/kotlin/com/carnival/sdk/data/sync/SyncEngine.kt`

Talk track:
- Sync queue items contain operation, payload, timestamp, retry count
- Flow:
  1. pull remote changes
  2. push local pending changes
  3. resolve conflicts (default Last Write Wins)
  4. update queue and local sync markers
- Retry with exponential backoff
- Auto trigger on connectivity restoration + periodic worker

Message:
“This is where offline durability turns into eventual consistency.”

---

## 7:50 - 8:50 | SDK Consumer API

Open:
- `shared/src/commonMain/kotlin/com/carnival/sdk/CruiseSDK.kt`

Talk track:
- `CruiseSDK.initialize(config)` manually composes dependencies
- Feature APIs exposed:
  - `auth`, `preferences`, `itinerary`, `order`, `chat`, `sync`
- All return `Flow<ResultState<T>>` (`Loading`, `Success`, `Error`)

Message:
“SDK consumers get one consistent asynchronous contract across all features.”

---

## 8:50 - 9:40 | Demo App Usage

Open:
- `sample-android-app/src/main/kotlin/com/carnival/sample/app/MainActivity.kt`

Talk track:
- Demonstrates live online/offline flows
- Includes:
  - run-full-scenario
  - reset state
  - step status badges
  - auto-scroll logs

Message:
“Stakeholders can observe queueing and sync outcomes in real time.”

---

## 9:40 - 10:00 | Quality and Close

Open:
- `shared/src/commonTest/kotlin/com/carnival/sdk/RepositoryAndSdkCoverageTests.kt`
- `shared/build/reports/kover/report.xml`

Talk track:
- Unit tests target repository/sync branches and SDK surface
- Kover verification enforces coverage gate in build

Closing line:
“Architecture, offline behavior, and quality controls are all codified and automated.”
