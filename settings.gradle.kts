rootProject.name = "CarnivalSDK"

pluginManagement {
    repositories {
        google()
        gradlePluginPortal()
        mavenCentral()
    }
}

dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositories {
        google()
        mavenCentral()
        maven("https://jitpack.io")
        maven("https://maven.pkg.github.com/lmjoshi-mp/Carnival-SDK") {
            credentials {
                username = System.getenv("GITHUB_ACTOR") ?: providers.gradleProperty("gpr.user").getOrNull()
                password = System.getenv("GITHUB_TOKEN") ?: providers.gradleProperty("gpr.key").getOrNull()
            }
        }
    }
}

include(":sample-android-app")

val useLocalShared = providers.gradleProperty("useLocalShared")
    .map { it.toBoolean() }
    .orElse(false)
    .get()

if (useLocalShared) {
    include(":shared")
}
