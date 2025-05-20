settings.rootProject.name = "fundamental";

settings.include("value-semantic");


pluginManagement {

    repositories {

        maven {

            url = uri("../.local_repo");
        }
        maven {

            url = uri("./.local_repo");
        }

        gradlePluginPortal();
        mavenCentral();
    }
}

dependencyResolutionManagement {

    repositories {

        maven {

            url = uri("../.local_repo");
        }
        maven {

            url = uri("./.local_repo");
        }

        mavenCentral();
    }
}

settings.gradle.beforeProject {


}