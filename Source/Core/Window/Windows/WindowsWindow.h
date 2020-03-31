#pragma once

#include "Platform/PlatformWindows.h"

namespace yggdrasil
{
    class WindowsWindow
    {
    public:
        static const YWChar AppClassName[];
    public:
        WindowsWindow();
        ~WindowsWindow();

        YInt initialise(const HINSTANCE _hInstance, const YWChar* _appTitle);
        const void dispatchMessages();
    private:

        HWND m_windowHandle = nullptr;
    };
}