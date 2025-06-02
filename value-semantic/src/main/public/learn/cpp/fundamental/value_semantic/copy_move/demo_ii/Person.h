

#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_COPY_MOVE_DEMO_II_PERSON_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_COPY_MOVE_DEMO_II_PERSON_H

#include <string>

namespace learn::cpp::fundamental::value_semantic::copy_move::demo_ii {

    struct Person {

        private: std::string firstName;
        private: std::string middleName;
        private: std::string lastName;
        private: int age;

        public: explicit Person() : Person(
            "N/a", "N/a", "N/a", 0
        ) { };
        
        public: virtual ~Person() = default;

        public: template<typename F, typename M, typename L,
            typename = typename std::enable_if<
                std::is_convertible<F, std::string>::value &&
                std::is_convertible<M, std::string>::value &&
                std::is_convertible<L, std::string>::value
            >::type
        >
        explicit Person(
            F && firstName = "N/a",
            M && middleName = "N/a",
            L && lastName = "N/a",
            int age = 0
        ) : firstName( std::forward<F>(firstName) ),
            middleName( std::forward<M>(middleName) ),
            lastName( std::forward<L>(lastName) ),
            age( age ) { }

        public: virtual std::string getFirstName() const {

            return this->firstName;
        }

        public: virtual std::string getMddleName() const {

            return this->middleName;
        }

        public: virtual std::string getLastName() const {

            return this->lastName;
        }

        public: virtual int getAge() const {
 
            return this->age;
        }
        
        // static void* operator new(std::size_t size) {
        //     void* p = std::malloc(size);
        //     if (!p) throw std::bad_alloc();
        //     std::cout << "[Person new] size=" << size << " @ " << p << std::endl;
        //     return p;
        // }

        // void* operator new(std::size_t sz, const std::nothrow_t&) noexcept {
        //     void* p = std::malloc(sz);
        //     std::cout << "[Person new] size=" << sz << " nothrow @ " << p << std::endl;
        //     return p;
        // }

        // static void operator delete(void* p) noexcept {
        //     std::cout << "[Person del] @ " << p << std::endl;
        //     std::free(p);
        // }

        // void operator delete(void* ptr, std::size_t size) noexcept {
        //     std::cout << "[Person delete] size=" << size << " @ " << ptr << std::endl;
        //     std::free(ptr);
        // }

        //REM: setters...
    };
}


#endif