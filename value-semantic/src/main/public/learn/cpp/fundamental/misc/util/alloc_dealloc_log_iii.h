
#ifndef __VALUE_SEMANTIC_NDEBUG

#ifndef __LEARN_CPP_FUNDAMENTAL_MISC_UTIL_ALLOC_DEALLOC_III_H
#define __LEARN_CPP_FUNDAMENTAL_MISC_UTIL_ALLOC_DEALLOC_III_H

// memory_logger.cpp
#include <cstdlib>     // std::malloc, std::free
#include <new>         // std::bad_alloc, std::nothrow_t
#include <iostream>    // std::cout
#include <cstddef>     // std::size_t

static bool inAllocLog = false;

// —— THROWING single-object new ——
void* operator new(std::size_t size) {
    void* p = std::malloc(size);
    if (!p) throw std::bad_alloc();
    if (!inAllocLog) {
        inAllocLog = true;
        // std::cout << "[ new ] size=" << size << " @ " << p << "\n";
        std::printf("(new) %-8zu @0x%p\n", size, p );
        inAllocLog = false;
    }
    return p;
}

// —— NON-THROWING single-object new ——
void* operator new(std::size_t size, const std::nothrow_t&) noexcept {
    void* p = std::malloc(size);
    if (!inAllocLog) {
        inAllocLog = true;
        // std::cout << "[ new ] size=" << size << " nothrow @ " << p << "\n";
        std::printf("(new) %-8zu @0x%p\n", size, p );
        inAllocLog = false;
    }
    return p;
}

// —— THROWING array new[] ——
void* operator new[](std::size_t size) {
    void* p = std::malloc(size);
    if (!p) throw std::bad_alloc();
    if (!inAllocLog) {
        inAllocLog = true;
        std::printf("(new[]) %-8zu @0x%p\n", size, p );
        // std::cout << "[new[]] size=" << size << " @ " << p << "\n";
        inAllocLog = false;
    }
    return p;
}

// —— NON-THROWING array new[] ——
void* operator new[](std::size_t size, const std::nothrow_t&) noexcept {
    void* p = std::malloc(size);
    if (!inAllocLog) {
        inAllocLog = true;
        std::printf("(new[]) %-8zu @0x%p\n", size, p );
        // std::cout << "[new[]] size=" << size << " nothrow @ " << p << "\n";
        inAllocLog = false;
    }
    return p;
}

// —— SIZED single-object delete (C++14+) ——
void operator delete(void* p, std::size_t size) noexcept {
    if (!inAllocLog) {
        inAllocLog = true;
        std::printf("(delete) @0x%p\n", p );
        // std::cout << "[del  ] size=" << size << " @ " << p << "\n";
        inAllocLog = false;
    }
    std::free(p);
}

// —— UNSIZED single-object delete ——
void operator delete(void* p) noexcept {
    if (!inAllocLog) {
        inAllocLog = true;
        std::printf("(delete) @0x%p\n", p );
        // std::cout << "[del  ]         @ " << p << "\n";
        inAllocLog = false;
    }
    std::free(p);
}

// —— SIZED array delete[] (C++14+) ——
void operator delete[](void* p, std::size_t size) noexcept {
    if (!inAllocLog) {
        inAllocLog = true;
        std::printf("(delete[]) %-8zu @0x%p\n", size, p );
        // std::cout << "[del[]] size=" << size << " @ " << p << "\n";
        inAllocLog = false;
    }
    std::free(p);
}

// —— UNSIZED array delete[] ——
void operator delete[](void* p) noexcept {
    if (!inAllocLog) {
        inAllocLog = true;
        std::printf("(delete[]) @0x%p\n", p );
        // std::cout << "[del[]]        @ " << p << "\n";
        inAllocLog = false;
    }
    std::free(p);
}


#endif
#endif