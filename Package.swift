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
            checksum: "92a06cd0132437ee28d608d1a6dd8feb89ee73b6c1579504a279d7d174c36404"
        )
    ]
)

