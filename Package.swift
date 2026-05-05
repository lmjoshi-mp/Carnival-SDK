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
            url: "https://github.com/lmjoshi-mp/Carnival-SDK/releases/download/1.0.0/CarnivalSDK.xcframework.zip",
            checksum: "7572c864414ad5371f5fba5fd6ba5a7c1a4d2af7d467844b49eb9118f29fe3a6"
        )
    ]
)
