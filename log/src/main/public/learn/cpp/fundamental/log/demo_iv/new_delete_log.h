
#ifndef __NO_LOG_DEMO_IV_NEW_DELETE_LOG

#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_IV_NEW_DELETE_LOG_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_IV_NEW_DELETE_LOG_H

#include <memory>
#include <cstdio>

void * operator new[]( std::size_t size, std::nothrow_t const & ) noexcept {

    void * ptr = std::malloc( size );

    std::printf( "(%-20s) [%-8zu]@0x%p\n", "new[], nothrow_t", size, ptr );

    return ptr;
}

void operator delete[]( void * ptr, std::size_t size ) noexcept {

    std::printf( "(%-20s) [%-8zu]@0x%p\n", "delete[], size_t", size, ptr );

    std::free( ptr );

    return;
}

#endif

#endif