
#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_TEST_DEMO_IV_ASSERT_TEST_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_TEST_DEMO_IV_ASSERT_TEST_H

#include "learn/cpp/fundamental/log/demo_iv/assert.h"
#include <thread>

using namespace learn::cpp::fundamental;

namespace learn::cpp::fundamental::log::test::demo_iv {

    struct AssertTest {

        private: explicit AssertTest() = default;

        public: virtual ~AssertTest() = default;

        public: static void run() {

            AssertTest assertTest;

            assertTest.testI();
        }

        private: void testI() {


            std::thread t1( []()->void{
                __LOG_DEMO_IV_ASSERT(
                    true,
                    "tag z 2",
                    "msg err z 2",
                    "msg assert z 2"
                );
            });
            
            __LOG_DEMO_IV_ASSERT(
                true,
                "tag z 1",
                "msg err z 1",
                nullptr
            );

            __LOG_DEMO_IV_ASSERT(
                true,
                "tag z 3",
                "msg err z 3",
                "msg assert z 3"
            ); 

            t1.join();

            log::demo_iv::AssertLoggerThreadSafe::getInstance().shutdown();
        }
    };
}

#endif