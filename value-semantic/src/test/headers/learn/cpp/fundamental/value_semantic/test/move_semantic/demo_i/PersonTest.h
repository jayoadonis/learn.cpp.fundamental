
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
            personTest.testIII();

        }

        //REM: 
        private: virtual void testI() const {

            std::cout << "==== default ctor & ... === " << std::endl;

            using namespace learn::cpp::fundamental;

            char * xyz = new char[]{'w','e','w','\0'};

            value_semantic::move_semantic::demo_i::Person person(std::move(xyz));

            delete[] xyz;

            std::cout << "<><><>1: '" << person.getFirstName() <<  "'" << std::endl;

            person.setFirstName(new char[]{'k','w','\0'});

            std::cout << "<><><>2: '" << person.getFirstName() <<  "'" << std::endl;

            // person.setFirstName(std::move(new char[]{'o','k','2','3','9','\0'}));

            // std::cout << "<><><>3: '" << person.getFirstName() <<  "'" << std::endl;

            // person.setFirstName(std::move(new char[]{'o','k','2','3','9','0','1','\0'}));

            // std::cout << "<><><>4: '" << person.getFirstName() <<  "'" << std::endl;
            
            // int firstNameCmp = std::strcmp( person.getFirstName(), "N/a");

            // assert(
            //     (firstNameCmp == 0) && "first name does not match!"
            // );

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

            std::cout << personI.getFirstName() << std::endl;

            personI.setFirstName("N/az");

            std::cout << personI.getFirstName() << std::endl;

            value_semantic::move_semantic::demo_i::Person personII( std::move(personI) );

            std::cout << personII.getFirstName() << std::endl;
            
            std::cout << personI.getFirstName() << std::endl;
            
        }

        private: void testIII() const {

            std::cout << "=== ===" << std::endl;

            using namespace learn::cpp::fundamental;

            value_semantic::move_semantic::demo_i::Person personI;

            std::printf(":::1 %s\n", personI.getFirstName() );

            char * canBeMoveFirstName = new char[]{'f','n', 'I','\0'};

            std::printf(":::1.1 %s\n", canBeMoveFirstName );

            personI.setFirstName( canBeMoveFirstName );
            
            std::printf(":::1.2 %s\n", canBeMoveFirstName );

            std::printf(":::1.3 %s\n", personI.getFirstName() );

            delete[] canBeMoveFirstName;
            canBeMoveFirstName = nullptr;

            std::printf(":::1.4 %s\n", canBeMoveFirstName );

            std::printf(":::1.5 %s\n", personI.getFirstName() );

            char const * shouldNotBeMoveFirstName = new char[]{'f','n', 'I','I','\0'};

            std::printf(":::2 %s\n", shouldNotBeMoveFirstName );

            personI.setFirstName( shouldNotBeMoveFirstName ); //REM: [WARNING] .|. It only point to it, shallow-copy.

            std::printf(":::2.1 %s\n", shouldNotBeMoveFirstName );

            std::printf(":::2.2 %s\n", personI.getFirstName() );

            delete[] shouldNotBeMoveFirstName;
            shouldNotBeMoveFirstName = nullptr;

            std::printf(":::2.3 %s\n", shouldNotBeMoveFirstName );

            std::printf(":::2.4 %s\n", personI.getFirstName() ); //REM: [ERR_RT, UB] .|. dangling pointer...
        }


    };
}

#endif