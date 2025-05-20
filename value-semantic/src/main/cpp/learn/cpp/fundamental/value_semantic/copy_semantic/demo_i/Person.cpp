
#include "learn/cpp/fundamental/value_semantic/copy_semantic/demo_i/Person.h"

#include <cstring>

namespace learn::cpp::fundamental::value_semantic::copy_semantic::demo_i {

    Person::Person() : Person("") {}

    Person::Person( char const * firstName ) : firstName(nullptr) {

        this->setFirstName( firstName );
    }

    Person::Person( Person const & otherPerson ) : Person( otherPerson.firstName ) { }

    Person::~Person() {

        delete[] this->firstName;
        this->firstName = nullptr;
    }

    Person & Person::operator=(Person const & otherPerson) {

        if( this != &otherPerson ) {

            this->setFirstName(otherPerson.firstName);
        }

        return *this;
    }

    void Person::setFirstName( char const * firstName ) {

        if( this->firstName ) {

            if( firstName && std::strcmp( this->firstName, firstName) == 0 ) return;

            delete[] this->firstName;
            this->firstName = nullptr;
        } 

        if( !firstName || (firstName && std::strcmp( firstName, "") == 0) ) {

            firstName = "N/a";
        }

        unsigned int len = 0;
        while(firstName[len]) ++len;
        this->firstName = new char[len+1];
        for(unsigned int i = 0; i <= len; ++i) {

            this->firstName[i] = firstName[i];
        }
    }

    char const * Person::getFirstName() const {

        return this->firstName ? this->firstName : "";
    }
}
