// PlatformApiDef.h
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _H_PLATFORMAPIDEF_H_
#define _H_PLATFORMAPIDEF_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef PLATFORMAPI_EXPORTS
#define PLATFORM_API __declspec(dllexport)
#else
#define PLATFORM_API __declspec(dllimport)
#endif
#ifndef PLATFORMAPI_EXPORTS
#pragma comment(lib, "PlatformApi.lib")
#endif//

#if defined(__cplusplus)
extern "C" {
#endif//

	//

#if defined(__cplusplus)
}

//

#endif//

#endif//_H_PLATFORMAPIDEF_H_
