
#ifndef __NO_LOG_DEMO_III_NEW_DELETE_LOG

#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_III_NEW_DELETE_LOG_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_III_NEW_DELETE_LOG_H

#include <memory>
#include <cstdio>

void * operator new[]( std::size_t size ) {

    void * ptr = std::malloc( size );

    if( !ptr ) throw std::bad_alloc();

    std::printf( "(%-20s) [%-8zu]@0x%p\n", "new[]", size, ptr );

    return ptr;
}

void operator delete[]( void * ptr ) noexcept {

    std::printf( "(%-20s) [%-8s]@0x%p\n", "delete[]", " ", ptr );

    std::free( ptr );

    return;
}

#endif

#endif