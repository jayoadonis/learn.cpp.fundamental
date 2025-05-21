
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_COPY_SEMANTIC_DEMO_II_PERSON_TEST_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_COPY_SEMANTIC_DEMO_II_PERSON_TEST_H

#include "learn/cpp/fundamental/value_semantic/copy_semantic/demo_ii/Person.h"

#include <cassert>



namespace learn::cpp::fundamental
    ::value_semantic::test::copy_semantic::demo_ii {
    
    struct PersonTest {

        private: explicit PersonTest() = default;
        public: virtual ~PersonTest() = default;

        public: static void run() {

            PersonTest personTest{};
            personTest.testI();
        }

        private: virtual void testI() const {

            learn::cpp::fundamental::value_semantic::copy_semantic::demo_ii::Person person;

            std::cout << "'" << person.getFirstName() << "'" << std::endl;

            person.setFirstName("Micky Dat");

            std::cout << "'" << person.getFirstName() << "'" << std::endl;

            person.setFirstName(nullptr);

            std::cout << "'" << person.getFirstName() << "'" << std::endl;
            
        }
    };

}

#endif