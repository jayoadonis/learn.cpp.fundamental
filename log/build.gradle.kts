

plugins {

    id("cpp-library");
    id("cpp-unit-test");
    id("maven-publish");
}

project.version = "0.0.0";
project.group = "learn.cpp.fundamental";

project.toolChains {

    withType<VisualCpp>().configureEach {
        
        // setInstallDir("C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\xyz");
    }

    withType<Gcc>().configureEach {

        // path( file("/usr/local/gcc/bin") );
    }

    withType<Clang>().configureEach {

        // path( file("/opt/clang/bin") );
    }

}

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

    binaries.configureEach { 

        //REM: nope not working...
        // toolChain.set(toolChains.named<Gcc>("gcc"))
        // toolChain.set(toolChains.named<Clang>("clang"))
        // toolChain.set(project.toolChains.named<VisualCpp>("visualCpp"))
    }
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

    //REM: nope not working...
    // toolChain.set( project.toolChains.named("gcc") );

    val commonArgs: Provider<List<String>> = toolChain.map { tc -> when (tc) {
        is Gcc, is Clang ->
            listOf( "-std=c++17");
        is VisualCpp ->
            listOf( "/std:c++17", "/EHsc", /* "/Zc:__cplusplus" */ );
        else ->
            throw GradleException( "Unsupported compiler: $tc" );
    }}

    compilerArgs.addAll( commonArgs );

    if( name.contains( "debug", true ) ||
        name.contains( "test", true )
    ) {

        compilerArgs.addAll(
            toolChain.map { tc -> 
                when( tc ) {
                    is Gcc, is Clang -> listOf(
                        "-D__NO_LOG_DEMO_I_NEW_DELETE_LOG",
                        "-D__NO_LOG_DEMO_II_NEW_DELETE_LOG",
                        "-D__NO_LOG_DEMO_III_NEW_DELETE_LOG",
                        "-D__NO_LOG_DEMO_IV_NEW_DELETE_LOG",
                        "-D__NO_DEMO_MACRO_LOG"
                    );
                    is VisualCpp -> listOf(
                        "/D__NO_LOG_DEMO_I_NEW_DELETE_LOG",
                        "/D__NO_LOG_DEMO_II_NEW_DELETE_LOG",
                        "/D__NO_LOG_DEMO_III_NEW_DELETE_LOG",
                        "/D__NO_LOG_DEMO_IV_NEW_DELETE_LOG",
                        "/D__NO_DEMO_MACRO_LOG"
                    );
                    else -> listOf("");
                }
            }
        )
    }
    else {

        compilerArgs.addAll(
            toolChain.map { tc -> 
                when( tc ) {
                    is Gcc, is Clang -> listOf(
                        "-D__NO_LOG_DEMO_I_NEW_DELETE_LOG",
                        "-D__NO_LOG_DEMO_II_NEW_DELETE_LOG",
                        "-D__NO_LOG_DEMO_III_NEW_DELETE_LOG",
                        "-D__NO_LOG_DEMO_IV_NEW_DELETE_LOG",
                        "-D__NO_DEMO_MACRO_LOG"
                    );
                    is VisualCpp -> listOf(
                        "/D__NO_LOG_DEMO_I_NEW_DELETE_LOG",
                        "/D__NO_LOG_DEMO_II_NEW_DELETE_LOG",
                        "/D__NO_LOG_DEMO_III_NEW_DELETE_LOG",
                        "/D__NO_LOG_DEMO_IV_NEW_DELETE_LOG",
                        "/D__NO_DEMO_MACRO_LOG"
                    );
                    else -> listOf("");
                }
            }
        )
    }
}

project.tasks.withType<RunTestExecutable>().configureEach {

    args?.clear();
    args( "all" );
}