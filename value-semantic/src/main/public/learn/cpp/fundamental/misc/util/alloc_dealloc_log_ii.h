#ifndef __VALUE_SEMANTIC_NDEBUG

#ifndef __LEARN_CPP_FUNDAMENTAL_MISC_UTIL_ALLOC_DEALLOC_II_H
#define __LEARN_CPP_FUNDAMENTAL_MISC_UTIL_ALLOC_DEALLOC_II_H

#include <cstdlib>   // std::malloc, std::free
#include <new>       // std::bad_alloc
#include <iostream>  // std::cout
#include <cstddef>   // std::size_t

static bool inAllocLog = false;

// // ——— single-object new ———
void* operator new(std::size_t sz) {
    void* p = std::malloc(sz);
    if (!p) throw std::bad_alloc();

    if (!inAllocLog) {
        inAllocLog = true;
        // std::cout << "[new]       size=" << sz << " @ " << p << "\n";
        inAllocLog = false;
    }
    return p;
}

// ——— sized single-object delete (C++14+) ———
void operator delete(void* p, std::size_t sz) noexcept {
    if (!inAllocLog) {
        inAllocLog = true;
        // std::cout << "[delete]    size=" << sz << " @ " << p << "\n";
        inAllocLog = false;
    }
    std::free(p);
}

// ——— unsized single-object delete ———
void operator delete(void* p) {
    if (!inAllocLog) {
        inAllocLog = true;
        // std::cout << "[delete]    @           " << p << "\n";
        inAllocLog = false;
    }
    std::free(p);
}

// ——— array new[] ———
void* operator new[](std::size_t sz) {
    void* p = std::malloc(sz);
    if (!p) throw std::bad_alloc();

    if (!inAllocLog) {
        inAllocLog = true;
        // std::cout << "[new[]]     size=" << sz << " @ " << p << "\n";
        inAllocLog = false;
    }
    return p;
}

// ——— sized array delete[] (C++14+) ———
void operator delete[](void* p, std::size_t sz) noexcept {
    if (!inAllocLog) {
        inAllocLog = true;
        // std::cout << "[delete[]]  size=" << sz << " @ " << p << "\n";
        inAllocLog = false;
    }
    std::free(p);
}

// ——— unsized array delete[] ———
void operator delete[](void* p) noexcept {
    if (!inAllocLog) {
        inAllocLog = true;
        // std::cout << "[delete[]]  @           " << p << "\n";
        inAllocLog = false;
    }
    std::free(p);
}


#endif

#endif