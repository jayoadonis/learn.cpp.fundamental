
#include "learn/cpp/fundamental/value_semantic/move_semantic/demo_ii/Person.h"

#include <cstring>
#include <cstddef>
#include <utility>
#include <iostream>

namespace learn::cpp::fundamental::value_semantic::move_semantic::demo_ii {

    Person::Person() : Person( nullptr ) {

        std::printf("%s\n", "ctro: default");
    }

    Person::Person(
        char const * const firstName/*,
        char const * const middleName,
        char const * const lastName,
        int age*/
    ) : firstName(const_cast<char*>(firstName)),
        isOwnFirstName(false)/*,
        middleName(middleName),
        isOwnMiddleName(false),
        lastName(lastName),
        isOwnLastName(false),
        age(age)*/
    {
        this->setFirstName( firstName );
        std::cout << "ctor: char connt * const\n";
    }

    Person::Person(
        Person && otherPerson
    ) noexcept 
    : firstName( otherPerson.firstName ),
        isOwnFirstName( otherPerson.isOwnFirstName )
    {
        std::cout << "ctor: Person &&\n";
        otherPerson.firstName = "N/a";
        otherPerson.isOwnFirstName = false;
    }

    Person::~Person() {

        if( this->isOwnFirstName ) {

            delete[] this->firstName;
            this->firstName = nullptr;
            this->isOwnFirstName = false;
        }
        // if( this->isOwnMiddleName ) {
        //     delete[] this->middleName;
        //     this->middleName = nullptr;
        // }
        // if( this->isOwnLastName ) {
        //     delete[] this->lastName;
        //     this->lastName = nullptr;
        // }
        // this->age = 0;
    }

    Person & Person::operator=(
        Person && otherPerson
    ) noexcept {

        if( this == &otherPerson ) {

            this->setFirstName( std::move(otherPerson.firstName) );
        }

        return *this;
    }

    void Person::setFirstName(
        char const * const firstName
    ) {

        std::cout << "setter: char const * const\n";
        if( firstName == nullptr ) {

            this->firstName = "N/a";
            this->isOwnFirstName = false;
            return;
        }

        if( this->firstName == firstName ) return;

        if( std::strcmp(this->firstName, firstName) == 0 ) return;

        if( this->isOwnFirstName ) {

            delete[] this->firstName;
            this->firstName = nullptr;
        }

        std::size_t len = 0;

        while(firstName[len++]); 
        
        this->firstName = new char[len]; 
 
        for( std::size_t i = 0; i <= len; ++i ) {

            this->firstName[i] = firstName[i];
        }

        this->isOwnFirstName = true;
    }

    void Person::setFirstName(
        char *&& firstName
    ) {

        std::cout << "setter: char *&&\n";

        if( firstName == nullptr ) {

            this->setFirstName( firstName );
            return;
        }

        if( this->isOwnFirstName ) {

            delete[] this->firstName;
            this->firstName = nullptr;
        }

        this->firstName = firstName;
        this->isOwnFirstName = true;
        firstName = nullptr;
    }

    char const * const Person::getFirstName() const {

        return this->firstName;
    }
}