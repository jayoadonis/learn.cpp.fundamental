
#include <iostream>
#include <cstdio>

// #include "learn/cpp/fundamental/misc/util/alloc_dealloc_log_iii.h"
#include "learn/cpp/fundamental/log/demo_i/new_delete_log.h" 
#include "learn/cpp/fundamental/log/demo_ii/new_delete_log.h" 
#include "learn/cpp/fundamental/log/demo_iii/new_delete_log.h" 
#include "learn/cpp/fundamental/log/demo_iv/new_delete_log.h" 


#include "learn/cpp/fundamental/value_semantic/test/copy_semantic/demo_ii/PersonTest.h"

using namespace learn::cpp::fundamental::value_semantic;

int main(int arg_c, char** arg_v) {

    // std::cout << "::: BEGIN." << ((void*)static_cast<int(*)(int,char**)>(main)) << std::endl;

    std::printf("::: %-15s 0x%p\n", "BEGIN (main)", (void*)static_cast<int(*)(int,char**)>(main) );  

    char * c = new char[]{'c','h', 'a', 'r', '\0'};

    // std::cout << "::: " << std::dec << static_cast<int>(c[0]) << " adfa\n";

    std::printf( "print (char*[]): '%s'\n", c );

    delete[] c;
    c = nullptr;

    int * i = new int(2);

    std::printf( "print (int): %d\n", *i );

    delete i;
    i = nullptr;

    test::copy_semantic::demo_ii::PersonTest::run();

    // std::cout << "::: END (main)." << ((void*)main) << std::endl;

    std::printf("::: %-15s 0x%p\n", "END (main)", (void*)static_cast<int(*)(int,char**)>(main) );  

    return 0;
} 