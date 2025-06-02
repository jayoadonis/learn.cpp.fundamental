#ifndef __VALUE_SEMANTIC_NDEBUG

#ifndef __LEARN_CPP_FUNDAMENTAL_MISC_UTIL_ALLOC_DEALLOC_LOG_H
#define __LEARN_CPP_FUNDAMENTAL_MISC_UTIL_ALLOC_DEALLOC_LOG_H

#include <new>        //REM: for std::bad_alloc, std::nothrow_t
#include <cstdlib>    //REM: for std::malloc, std::free
#include <iostream>   //REM: for std::cout
#include <cstddef>    //REM: for std::size_t

static bool inNewDelete = false;

// // single‐object new
void* operator new(std::size_t sz) {
    void* p = std::malloc(sz);
    if (!p) throw std::bad_alloc();

    if (!inNewDelete) {
        inNewDelete = true;
        std::cout << "[new]  size=" << sz << " @ " << p << "\n";
        inNewDelete = false;
    }
    return p;
}

// single‐object delete
void operator delete(void* p) noexcept { 
    if (!inNewDelete) {
        inNewDelete = true;
        std::cout << "[del]         @ " << p << "\n";
        inNewDelete = false;
    }
    std::free(p);
}

// sized deallocation (C++14+)
void operator delete(void* p, std::size_t sz) noexcept {
    if (!inNewDelete) {
        inNewDelete = true;
        std::cout << "[del]  size=" << sz << " @ " << p << "\n";
        inNewDelete = false;
    }
    std::free(p);
}

// ------ array‐new/delete ------

void* operator new[](std::size_t size) {
    void* p = std::malloc(size);
    if (!p) throw std::bad_alloc();
    std::cout << "[new[]] size=" << size << " @ " << p << "\n";
    return p;
}

void operator delete[](void* p) noexcept {
    std::cout << "[del[]]        @ " << p << "\n";
    std::free(p);
}

void operator delete[](void* p, std::size_t size) noexcept {
    std::cout << "[del[]] size=" << size << " @ " << p << "\n";
    std::free(p);
}


// static void log_alloc(const char* what, std::size_t size, void* p) {
//     std::cout << what 
//               << " size=" << size 
//               << " addr=" << p 
//               << "\n";
// }

// // void* operator new(std::size_t size) {
// //     void* p = std::malloc(size);
// //     if (!p) throw std::bad_alloc();
// //     log_alloc("alloc", size, p);
// //     return p;
// // }

// void* operator new[](std::size_t size) {
//     void* p = std::malloc(size);
//     if (!p) throw std::bad_alloc();
//     log_alloc("alloc[]", size, p);
//     return p;
// }

// // void operator delete(void* p) noexcept {
// //     if (p) {
// //         log_alloc(" free", 0, p);
// //         std::free(p);
// //     }
// // }

// void operator delete[](void* p) noexcept {
//     if (p) {
//         log_alloc(" free[]", 0, p);
//         std::free(p);
//     }
// }

// // void* operator new(std::size_t size, const std::nothrow_t&) noexcept {
// //     void* p = std::malloc(size);
// //     log_alloc("alloc(nothrow)", size, p);
// //     return p;
// // }

// // void* operator new[](std::size_t size, const std::nothrow_t&) noexcept {
// //     void* p = std::malloc(size);
// //     log_alloc("alloc[] (nothrow)", size, p);
// //     return p;
// // }

// // void operator delete(void* p, const std::nothrow_t&) noexcept {
// //     if (p) {
// //         log_alloc(" free(nothrow)", 0, p);
// //         std::free(p);
// //     }
// // }

// // void operator delete[](void* p, const std::nothrow_t&) noexcept {
// //     if (p) {
// //         log_alloc(" free[](nothrow)", 0, p);
// //         std::free(p);
// //     }
// // }

#endif

#endif