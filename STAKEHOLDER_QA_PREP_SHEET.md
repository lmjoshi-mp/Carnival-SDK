# CruiseSDK Stakeholder Q&A Prep Sheet

Use this during demos/reviews to answer common business and technical questions quickly.

## 1) “What problem does this SDK solve?”

**Answer:**  
It provides a unified, reusable cruise operations SDK for Android and iOS with offline-first behavior, so core flows keep working when ship connectivity is unstable.

---

## 2) “Why KMM instead of separate Android/iOS implementations?”

**Answer:**  
Shared business logic prevents platform drift, reduces duplicate effort, and keeps behavior consistent across apps while still allowing platform-specific integration at the edges.

---

## 3) “How does data flow in this architecture?”

**Answer:**  
Consumer -> `CruiseSDK` API -> UseCase -> Repository interface -> Repository implementation -> Local/Remote data source.  
Reads are local-first. Writes are local-first and synced later if needed.

---

## 4) “What happens offline?”

**Answer:**  
Operations still execute against local storage.  
Mutations are marked pending and added to a sync queue.  
When connectivity returns, SyncEngine reconciles pending operations with the backend.

---

## 5) “How do you avoid data loss during reconnect?”

**Answer:**  
Queued operations are persisted as sync records containing operation type, payload, timestamp, and retry metadata.  
Failed pushes are retried with exponential backoff.

---

## 6) “How are conflicts handled?”

**Answer:**  
Default strategy is Last Write Wins using update timestamps.  
The design includes a `ConflictResolver` abstraction so custom merge rules can be plugged in later.

---

## 7) “What are the supported feature sets now?”

**Answer:**
- Authentication (online + cached session fallback)
- Preferences save/fetch
- Itinerary fetch with caching and pagination
- Kitchen order place/update/observe
- Chat send/receive with polling fallback
- Manual and automatic sync

---

## 8) “What does the API look like for app teams?”

**Answer:**  
Single entry point:
- `CruiseSDK.initialize(config)`
- `CruiseSDK.auth...`
- `CruiseSDK.preferences...`
- `CruiseSDK.itinerary...`
- `CruiseSDK.order...`
- `CruiseSDK.chat...`
- `CruiseSDK.sync...`

Every call returns `Flow<ResultState<T>>` (`Loading`, `Success`, `Error`).

---

## 9) “How do you guarantee code quality?”

**Answer:**  
The SDK includes unit tests across repositories, sync logic, local store behavior, and SDK surface APIs.  
Coverage is enforced by Kover with a `>= 90%` line coverage gate on the shared module.

---

## 10) “Is this production-ready?”

**Answer:**  
Core architecture and behavior are production-grade.  
For full production hardening, next steps are:
- SQLDelight-backed persistent store (replace in-memory store)
- Platform secure token storage adapters
- richer telemetry/metrics around sync outcomes
- optional websocket layer for chat optimization

---

## 11) “How quickly can we onboard a consuming app?”

**Answer:**  
Fast. A demo Android consumer app is already included to validate integration patterns and behavior under online/offline/sync transitions.

---

## 12) “What are key risks and mitigations?”

**Answer:**
- **Risk:** connectivity instability  
  **Mitigation:** local-first + queue + retry + conflict strategy
- **Risk:** platform behavior mismatch  
  **Mitigation:** shared KMM business logic
- **Risk:** regression during enhancement  
  **Mitigation:** coverage gate and automated tests

---

## 13) “How does this scale for future cruise features?”

**Answer:**  
New features plug into the same pattern:
Domain contract -> UseCase -> Repository implementation -> Local/Remote + Sync integration.  
This keeps architecture predictable and scalable.

---

## 14) “What should leadership remember in one line?”

**Answer:**  
This SDK turns intermittent maritime connectivity into a reliable product experience through offline-first architecture and automated synchronization.
