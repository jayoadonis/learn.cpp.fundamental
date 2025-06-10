
#ifndef __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_IV_ASSERT_H
#define __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_IV_ASSERT_H

#include <cstdio>
#include <sstream>
#include <string>
#include <chrono>
#include <type_traits>
#include <iostream>
#include <iomanip>

#include <mutex>
#include <atomic>
#include <queue>

namespace learn::cpp::fundamental
::log
::demo_iv {

#define __TRACE_INFO "---"

    struct AssertLoggerThreadSafe {

        private: std::mutex                         mutualExclusion;
        private: std::condition_variable            condVar;
        private: std::thread                        threadWorker;
        private: std::queue<std::string>            logStringQueue;
        public: static std::atomic<unsigned int>    ASSERT_ERR_COUNTER;
        private: bool                               isDone;

        private: explicit AssertLoggerThreadSafe();
        private: explicit AssertLoggerThreadSafe(
            AssertLoggerThreadSafe const &
        ) = delete;

        protected: virtual ~AssertLoggerThreadSafe();

        public: static AssertLoggerThreadSafe& getInstance() {

            static AssertLoggerThreadSafe assertThreadSafe;

            return assertThreadSafe;
        }

        public: void shutdown();
        public: void enqueue(
            std::string const & logString
        );
        public: void run();

        public: virtual AssertLoggerThreadSafe& operator =( 
            AssertLoggerThreadSafe const &
        ) = delete; 

    };

    inline std::atomic<unsigned int> AssertLoggerThreadSafe::ASSERT_ERR_COUNTER{0};

    inline std::string current_timestamp() {

        using namespace std::chrono;

        time_point<system_clock> now = std::move( system_clock::now() );
        long long time_t = system_clock::to_time_t( std::move( now ) );

        std::tm tm;

        #if defined(_WIN32) || defined(_WIN64 )

            localtime_s( &tm, &time_t );
        #elif defined(__linux__) || defined(__GNUC__)

            localtime_r( &time_t, &tm );
        #else 

            //REM: throw an exception...
        #endif

        char result_buff_tm[64];

        std::strftime( 
            result_buff_tm, sizeof(result_buff_tm), 
            "%Y-%m-%d %I:%M:%S %p", 
            &tm 
        );

        return std::string( result_buff_tm );
    }

    inline void assert_logger_thread_safe(
        bool condition,
        char const * tag,
        char const * msg_err,
        char const * msg_assert,
        char const * trace_info
    ) {

        #ifndef __NO_LOG_DEMO_IV_ASSERT

            if( !condition ) {
                AssertLoggerThreadSafe::ASSERT_ERR_COUNTER.fetch_add(
                    1, std::memory_order_relaxed
                );
            }

            std::ostringstream ossLog;

            ossLog << "["
                << std::move( current_timestamp() )
                << "]"
                << " ["
                << std::setw(8)
                << std::left
                << ((condition)? "OK" : "NOPE")
                << std::right
                << " ]: "
                << tag
                << ", "
                << ((condition)? ((msg_assert)? msg_assert : "---") : ((msg_err)? msg_err : "---"))
                << "; "
                << trace_info;

            AssertLoggerThreadSafe::getInstance().enqueue( ossLog.str() );
        
        #endif

        return;
    }

/*
    template<typename... Ts>
    inline void assert_logger_thread_safe_f(
        bool condition,
        char const * fmt,
        Ts&&... args
    ) {

        if constexpr (!__NO_LOG_DEMO_IV_ASSERT) {

            if( __builtin_expect( !condition, 0 ) ) {

                char buf_error[256]; //REM: Dangling ptr may appear...
                std::snprintf(
                    buf_error,
                    sizeof(buf_error),
                    fmt,
                    std::forward<Ts>(args)...
                );

                assert_logger_thread_safe(
                    condition,
                    nullptr,
                    buf_error, //REM: Dangling ptr may appear...
                    nullptr,
                    __TRACE_INFO
                );
            }
        }
    }
*/

} //REM: END; learn::cpp::fundamental::log::demo_iv

    #ifndef __NO_LOG_DEMO_IV_ASSERT
        #define __LOG_DEMO_IV_ASSERT( cond, tag, msg_err, msg_assert )      \
            do {                                                            \
                learn::cpp::fundamental::log::demo_iv::assert_logger_thread_safe(  \
                    cond,                                                   \
                    tag,                                                    \
                    msg_err, msg_assert,                                    \
                    __TRACE_INFO                                     \
                );                                                           \
            } while( 0 ) 
            /*REM: END; __LOG_DEMO_IV_ASSERT( cond, tag, msg_err, msg_assert )*/
    #else
        #define __LOG_DEMO_IV_ASSERT( cond, tag, msg_err, msg_assert )
    #endif 

#endif //REM: END; __LEARN_CPP_FUNDAMENTAL_LOG_DEMO_IV_ASSERT_H
