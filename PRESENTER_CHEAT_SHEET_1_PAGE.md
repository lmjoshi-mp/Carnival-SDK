# CruiseSDK Presenter Cheat Sheet (1 Page)

Use this live while presenting. Keep answers short and outcome-focused.

## 30-Second Opening

“We built a Kotlin Multiplatform CruiseSDK for auth, preferences, itinerary, ordering, and chat.  
It is offline-first: local-first reads/writes, queued sync during disconnection, and automatic reconciliation on reconnect.”

---

## 5-Part Demo Flow (Fast)

1. **Architecture shape**  
   Show: `ARCHITECTURE_STAKEHOLDER_WALKTHROUGH.md`  
   Say: “Strict domain + data separation; no UI in SDK.”

2. **Data flow**  
   Show: `shared/src/commonMain/kotlin/com/carnival/sdk/CruiseSDK.kt`  
   Say: “Consumer calls API facade -> use case -> repository -> local/remote.”

3. **Offline-first behavior**  
   Show: `shared/src/commonMain/kotlin/com/carnival/sdk/data/repository/RepositoryImpl.kt`  
   Say: “Writes go local first; offline/failure goes to sync queue.”

4. **Sync reliability**  
   Show: `shared/src/commonMain/kotlin/com/carnival/sdk/data/sync/SyncEngine.kt`  
   Say: “Pull + push + backoff + conflict resolution (LWW default).”

5. **Quality proof**  
   Show: `shared/build/reports/kover/report.xml`  
   Say: “Coverage gate is enforced; build fails if below threshold.”

---

## One-Line Value Statements

- **Reliability:** “User actions continue offline; consistency is restored automatically.”
- **Consistency:** “Same business logic across Android and iOS through KMM.”
- **Scalability:** “New features follow the same use case + repository + sync pattern.”
- **Governance:** “Coverage and tests are build-gated, not optional.”

---

## Likely Questions (Quick Answers)

- **Q: What happens without internet?**  
  A: “Reads/writes continue from local storage; writes are queued for sync.”

- **Q: How do you avoid conflicts?**  
  A: “Last Write Wins by default; resolver is pluggable.”

- **Q: Is this production-ready?**  
  A: “Architecture and sync behavior are production-grade; next hardening is persistent DB + secure token adapters.”

- **Q: How do app teams consume it?**  
  A: “Single entry point: `CruiseSDK.initialize(...)` then feature APIs returning `Flow<ResultState<T>>`.”

- **Q: How do we trust quality?**  
  A: “Automated tests plus Kover gate with minimum coverage threshold.”

---

## Must-Remember Close (15 Seconds)

“This SDK converts unstable cruise connectivity into a reliable product experience through offline-first design, deterministic sync, and enforceable quality gates.”
