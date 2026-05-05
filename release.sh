#!/bin/bash
set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== Carnival SDK Release Publisher ===${NC}\n"

# Check if version is provided
if [ -z "$1" ]; then
    echo -e "${RED}ERROR: Version number required${NC}"
    echo -e "Usage: $0 <version> [commit-message]"
    echo -e "Example: $0 1.0.1 \"Add new feature\""
    exit 1
fi

VERSION=$1
COMMIT_MSG=${2:-"Release version $VERSION"}

echo -e "${GREEN}✓ Preparing release $VERSION${NC}"

# Update version in build.gradle.kts
echo -e "${BLUE}Updating version in build.gradle.kts...${NC}"
sed -i '' "s/version = \"[^\"]*\"/version = \"$VERSION\"/g" shared/build.gradle.kts

# Build and test
echo -e "${BLUE}Building and testing...${NC}"
./gradlew :shared:build

# Commit changes
echo -e "${BLUE}Committing changes...${NC}"
git add shared/build.gradle.kts
git commit -m "$COMMIT_MSG"

# Create and push tag
echo -e "${BLUE}Creating and pushing tag $VERSION...${NC}"
git tag -a $VERSION -m "Version $VERSION"
git push origin main
git push origin $VERSION

echo -e "\n${GREEN}✓ Release $VERSION published successfully!${NC}"
echo -e "${YELLOW}JitPack will build the library automatically within a few minutes.${NC}"
echo -e "${YELLOW}Check status at: https://jitpack.io/com/github/lmjoshi-mp/Carnival-SDK/$VERSION${NC}"
