// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

#define USE_PLATFORMAPI	0

#define USE_XPLATFORMAPI 1

#if USE_PLATFORMAPI || USE_XPLATFORMAPI

#include <windows.h> 
#include <stdlib.h>
#include <wtypes.h>

#include <ShlObj.h>
#include <Shlwapi.h>
#include <ShellAPI.h>
#include <Psapi.h>
//#pragma comment(lib, "ShlObj.lib")
#pragma comment(lib, "Shlwapi.lib")
//#pragma comment(lib, "ShellAPI.lib")
#pragma comment(lib, "Psapi.lib")

#else

#include <XLib/XLib.h>
#include <XLib/XSocket.h>

#include <NetIO/NetIO.h>
#pragma comment(lib, "NetIO.lib")

#include <DataEngine/DataEngine.h>
#pragma comment(lib, "DataEngine.lib")

#pragma comment(lib, "XPlatformLib.lib")
#pragma comment(lib, "XLogin.lib")

#endif//
