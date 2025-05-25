
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMENTIC_DEMO_I_PERSON_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMENTIC_DEMO_I_PERSON_H

#include <utility>

namespace learn::cpp::fundamental
::value_semantic
::move_semantic::demo_i {

    struct Person {

        public: explicit Person();
        public: explicit Person( char const* firstName );
        public: explicit Person( char *&& firstName );
        public: explicit Person( Person && otherPerson ) noexcept;
        public: virtual ~Person();

        public: virtual Person & operator=( Person && otherPerson ) noexcept;

        // public: virtual void setFirstName( char *&& firstName );

        template<
            typename T,
            typename = typename std::enable_if<
                std::is_same<
                    typename std::decay<T>::type,    
                    const char*
                >::value
            >::type
        >
        void setFirstName(T ptr);

        template<
            typename T,
            typename = typename std::enable_if<
                std::is_same<
                    typename std::decay<T>::type,
                    char*
                >::value
            >::type
        >
        void setFirstName(T&& ptr);

        public: virtual char const * getFirstName() const; 
        protected: virtual void cleanup();

        private: char * firstName;
        private: bool isOwn;
    };
}

#include "learn/cpp/fundamental/value_semantic/move_semantic/demo_i/Person.tpp"

#endif