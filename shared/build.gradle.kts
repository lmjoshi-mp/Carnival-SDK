plugins {
    kotlin("multiplatform")
    id("com.android.library")
    id("org.jetbrains.kotlinx.kover")
    kotlin("plugin.serialization")
    id("maven-publish")
    signing
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

    // iOS targets with framework configuration
    iosX64 {
        binaries.framework {
            baseName = "CarnivalSDK"
            isStatic = true
        }
    }
    iosArm64 {
        binaries.framework {
            baseName = "CarnivalSDK"
            isStatic = true
        }
    }
    iosSimulatorArm64 {
        binaries.framework {
            baseName = "CarnivalSDK"
            isStatic = true
        }
    }

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
    publications.withType<MavenPublication>().configureEach {
        groupId = (findProperty("group")?.toString() ?: "io.github.lmjoshi-mp")
        version = (findProperty("version")?.toString() ?: project.version.toString())

        if (name == "kotlinMultiplatform") {
            artifactId = "shared"
        }

        pom {
            name.set("Carnival SDK")
            description.set("Kotlin Multiplatform SDK for Carnival applications.")
            url.set("https://github.com/lmjoshi-mp/Carnival-SDK")
            licenses {
                license {
                    name.set("MIT License")
                    url.set("https://opensource.org/licenses/MIT")
                }
            }
            developers {
                developer {
                    id.set("lmjoshi-mp")
                    name.set("Lalit Joshi")
                }
            }
            scm {
                url.set("https://github.com/lmjoshi-mp/Carnival-SDK")
                connection.set("scm:git:git://github.com/lmjoshi-mp/Carnival-SDK.git")
                developerConnection.set("scm:git:ssh://git@github.com/lmjoshi-mp/Carnival-SDK.git")
            }
        }
    }
    repositories {
        val gprUser = System.getenv("GITHUB_ACTOR")?.takeIf { it.isNotEmpty() }
            ?: project.findProperty("gpr.user")?.toString()
            ?: "lmjoshi-mp"
        val gprKey = System.getenv("GITHUB_TOKEN")?.takeIf { it.isNotEmpty() }
            ?: project.findProperty("gpr.key")?.toString()
        if (!gprKey.isNullOrBlank()) {
            maven {
                name = "GitHubPackages"
                url = uri("https://maven.pkg.github.com/lmjoshi-mp/Carnival-SDK")
                credentials {
                    username = gprUser
                    password = gprKey
                }
            }
        }
    }
}

signing {
    val signingKey = findProperty("signingInMemoryKey")?.toString() ?: System.getenv("MAVEN_SIGNING_KEY")
    val signingPassword = findProperty("signingInMemoryKeyPassword")?.toString() ?: System.getenv("MAVEN_SIGNING_PASSWORD")
    val signingKeyId = findProperty("signingInMemoryKeyId")?.toString() ?: System.getenv("MAVEN_SIGNING_KEY_ID")

    if (!signingKey.isNullOrBlank()) {
        useInMemoryPgpKeys(signingKeyId, signingKey, signingPassword)
        sign(publishing.publications)
    }
}

// Task to generate XCFramework for iOS (for Swift Package Manager)
tasks.register("buildXCFramework") {
    description = "Build XCFramework for iOS"
    dependsOn("iosArm64MainBinaries", "iosSimulatorArm64MainBinaries")

    doLast {
        val buildDirLayout = layout.buildDirectory.get().asFile
        val frameworkName = "CarnivalSDK"
        val xcframeworkDir = File(buildDirLayout, "xcframework")
        
        if (xcframeworkDir.exists()) {
            xcframeworkDir.deleteRecursively()
        }
        xcframeworkDir.mkdirs()
        
        // Framework paths for device and simulator
        val deviceFramework = File(buildDirLayout, "bin/iosArm64/releaseFramework/${frameworkName}.framework")
        val simulatorFramework = File(buildDirLayout, "bin/iosSimulatorArm64/releaseFramework/${frameworkName}.framework")

        if (deviceFramework.exists() && simulatorFramework.exists()) {
            val xcframeworkPath = File(xcframeworkDir, "${frameworkName}.xcframework").absolutePath

            val command = arrayOf(
                "bash",
                "-c",
                "xcodebuild -create-xcframework " +
                "-framework ${deviceFramework.absolutePath} " +
                "-framework ${simulatorFramework.absolutePath} " +
                "-output ${xcframeworkPath}"
            )

            val process = Runtime.getRuntime().exec(command)
            val exitCode = process.waitFor()

            if (exitCode == 0) {
                println("✅ XCFramework created successfully at: $xcframeworkPath")
            } else {
                val error = process.errorStream.bufferedReader().readText()
                println("❌ XCFramework creation failed: $error")
            }
        } else {
            println("⚠️ Framework binaries not found.")
            println("   Device: ${deviceFramework.absolutePath} (exists: ${deviceFramework.exists()})")
            println("   Simulator: ${simulatorFramework.absolutePath} (exists: ${simulatorFramework.exists()})")
        }
    }
}
