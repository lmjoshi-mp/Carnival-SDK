# Carnival SDK - Executive Summary (One Slide)

## Business Goal

Deliver a reliable cruise application SDK that works seamlessly:
- online,
- offline while onboard,
- and auto-recovers/syncs when connectivity returns.

## What Was Built

- Kotlin Multiplatform SDK (`Android + iOS`) with a single integration surface:
  - `CruiseSDK.initialize(config)`
  - `CruiseSDK.auth / preferences / itinerary / order / chat / sync`
- Clean Architecture with strict separation:
  - **Domain** for business rules/contracts
  - **Data** for implementations (remote/local/sync)

## Why It Matters

- **Guest experience continuity:** app remains operational without internet.
- **Operational resilience:** queued actions sync automatically on reconnect.
- **Platform consistency:** shared core logic reduces Android/iOS behavior drift.
- **Scalability:** modular design simplifies adding new features and partners.

## Offline-First Strategy (Value Snapshot)

- Local storage is the **Single Source of Truth**.
- Writes are saved locally first (immediate response to user).
- Pending actions are queued with retry/backoff.
- Sync engine resolves conflicts using Last-Write-Wins (extensible).

## Current Validation Status

- Multiplatform build is green with wrapper-based Gradle.
- Unit tests exist for key use case and sync-retry scenarios.
- Coverage tooling is not yet configured to prove a 90% threshold.

## Next Milestones (Recommended)

1. Add coverage enforcement (`Kover`) with `>= 90%` gate.
2. Expand test suite across all repositories/use cases.
3. Replace in-memory local store with SQLDelight-backed persistent store.
4. Add secure token storage implementation per platform.
