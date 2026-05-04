// swift-tools-version: 5.9
import PackageDescription

let package = Package(
    name: "Carnival-SDK",
    platforms: [
        .iOS(.v14)
    ],
    products: [
        .library(
            name: "CarnivalSDK",
            targets: ["CarnivalSDK"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "CarnivalSDK",
            url: "https://github.com/lmjoshi-mp/Carnival-SDK/releases/download/v1.0.0/CarnivalSDK.xcframework.zip",
            checksum: "PLACEHOLDER_CHECKSUM"
        )
    ]
)

