

#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMANTIC_DEMO_III_DOG_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMANTIC_DEMO_III_DOG_H


namespace learn::cpp::fundamental::value_semantic::move_semantic::demo_ii {

    struct Dog {

        private: char * name = nullptr;
        private: char * breed = nullptr;
        private: bool isOwnPtrName = false;
        private: bool isOwnPtrBreed = false;

        public: explicit Dog() = default;

        public: explicit Dog(
            char const * const name,
            char const * const breed
        );

        public: Dog( Dog const & otherDog );
        public: Dog( Dog && otherDog ) noexcept;

        public: virtual ~Dog();

        public: Dog & operator=( Dog const & otherDog );
        public: Dog & operator=( Dog && otherDog ) noexcept;

        
    };
}

#endif