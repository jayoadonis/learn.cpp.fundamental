
#ifndef __NO_LOG_DEMO_I_NEW_DELETE_LOG

#include "learn/cpp/fundamental/log/demo_i/new_delete_log.h"

void * operator new( std::size_t size ) {

    void * ptr = std::malloc( size );

    if( !ptr ) throw std::bad_alloc();

    std::printf( "(%-10s) [%-8zu]@0x%p\n", "new", size, ptr );

    return ptr;
}

void operator delete( void * ptr ) noexcept {

    std::printf( "(%-10s) [%-8s]@0x%p\n", "delete", " ", ptr );

    std::free( ptr );
}

#endif