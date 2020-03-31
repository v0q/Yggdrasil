#pragma once

#include "Platform.h"

#if Y_PLATFORM == Y_WINDOWS
    typedef unsigned __int8 YUChar;
    typedef unsigned __int16 YUShort;
    typedef unsigned __int32 YUInt;
    typedef unsigned __int64 YUIntBig;

    typedef size_t YSizeType;

    typedef __int16 YShort;
    typedef __int32 YInt;
    typedef __int64 YIntBig;

    typedef __int8 YChar;
    typedef wchar_t YWChar;
#else
    typedef unsigned char YUChar;
    typedef unsigned short YUShort;
    typedef unsigned int YUInt;
    typedef unsigned long long YUIntBig;
    typedef size_t YSizeType;

    typedef short YShort;
    typedef int YInt;
    typedef long long YIntBig;
#endif
