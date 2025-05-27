
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMANTIC_DEMO_II
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMANTIC_DEMO_II


namespace learn::cpp::fundamental::value_semantic::move_semantic::demo_ii {

    struct Person {

        private: char * firstName;
        private: bool isOwnFirstName;
        // private: char * middleName;
        // private: bool isOwnMiddleName;
        // private: char * lastName;
        // private: bool isOwnLastName;
        // private: int age;

        public: explicit Person();
        public: explicit Person( 
            char const * const firstName/*,
            char const * const middleName,
            char const * const lastName,
            int age*/
        );
        // public: explicit Person( 
        //     Person const & otherPerson 
        // );
        public: explicit Person(
            Person && otherPerson
        ) noexcept;
        public: virtual ~Person();

        // public: virtual Person & operator=(
        //     Person const & otherPerson
        // );
        public: virtual Person & operator=(
            Person && otherPerson
        ) noexcept;

        public: virtual void setFirstName(
            char const * const firstName
        );
        public: virtual void setFirstName(
            char *&& firstName
        );

        public: virtual char const * const getFirstName() const;
    };
}

#endif