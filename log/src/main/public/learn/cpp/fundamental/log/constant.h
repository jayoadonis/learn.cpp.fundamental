#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_CONSTANT_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_CONSTANT_H

#if defined(_MSVC_LANG) && _MSVC_LANG >= 201703L
  //REM: MSVC 15.3+ compiled with /std:c++17 or better
  #define __CPP17_OR_LATER 1

#elif defined(__cplusplus) && __cplusplus >= 201703L
  //REM: GCC, Clang, Intel, older MSVC in /Zc:__cplusplus mode, etc.
  #define __CPP17_OR_LATER 1

#else
  #define __CPP17_OR_LATER 0
#endif

#if __CPP17_OR_LATER
  #define __BEGIN_LEARN_CPP_FUNDAMENTAL_LOG      namespace learn::cpp::fundamental::log {
  #define __END_LEARN_CPP_FUNDAMENTAL_LOG        }

  #define __BEGIN_LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I \
    namespace learn::cpp::fundamental::log::demo_i {
  #define __END_LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I   }
#else
  #define __BEGIN_LEARN_CPP_FUNDAMENTAL_LOG        \
    namespace learn {                            \
        namespace cpp {                            \
            namespace fundamental {                  \
                namespace log {

  #define __END_LEARN_CPP_FUNDAMENTAL_LOG          \
                }                                     \
            }                                       \
        }                                         \
    }

  #define __BEGIN_LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I  \
    __BEGIN_LEARN_CPP_FUNDAMENTAL_LOG             \
        namespace demo_i {

  #define __END_LEARN_CPP_FUNDAMENTAL_LOG_DEMO_I    \
        }                                          \
    __END_LEARN_CPP_FUNDAMENTAL_LOG
#endif //REM: END; __CPP17_OR_LATER

#endif //REM: END; __LEARN_CPP_FUNDAMENTAL_LOG_CONSTANT_H
