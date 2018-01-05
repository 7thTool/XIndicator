#ifndef _H_DATALISTENER_H_
#define _H_DATALISTENER_H_

#include "EvtData.h"

class DataHandler;

class DE_API DataListener : public EvtListener
{
	typedef EvtListener Base;
public:
	static DataHandler* FindHandler(LPCSTR lpszHandlerName, LPCSTR lpszUserName = NULL);
	static DataHandler* OpenHandler(LPCSTR lpszHandlerName, LPCSTR lpszUserName = NULL, BOOL bCreateIfNotExist = TRUE);
	static long CloseHandler(DataHandler* pHandler);
public:
	DataListener();
	virtual ~DataListener();

public:
};

#endif//_H_DATALISTENER_H_