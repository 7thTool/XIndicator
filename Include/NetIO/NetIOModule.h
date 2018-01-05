#ifndef _H_NETIOMODULE_H_
#define _H_NETIOMODULE_H_

#include "NetIOHandler.h"
#include "NetIOEngine.h"

class NetIOModule
{
public:
	virtual long Initialize(NetIOEngine* pNetIOEngine) = 0;
	virtual void Release() = 0;

	//virtual NetIOHandler* FindHandler(LPCSTR lpszHandlerName
	//	, LPCSTR lpszHostAddress, UINT nHostPort
	//	, PPROXYINFO pProxy = NULL, int nSockType = SOCK_STREAM, int nSockAf = AF_INET) = 0;
	virtual NetIOHandler* OpenHandler(LPCSTR lpszHandlerName
		, LPCSTR lpszHostAddress, UINT nHostPort
		, PPROXYINFO pProxy = NULL, int nSockType = SOCK_STREAM, int nSockAf = AF_INET
		, BOOL bCreateIfNotExist = TRUE) = 0;
	virtual long CloseHandler(NetIOHandler* pNetIOHandler) = 0;
};

//extern NetIOModule* _NetIOModule;

#endif//_H_NETIOMODULE_H_
