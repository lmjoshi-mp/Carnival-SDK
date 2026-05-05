#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}🔨 Building XCFramework for iOS...${NC}"

# Build the shared library
./gradlew :shared:buildXCFramework

if [ $? -eq 0 ]; then
    echo -e "${GREEN}✅ XCFramework built successfully!${NC}"

    # Create a zip file for distribution
    XCFRAMEWORK_PATH="shared/build/xcframework/CarnivalSDK.xcframework"

    if [ -d "$XCFRAMEWORK_PATH" ]; then
        cd shared/build/xcframework
        zip -r "CarnivalSDK.xcframework.zip" "CarnivalSDK.xcframework"
        CHECKSUM=$(swift package compute-checksum "CarnivalSDK.xcframework.zip" 2>/dev/null || shasum -a 256 "CarnivalSDK.xcframework.zip" | awk '{print $1}')

        echo -e "${GREEN}✅ XCFramework packaged: CarnivalSDK.xcframework.zip${NC}"
        echo -e "${YELLOW}📋 Checksum for Package.swift: $CHECKSUM${NC}"
        echo ""
        echo -e "${YELLOW}Next steps:${NC}"
        echo "1. Upload 'CarnivalSDK.xcframework.zip' to GitHub Releases (for your target tag)"
        echo "2. Update Package.swift checksum: $CHECKSUM"
        echo "3. Tag release: git tag -a <tag> -m 'Version <version>'"
        echo "4. Push to GitHub: git push origin <tag>"

        cd ../../..
    else
        echo -e "${RED}❌ XCFramework not found at: $XCFRAMEWORK_PATH${NC}"
        exit 1
    fi
else
    echo -e "${RED}❌ XCFramework build failed!${NC}"
    exit 1
fi

