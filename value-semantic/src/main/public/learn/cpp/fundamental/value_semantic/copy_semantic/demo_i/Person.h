
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_COPY_SEMANTIC_DEMO_I_PERSON_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_COPY_SEMANTIC_DEMO_I_PERSON_H


namespace learn::cpp::fundamental::value_semantic::copy_semantic::demo_i {

    struct Person {

        public: explicit Person();
        public: explicit Person( char const * firstName );
        //REM: copy-ctor
        public: explicit Person( Person const & otherPerson );
        public: virtual ~Person();

        //REM: copy-assigment-op
        public: virtual Person & operator=( Person const & otherPerson );

        public: virtual void setFirstName( char const * firstName );
        public: virtual char const * getFirstName() const;

        private: char * firstName;
    };
}

#endif