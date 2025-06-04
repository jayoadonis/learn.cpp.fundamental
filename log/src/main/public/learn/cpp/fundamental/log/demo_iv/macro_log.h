

#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_IV_MACRO_LOG_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_IV_MACRO_LOG_H

#include <cstdint>

namespace learn::cpp::fundamental
::log
::demo_iv {

    constexpr std::int8_t char_to_dec( char const ch_digit ) {

        return ( ch_digit >= '0' && ch_digit <= '9' ) 
            ? static_cast<std::int8_t>( ch_digit - '0' )
            : static_cast<std::int8_t>( -0x80 );
    } 
}
#ifndef __NO_DEMO_MACRO_LOG
#endif //REM: __NO_DEMO_MACRO_LOG

#endif