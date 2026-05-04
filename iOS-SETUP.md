# iOS Integration Guide - Carnival SDK

## Swift Package Manager (Recommended)

### Step 1: Add Package to Xcode

In Xcode:
1. Open your project
2. Go to **File** → **Add Packages**
3. Enter repository URL: `https://github.com/lmjoshi-mp/Carnival-SDK.git`
4. Select version `1.0.0` (or latest)
5. Choose your target and click **Add Package**

### Step 2: Import and Use

```swift
import CarnivalSDK

// Initialize the SDK
CruiseSDK.initialize(
    config: CruiseSDKConfig(
        baseUrl: "https://api.carnival-cruise.com"
    )
)

// Use SDK APIs
CruiseSDK.auth.login(email: "user@example.com", password: "password")
    .sink { result in
        switch result {
        case .loading:
            print("Loading...")
        case .success(let data):
            print("Logged in: \(data)")
        case .error(let error):
            print("Error: \(error)")
        }
    }
    .store(in: &cancellables)
```

## CocoaPods (Alternative)

### Step 1: Add to Podfile

```ruby
target 'YourApp' do
  pod 'Carnival-SDK', '~> 1.0.0'
end
```

### Step 2: Install

```bash
pod install
```

### Step 3: Import and Use

```swift
import CarnivalSDK

// Same usage as above
```

## Available APIs

### Authentication
```swift
CruiseSDK.auth.login(email: String, password: String) -> Flow<ResultState<AuthResponse>>
CruiseSDK.auth.logout() -> Flow<ResultState<Void>>
CruiseSDK.auth.getCurrentUser() -> Flow<ResultState<User>>
```

### Preferences
```swift
CruiseSDK.preferences.save(preferences: UserPreferences) -> Flow<ResultState<Void>>
CruiseSDK.preferences.get() -> Flow<ResultState<UserPreferences>>
```

### Itinerary
```swift
CruiseSDK.itinerary.get(page: Int, pageSize: Int) -> Flow<ResultState<[ItineraryItem]>>
CruiseSDK.itinerary.getById(id: String) -> Flow<ResultState<ItineraryDetails>>
```

### Orders
```swift
CruiseSDK.order.place(order: Order) -> Flow<ResultState<OrderResponse>>
CruiseSDK.order.getOrders(page: Int) -> Flow<ResultState<[Order]>>
```

### Chat
```swift
CruiseSDK.chat.send(message: Message) -> Flow<ResultState<MessageResponse>>
CruiseSDK.chat.getMessages() -> Flow<ResultState<[Message]>>
```

### Sync
```swift
CruiseSDK.sync.trigger() -> Flow<ResultState<SyncStatus>>
CruiseSDK.sync.getSyncStatus() -> Flow<ResultState<SyncStatus>>
```

## Offline Support

The SDK automatically handles offline scenarios:

- **Local caching**: All data is cached locally
- **Automatic sync**: When connectivity is restored, offline changes are automatically synced
- **Conflict resolution**: Uses Last-Write-Wins strategy by default
- **Retry mechanism**: Automatic exponential backoff for failed requests

## Troubleshooting

### Package Resolution Issues

If you encounter package resolution issues:

1. **Clear cache**:
   ```bash
   rm -rf ~/Library/Developer/Xcode/DerivedData
   ```

2. **Update package**:
   - In Xcode: **File** → **Packages** → **Update Package Versions**

3. **Check network**:
   - Ensure GitHub is accessible
   - Add GitHub credentials if using private repositories

### Authentication Errors

If you get 401 authentication errors:

1. Ensure personal access token has `read:packages` scope
2. Set environment variables:
   ```bash
   export GITHUB_ACTOR=your_username
   export GITHUB_TOKEN=your_token
   ```

## Documentation

For more details, see the main [README.md](./README.md)

