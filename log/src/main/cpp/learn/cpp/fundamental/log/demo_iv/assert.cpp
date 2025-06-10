

#include "learn/cpp/fundamental/log/demo_iv/assert.h"


namespace learn::cpp::fundamental
::log
::demo_iv {

    AssertLoggerThreadSafe::AssertLoggerThreadSafe()
    :
    isDone( false ),
    threadWorker(
        static_cast<void (AssertLoggerThreadSafe::*)(void)>(&AssertLoggerThreadSafe::run),
        this
    )
    {

    }

    AssertLoggerThreadSafe::~AssertLoggerThreadSafe() {

        this->shutdown();
    }

    void AssertLoggerThreadSafe::shutdown() {

        {
            std::lock_guard<std::mutex> lock( this->mutualExclusion );
            this->isDone = true;
        }

        this->condVar.notify_all();

        if( this->threadWorker.joinable() ) {

            this->threadWorker.join();
        }

        return;
    }

    void AssertLoggerThreadSafe::enqueue( 
        std::string const & logString
    ) {

        {
            std::lock_guard<std::mutex> lock( this->mutualExclusion );
            this->logStringQueue.push( std::move( logString ) );
        }

        this->condVar.notify_one();

        return;
    }

    void AssertLoggerThreadSafe::run() {
            
        std::unique_lock<std::mutex> lock( this->mutualExclusion );
        
        while( true ) {
            this->condVar.wait( 
                lock,
                [this]() -> bool {

                    return this->isDone || !this->logStringQueue.empty();
                } 
            );
            if( this->isDone && this->logStringQueue.empty() ) {

                break;
            }
            while( !this->logStringQueue.empty() ) {

                std::string logString = std::move( this->logStringQueue.front() );
                this->logStringQueue.pop();
                
                lock.unlock();
                
                std::printf(
                    "%s\n", logString.c_str()
                );

                lock.lock();
            }
        }
        
        return;
    }
}