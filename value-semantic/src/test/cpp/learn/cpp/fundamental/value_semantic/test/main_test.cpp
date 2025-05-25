

#include "learn/cpp/fundamental/value_semantic/test/copy_semantic/demo_i/PersonTest.h"
#include "learn/cpp/fundamental/value_semantic/test/copy_semantic/demo_ii/PersonTest.h"
#include "learn/cpp/fundamental/value_semantic/test/move_semantic/demo_i/PersonTest.h"

#include "learn/cpp/fundamental/misc/constant/Status.h"

#include "learn/cpp/fundamental/misc/util/alloc_dealloc_log.h"

#include <ios>
#include <utility>
#include <cstring>
#include <string>
#include <iostream>
int main(int arg_c, char** arb_v) {

    using namespace learn::cpp::fundamental::value_semantic;

    test::copy_semantic::demo_i::PersonTest::run();

    test::copy_semantic::demo_ii::PersonTest::run();

    test::move_semantic::demo_i::PersonTest::run();

    // using namespace learn::cpp::fundamental::misc;
    
    // std::cout 
    //     << constant::Status::RUN.name
    //     << ", "
    //     << constant::Status::RUN.ordinal
    //     << std::endl;

    // for( constant::Status const * const y : constant::Status::VALUES ) {
        
    //     std::cout 
    //         << "<><><> "
    //         << y->ordinal 
    //         << ", "
    //         << y->symbol
    //         << ", "
    //         << y->name
    //         << std::endl;
    // }

    // constant::Status z = constant::Status::RUN;

    // std::cout << std::boolalpha
    //     << (constant::Status::IDL == constant::Status::UNK )
    //     << std::endl
    //     << (constant::Status::IDL != constant::Status::UNK )
    //     << std::endl
    //     << z.name << ", " << z.symbol << ", " << z.ordinal
    //     << std::endl
    //     // << constant::Status::PAU.name //REM: [FIX]
    //     << std::endl;
    return 0;
}