

#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_TEST_DEMO_IV_MACRO_LOG_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_TEST_DEMO_IV_MACRO_LOG_H

#include "learn/cpp/fundamental/log/demo_iv/macro_log.h"
#include <cstdio>
#include <iostream>
#include <iomanip>

namespace learn::cpp::fundamental
::log
::test::demo_iv {

    struct MacroLogTest {

        public: explicit MacroLogTest() = default;
        public: virtual ~MacroLogTest() = default;

        public: static void run(void) {

            MacroLogTest macroLogTest;
            macroLogTest.testI();
            
            return;
        }

        private: void testI() const {

            std::printf( ">>> %d\n", log::demo_iv::char_to_dec ( '9' ) );

            return;
        }
    };
}

#endif