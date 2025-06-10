

#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I_MACRO_LOG_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I_MACRO_LOG_H


#define __LCFLDIM_LOG_FUNC(func_name, signature, msg)                 \
    std::printf(                                                      \
        "%s: %s, %p\n",                                               \
        msg,                                                          \
        /* print the mangled name of the function-pointer type: */    \
        typeid(static_cast<signature>(&func_name)).name(),            \
        /* reinterpret_cast to void* just to print the address: */    \
        reinterpret_cast<void*>(                                      \
            static_cast<signature>(&func_name)                        \
        )                                                             \
    )


#define __LCFLDIM_LOG_MEM_FUNC(type, mem_func, signature, msg)        \
    std::printf(                                                      \
        "%s: %s\n",                                                   \
        msg,                                                          \
        typeid(static_cast<signature>(&type::mem_func)).name()        \
    )


#include "learn/cpp/fundamental/log/constant.h"

__BEGIN_LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I 

    double func_one( double x ) {

        return static_cast<double>(x * 2);
    }

    int func_two( double x ) {

        return static_cast<int>(x) * 2;
    }
    
__END_LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I

#endif