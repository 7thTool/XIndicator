#ifndef _H_ORDERTICKET_H_
#define _H_ORDERTICKET_H_

template<class T>
class OrderTicketMap 
{
	typedef OrderTicketMap<T> This;
public:
	OrderTicketMap()
	{

	}
	~OrderTicketMap()
	{

	}

protected:

public:
	void OnResponseOrderSend(const OrderInfo& order)
	{
		
	}

	void OnOrderTicketChanged(int orderType)
	{

	}

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_DE_NOTIFY,OnNotify)
	END_EVT_MAP()

	long OnNotify(Event& evt)
	{
		switch(evt.value)
		{
		case MAKEVALUE(MNOTIFY_PLAT_DE,CNOTIFY_DE_RESPONSE_ORDERSEND):
			{
				T* pT = static_cast<T*>(this);
				N_OrderInfoPtr objPtr = N_OrderInfoPtr::dynamicCast(evt.objPtr);
				if (objPtr) {
					pT->OnResponseOrderSend(objPtr->order);
				}
				return RLT_OK;
			}
			break;
		case MAKEVALUE(MNOTIFY_PLAT_DE,CNOTIFY_DE_PUSH_ORDER):
			{
				T* pT = static_cast<T*>(this);
				pT->OnOrderTicketChanged(ORDER_TYPE_ORDER);
				return RLT_OK;
			}
			break;
		case MAKEVALUE(MNOTIFY_PLAT_DE,CNOTIFY_DE_PUSH_TRADE):
			{
				T* pT = static_cast<T*>(this);
				pT->OnOrderTicketChanged(ORDER_TYPE_TRADE);
				return RLT_OK;
			}
			break;
		case MAKEVALUE(MNOTIFY_PLAT_DE,CNOTIFY_DE_PUSH_POSITION):
			{
				T* pT = static_cast<T*>(this);
				pT->OnOrderTicketChanged(ORDER_TYPE_POSITION);
				return RLT_OK;
			}
			break;
		default:
			evt.handled = false;
			break;
		}
		return RLT_UNKNOWN;
	}
};


#endif//_H_ORDERTICKET_H_