#ifndef _H_DATAMODULE_H_
#define _H_DATAMODULE_H_

#include "DataHandler.h"
#include "DataEngine.h"

class DataModule
{
public:
	//DataModule();
	//virtual ~DataModule();

	virtual long Initialize(DataEngine* pDataEngine) = 0;
	virtual void Release() = 0;

	//合并连接的话，使用FindHandler，没有找到就再调用CreateHandler
	//virtual DataHandler* FindHandler(LPCSTR lpszHandlerName) = 0;
	//直接创建一个新的Handler,使用CreateHandler
	virtual DataHandler* OpenHandler(LPCSTR lpszHandlerName, BOOL bCreateIfNotExist = TRUE) = 0;
	//不再使用该Handler时，就调用DestroyHandler，以释放Handler或减少Handler的引用
	virtual long CloseHandler(DataHandler* pHandler) = 0;

	virtual void OnIdle() = 0;
};

//extern "C"
//{
//	void* _DataModule();
//};

#endif//_H_DATAMODULE_H_