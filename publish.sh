#!/bin/bash
set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== Carnival SDK Library Publisher ===${NC}\n"

# Check if token is set
if [ -z "$GITHUB_TOKEN" ]; then
    echo -e "${RED}ERROR: GITHUB_TOKEN environment variable is not set${NC}"
    echo -e "\nSet your GitHub Personal Access Token:"
    echo "  export GITHUB_ACTOR=lmjoshi-mp"
    echo "  export GITHUB_TOKEN=REDACTED"
    echo ""
    echo "Or update local.properties with:"
    echo "  gpr.key=REDACTED"
    exit 1
fi

echo -e "${GREEN}✓ GitHub credentials found${NC}"
echo "  User: lmjoshi-mp"
echo "  Token: ${GITHUB_TOKEN:0:10}...${NC}\n"

# Build the library
echo -e "${BLUE}Building shared library...${NC}"
./gradlew :shared:build -x test

# Publish to GitHub Packages
echo -e "\n${BLUE}Publishing to GitHub Packages...${NC}"
./gradlew :shared:publishKotlinMultiplatformPublicationToGitHubPackagesRepository

echo -e "\n${GREEN}✓ Successfully published to GitHub Packages!${NC}"
echo ""
echo "Library coordinates:"
echo "  Group: com.github.lmjoshi-mp.Carnival-SDK"
echo "  Artifact: shared"
echo "  Version: 1.0.0"
echo ""
echo "To use in another project:"
echo "  repositories {"
echo "    maven {"
echo "      url = uri(\"https://maven.pkg.github.com/lmjoshi-mp/Carnival-SDK\")"
echo "      credentials {"
echo "        username = System.getenv(\"GITHUB_ACTOR\") ?: \"username\""
echo "        password = System.getenv(\"GITHUB_TOKEN\") ?: \"token\""
echo "      }"
echo "    }"
echo "  }"
echo "  dependencies {"
echo "    implementation \"com.github.lmjoshi-mp.Carnival-SDK:shared:1.0.0\""
echo "  }"

