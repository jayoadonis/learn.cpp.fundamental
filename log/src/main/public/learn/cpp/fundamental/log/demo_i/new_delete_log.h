

#ifndef __NO_LOG_DEMO_I_NEW_DELETE_LOG

#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I_NEW_DELETE_LOG_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I_NEW_DELETE_LOG_H

#include <cstddef>
#include <memory>

void * operator new( std::size_t size );

void operator delete( void * ptr ) noexcept;

#endif
#endif