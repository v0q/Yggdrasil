#include "Precompiled.h"

#if Y_PLATFORM == Y_WINDOWS
int APIENTRY YggdrasilEntryPoint(const char* _parsedCommandLine
    , HINSTANCE _hInstance
    , HINSTANCE _hPrevInstance
    , LPWSTR _lpCmdLine
    , int _nCmdShow)
#endif
{
    YInt ExitCode = 0;

#if Y_PLATFORM == Y_WINDOWS
    Y_UNUSED_VAR(_parsedCommandLine);
    Y_UNUSED_VAR(_hInstance);
    Y_UNUSED_VAR(_hPrevInstance);
    Y_UNUSED_VAR(_lpCmdLine);
    Y_UNUSED_VAR(_nCmdShow);
#endif

    return ExitCode;
}
