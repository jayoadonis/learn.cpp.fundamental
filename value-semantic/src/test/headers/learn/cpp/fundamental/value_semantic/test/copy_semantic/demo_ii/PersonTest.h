
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_COPY_SEMANTIC_DEMO_II_PERSON_TEST_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_COPY_SEMANTIC_DEMO_II_PERSON_TEST_H

#include "learn/cpp/fundamental/value_semantic/copy_semantic/demo_ii/Person.h"

#include <cassert>
#include <cstring>


namespace learn::cpp::fundamental
    ::value_semantic::test::copy_semantic::demo_ii {
    
    struct PersonTest {

        private: explicit PersonTest() = default;
        public: virtual ~PersonTest() = default;

        public: static void run() {

            PersonTest personTest{};
            personTest.testI();
            personTest.testII();
        }

        private: virtual void testI() const {

            learn::cpp::fundamental::value_semantic::copy_semantic::demo_ii::Person person;

            std::cout << "'" << person.getFirstName() << "'" << std::endl;

            person.setFirstName("Micky Dat");

            std::cout << "'" << person.getFirstName() << "'" << std::endl;

            person.setFirstName(nullptr);

            std::cout << "'" << person.getFirstName() << "'" << std::endl;
            
        }

        
        private: virtual void testII() const {

            using namespace learn::cpp::fundamental;
            
            value_semantic::copy_semantic::demo_ii::Person person;

            int cmpFirstNameI = std::strcmp("N/a", person.getFirstName());

            assert(
                (cmpFirstNameI == 0) && "First Name does not match."
            );

            person.setFirstName(std::move(new char[]{'1', '2', ' ', '9', '\0'}));

            int cmpFirstNameII = std::strcmp("12 9", person.getFirstName());

            assert(
                (cmpFirstNameII == 0) && "First Name does not match."
            );

            person.setFirstName(nullptr);

            int cmpFirstNameIII = std::strcmp("N/a", person.getFirstName());

            assert(
                (cmpFirstNameIII == 0) && "First Name does not match."
            );
        }
    };

}

#endif