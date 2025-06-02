
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_COPY_MOVE_DEMO_II_PERSON_TEST_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_COPY_MOVE_DEMO_II_PERSON_TEST_H

#include "learn/cpp/fundamental/value_semantic/copy_move/demo_ii/Person.h"
#include <iostream>

namespace learn::cpp::fundamental::value_semantic::test::copy_move::demo_ii {

    struct PersonTest {

        private: explicit PersonTest() = default;

        public: static void run() {

            PersonTest personTest;

            personTest.testI();
        }

        private: void testI() const {
            
            std::printf("%s\n", "=== copy_move/demo_ii/Person.h, testI(V)V ===");

            using namespace learn::cpp::fundamental;

            // value_semantic::copy_move::demo_ii::Person person;
 
            std::string * x = new std::string[]{ "what", "now"};

            delete[] x;
            x = nullptr;

            // value_semantic::copy_move::demo_ii::Person personII("asdf","asdf","sadf",0);


            value_semantic::copy_move::demo_ii::Person * personW = 
                new value_semantic::copy_move::demo_ii::Person();

            delete personW;
            personW = nullptr;


            std::string * y = new std::string("y-str");

            delete y;
            y = nullptr;


        }

    };
}


#endif