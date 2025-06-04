

#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_II_MACRO_LOG_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_II_MACRO_LOG_H

#include <cstdio>
#include <typeinfo>
#include <cstring>
#include <type_traits>

// Helper that logs any function-pointer or pointer-to-member-function:
template <typename PF>
inline void __lcfldiim_log_any_ptr(const char* msg, PF pf) {
    const char* mangled = typeid(pf).name();
    if constexpr (sizeof(PF) <= sizeof(void*)) {
        // void* raw_addr = nullptr;
        // std::memcpy(&raw_addr, &pf, sizeof(pf));
        std::printf("%s: %s, %p, %p\n", msg, mangled, *&pf, &pf);
    } else {
        std::printf("%s: %s, [pmf too big to cast]\n", msg, mangled);
    }
}

// Macros for overloaded functions/members (you must pass a signature to disambiguate):
#define __LCFLDIIM_LOG_FUNC_SIG(funcName, signature, msg)            \
    do { __lcfldiim_log_any_ptr(msg,                                 \
            static_cast<signature>(&funcName)                       \
        );                                                          \
    } while (0)

#define __LCFLDIIM_LOG_MEM_FUNC_SIG(type, memberName, signature, msg) \
    do { __lcfldiim_log_any_ptr(msg,                                  \
            static_cast<signature>(&type::memberName)                \
        );                                                           \
    } while (0)


#endif