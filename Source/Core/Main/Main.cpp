#include "Precompiled.h"

#include "Core/Window/Windows/WindowsWindow.h"

bool g_IsQuitRequested = false;

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
    Y_UNUSED_VAR(_hPrevInstance);
    Y_UNUSED_VAR(_lpCmdLine);
    Y_UNUSED_VAR(_nCmdShow);

    yggdrasil::hInstance = _hInstance;
    yggdrasil::WindowsWindow window;
    ExitCode |= window.initialise(yggdrasil::hInstance, Y_TEXT("Yggdrasil"));

    if (ExitCode != 0)
    {
        g_IsQuitRequested = true;
    }
    while (!g_IsQuitRequested)
    {
        window.dispatchMessages();
    }
#endif

    return ExitCode;
}
