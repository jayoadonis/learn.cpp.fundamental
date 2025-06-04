

#include "learn/cpp/fundamental/log/demo_i/new_delete_log.h"
#include "learn/cpp/fundamental/log/demo_ii/new_delete_log.h"
#include "learn/cpp/fundamental/log/demo_iii/new_delete_log.h"
#include "learn/cpp/fundamental/log/demo_iv/new_delete_log.h"

// #include "learn/cpp/fundamental/log/demo_i/macro_log.h"
#include "learn/cpp/fundamental/log/demo_ii/macro_log.h"
#include "learn/cpp/fundamental/log/demo_iii/macro_log.h"

#include <cstdio>
#include <new>

struct StructI {


    public: int memFunc(char**) {
        
        std::printf("<<<< %p\n", this );
        __LCFLDIIM_LOG_MEM_FUNC_SIG( StructI, memFunc, int (StructI::*)(char**), ">>> Hi there:" );

        std::printf( 
            "%s\n", 
            __CPP_LOCATION_FULL_II 
        );

        __DEMO_III_MACRO_LOG_PRINTLN( 
            "taggy", 
            "messagie"
        );

        return 0;
    }
};

void func_one() {

    return;
}

int main( int arg_c, char** arg_v ) {

    std::printf( "%s\n", "hi there.");

    int * x = new (std::nothrow) int(0);

    delete x;
    x = nullptr;

    char * ch_seq = new (std::nothrow) char[]{ 'c', 'h', 'S','e','q', '\0'};

    delete[] ch_seq;
    ch_seq = nullptr;

    
    // __LCFLDIM_LOG_FUNC( func_one, void (*)(), ">>> func_one(V)V" );

    std::printf( "<<< %p\n", (void*)reinterpret_cast<void (*)()>(main) );

    __LCFLDIIM_LOG_MEM_FUNC_SIG( StructI, memFunc, int (StructI::*)(char**), ">>> Hi there:" );
    __LCFLDIIM_LOG_MEM_FUNC_SIG( StructI, memFunc, int (StructI::*)(char**), ">>> Hi there:" );
    __LCFLDIIM_LOG_MEM_FUNC_SIG( StructI, memFunc, int (StructI::*)(char**), ">>> Hi there:" );

    StructI s;
    char* dummyArg[] = { nullptr };
    s.memFunc(dummyArg);

    __DEMO_III_MACRO_LOG_PRINTLN(
        "Tagz", "MsgZ"
    );

    return 0;
}