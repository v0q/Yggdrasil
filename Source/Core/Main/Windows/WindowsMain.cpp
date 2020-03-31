#include "Precompiled.h"

extern HINSTANCE yggdrasil::hInstance = nullptr;

static char ParsedCommandLine[] = "";
extern int APIENTRY YggdrasilEntryPoint(const char* _parsedCommandLine
    , HINSTANCE _hInstance
    , HINSTANCE _prevInstance
    , LPWSTR _lpCmdLine
    , int _nCmdShow);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance
    , _In_opt_ HINSTANCE hPrevInstance
    , _In_ LPWSTR lpCmdLine
    , _In_ int nCmdShow)
{
    YInt ExitCode = YggdrasilEntryPoint(ParsedCommandLine, hInstance, hPrevInstance, lpCmdLine, nCmdShow);

    return ExitCode;
}
