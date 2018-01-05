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
	
	//合并连接的话，使用FindHandler，没有找到就再调用CreateHandler
	//virtual DataHandler* FindHandler(LPCSTR lpszHandlerName, LPCSTR lpszUserName = NULL) = 0;
	//直接创建一个新的Handler,使用CreateHandler
	virtual DataHandler* OpenHandler(LPCSTR lpszHandlerName, LPCSTR lpszUserName = NULL, BOOL bCreateIfNotExist = TRUE) = 0;
	//不再使用该Handler时，就调用DestroyHandler，以释放Handler或减少Handler的引用
	virtual long CloseHandler(DataHandler* pHandler) = 0;
};

extern DE_API DataEngine* _DataEngine;

#endif//_H_DATAENGINE_H_