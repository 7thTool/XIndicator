#ifndef _H_DATAENGINE_H_
#define _H_DATAENGINE_H_

#include "DEDef.h"
#include "DataHandler.h"

class DataEngine : public DataHandler
{
public:
	//DataEngine();
	//virtual ~DataEngine();

	virtual long Start(void*) = 0;
	virtual void Stop() = 0;

	virtual LPCSTR GetAppPath() = 0;
	virtual LPCSTR GetAppData() = 0;
	virtual LPCSTR GetWorkDir() = 0;
	
	//�ϲ����ӵĻ���ʹ��FindHandler��û���ҵ����ٵ���CreateHandler
	//virtual DataHandler* FindHandler(LPCSTR lpszHandlerName, LPCSTR lpszUserName = NULL) = 0;
	//ֱ�Ӵ���һ���µ�Handler,ʹ��CreateHandler
	virtual DataHandler* OpenHandler(LPCSTR lpszHandlerName, LPCSTR lpszUserName = NULL, BOOL bCreateIfNotExist = TRUE) = 0;
	//����ʹ�ø�Handlerʱ���͵���DestroyHandler�����ͷ�Handler�����Handler������
	virtual long CloseHandler(DataHandler* pHandler) = 0;
};

extern DE_API DataEngine* _DataEngine;

#endif//_H_DATAENGINE_H_