#pragma once

#include "Platform.h"

#if Y_PLATFORM == Y_WINDOWS
    #include <assert.h>

    #if Y_BUILD == Y_DEBUG
    //#define y_assert(predicate) ((predicate) ? ((void)0) : (DbgRaiseAssertionFailure()))
    #define y_assert(predicate) ((predicate) ? ((void)0) : (__debugbreak()))
    //#define y_assert(predicate) ((predicate) ? ((void)0) : (_ASSERT(predicate)))
    //#define y_assert(predicate) ((predicate) ? ((void)0) : (__asm { int 3 }))
    #else
    // Assert will not have any effect in release build later, but for building and debugging
    // we'll trigger debug breaks on asserts in release as well.
    //#define y_assert(predicate) ((void)0);
    //#define y_assert(predicate) assert((predicate))
    #define y_assert(predicate) ((predicate) ? ((void)0) : (__debugbreak()))
    #endif
#elif Y_PLATFORM == Y_MAC
    #define y_assert(predicate) ((void)0)
#endif
