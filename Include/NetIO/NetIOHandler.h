#ifndef _H_NETIOHANDLER_H_
#define _H_NETIOHANDLER_H_

#include "EvtNetIO.h"

class NETIO_API NetIOHandler 
	: public EvtChannelObjecterT<NetIOHandler,EvtHandler>
{
	typedef NetIOHandler This;
	typedef EvtChannelObjecterT<NetIOHandler,EvtHandler> Base;
public:

	virtual void RegisterListener(EvtObjecter* pListener);
	virtual void UnRegisterListener(EvtObjecter* pListener);
};

#endif//_H_NETIOHANDLER_H_
