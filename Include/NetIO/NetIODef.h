#ifndef _H_NETIO_DEF_H_
#define _H_NETIO_DEF_H_

#include <NetDef.h>

#ifndef NETIO_DLL
#define NETIO_DLL
#endif//

#ifdef NETIO_DLL
#ifdef NETIO_EXPORTS
#define NETIO_API __declspec(dllexport)
#else
#define NETIO_API __declspec(dllimport)
#endif
#else
#ifdef NETIO_API
#undef NETIO_API
#endif//
#endif//

#ifndef NETIO_EXPORTS
#pragma comment(lib, "NetIO.lib")
#endif//NETIO_EXPORTS

#define NETIO_UDP				"UDP"
#define NETIO_UDP_LISTEN		"UDPLISTEN"
#define NETIO_QL_4X				"QL4X"
#define NETIO_QL_4X_LISTEN		"QL4XListen"
#define NETIO_HTTP				"HTTP"

#endif//_H_NETIO_DEF_H_