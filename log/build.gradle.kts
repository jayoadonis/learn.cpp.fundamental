
plugins {

    id("cpp-library");
    id("cpp-unit-test");
    id("maven-publish");
}

project.version = "0.0.0";
project.group = "learn.cpp.fundamental";

project.library {

    linkage.set(
        listOf( Linkage.STATIC )
    );

    targetMachines.set(
        listOf( 
            machines.windows.x86_64,
            machines.linux.x86_64
        )
    );
}

project.unitTest {
    
    baseName.set("${project.name}_test");

}

project.publishing {

    repositories {

        maven {

            name = "local"
            url = uri( "${project.rootDir}/.local_repo" );
        }
    }
}

project.tasks.withType<CppCompile>().configureEach {

    compilerArgs.addAll( toolChain.map { tc ->
        when( tc ) {
            is Gcc, is Clang -> listOf(
                "-std=c++17"
            );
            is VisualCpp -> listOf(
                "/std=c++17"
            );
            else -> throw GradleException("Unsupported compiler: '$tc'.");
        }
    });

    if( name.contains( "debug", true ) ||
        name.contains( "test", true )
    ) {

    }
    else {

        compilerArgs.addAll(
            toolChain.map { tc -> 
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
            }
        )
    }
}