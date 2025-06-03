

#ifndef __NO_LOG_DEMO_I_NEW_DELETE_LOG

#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I_NEW_DELETE_LOG_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I_NEW_DELETE_LOG_H

#include <cstddef>
#include <memory>

void * operator new( std::size_t size ) {

    void * ptr = std::malloc( size );

    if( !ptr ) throw std::bad_alloc();

    std::printf( "aaa(%-10s) [%-8zu]@0x%p\n", "new", size, ptr );

    return ptr;
}

void operator delete( void * ptr ) noexcept {

    std::printf( "zzz(%-10s) [%-8s]@0x%p\n", "delete", " ", ptr );

    std::free( ptr );
}

#endif
#endif