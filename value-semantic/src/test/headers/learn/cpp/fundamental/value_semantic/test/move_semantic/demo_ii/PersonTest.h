
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_MOVE_SEMANTIC_DEMO_II_PERSON_TEST_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_TEST_MOVE_SEMANTIC_DEMO_II_PERSON_TEST_H

#include "learn/cpp/fundamental/value_semantic/move_semantic/demo_ii/Person.h"
#include <cassert>
#include <cstring>

namespace learn::cpp::fundamental
::value_semantic
::test::move_semantic::demo_ii {

    struct PersonTest {

        private: explicit PersonTest() {

        }

        public: static void run() {

            PersonTest personTest;
            personTest.testI();
            personTest.testII();
            personTest.testIII();
            personTest.testIV();
        }

        private: void testI() const {

            std::printf("%s\n", "=== move_semantic/demo_ii/Person.h : default ctor === ");

            using learn::cpp::fundamental
            ::value_semantic
            ::move_semantic::demo_ii::Person;

            Person person;

            int cmpFirstName = std::strcmp(
                person.getFirstName(),
                "N/a"
            );

            assert(
                (cmpFirstName == 0) && "1. First name does not match."
            );

        }

        private: void testII() const {

            std::printf("%s\n", "=== move_semantic/demo_ii/Person.h : setters : deep-copy === ");

            using learn::cpp::fundamental
            ::value_semantic
            ::move_semantic::demo_ii::Person;

            Person person;

            person.setFirstName( "what now" );

            int cmpFirstName = std::strcmp(
                person.getFirstName(),
                "what now" 
            );

            assert(
                (cmpFirstName == 0) && "1. First name does not match."
            );

            char const * x = new char[]{'n','c','1','\0'};

            cmpFirstName = std::strcmp(
                 x,
                "nc1"
            );

            assert(
                (cmpFirstName == 0) && "2. First name does not match."
            );

            person.setFirstName( x );

            assert(
                (x != nullptr) && "3. First name does not match."
            );

            delete[] x;
            x = nullptr;

            assert(
                (x == nullptr) && "4. First name does not match."
            );

            cmpFirstName = std::strcmp(
                person.getFirstName(),
                "nc1"
            );

            assert(
                (cmpFirstName == 0) && "5. First name does not match."
            );
        }

        private: void testIII() const {

            std::printf("%s\n", "=== move_semantic/demo_ii/Person.h : setters : shallow-copy === ");

            using learn::cpp::fundamental
            ::value_semantic
            ::move_semantic::demo_ii::Person;

            Person person;
           
            char * x = new char[]{'n','c','1','\0'};

            int cmpFirstName = std::strcmp(
                x,
                "nc1"
            );

            assert(
                (cmpFirstName == 0) && "1. Should be matched."
            );

            assert(
                (x != nullptr) && "2. should not be null."
            );

            person.setFirstName( std::move(x) );

            assert(
                (x == nullptr) && "3. should be null."
            );

            cmpFirstName = std::strcmp(
                person.getFirstName(),
                "nc1"
            );

            assert(
                (cmpFirstName == 0) && "4. First Name should be match."
            );

            delete[] x;
            x = nullptr;

            cmpFirstName = std::strcmp(
                person.getFirstName(),
                "nc1"
            );

            assert(
                (cmpFirstName == 0) && "5. First Name should be match."
            );
        }

        private: void testIV() const {

            std::printf("%s\n", "=== 'move_semantic/demo_ii/Person.h' : move ctor");

            using learn::cpp::fundamental
            ::value_semantic
            ::move_semantic::demo_ii::Person;

            Person personI;

            int cmpFN = std::strcmp( 
                personI.getFirstName(), "N/a"
            );

            assert(
                (cmpFN == 0) && "1. first name's expected to be matched."
            );

            personI.setFirstName("ok");

            cmpFN = std::strcmp( 
                personI.getFirstName(), "ok"
            );

            assert(
                (cmpFN == 0) && "2. first name's expected to be matched."
            );

            Person personII( std::move(personI) );

            cmpFN = std::strcmp( 
                personI.getFirstName(), "N/a"
            );

            assert(
                (cmpFN == 0) && "3. first name's expected to be matched."
            );

            cmpFN = std::strcmp( 
                "ok", personII.getFirstName()
            );

            assert(
                (cmpFN == 0) && "4. first name's expected to be matched."
            );

            cmpFN = std::strcmp( 
                personI.getFirstName(), personII.getFirstName()
            );

            assert(
                (cmpFN != 0) && "5. first name's expected to be matched."
            );
        }
    };
}


#endif