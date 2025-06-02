
#include <iostream>
#include <new>
#include <cstdio>

#include "learn/cpp/fundamental/misc/util/alloc_dealloc_log_iii.h"

#include "learn/cpp/fundamental/log/demo_i/new_delete_log.h"
 
// void * operator new( std::size_t size ) {

//     void * ptr = std::malloc( size );

//     if( !ptr ) throw std::bad_alloc(); 

//     std::printf("<><><> %s, %zu, %p\n", "new", size, ptr );

//     return ptr;
// }

// void operator delete( void * ptr ) noexcept {

//     std::printf("<><><> %s, %p\n", "free", ptr );

//     std::free( ptr );
// }

int main(int arg_c, char** arg_v) {

    // std::cout << "what..." << std::endl;
 
    // std::printf("<> what.\n");

    char * c = new char[]{'c','h','\0'};

    delete[] c;
    c = nullptr;

    return 0;
} 