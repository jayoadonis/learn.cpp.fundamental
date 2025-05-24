
#include "learn/cpp/fundamental/value_semantic/move_semantic/demo_i/Person.h"

#include <cstddef>
#include <utility>
#include <cstring>
#include <iostream>

//REM: [NOT_PROPERLY_WORKING]
namespace learn::cpp::fundamental
::value_semantic
::move_semantic::demo_i {

    Person::Person() 
    : Person(std::move(new char[]{'N','/','a','\0'})) 
    {}

    Person::Person( char *&& firstName ) 
    : firstName(nullptr) 
    {
        
        this->setFirstName( std::move(firstName) ); 
    }

    Person::Person( Person && otherPerson ) noexcept 
    : Person( std::move(otherPerson.firstName) ) 
    {
        // otherPerson.firstName = nullptr;
    }

    Person::~Person() {

        if( this->firstName ) {

            delete[] this->firstName;
            this->firstName = nullptr;
        }
    }

    Person & Person::operator=( Person && otherPerson ) noexcept {

        if( this != &otherPerson ) {

            this->setFirstName( std::move(otherPerson.firstName) );
        }

        return *this;
    }

    void Person::setFirstName( char *&& firstName ) {

        if( this->firstName == firstName ) return;

        if( !firstName || firstName[0] == '\0' ) {
            delete[] firstName;
            firstName = std::move(new char[]{'N','/','a','\0'});
        }

        if( this->firstName && std::strcmp(this->firstName, firstName) == 0 ) {

            delete[] firstName;
            firstName = nullptr;

            return;
        }

        delete[] this->firstName;

        this->firstName = static_cast<char *&&>(firstName);
        firstName = nullptr;

    }

    char const * Person::getFirstName() const {

        return this->firstName? this->firstName : "N/a";
    }
}