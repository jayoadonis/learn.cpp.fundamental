

#include "learn/cpp/fundamental/log/demo_i/new_delete_log.h"
#include "learn/cpp/fundamental/log/demo_ii/new_delete_log.h"
#include "learn/cpp/fundamental/log/demo_iii/new_delete_log.h"
#include "learn/cpp/fundamental/log/demo_iv/new_delete_log.h"


#include <cstdio>
#include <new>

int main( int arg_c, char** arg_v ) {

    std::printf( "%s\n", "hi there.");

    int * x = new (std::nothrow) int(0);

    delete x;
    x = nullptr;

    char * ch_seq = new (std::nothrow) char[]{ 'c', 'h', 'S','e','q', '\0'};

    delete[] ch_seq;
    ch_seq = nullptr;

    return 0;
}