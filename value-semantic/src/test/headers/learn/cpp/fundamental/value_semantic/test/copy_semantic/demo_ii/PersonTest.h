
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_COPY_SEMANTIC_DEMO_II_PERSON_TEST_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_COPY_SEMANTIC_DEMO_II_PERSON_TEST_H

#include "learn/cpp/fundamental/value_semantic/copy_semantic/demo_ii/Person.h"

#include <cassert>
#include <cstring>
#include <cstdio>

#include <typeinfo>
#include <iostream>

namespace learn::cpp::fundamental
::value_semantic
::test::copy_semantic::demo_ii {
    
    struct PersonTest {

        private: explicit PersonTest() = default;
        public: virtual ~PersonTest() = default;

        public: static void run() {

            std::printf( 
                "::: BEGIN: run(V)V, %s, %p\n", 
                typeid(static_cast<void(*)()>(&PersonTest::run)).name(), 
                (void*)static_cast<void(*)()>(&PersonTest::run) 
            );

            PersonTest personTest{};

            std::printf( "::: BEGIN: %s, %p\n", typeid(personTest).name(), static_cast<void*>(&personTest) );
            personTest.testI();
            personTest.testII();
            personTest.testIII();
            std::printf( "::: END: %s, %p\n", typeid(personTest).name(), static_cast<void*>(&personTest) );

            std::printf( 
                "::: END: run(V)V, %s, %p\n", 
                typeid(static_cast<void(*)()>(&PersonTest::run)).name(), 
                (void*)static_cast<void(*)()>(&PersonTest::run) 
            );

        }

        private: virtual void testI() const {

            void (PersonTest::* instMemFunc)(void) const = 
                &PersonTest::testI; 

            std::printf( 
                ":: BEGIN: testI(V)V, %s, %p, %p\n", 
                typeid(instMemFunc).name(), 
                (void*)&instMemFunc,
                this
            ); 

            using namespace learn::cpp::fundamental::value_semantic;
            
            value_semantic::copy_semantic::demo_ii::Person person;

            std::cout << "1. '" << person.getFirstName() << "'" << std::endl;

            person.setFirstName("Micky Dat");

            std::cout << "2. '" << person.getFirstName() << "'" << std::endl;

            person.setFirstName(nullptr);

            std::cout << "3. '" << person.getFirstName() << "'" << std::endl;

            std::printf( 
                ":: END: testI(V)V, %s, %p\n", 
                typeid(static_cast<void(PersonTest::*)()const>(&PersonTest::testI)).name(), 
                this
            ); 
            
        }

        
        private: virtual void testII() const {


            std::printf( ":: BEGIN: testII(V)V, %p\n", this ); 

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

            std::printf( ":: END: testII(V)V, %p\n", this ); 
        }

        private: void testIII() const {

            std::printf( ":: BEGIN: testIII(V)V, copy-cotr, %p\n", this );
            
            using namespace learn::cpp::fundamental::value_semantic;

            value_semantic::copy_semantic::demo_ii::Person personOne;
            value_semantic::copy_semantic::demo_ii::Person personTwo( personOne );
            // value_semantic::copy_semantic::demo_ii::Person personThree = personTwo;
            
            std::printf( ":: END: testIII(V)V, copy-cotr, %p\n", this );

        }
    };

}

#endif


