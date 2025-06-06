
#include "learn/cpp/fundamental/value_semantic/copy_semantic/demo_i/Person.h"

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

        //REM: [TODO] .|. is_blank_mt( char const * c_str );
        if( !firstName || firstName[0] == '\0' ) firstName = "N/a";
        
        if( this->firstName && std::strcmp(this->firstName, firstName) == 0 ) return;

        delete[] this->firstName;

        std::size_t len = 0;
        while(firstName[len++]);
        this->firstName = new char[len];

        for(std::size_t i = 0; i <= len; ++i)
            this->firstName[i] = firstName[i];
    }

    char const * Person::getFirstName() const {

        return this->firstName;
    }
}
