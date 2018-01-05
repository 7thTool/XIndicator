#ifndef _H_NETIOENGINE_H_
#define _H_NETIOENGINE_H_

#include "NetIODef.h"
#include "NetIOHandler.h"

class NetIOEngine
{
public:
	//启动网络引擎
	virtual long Start(const char* pX) = 0;
	//停止网络引擎
	virtual void Stop() = 0;

	//合并连接的话，使用FindHandler，没有找到就再调用CreateHandler
	//virtual NetIOHandler* FindHandler(LPCSTR lpszHandlerName
	//	, LPCSTR lpszHostAddress, UINT nHostPort
	//	, PPROXYINFO pProxy = NULL, int nSockType = SOCK_STREAM, int nSockAf = AF_INET) = 0;
	//直接创建一个新的Handler,使用CreateHandler
	virtual NetIOHandler* OpenHandler(LPCSTR lpszHandlerName
		, LPCSTR lpszHostAddress, UINT nHostPort, PPROXYINFO pProxy = NULL
		, int nSockType = SOCK_STREAM, int nSockAf = AF_INET
		, BOOL bCreateIfNotExist = TRUE) = 0;
	//不再使用该Handler时，就调用DestroyHandler，以释放Handler或减少Handler的引用
	virtual long CloseHandler(NetIOHandler* pHandler) = 0;
};

extern NETIO_API NetIOEngine* _NetIOEngine;

#endif//_H_NETIOENGINE_H_
