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

### For Android Developers

1. Publish to GitHub Packages:
   ```bash
   # Set GitHub credentials in local.properties
   gpr.user=YOUR_USERNAME
   gpr.key=YOUR_GITHUB_TOKEN
   
   # Publish the library
   ./gradlew :shared:publish
   ```

2. Update `gradle.properties` in consuming app:
   ```properties
   useLocalShared=false
   sharedLibCoordinate=com.github.lmjoshi-mp.Carnival-SDK:shared:1.0.0
   ```

3. Add repository to `settings.gradle.kts`:
   ```kotlin
   maven("https://maven.pkg.github.com/lmjoshi-mp/Carnival-SDK") {
       credentials {
           username = System.getenv("GITHUB_ACTOR") ?: "username"
           password = System.getenv("GITHUB_TOKEN") ?: "token"
       }
   }
   ```

4. Add dependency to `build.gradle.kts`:
   ```kotlin
   dependencies {
       implementation("com.github.lmjoshi-mp.Carnival-SDK:shared:1.0.0")
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

### For Local Development

Set `useLocalShared=true` in `gradle.properties` to use `project(":shared")` directly.
