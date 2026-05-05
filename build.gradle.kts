plugins {
    id("com.android.application") version "8.5.2" apply false
    id("com.android.library") version "8.5.2" apply false
    id("io.github.gradle-nexus.publish-plugin") version "2.0.0"
    id("org.jetbrains.kotlinx.kover") version "0.8.3" apply false
    kotlin("android") version "2.0.21" apply false
    kotlin("plugin.compose") version "2.0.21" apply false
    kotlin("multiplatform") version "2.0.21" apply false
    kotlin("jvm") version "2.0.21" apply false
    kotlin("plugin.serialization") version "2.0.21" apply false
}

nexusPublishing {
    repositories {
        val sonatypeUser = providers.gradleProperty("mavenCentralUsername").orNull
            ?: System.getenv("MAVEN_CENTRAL_USERNAME")
        val sonatypePassword = providers.gradleProperty("mavenCentralPassword").orNull
            ?: System.getenv("MAVEN_CENTRAL_PASSWORD")
        if (!sonatypeUser.isNullOrBlank() && !sonatypePassword.isNullOrBlank()) {
            sonatype {
                nexusUrl.set(uri("https://s01.oss.sonatype.org/service/local/"))
                snapshotRepositoryUrl.set(uri("https://s01.oss.sonatype.org/content/repositories/snapshots/"))
                username.set(sonatypeUser)
                password.set(sonatypePassword)
            }
        }
    }
}
