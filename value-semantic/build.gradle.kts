import org.yaml.snakeyaml.Yaml;

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
val learnCPPFundamentalStdCPPCompilerArgLinuxProp: String by project;
val learnCPPFundamentalStdCPPCompilerArgWindowsProp: String by project;

project.version = "0.0.0";
project.group = learnCPPFundamentalProjectGroupProp;

project.unitTest {

    // binaries.configureEach { 

    // }

}

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

    // testImplementation( "learn.cpp.fundamental:log:0.0.0:cpp-api-headers@zip" );
    // testImplementation( "learn.cpp.fundamental:log_release_windows:0.0.0@dll" );

    testImplementation(project(":log"));
    // testImplementation( "learn.cpp.fundamental:log:0.0.0" );
}

project.publishing {

    publications {

        withType<MavenPublication>().configureEach {
            
            var devsYamlTxt: String?; 

            try {
                devsYamlTxt = file(
                    "${project.rootDir}/gradle/developers.yml"
                ).readText();
            }
            catch( exc: Exception ) {
                devsYamlTxt = """
                developers:
                    - developer:
                        id: <default>
                        name: <default>
                        email: <default>
                """;
            }

            val devsYamlRoot = Yaml().load<Map<String, Any>>(devsYamlTxt);

            @Suppress("UNCHECKED_CAST")
            val devsYaml = devsYamlRoot["developers"] as? List<Map<String, Map<String, String>>>;

            pom {
                developers {
                    devsYaml?.forEach { entry ->
                        val dev = entry["developer"]!!;
                        developer {
                            id.set(     dev["id"]       ?: "<default>");
                            name.set(   dev["name"]     ?: "<default>");
                            email.set(  dev["email"]    ?: "<default>");
                            url.set(    dev["url"]      ?: "<default>");
                        }
                    }
                }
            }
        }
    }

    repositories {

        maven {

            name = "local";
            url = uri("${project.rootDir}/.local_repo");
        }
    }
}

project.tasks.withType<CppCompile>().configureEach {

    compilerArgs.addAll( toolChain.map { tc ->
        when(tc) {
            is Gcc, is Clang -> listOf(learnCPPFundamentalStdCPPCompilerArgLinuxProp);
            is VisualCpp -> listOf(learnCPPFundamentalStdCPPCompilerArgWindowsProp);
            else -> throw GradleException("Unsupported toolchain: '$tc'.");
        }
    });
    
    compilerArgs.add( toolChain.map { tc ->
        when( tc ) {
            is Gcc, is Clang -> "-D__VALUE_SEMANTIC_NDEBUG"
            is VisualCpp -> "/D__VALUE_SEMANTIC_NDEBUG"
            else -> ""
        }
    });

    if( name.contains("debug", ignoreCase = true) ||
        name.contains("test", ignoreCase = true) 
    ) {

    }
    else {
        
        compilerArgs.addAll( toolChain.map { tc ->
            when( tc ) {
                is Gcc, is Clang -> listOf(
                    "-D__NO_LOG_DEMO_I_NEW_DELETE_LOG",
                    "-D__NO_LOG_DEMO_II_NEW_DELETE_LOG",
                    "-D__NO_LOG_DEMO_III_NEW_DELETE_LOG",
                    "-D__NO_LOG_DEMO_IV_NEW_DELETE_LOG"
                );
                is VisualCpp -> listOf(
                    "/D__NO_LOG_DEMO_I_NEW_DELETE_LOG",
                    "/D__NO_LOG_DEMO_II_NEW_DELETE_LOG",
                    "/D__NO_LOG_DEMO_III_NEW_DELETE_LOG",
                    "/D__NO_LOG_DEMO_IV_NEW_DELETE_LOG"
                );
                else -> listOf("");
            }
            
        });
    }

}