
plugins {

    id("cpp-library");
    id("cpp-unit-test");
    id("maven-publish");
}

val RAW_OS_FAMILY: String = System.getProperty("os.name")?.toString()
    ?: throw GradleException("Cannot find props 'os.name'");
val OS_FAMILY: String = when {
    RAW_OS_FAMILY.lowercase().contains("win") -> "windows";
    RAW_OS_FAMILY.lowercase().contains("mac") -> "macos";
    RAW_OS_FAMILY.lowercase().contains("nux") ||
        RAW_OS_FAMILY.lowercase().contains("nix") -> "linux";
    else -> throw GradleException("Unsupported Operating System: '$RAW_OS_FAMILY'.");
}

val learnCPPFundamentalProjectGroupProp: String by project;

project.version = "0.0.0";
project.group = learnCPPFundamentalProjectGroupProp;

project.library {

    linkage.set(
        listOf(Linkage.STATIC)
    );

    targetMachines.set(
        listOf(
            machines.windows.x86_64,
            machines.linux.x86_64
        )
    );

}

project.dependencies {

}

project.publishing {

    publications {

        withType<MavenPublication>().configureEach {
            
            pom {
                developers {
                    developer {
                        id.set("jayoadonis");
                        name.set("Jayo, A.R.B.");
                        email.set("jayo.adonisraphael@gmail.com");
                        url.set("www.github.com/jayoadonis/learn.cpp.fundamental");
                    }
                }
            }
        }
    }

    repositories {

        maven {

            name = "local";
            url = uri("./.local_repo");
        }
    }
}

project.tasks.withType<CppCompile>().configureEach {

    compilerArgs.addAll( toolChain.map { tc ->
        when(tc) {
            is Gcc, is Clang -> listOf("-std=c++17");
            is VisualCpp -> listOf("/std:c++17");
            else -> throw GradleException("Unsupported toolchain: '$tc'.");
        }
    });
}