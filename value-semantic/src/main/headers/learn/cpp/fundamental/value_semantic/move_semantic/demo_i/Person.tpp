
#ifndef __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMANTIC_DEMO_I_PERSON_TPP
#define __LEARN_CPP_FUNDAMENTAL_VALUE_SEMANTIC_MOVE_SEMANTIC_DEMO_I_PERSON_TPP


#include "learn/cpp/fundamental/value_semantic/move_semantic/demo_i/Person.h"

namespace learn::cpp::fundamental
::value_semantic
::move_semantic::demo_i {

    template<typename T, typename>
    void Person::setFirstName(T ptr) {

        std::cout << "type const *" << std::endl;

        if( this->firstName == ptr ) return;

        this->cleanup();
        this->firstName = const_cast<char*>(ptr);
        this->isOwn     = false;
    }

    template<typename T, typename>
    void Person::setFirstName(T&& ptr) {

        std::cout << "type *&&" << std::endl;

        if( this->firstName == ptr ) return;

        this->cleanup();
        this->firstName = ptr;
        this->isOwn     = true;
        ptr             = nullptr;
    }

}

#endif