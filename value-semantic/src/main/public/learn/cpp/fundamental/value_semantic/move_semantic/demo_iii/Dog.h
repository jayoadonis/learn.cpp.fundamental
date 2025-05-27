
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMANTIC_DEMO_III_DOG_H
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMANTIC_DEMO_III_DOG_H

#include "learn/cpp/fundamental/value_semantic/move_semantic/demo_iii/Person.h"

namespace learn::cpp::fundamental::value_semantic::move_semantic::demo_iii {

    struct Dog {
    private:
        Person owner_;
        char*  name_    = nullptr;

    public:
        // 1) Default
        explicit Dog() = default;

        // 2) Owner + C-string ctor
        explicit Dog(const Person& owner, const char* name)
        : owner_(owner), name_(nullptr)
        {
            if (name) {
                std::size_t len = std::strlen(name) + 1;
                name_      = new char[len];
                std::memcpy(name_, name, len);
            }
        }

        // 3) Copy ctor
        Dog(const Dog& other)
        : owner_(other.owner_), name_(nullptr)
        {
            if (other.name_) {
                std::size_t len = std::strlen(other.name_) + 1;
                name_ = new char[len];
                std::memcpy(name_, other.name_, len);
            }
        }

        // 4) Copy assignment
        Dog& operator=(const Dog& other) {
            if (this != &other) {
                owner_ = other.owner_;
                if (name_) delete[] name_;
                name_ = nullptr;
                if (other.name_) {
                    std::size_t len = std::strlen(other.name_) + 1;
                    name_ = new char[len];
                    std::memcpy(name_, other.name_, len);
                }
            }
            return *this;
        }

        // 5) Move ctor
        Dog(Dog&& other) noexcept
        : owner_(std::move(other.owner_)), 
            name_(other.name_)
        {
            other.name_ = nullptr;
        }

        // 6) Move assignment
        Dog& operator=(Dog&& other) noexcept {
            if (this != &other) {
                owner_ = std::move(other.owner_);
                if (name_) delete[] name_;
                name_       = other.name_;
                other.name_ = nullptr;
            }
            return *this;
        }

        // 7) Dtor
        ~Dog() {
            delete[] name_;
        }

        // Setters
        void setOwner(const Person& p) {
            std::cout << "person const &, begin" << std::endl;
            owner_ = p;
            std::cout << "person const &, end" << std::endl;
        }
        void setOwner(Person&& p) noexcept {
            std::cout << "person &&, begin" << std::endl;
            owner_ = std::move(p);
            std::cout << "person &&, end" << std::endl;
        }
        void setName(const char* name) {
            delete[] name_;
            name_ = nullptr;
            if (name) {
                std::size_t len = std::strlen(name) + 1;
                name_      = new char[len];
                std::memcpy(name_, name, len);
            }
        }

        // Getters
        const Person& getOwner() const noexcept { 
            return owner_; 
        }
        const char* getName() const noexcept { 
            return name_; 
        }
    };
   
}

#endif