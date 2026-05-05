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

## Publishing & Distribution

### For Android Developers (JitPack - No Authentication Required)

1. **Add JitPack repository** to `settings.gradle.kts`:
   ```kotlin
   dependencyResolutionManagement {
       repositories {
           mavenCentral()
           maven { url 'https://jitpack.io' }
       }
   }
   ```

2. **Add dependency** to `build.gradle.kts`:
   ```kotlin
   dependencies {
       implementation("com.github.lmjoshi-mp:Carnival-SDK:1.0.0")
   }
   ```

### For iOS Developers (Swift Package Manager)

1. **Build XCFramework**:
   ```bash
   ./build-xcframework.sh
   ```
   This generates `CarnivalSDK.xcframework.zip` with checksum for Package.swift.

2. **Upload to GitHub Releases**:
   - Create a GitHub release for tag `v1.0.0`
   - Upload `shared/build/xcframework/CarnivalSDK.xcframework.zip`
   - Update checksum in `Package.swift`

3. **Use in Xcode (Swift Package Manager)**:
   ```swift
   // In Xcode: File → Add Packages
   // Enter repository URL:
   https://github.com/lmjoshi-mp/Carnival-SDK.git

   // Select version: 1.0.0
   // Add to your target
   ```

4. **Or add to `Package.swift`**:
   ```swift
   dependencies: [
       .package(url: "https://github.com/lmjoshi-mp/Carnival-SDK.git", from: "1.0.0")
   ]
   ```

### For iOS Developers (CocoaPods)

1. **Add to Podfile**:
   ```ruby
   pod 'Carnival-SDK', '~> 1.0.0'
   ```

2. **Run**:
   ```bash
   pod install
   ```

### Publishing New Versions

1. **Update version** in `shared/build.gradle.kts`:
   ```kotlin
   version = "1.0.1" // Increment version
   ```

2. **Commit and tag**:
   ```bash
   git add .
   git commit -m "Release version 1.0.1"
   git tag -a 1.0.1 -m "Version 1.0.1"
   git push origin main
   git push origin 1.0.1
   ```

3. **JitPack will automatically build** the new version within minutes.

### For Local Development

Set `useLocalShared=true` in `gradle.properties` to use `project(":shared")` directly.
