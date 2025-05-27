

#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_MOVE_SEMANTIC_DEMO_III_PERSON_DOG_TEST_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_MOVE_SEMANTIC_DEMO_III_PERSON_DOG_TEST_H

#include "learn/cpp/fundamental/value_semantic/move_semantic/demo_iii/Person.h"
#include "learn/cpp/fundamental/value_semantic/move_semantic/demo_iii/Dog.h"

using learn::cpp::fundamental::value_semantic::move_semantic::demo_iii::Person;
using learn::cpp::fundamental::value_semantic::move_semantic::demo_iii::Dog;

namespace learn::cpp::fundamental
::value_semantic
::test::move_semantic::demo_iii {

    struct PersonDogTest {

        private: explicit PersonDogTest() {

        }

        public: static void run() {

            PersonDogTest personDogTest;

            personDogTest.testI();
        }

        private: void testI() const {

            std::cout << "=== PersonDogTest testI ===\n";
            
            Person mike;
            mike.setFirstName( "Mike");

            Dog max;
            max.setName( "Max" );
            // max.setOwner( mike );
            // max.setOwner( mike );
            // max.setOwner( mike );
            // max.setOwner( Person("Mike") );
            // max.setOwner( Person("Mike_ii") );
            // max.setOwner( Person("Mike_iii") );
            max.setOwner( std::move(mike) );
            // max.setOwner( std::move(mike) );
            // max.setOwner( std::move(mike) );

            // int cmpOwnerFn = std::strcmp(
            //     "Mike", max.getOwner().getFirstName()
            // );

            // assert(
            //     (cmpOwnerFn == 0) && "Should have match owner first name."
            // );

            // int cmpDogName = std::strcmp(
            //     "Max", max.getName()
            // );

            // assert(
            //     (cmpDogName == 0) && "Should have match the dog name."
            // );

            // Dog rex( std::move(max) );

            // assert(
            //     (max.getName() == nullptr) && "Should be nullptr."
            // ); 
            
            // assert(
            //     (max.getOwner().getFirstName() == nullptr) && "Should be nullptr."
            // );

            // cmpOwnerFn = std::strcmp(
            //     "Mike", mike.getFirstName()
            // );
            
            // assert(
            //     (cmpOwnerFn == 0) && "Should match owner first name."
            // );
        }

    };
}


#endif