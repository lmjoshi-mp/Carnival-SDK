# Sample Android Consumer App

This module demonstrates a practical Android app consuming the `CruiseSDK`.

## Features in the demo screen

- Login with SDK
- Save preferences
- Fetch itinerary
- Toggle offline/online
- Place order while offline (queued)
- Send chat while offline (queued)
- Trigger sync on reconnect
- Observe synced orders and messages
- Step cards with live status badges (Idle/Running/Success/Error)
- One-click `Run Full Scenario` to execute the complete flow automatically
- One-click `Reset Demo State` to restart from a clean online baseline

## Build

From project root:

```bash
./gradlew :sample-android-app:assembleDebug
```

## Run

Open the module in Android Studio and run `sample-android-app` on an emulator/device.
