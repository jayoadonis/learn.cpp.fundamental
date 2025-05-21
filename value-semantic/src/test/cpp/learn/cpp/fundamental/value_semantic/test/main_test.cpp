

#include "learn/cpp/fundamental/value_semantic/test/copy_semantic/demo_i/PersonTest.h"
#include "learn/cpp/fundamental/value_semantic/test/copy_semantic/demo_ii/PersonTest.h"



int main(int arg_c, char** arb_v) {

    using namespace learn::cpp::fundamental::value_semantic;

    test::copy_semantic::demo_i::PersonTest::run();

    test::copy_semantic::demo_ii::PersonTest::run();

    return 0;
}