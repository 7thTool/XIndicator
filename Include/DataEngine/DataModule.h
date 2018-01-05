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

	//�ϲ����ӵĻ���ʹ��FindHandler��û���ҵ����ٵ���CreateHandler
	//virtual DataHandler* FindHandler(LPCSTR lpszHandlerName) = 0;
	//ֱ�Ӵ���һ���µ�Handler,ʹ��CreateHandler
	virtual DataHandler* OpenHandler(LPCSTR lpszHandlerName, BOOL bCreateIfNotExist = TRUE) = 0;
	//����ʹ�ø�Handlerʱ���͵���DestroyHandler�����ͷ�Handler�����Handler������
	virtual long CloseHandler(DataHandler* pHandler) = 0;

	virtual void OnIdle() = 0;
};

//extern "C"
//{
//	void* _DataModule();
//};

#endif//_H_DATAMODULE_H_