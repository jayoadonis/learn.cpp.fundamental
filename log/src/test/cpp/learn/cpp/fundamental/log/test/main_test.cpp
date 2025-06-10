

#include "learn/cpp/fundamental/log/demo_i/new_delete_log.h"
#include "learn/cpp/fundamental/log/demo_ii/new_delete_log.h"
#include "learn/cpp/fundamental/log/demo_iii/new_delete_log.h"
#include "learn/cpp/fundamental/log/demo_iv/new_delete_log.h"

#include "learn/cpp/fundamental/log/test/demo_iv/MacroLogTest.h" 
#include "learn/cpp/fundamental/log/test/demo_iv/AssertTest.h" 

#include <functional>
#include <algorithm>
#include <cctype>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <exception>

using namespace learn::cpp::fundamental;

typedef std::function<void(void)> TestActionFunc;

inline constexpr unsigned int hash( char const * c_str ) {
    
    unsigned int h = 0;

    while ( *c_str ) {
        h = h * 31u + static_cast<unsigned int>(*c_str++);
    }

    return h;
}

std::string sv_to_lowercase_str_copy( std::string_view sv ) {

    std::string result;
    result.reserve( sv.size() );
    std::transform(
        sv.begin(), sv.end(),
        std::back_inserter( result ),
        [](unsigned char ch) -> char { 

            return static_cast<char>(std::tolower( ch ) );
        }
    );

    return result;
}

template <std::size_t N>
inline std::array<char, N> c_str_to_lowercase_a(char const (&input)[N]) {
    std::array<char, N> result{};
    for (std::size_t i = 0; i < N; ++i) {
        result[i] = static_cast<char>(
            (input[i] >= 'A' && input[i] <= 'Z') ? input[i] + ('a' - 'A') : input[i]
        );
    }
    return result;
}

char const * c_str_to_lowercase_c_str(const char * s) {
    static char buffer[256]; 
    std::size_t i = 0;
    while (s[i] && i < sizeof(buffer) - 1) {
        buffer[i] = static_cast<char>(
            (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + ('a' - 'A') : s[i]
        );
        ++i;
    }
    buffer[i] = '\0';
    return buffer;
}

inline constexpr bool equals_ignore_case(char const * x, char const * y) {

    while (*x && *y) {
        char ch_x = (*x >= 'A' && *x <= 'Z') ? *x + ('a' - 'A') : *x;
        char ch_y = (*y >= 'A' && *y <= 'Z') ? *y + ('a' - 'A') : *y;
        if (ch_x != ch_y) return false;
        ++x;
        ++y;
    }
    return *x == *y;
}

int main( int arg_c, char** arg_v ) {

    if( arg_c < 2 || arg_c > 2 ) {

        std::printf("Usage: %s [all|one|two|three|...]\n", arg_v[0]);
        return -1;
    }

    std::vector< 
        std::pair< std::string, TestActionFunc > 
    > test_actions = {
        {"one", static_cast<TestActionFunc>(&log::test::demo_iv::AssertTest::run) },
        {"two", []()->void{ std::printf("%s\n", "test_two running..."); } }
    };

    if ( equals_ignore_case(arg_v[1], "all") ) {

        for(
            std::size_t i = 0;
            i < test_actions.size();
            ++i
        ) {

            std::string const & name = test_actions[i].first;
            TestActionFunc const & func = test_actions[i].second;

            std::printf("::: %s\n", name.c_str() );

            func();
        }
    }
    else {

        std::vector<
            std::pair< std::string, TestActionFunc>
        >::iterator ptr_itr = 
            std::find_if(
                test_actions.begin(),
                test_actions.end(),
                [&arg_v]( std::pair< std::string, TestActionFunc> const & p ) -> bool {

                    return (p.first == arg_v[1] );
                }
            );
        
        if( ptr_itr != test_actions.end() ) {

            std::pair<std::string, TestActionFunc>& p = *ptr_itr;

            std::string const & name = p.first;
            TestActionFunc const & func = p.second;

            std::printf("::: %s\n", name.c_str() );

            func();
        }
        else {

            std::printf( "Invalid args: '%s'.", arg_v[1] );
            return -1;
        }
    }

    // switch( hash(arg_v[1]) ) {
    //     case hash("one"):
    //         log::test::demo_iv::AssertTest::run();
    //         break;
    //     case hash("two"):
    //         break;
    //     case hash("three"):
    //         break;
    //     default:
    //         std::printf("Invalid args: '%s'. All exhausted.\n", arg_v[1]);
    // }


    return log::demo_iv::AssertLoggerThreadSafe::ASSERT_ERR_COUNTER;
}
