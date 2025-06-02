

#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_BOTH_SEMANTIC_DEMO_I_PERSON_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_BOTH_SEMANTIC_DEMO_I_PERSON_H


namespace learn::cpp::fundamental::value_semantic::both_semantic::demo_i {

    struct Person {

        public: explicit Person();
        public: explicit Person( char const * firstName );
        public: explicit Person( Person const & otherPerson );
        public: explicit Person( Person && otherPerson ) noexcept;
        template<typename T, typename =
            std::is_enable_if<
                std::is_same_v<T, Person>
            >
        >
        public: explicit Person( T&& otherPerson );
        public: virtual ~Person();

        public: virtual Person & operator=( Person const & otherPerson );
        public: virtual Person & operator=( Person && otherPerson ) noexcept;

        public: virtual void setFirstName( char const * firstName );
        public: virtual void setFirstName( char *&& firstName ) noexcept;
        template<typename T, typename =
            std::is_enable_if<
                std::is_same_v<T, char *>
            >
        >
        public: virtual void setFirstName( T&& firstName );
        public: virtual char const * getFirstName() const;

        protected: virtual char * normalize( 
            char const * const firstName, 
            char const * const defaultValue
        );

        protected: virtual char * normalize(
            char *&& firstName,
            char *&& defaultValue
        ) noexcept;
        
        template<typename T, typename =
            std::is_enable_if<
                std::is_same_v<T, char *>
            >
        >
        protected: virtual char * normalize(
            T&& firstName,
            T&& defaultValue
        );

        public: virtual void setFirstName( T&& firstName );

        private: char const * firstName;
    };
}

#endif