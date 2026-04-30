# CruiseSDK Client Deck (Slide-by-Slide)

Use each `## Slide` section as one slide in PowerPoint/Google Slides.

## Slide 1 - Title
**CruiseSDK: Scalable Offline-First Architecture**  
**Subtitle:** Clean Architecture in KMM for reliable cruise operations

**Presenter note:**  
Set context: this SDK powers mission-critical cruise flows in unstable network conditions.

---

## Slide 2 - Executive Summary
- Built with **Kotlin Multiplatform (KMM)** for Android + iOS consistency
- Uses **Clean Architecture** for long-term scalability
- Designed **offline-first** with automatic sync and conflict handling
- Quality enforced with automated tests and coverage gate

**Presenter note:**  
Business promise: faster feature expansion, fewer regressions, better guest experience.

---

## Slide 3 - Business Problem
- Cruise connectivity is intermittent/unreliable
- Operational flows cannot fail because of poor network
- Product needs real-time behavior + offline resilience
- New features must be added without rewriting core code

**Presenter note:**  
This is why architecture matters more than just “API integration.”

---

## Slide 4 - Why Clean Architecture
- Separation of concerns by layer
- Low coupling between UI, business, and data access
- Independent testing of business rules
- Easier replacement of API/DB/infra components
- Parallel development across teams

---

## Slide 5 - Architecture Layers
- **Presentation:** UI + ViewModel (consumer app side)
- **Domain:** UseCases + Models + Repository contracts
- **Data:** Repository implementations + Local/Remote + Sync
- **Core:** Network, dispatchers, utilities, platform abstractions

**Presenter note:**  
The SDK itself focuses on domain + data + core; no UI layer inside SDK.

---

## Slide 6 - Dependency Direction (Key Principle)
`UI -> ViewModel -> UseCase -> Repository Interface <- Repository Impl <- Data Sources`

- Dependencies always point inward toward business logic
- Domain does not depend on frameworks (Ktor/DB/UI)
- Data layer depends on domain, never the reverse

---

## Slide 7 - SDK Public API
- `CruiseSDK.initialize(config)`
- `CruiseSDK.auth.login()`
- `CruiseSDK.preferences.save()/get()`
- `CruiseSDK.itinerary.get()`
- `CruiseSDK.order.place()/updateStatus()/observe()`
- `CruiseSDK.chat.send()/receive()`
- `CruiseSDK.sync.trigger()`

- Unified response contract: `Flow<ResultState<T>>`

---

## Slide 8 - Core Features Included
1. Authentication  
2. User Preferences  
3. Itinerary Retrieval  
4. Kitchen Ordering  
5. Admin Chat (near real-time)  
6. Offline Queue + Sync Engine

---

## Slide 9 - Android & iOS Consumption (Presentation Layer)
- Both apps call the same shared SDK APIs from their ViewModel/Presenter layer
- SDK responses are exposed as `Flow<ResultState<T>>` for predictable UI state updates
- Android maps states to `StateFlow`/Jetpack UI (`Loading`, `Success`, `Error`)
- iOS maps the same states to Swift UI state (`loading`, `data`, `failure`) via KMM bridge
- No business logic duplication in app layer; platform teams focus only on UI rendering
- New SDK capability appears on both platforms with a consistent contract

**Presenter note:**  
Message to client: one SDK integration model, two native experiences, same business behavior.

---

## Slide 10 - Standard Feature Data Flow
1. UI event triggers ViewModel action  
2. ViewModel calls UseCase  
3. UseCase calls Repository contract  
4. Repository implementation resolves local/remote/sync path  
5. Result flows back via StateFlow/Flow

---

## Slide 11 - Login Flow (End-to-End)
- User submits credentials
- `LoginUseCase` validates and delegates
- Repository calls remote login (if online)
- Session + token persisted securely
- Offline fallback uses cached valid session
- UI reacts to Success/Error state

---

## Slide 12 - Food Ordering (Why Architecture Matters)
Ordering is a **multi-capability domain**, not a single API call:
- Get menu
- Add/update cart
- Place order
- Track order
- Cancel order
- (Future) discounts, reorder, split payment

**Message:** each business action has its own UseCase.

---

## Slide 13 - Menu + Cart Design
- Menu uses cache-aware retrieval
- Cart is local-first for instant UX
- Quantity/remove operations update local DB immediately
- Business rules applied in UseCases (limits, stock checks, totals)

---

## Slide 14 - Place Order Flow (Critical Path)
- Validate cart/payment/order window
- Write order locally first (`pendingSync`)
- If online: push immediately
- If offline: queue operation
- Sync engine retries with backoff
- Kitchen/admin notified once accepted

**Message:** no lost user intent during network instability.

---

## Slide 15 - Track/Cancel Order Flows
- Tracking: repository emits status stream (`Placed -> Preparing -> Delivered`)
- Cancel: rule-driven (allowed only at valid stage)
- Local and backend status remain synchronized

---

## Slide 16 - Chat Flow
- Send message -> local-first write
- Online send immediately; offline queue if needed
- Receive via stream + polling fallback
- UI updates reactively from local source

---

## Slide 17 - Offline-First Strategy
- Local DB/storage is **single source of truth**
- Reads always from local
- Writes always persisted locally first
- Pending operations stored in sync queue
- Background and reconnect-triggered synchronization

---

## Slide 18 - Sync Engine Strategy
- Queue item fields: operation, payload, timestamp, retryCount
- Sync cycle:
  1. Pull remote changes
  2. Push local pending changes
  3. Resolve conflicts
  4. Update local state + queue
- Retry uses exponential backoff
- Conflict resolution default: Last Write Wins (extensible)

---

## Slide 19 - Technology Stack
- KMM shared module
- Coroutines + Flow
- Ktor client
- SQLDelight-ready local abstraction
- WebSocket/polling support for realtime
- Expect/actual platform adapters (device info, logging, file, monitor, token factory)

---

## Slide 20 - Quality & Governance
- Unit tests for UseCases, repositories, sync engine, SDK facade
- Kover coverage gate on shared module
- Build fails if coverage threshold not met
- Predictable release quality and lower regression risk

---

## Slide 21 - Client Value Delivered
- Faster feature onboarding
- Fewer production regressions
- Better offline reliability and guest trust
- Easier long-term maintainability
- Cross-platform consistency without duplicated business logic

---

## Slide 22 - Roadmap (Next Hardening)
- Replace in-memory local store with persistent SQLDelight implementation
- Platform-secure token storage (Keystore/Keychain)
- Advanced telemetry for sync diagnostics
- Optional websocket-first chat transport

---

## Slide 23 - Closing
**“A scalable system is not built by writing more code; it is built by placing the right responsibilities in the right layers.”**

**Q&A**
