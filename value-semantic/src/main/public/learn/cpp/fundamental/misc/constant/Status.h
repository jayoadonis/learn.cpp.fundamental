
#ifndef __LEARN_CPP_FUNDAMENTAL_MISC_CONSTANT_STATUS_H
#define __LEARN_CPP_FUNDAMENTAL_MISC_CONSTANT_STATUS_H

#include <array>

namespace learn::cpp::fundamental
::misc::constant {

    struct Status {

        public: static Status const NA;
        public: static Status const UNK;
        public: static Status const CRT;
        public: static Status const RDY;
        public: static Status const WTG;
        public: static Status const STG;
        public: static Status const RUN;
        public: static Status const STP;
        public: static Status const PAU;
        public: static Status const IDL;
        public: static Status const TMD;
        public: static Status const TMO;

        private: explicit Status(
            unsigned int const ordinal,
            char const * symbol,
            char const * name
        ) : ordinal( ordinal ),
            symbol( symbol ),
            name( name )
        { }

        public: char const * const name;
        public: char const * const symbol;
        public: unsigned int const ordinal;
        #define __YIKES_COUNT 10
        public: static unsigned int const COUNT; 
        public: static std::array<Status const * const, __YIKES_COUNT> const VALUES;
    };

    unsigned int const Status::COUNT = __YIKES_COUNT;

    Status const Status::NA(0, "N/a", "NOT_APPLICABLE");
    Status const Status::UNK(1, "UNK", "UNKNOWN");
    Status const Status::CRT(2, "CRT", "CREATE");
    Status const Status::RDY(3, "RDY", "READY");
    Status const Status::WTG(4, "WTG", "WAITING");
    Status const Status::RUN(5, "RUN", "RUNNING");
    Status const Status::STP(6, "STP", "STOPPING");
    Status const Status::IDL(7, "IDL", "IDLE");
    Status const Status::TMD(8, "TMD", "TERMINATED");
    Status const Status::TMO(9, "TMO", "TIMEOUT");

    std::array<Status const * const, Status::COUNT> const Status::VALUES = {{
        &Status::NA,
        &Status::UNK,
        &Status::CRT,
        &Status::RDY,
        &Status::WTG,
        &Status::RUN,
        &Status::STP,
        &Status::IDL,
        &Status::TMD,
        &Status::TMO,
    }};
}

#endif