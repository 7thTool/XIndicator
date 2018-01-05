#ifndef _H_NETIOENGINE_H_
#define _H_NETIOENGINE_H_

#include "NetIODef.h"
#include "NetIOHandler.h"

class NetIOEngine
{
public:
	//������������
	virtual long Start(const char* pX) = 0;
	//ֹͣ��������
	virtual void Stop() = 0;

	//�ϲ����ӵĻ���ʹ��FindHandler��û���ҵ����ٵ���CreateHandler
	//virtual NetIOHandler* FindHandler(LPCSTR lpszHandlerName
	//	, LPCSTR lpszHostAddress, UINT nHostPort
	//	, PPROXYINFO pProxy = NULL, int nSockType = SOCK_STREAM, int nSockAf = AF_INET) = 0;
	//ֱ�Ӵ���һ���µ�Handler,ʹ��CreateHandler
	virtual NetIOHandler* OpenHandler(LPCSTR lpszHandlerName
		, LPCSTR lpszHostAddress, UINT nHostPort, PPROXYINFO pProxy = NULL
		, int nSockType = SOCK_STREAM, int nSockAf = AF_INET
		, BOOL bCreateIfNotExist = TRUE) = 0;
	//����ʹ�ø�Handlerʱ���͵���DestroyHandler�����ͷ�Handler�����Handler������
	virtual long CloseHandler(NetIOHandler* pHandler) = 0;
};

extern NETIO_API NetIOEngine* _NetIOEngine;

#endif//_H_NETIOENGINE_H_
