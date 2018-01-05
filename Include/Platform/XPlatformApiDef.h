// XPlatformApiDef.h
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _H_XPLATFORMAPIDEF_H_
#define _H_XPLATFORMAPIDEF_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef XPLATFORMAPI_EXPORTS
#define XPLATFORM_API __declspec(dllexport)
#else
#define XPLATFORM_API __declspec(dllimport)
#endif
#ifndef XPLATFORMAPI_EXPORTS
#pragma comment(lib, "XPlatformApi.lib")
#endif//

#if defined(__cplusplus)
extern "C" {
#endif//

	//

#if defined(__cplusplus)
}

//

#endif//

#endif//_H_XPLATFORMAPIDEF_H_