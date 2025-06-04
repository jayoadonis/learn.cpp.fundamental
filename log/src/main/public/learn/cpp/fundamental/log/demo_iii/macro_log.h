
#ifndef __NO_DEMO_MACRO_LOG

#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_III_MACRO_LOG_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_III_MACRO_LOG_H

#include <cstdio>
#include <cstdint>
#include <array>

// -----------------------------------------------------------------------------
// 1) Small helper to convert a digit‐character ('0'..'9') → integer 0..9,
//    or return an “error” marker (-0x80) if it’s not in that range.
//
//    We return int8_t since the result will always fit (0..9 or error).
constexpr std::int8_t char_to_dec(char ch_digit) {
    return (ch_digit >= '0' && ch_digit <= '9')
           ? static_cast<std::int8_t>(ch_digit - '0')
           : static_cast<std::int8_t>(-0x80);
}

// -----------------------------------------------------------------------------
// 2) Simple struct to hold hours/minutes/seconds as ints.
struct HrMinSec {
    int h, m, s;
};

// -----------------------------------------------------------------------------
// 3) Parse a literal "HH:MM:SS" into an HrMinSec.
//    We assume `t` is exactly 8 characters + '\0'. E.g. "14:23:07".
constexpr HrMinSec parse_time(char const t[9]) {
    return HrMinSec {
        // char_to_dec(t[0]) and t[1] each yield 0..9, so 10*something + something → 0..23
        char_to_dec(t[0]) * 10 + char_to_dec(t[1]),
        char_to_dec(t[3]) * 10 + char_to_dec(t[4]),
        char_to_dec(t[6]) * 10 + char_to_dec(t[7])
    };
}

// -----------------------------------------------------------------------------
// 4) Build a 12‐hour “hh:mm:ss AM/PM” string (length = 11, plus '\0' = 12):
//
//    This is constexpr, so it all happens at compile‐time. We return a
//    std::array<char, 12> containing, for example, "02:23:07 PM\0".
constexpr std::array<char, 12> make_build_time_12() {
    // __TIME__ is a compile‐time literal "HH:MM:SS"
    constexpr char const_time[] = __TIME__; // e.g. "14:23:07"

    constexpr HrMinSec t  = parse_time(const_time);
    constexpr bool    is_pm = (t.h >= 12);
    constexpr int     raw_h = t.h % 12;
    constexpr int     h12   = (raw_h == 0 ? 12 : raw_h);

    std::array<char, 12> out = {};

    // Fill in "hh"
    out[0] = static_cast<char>('0' + (h12 / 10));
    out[1] = static_cast<char>('0' + (h12 % 10));
    out[2] = ':';

    // Fill in "mm"
    out[3] = static_cast<char>('0' + (t.m / 10));
    out[4] = static_cast<char>('0' + (t.m % 10));
    out[5] = ':';

    // Fill in "ss"
    out[6] = static_cast<char>('0' + (t.s / 10));
    out[7] = static_cast<char>('0' + (t.s % 10));
    out[8] = ' ';

    // Fill in "AM" or "PM"
    out[9]  = (is_pm ? 'P' : 'A');
    out[10] = 'M';

    // Null‐terminate
    out[11] = '\0';

    return out;
}

// -----------------------------------------------------------------------------
// 5) Store the 12‐hour array in a named constexpr. This ensures it’s not a
//    temporary, so its .data() pointer remains valid at runtime.
inline constexpr std::array<char, 12> BUILD_TIME_12_ARRAY = make_build_time_12();

// Now expose a `const char*` to that array’s data:
inline constexpr const char* BUILD_TIME_12_CSTR = BUILD_TIME_12_ARRAY.data();

// -----------------------------------------------------------------------------
// 6) Example macro that uses BUILD_TIME_12_CSTR. In your code, you can write
//    printf("%s\n", BUILD_TIME_12_CSTR); or std::cout << BUILD_TIME_12_CSTR << "\n";
#define __CPP_TIMESTAMP_12 BUILD_TIME_12_CSTR

//REM: Detect operating system:
#if defined(_WIN32) || defined(_WIN64)
  #define __CPP_OS_NAME  "Windows"
#elif defined(__APPLE__) && defined(__MACH__)
  #define __CPP_OS_NAME  "macOS"
#elif defined(__linux__)
  #define __CPP_OS_NAME  "Linux"
#elif defined(__unix__)
  #define __CPP_OS_NAME  "Unix"
#else
  #define __CPP_OS_NAME  "UnknownOS"
#endif

//REM: Detect CPU architecture:
#if defined(_M_X64) || defined(__x86_64__) 
  #define __CPP_ARCH  "x86_64"
#elif defined(_M_IX86) || defined(__i386__)
  #define __CPP_ARCH  "x86"
#elif defined(_M_ARM64) || defined(__aarch64__)
  #define __CPP_ARCH  "ARM64"
#elif defined(_M_ARM)   || defined(__arm__)
  #define __CPP_ARCH  "ARM"
#elif defined(__powerpc64__) || defined(__ppc64__)
  #define __CPP_ARCH  "PPC64"
#elif defined(__powerpc__)   || defined(__ppc__)
  #define __CPP_ARCH  "PPC"
#else
  #define __CPP_ARCH  "UnknownArch"
#endif

//REM: Combine OS + ARCH into one macro:
#define __CPP_PLATFORM  __CPP_OS_NAME "/" __CPP_ARCH

//REM: Some of the standard preprocessor:
#define __CPP_FILE  __FILE__
#define __CPP_LINE  __LINE__

/** 
 * Plain function‐name macro (always C++11‐compliant):
 * __func__ is guaranteed by C++11.  Note: on GCC/Clang, __func__ is
 * just the unadorned function name (no parameters), whereas __PRETTY_FUNCTION__
 * includes return type and full signature.
 */
#if defined(__cplusplus) && (__cplusplus >= 201103L)
  #define __CPP_FUNC_NAME  __func__
#else
  //REM: As a fallback in pre-C++11 modes, some compilers still define __FUNCTION__.
  #if defined(__FUNCTION__)
    #define __CPP_FUNC_NAME  __FUNCTION__
  #else
    #define __CPP_FUNC_NAME  "(unknown_function)"
  #endif
#endif

/**
 * MSVC defines __FUNCSIG__, GCC & Clang define __PRETTY_FUNCTION__.
 * Intel (ICC) on Linux also defines __PRETTY_FUNCTION__.  Fall back to __func__.
 */
#if defined(_MSC_VER)
  //REM: Microsoft Visual C++: __FUNCSIG__ includes return type, calling convention, etc.
  #define __CPP_FUNC_SIG  __FUNCSIG__
#elif defined(__clang__) || defined(__GNUC__) || defined(__ICC) || defined(__INTEL_COMPILER)
  //REM: GCC, Clang, Intel: __PRETTY_FUNCTION__ gives a “pretty” human-readable signature
  #define __CPP_FUNC_SIG  __PRETTY_FUNCTION__
#else
  //REM: If none of the above, just use __func__; you lose parameter types but at least
  //REM: you still get the correct function name.
  #define __CPP_FUNC_SIG  __CPP_FUNC_NAME
#endif

//REM: Convert decimal/int to string (Stringifying)
#define __CPP_STRINGIFY_IMPL(x)  #x
#define __CPP_STRINGIFY(x)       __CPP_STRINGIFY_IMPL(x)

#define __CPP_LOCATION_STRING  __CPP_FILE ":" __CPP_STRINGIFY(__CPP_LINE) ": " __CPP_FUNC_SIG

//REM: Build date and time (these are standard macros in all C/C++ compilers):
#define __CPP_BUILD_DATE   __DATE__     //REM: ex: "MM  DD YYYY"
#define __CPP_BUILD_TIME   __TIME__     //REM: ex: "hh:mm:ss"

//REM: Timestamp
#define __CPP_BUILDSTAMP   __CPP_BUILD_DATE " " __CPP_BUILD_TIME

// If you want to include the host OS or compiler version, you can do things like:
#if defined(_MSC_VER)
  #define __CPP_COMPILER  "MSVC " __CPP_STRINGIFY(_MSC_VER)
#elif defined(__clang__)
  #define __CPP_COMPILER  "Clang " __clang_version__
#elif defined(__GNUC__)
  #define __CPP_COMPILER  "GCC " __CPP_STRINGIFY(__GNUC__) "." __CPP_STRINGIFY(__GNUC_MINOR__)
#else
  #define __CPP_COMPILER  "UnknownCompiler"
#endif

//REM: c-string way of more info
#define __CPP_LOCATION_FULL \
    "[" __CPP_PLATFORM "] " \
    "[" __CPP_COMPILER "] " \
    "[" __CPP_BUILDSTAMP "] " \
    "[" __CPP_FILE ":" __CPP_STRINGIFY(__CPP_LINE) "] " \
    __CPP_FUNC_SIG

inline thread_local static char _cpp_loc_buf[1024];
inline static char const * _format_i = "[%-15s] [%-15s] [%13s %12s]: %s, %s; [%s:%d] %s\n";
inline static char const * _format_ii = "[%-15s] [%-15s] [%13s %12s] [%s:%d] %s";

#define __CPP_LOCATION_FULL_II \
    (                                           \
        std::snprintf(                          \
            _cpp_loc_buf, sizeof(_cpp_loc_buf), \
            _format_ii,                         \
            __CPP_PLATFORM,                     \
            __CPP_COMPILER,                     \
            __CPP_BUILD_DATE, __CPP_TIMESTAMP_12,   \
            __CPP_FILE,                         \
            __CPP_LINE,                         \
            __CPP_FUNC_SIG                      \
        ),                                      \
        _cpp_loc_buf                            \
    )

//REM: print linefeed of more info
#define __DEMO_III_MACRO_LOG_PRINTLN(tag, msg)      \
    std::printf(                                    \
        _format_i,                                   \
        __CPP_PLATFORM,                             \
        __CPP_COMPILER,                             \
        __CPP_BUILD_DATE, __CPP_TIMESTAMP_12,                           \
        tag, msg,                                   \
        __CPP_FILE, __CPP_LINE,                     \
        __CPP_FUNC_SIG                              \
    )

#endif

#endif //REM: __NO_DEMO_MACRO_LOG