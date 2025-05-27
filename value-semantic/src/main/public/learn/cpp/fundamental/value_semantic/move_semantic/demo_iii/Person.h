

#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMANTIC_DEMO_III_PERSON_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMANTIC_DEMO_III_PERSON_H

#include <cstring>  //REM: for strlen, strcpy
#include <utility>  //REM: for std::move

namespace learn::cpp::fundamental::value_semantic::move_semantic::demo_iii {

    struct Person {
    private:
        char* firstName_    = nullptr;
        bool  ownsMemory_   = false;

    public:
        // 1) Default ctor
        explicit Person() = default;

        // 2) C-string ctor
        explicit Person(const char* fn) 
        : firstName_(nullptr), ownsMemory_(false)
        {
            if (fn) {
                std::size_t len = std::strlen(fn) + 1;
                firstName_   = new char[len];
                std::memcpy(firstName_, fn, len);
                ownsMemory_ = true;
            }
        }

        // 3) Copy ctor
        Person(const Person& other)
        : firstName_(nullptr), ownsMemory_(false)
        {
            if (other.firstName_) {
                std::size_t len = std::strlen(other.firstName_) + 1;
                firstName_   = new char[len];
                std::memcpy(firstName_, other.firstName_, len);
                ownsMemory_ = true;
            }
        }

        // 4) Copy assignment
        Person& operator=(const Person& other) {
            if (this != &other) {
                // free existing
                if (ownsMemory_) delete[] firstName_;

                // copy new
                firstName_  = nullptr;
                ownsMemory_ = false;
                if (other.firstName_) {
                    std::size_t len = std::strlen(other.firstName_) + 1;
                    firstName_   = new char[len];
                    std::memcpy(firstName_, other.firstName_, len);
                    ownsMemory_ = true;
                }
            }
            return *this;
        }

        // 5) Move ctor
        Person(Person&& other) noexcept
        : firstName_(other.firstName_),
            ownsMemory_(other.ownsMemory_)
        {
            other.firstName_  = nullptr;
            other.ownsMemory_ = false;
        }

        // 6) Move assignment
        Person& operator=(Person&& other) noexcept {
            if (this != &other) {
                if (ownsMemory_) delete[] firstName_;

                firstName_   = other.firstName_;
                ownsMemory_  = other.ownsMemory_;
                other.firstName_  = nullptr;
                other.ownsMemory_ = false;
            }
            return *this;
        }

        // 7) Dtor
        ~Person() {
            if (ownsMemory_) 
                delete[] firstName_;
        }

        // Setter
        void setFirstName(const char* fn) {
            if (ownsMemory_) delete[] firstName_;
            firstName_  = nullptr;
            ownsMemory_ = false;
            if (fn) {
                std::size_t len = std::strlen(fn) + 1;
                firstName_   = new char[len];
                std::memcpy(firstName_, fn, len);
                ownsMemory_ = true;
            }
        }

        // Getter (read-only)
        const char* getFirstName() const noexcept {
            return firstName_;
        }
    };
}


#endif