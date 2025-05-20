import java.io.File;
import java.util.Properties;

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

    val learnCPPFundamentalProjectEnvProp : String = settings.providers
        .gradleProperty("learnCPPFundamentalProjectEnvProp")
        .getOrElse("debug")
        .trim()
        .lowercase();
    
    val isDebug: Boolean = learnCPPFundamentalProjectEnvProp == "debug";

    val loadEnvs = when {
        !isDebug -> loadEnv("./.env.prod");
        else -> loadEnv();
    }

    loadEnvs.forEach { (key, value) -> 
        rootProject.extra.set(key, value);
    }
        
}

fun loadEnv( filepath: String = "./.env.dev" ): Map<String, String> {

    val PROPS: Properties = Properties();
    val FILEPATH: File = File(filepath);

    if( FILEPATH.exists() ) {
        FILEPATH.inputStream().use { line -> 
            PROPS.load( line );
        }
    }
    else throw GradleException("Filepath not found: '$filepath'.");

    return PROPS.map{
        it.key.toString() to it.value.toString()
    }.toMap();
}