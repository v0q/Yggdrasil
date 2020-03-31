#include "Precompiled.h"
#include "WindowsWindow.h"

extern bool g_IsQuitRequested;

namespace
{
    LRESULT CALLBACK wndProc(HWND _hwnd, UINT _message, WPARAM _wParam, LPARAM _lParam)
    {
        switch (_message)
        {
        case WM_CLOSE:
        {
            g_IsQuitRequested = true;
        } break;
        case WM_DESTROY:
        {
            PostQuitMessage(EXIT_SUCCESS);
        } break;
        }

        return DefWindowProc(_hwnd, _message, _wParam, _lParam);
    }
}

namespace yggdrasil
{
    const YWChar WindowsWindow::AppClassName[] = Y_TEXT("YggdrasilWindow");

    WindowsWindow::WindowsWindow()
    {

    }

    WindowsWindow::~WindowsWindow()
    {

    }

    YInt WindowsWindow::initialise(const HINSTANCE _hInstance, const YWChar *_appTitle)
    {
        WNDCLASS wndClass;
        memset(&wndClass, 0, sizeof(WNDCLASS));
        // Redraw on size change (width or height)
        wndClass.style = CS_HREDRAW | CS_VREDRAW;
        wndClass.lpfnWndProc = wndProc;
        wndClass.hInstance = _hInstance;
        // Background brush, use null as the application will paint it's own background
        //wndClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
        wndClass.hbrBackground = nullptr;
        wndClass.hCursor = LoadCursor(_hInstance, IDC_ARROW);
        wndClass.hIcon = LoadIcon(_hInstance, IDI_APPLICATION);
        // No default menu(s) (at least for now)
        wndClass.lpszMenuName = nullptr;
        // Application class name (use the same for creating a window)
        wndClass.lpszClassName = WindowsWindow::AppClassName;

        ATOM wndId = RegisterClass(&wndClass);
        if (wndId == 0)
        {
            return false;
        }

        RECT windowRect = {
             0
             , 0
             , 1280
             , 720
        };

        DWORD windowStyle = 0;
        windowStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;

        // Calculate the actual size based on the wanted size
        AdjustWindowRect(&windowRect, windowStyle, false);

        // Using hardcoded width and height values for now
        m_windowHandle = CreateWindowEx(0
            , AppClassName
            , _appTitle
            , windowStyle
            , CW_USEDEFAULT
            , CW_USEDEFAULT
            , windowRect.right - windowRect.left
            , windowRect.bottom - windowRect.top
            , nullptr
            , nullptr
            , _hInstance
            , nullptr);

        if (m_windowHandle == nullptr)
        {
            y_assert(m_windowHandle != nullptr);
            PostQuitMessage(EXIT_FAILURE);
            return 1;
        }

        ShowWindow(m_windowHandle, SW_SHOW);

        return 0;
    }

    const void WindowsWindow::dispatchMessages()
    {
        MSG message = { 0 };
        while (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
        {
            // Pass the message to the procedure
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
    }
}