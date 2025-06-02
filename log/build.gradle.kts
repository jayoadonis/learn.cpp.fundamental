
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

}

project.publishing {

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

        compilerArgs.add(
            toolChain.map { tc -> 
                when( tc ) {
                    is Gcc, is Clang -> "-D__NO_LOG_DEMO_I_NEW_DELETE_LOG";
                    is VisualCpp -> "/D__NO_LOG_DEMO_I_NEW_DELETE_LOG";
                    else -> "";
                }
            }
        )
    }
}