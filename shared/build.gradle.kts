plugins {
    kotlin("multiplatform")
    id("com.android.library")
    id("org.jetbrains.kotlinx.kover")
    kotlin("plugin.serialization")
    id("maven-publish")
}

kotlin {
    jvm {
        compilations.all {
            compileTaskProvider.configure {
                compilerOptions {
                    jvmTarget.set(org.jetbrains.kotlin.gradle.dsl.JvmTarget.JVM_17)
                }
            }
        }
    }
    androidTarget {
        compilations.all {
            compileTaskProvider.configure {
                compilerOptions {
                    jvmTarget.set(org.jetbrains.kotlin.gradle.dsl.JvmTarget.JVM_17)
                }
            }
        }
    }
    iosX64()
    iosArm64()
    iosSimulatorArm64()

    sourceSets {
        commonMain.dependencies {
            implementation("org.jetbrains.kotlinx:kotlinx-coroutines-core:1.8.1")
            implementation("org.jetbrains.kotlinx:kotlinx-serialization-json:1.7.3")
            implementation("org.jetbrains.kotlinx:kotlinx-datetime:0.6.1")
            implementation("io.ktor:ktor-client-core:2.3.12")
            implementation("io.ktor:ktor-client-content-negotiation:2.3.12")
            implementation("io.ktor:ktor-serialization-kotlinx-json:2.3.12")
            implementation("io.ktor:ktor-client-logging:2.3.12")
        }
        androidMain.dependencies {
            implementation("io.ktor:ktor-client-okhttp:2.3.12")
        }
        jvmMain.dependencies {
            implementation("io.ktor:ktor-client-cio:2.3.12")
        }
        iosMain.dependencies {
            implementation("io.ktor:ktor-client-darwin:2.3.12")
        }
        commonTest.dependencies {
            implementation(kotlin("test"))
            implementation("org.jetbrains.kotlinx:kotlinx-coroutines-test:1.8.1")
            implementation("io.ktor:ktor-client-mock:2.3.12")
            implementation("io.ktor:ktor-client-content-negotiation:2.3.12")
            implementation("io.ktor:ktor-serialization-kotlinx-json:2.3.12")
        }
    }
}

android {
    namespace = "com.carnival.sdk"
    compileSdk = 34

    defaultConfig {
        minSdk = 24
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }
}

kover {
    reports {
        filters {
            excludes {
                packages(
                    "com.carnival.sdk.domain.model",
                    "com.carnival.sdk.data.remote.dto",
                    "com.carnival.sdk.data.mapper",
                )
                classes(
                    "com.carnival.sdk.SampleUsageKt",
                    "com.carnival.sdk.SampleUsageKt$*",
                    "com.carnival.sdk.core.network.NetworkModuleKt",
                    "com.carnival.sdk.core.network.NetworkModuleKt$*",
                )
            }
        }

        total {
            xml {
                onCheck = true
            }
            html {
                onCheck = true
            }
            verify {
                rule {
                    minBound(90)
                }
            }
        }
    }
}

publishing {
    publications {
        // Only configure the kotlinMultiplatform publication
        getByName<MavenPublication>("kotlinMultiplatform") {
            artifactId = "shared"
            groupId = "com.github.lmjoshi-mp.Carnival-SDK"
            version = "1.0.0"
        }
    }
    repositories {
        maven {
            name = "GitHubPackages"
            url = uri("https://maven.pkg.github.com/lmjoshi-mp/Carnival-SDK")
            credentials {
                val gprUser = System.getenv("GITHUB_ACTOR")?.takeIf { it.isNotEmpty() }
                    ?: project.findProperty("gpr.user")?.toString()
                    ?: "lmjoshi-mp"

                val gprKey = System.getenv("GITHUB_TOKEN")?.takeIf { it.isNotEmpty() }
                    ?: project.findProperty("gpr.key")?.toString()

                username = gprUser
                password = gprKey
            }
        }
    }
}

// Disable publishing platform-specific variants to GitHub Packages
afterEvaluate {
    tasks.findByName("publishIosArm64PublicationToGitHubPackagesRepository")?.enabled = false
    tasks.findByName("publishIosX64PublicationToGitHubPackagesRepository")?.enabled = false
    tasks.findByName("publishIosSimulatorArm64PublicationToGitHubPackagesRepository")?.enabled = false
    tasks.findByName("publishJvmPublicationToGitHubPackagesRepository")?.enabled = false
}

