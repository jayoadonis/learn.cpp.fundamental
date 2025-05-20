
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_COPY_SEMANTIC_DEMO_I_PERSON_TEST_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_COPY_SEMANTIC_DEMO_I_PERSON_TEST_H

#include <cstring>
#include <cassert>
#include <iostream>
#include "learn/cpp/fundamental/value_semantic/copy_semantic/demo_i/Person.h"

namespace learn::cpp::fundamental::value_semantic::test::copy_semantic::demo_i {

    struct PersonTest {

        private: explicit PersonTest() = default;
        public: virtual ~PersonTest() = default;

        public: static void run() {

            PersonTest personTest;
            personTest.testI();
            personTest.testII();
            personTest.testIII();
        }

        private: virtual void testI() const {

            learn::cpp::fundamental::value_semantic::copy_semantic::demo_i::Person personI;

            personI.setFirstName("ABA CaD@");

            int firstNameCmp = std::strcmp( personI.getFirstName(), "ABA CaD@");

            assert( (firstNameCmp == 0) && "Not match first name!");

            personI.setFirstName(nullptr);

            firstNameCmp = std::strcmp( personI.getFirstName(), "N/a");

            assert( (firstNameCmp == 0) && "Not match first name!");
            
        } 

        private: void testII() const {

            learn::cpp::fundamental::value_semantic::copy_semantic::demo_i::Person personI;
            personI.setFirstName("Carlo Something");

            learn::cpp::fundamental::value_semantic::copy_semantic::demo_i::Person personII(personI);

            int firstNameCmpII = std::strcmp(personI.getFirstName(), personII.getFirstName());
            assert( (firstNameCmpII == 0) && "Copy-ctor not working..." );
            
            learn::cpp::fundamental::value_semantic::copy_semantic::demo_i::Person personIII;

            personI = personIII;

            int firstNameCmpIIIa = std::strcmp(personI.getFirstName(), personIII.getFirstName());
            int firstNameCmpIIIb = std::strcmp(personI.getFirstName(), "N/a");

            assert( (firstNameCmpIIIa == 0) && "Copy-assignment-op not working..." );
            assert( (firstNameCmpIIIb == 0) && "Copy-assignment-op not working..." );

            personIII = personIII;
        }

        //REM: Test copy-ctor with r-value/temp-value instance.
        private: void testIII() const {

            using learn::cpp::fundamental::value_semantic::copy_semantic::demo_i::Person;

            Person personI( Person{} );

            int firstNameCmp = std::strcmp(personI.getFirstName(), "N/a");

            assert(
                (firstNameCmp == 0) && "Copy-ctor not working..."
            );

            Person personII( Person("Sample First Name") );

            int firstNameCmpI = std::strcmp(personII.getFirstName(), "Sample First Name");

            assert(
                (firstNameCmpI == 0) && "Copy-ctor not working..."
            );
        }
    };
}
#endif