
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_COPY_SEMANTIC_DEMO_II_PERSON_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_COPY_SEMANTIC_DEMO_II_PERSON_H

#include <cstddef>
namespace learn::cpp::fundamental
    ::value_semantic::copy_semantic::demo_ii {

    struct Person {

        public: explicit Person();
        public: explicit Person(
            char const * firstName,
            char const * middleName,
            char const * lastName,
            int age
        );
        public: explicit Person(
            Person const & otherPerson
        );
        public: virtual ~Person();

        public: virtual Person& operator=(
            Person const & otherPerson
        );

        public: virtual void setFirstName(
            char const * firstName
        );
        public: virtual void setFirstName(
            char *&& otherfirstName
        );
        public: virtual void setFirstName(
            std::nullptr_t nullPtrT
        );

        public: virtual void setMiddleName(
            char const * middleName
        );

        public: virtual void setLastName(
            char const * lastName
        );

        public: virtual void setAge(
            int age
        );

        public: virtual char const * getFirstName() const;
        public: virtual char const * getMiddleName() const;
        public: virtual char const * getLastName() const;
        public: virtual int getAge() const;

        private: char * firstName;
        private: char * middleName;
        private: char * lastName;
        private: int age;
    };
}

#endif