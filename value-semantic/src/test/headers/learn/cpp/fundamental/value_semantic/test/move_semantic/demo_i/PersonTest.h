
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_MOVE_SEMANTIC_DEMO_I_PERSON_TEST_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_MOVE_SEMANTIC_DEMO_I_PERSON_TEST_H

#include <cassert>
#include <iostream>
#include <utility>
#include "learn/cpp/fundamental/value_semantic/move_semantic/demo_i/Person.h"

namespace learn::cpp::fundamental
::value_semantic
::test::move_semantic::demo_i {


    struct PersonTest {

        private: explicit PersonTest() = default;
        public: virtual ~PersonTest() = default;

        public: static void run() {

            PersonTest personTest{};
            personTest.testI();
            personTest.testII();

        }

        //REM: 
        private: virtual void testI() const {

            std::cout << "==== default ctor === " << std::endl;

            using namespace learn::cpp::fundamental;

            value_semantic::move_semantic::demo_i::Person person;
            
            int firstNameCmp = std::strcmp( person.getFirstName(), "N/a");

            assert(
                (firstNameCmp == 0) && "first name does not match!"
            );

            // std::cout << "<><><>: '" << person.getFirstName() <<  "'" << std::endl;

            // char const * fN = person.getFirstName();

            // std::cout << "<><><>1: '" << fN <<  "'" << std::endl; 

            // person.setFirstName( 
            //     std::move(new char[]{'h','i', ' ', 't','h','e','r','e','\0'}) 
            // );
            
            // std::cout << "<><><>1: '" << person.getFirstName() <<  "'" << std::endl; 

        }

        private: virtual void testII() const {

            using namespace learn::cpp::fundamental;

            std::cout << "=== default ctor & move ctor ===" << std::endl;

            value_semantic::move_semantic::demo_i::Person personI;

            // std::cout << personI.getFirstName() << std::endl;

            // value_semantic::move_semantic::demo_i::Person personII( 
            //     static_cast<value_semantic::move_semantic::demo_i::Person&&>(personI) 
            // );
        }


    };
}

#endif