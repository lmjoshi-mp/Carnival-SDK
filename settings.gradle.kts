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
        maven("https://maven.pkg.github.com/REPLACE_WITH_GITHUB_USERNAME/Carnival-SDK") {
            credentials {
                username = System.getenv("GITHUB_ACTOR") ?: project.findProperty("gpr.user") as String?
                password = System.getenv("GITHUB_TOKEN") ?: project.findProperty("gpr.key") as String?
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
