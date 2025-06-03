
#include "learn/cpp/fundamental/value_semantic/copy_semantic/demo_ii/Person.h"

#include <cstddef>
#include <cstring>

namespace learn::cpp::fundamental
::value_semantic
::copy_semantic::demo_ii {

    Person::Person() : Person(
        "", "", "", 0
    ) {

    }

    Person::Person(
        char const * firstName,
        char const * middleName,
        char const * lastName,
        int age
    ): firstName(nullptr),
    middleName(nullptr),
    lastName(nullptr),
    age(0) {
        
        this->setFirstName( firstName );
        this->setMiddleName( middleName );
        this->setLastName( lastName );
        this->setAge( age );
    }

    Person::Person( 
        Person const & otherPerson
    ): Person(
        otherPerson.firstName,
        otherPerson.middleName,
        otherPerson.lastName,
        otherPerson.age
    ) {
        
    }

    Person::~Person() {

        delete[] this->firstName;
        this->firstName = nullptr;

        delete[] this->middleName;
        this->middleName = nullptr;

        delete[] this->lastName;
        this->lastName = nullptr;

        this->age = 0;
    }

    Person & Person::operator=(
        Person const & otherPerson
    ) {

        if( this != &otherPerson ) {

            this->setFirstName(otherPerson.firstName);
            this->setMiddleName(otherPerson.middleName);
            this->setLastName(otherPerson.lastName);
            this->setAge(otherPerson.age);
        }

        return *this;
    }

    void Person::setFirstName(
        char const * firstName
    ) {

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

    void Person::setFirstName( 
        char *&& otherFirstName
    ) {

        if( !otherFirstName || otherFirstName[0] == '\0' ) {
            delete[] otherFirstName;
            otherFirstName = strdup("N/a");
        }
        
        if( this->firstName 
            && std::strcmp(this->firstName, otherFirstName) == 0 
        ) {
            delete[] otherFirstName;
            otherFirstName = nullptr;
            return;
        }

        delete[] this->firstName;

        this->firstName = otherFirstName;

        otherFirstName = nullptr;
    }

    void Person::setFirstName(
        std::nullptr_t nullPtrT
    ) {

        this->setFirstName(static_cast<char const *>(nullPtrT));
    }

    void Person::setMiddleName(
        char const * middleName
    ) {

        //REM: [TODO] .|. is_blank_mt( char const * c_str );
        if( !middleName || middleName[0] == '\0' ) middleName = "N/a";

        if( this->middleName && std::strcmp( this->middleName, middleName ) == 0 ) return;

        delete[] this->middleName;

        std::size_t len = 0;
        while(middleName[len++]);

        this->middleName = new char[len];

        for(std::size_t i = 0; i <= len; ++i)
            this->middleName[i] = middleName[i];
    }

    void Person::setLastName(
        char const * lastName
    ) {

        //REM: [TODO] .|. is_blank_mt( char const * c_str );
        if( !lastName || lastName[0] == '\0' ) lastName = "N/a";

        if( this->lastName && std::strcmp(this->lastName, lastName) == 0 ) return;

        delete[] this->lastName;

        std::size_t len = 0;
        while(lastName[len++]);
        this->lastName = new char[len];

        for(std::size_t i = 0; i <= len; ++i)
            this->lastName[i] = lastName[i];
    }

    void Person::setAge(
        int age
    ) {

        this->age = (age>0) ? age : 0;
    }

    char const * Person::getFirstName() const {

        return this->firstName;
    }

    char const * Person::getMiddleName() const {

        return this->middleName;
    }

    char const * Person::getLastName() const {

        return this->lastName;
    }

    int Person::getAge() const {

        return this->age;
    }
}