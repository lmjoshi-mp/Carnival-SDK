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
            url: "https://github.com/lmjoshi-mp/Carnival-SDK/releases/download/1.0.2/CarnivalSDK.xcframework.zip",
            checksum: "2af0ac044cff5ce1b079829f190383658baf23831b1466f8bcf76647d5318621"
        )
    ]
)
