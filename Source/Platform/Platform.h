#pragma once

#define Y_WINDOWS 0x00001001
#define Y_LINUX   0x00001010
#define Y_MAC     0x00001100

#define Y_RELEASE 0x10010000
#define Y_DEBUG   0x10100000

// Build specific
#if defined(RELEASE)
    #define Y_BUILD Y_RELEASE
#elif defined(DEBUG)
    #define Y_BUILD Y_DEBUG
#endif

// Platform definitions
#if defined(_WIN64)
    #define Y_PLATFORM Y_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
    #define Y_PLATFORM Y_MAC
#elif defined(__linux__)
    #define Y_PLATFORM Y_LINUX
#else
    #error Invalid platform or unable to determine the platform correctly
#endif

#define __yggdrasil_internal_to_text(text) L ## text

// Various helper macros, should be moved elsewhere?
// Definitely should be moved elsewhere
#define Y_UNUSED_VAR(var) (void)(var);
#define Y_ARR_SIZE(arr) (sizeof(*__y_sizeof(arr)))
#define Y_TEXT(text) __yggdrasil_internal_to_text(text)

template <typename T, size_t N>
char(*__y_sizeof(T(&arr)[N]))[N];
