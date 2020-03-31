#pragma once

#include "Platform/Assertions.h"
#include "Platform/Platform.h"
#include "Platform/TypeDefs.h"

#if Y_PLATFORM == Y_WINDOWS
    #include "Platform/PlatformWindows.h"
#endif