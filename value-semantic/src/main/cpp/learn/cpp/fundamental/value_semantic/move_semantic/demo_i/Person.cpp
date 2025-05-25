
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
    : Person("N/awz")
    {}

    Person::Person( char const * firstName )
    : firstName(nullptr), isOwn(false)
    {
        std::cout << "ctor: char const*" << std::endl;
        this->setFirstName( firstName );
    }

    Person::Person( char *&& firstName ) 
    : firstName(nullptr), isOwn(false)
    {
        std::cout << "ctor: char *&&" << std::endl;
        this->setFirstName( std::move(firstName) ); 
    }

    Person::Person( Person && otherPerson ) noexcept 
    : firstName( std::move(otherPerson.firstName) ), isOwn(otherPerson.isOwn)
    {
        otherPerson.firstName = "N/a";
        otherPerson.isOwn = false;
    }

    Person::~Person() {

        this->cleanup();
    }

    Person & Person::operator=( Person && otherPerson ) noexcept {

        if( this != &otherPerson ) {

            this->setFirstName( std::move(otherPerson.firstName) );
        }

        return *this;
    }

    // void Person::setFirstName( char *&& firstName ) {

    //     if( this->firstName == firstName ) return;


    //     if( !firstName || firstName[0] == '\0' ) {

    //         delete[] firstName;
    //         firstName = std::move(new char[]{'N','/','a','\0'});
    //     }
    //     if( this->firstName && std::strcmp(this->firstName, firstName) == 0 ) {

    //         if (!std::is_const_v<std::remove_pointer_t<decltype(firstName)>>) {
                
    //             delete[] firstName;
    //             firstName = nullptr;

    //         }

    //         return;
    //     }

    //     delete[] this->firstName;

    //     this->firstName = static_cast<char*&&>(firstName);
        
    //     firstName = nullptr;
    // }

    void Person::cleanup() {
        if (this->isOwn && this->firstName) {
            delete[] this->firstName;
        }
        this->firstName     = nullptr;
        this->isOwn         = false;
    }

    char const * Person::getFirstName() const {

        return this->firstName? this->firstName : "N/a";
    }
}