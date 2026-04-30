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
