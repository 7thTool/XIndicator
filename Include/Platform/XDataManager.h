#ifndef _H_XDATAMANAGERIMPL_H_
#define _H_XDATAMANAGERIMPL_H_

#include <Util/Objecter.h>
#include <Util/ObjecterMap.h>
#include <DataEngine/DataListener.h>

class XDataManager 
	: public EvtListenerT<DataHandler,DataListener>
	, public EvtRequestT<XDataManager,Event,EventLess>
	, public EvtIdler
	, virtual public Objecter
	, public ObjecterMap<XDataManager>
{
	typedef XDataManager This;
	typedef EvtListenerT<DataHandler,DataListener> Base;
	typedef EvtListenerT<DataHandler,DataListener> Listener;
	typedef EvtRequestT<XDataManager,Event,EventLess> EvtRequest;
protected:
	CriticalSection m_Section;
	AccountListInfoPtr m_AccountListPtr;
	ServerListInfoPtr m_ServerListPtr;
	OnlineListInfoPtr m_OnlineListPtr;
	/*typedef std::vector<DataHandler*> pHandlers;
	//认证对象是以Register结尾的对象，比如QL4XRegister
	pHandlers m_pRegisters;
	//行情或者其他对象（按需）
	pHandlers m_pExchanges;
	//交易对象是以Trader结尾的对象，比如CTPTrader
	pHandlers m_pTraders;
	//其他对象
	//std::vector<DataHandler*> m_pOthers;*/
	//typedef std::map<DataHandler*,OnlineInfoPtr> m_pHandler2OnlineInfoPtr;

public:
	XDataManager();
	virtual ~XDataManager();

	long Instance();
	void Release();

	void LoadFromFile(AccountInfoPtr objPtr);
	void SaveToFile(AccountInfoPtr objPtr);

	/*void OnAccountInfoChanged()
	{//这里处理增加和删除帐号，和帐号下的相关服务
		int i=0;

		Init();

		DataHandler* pExchange = NULL;
		while(pExchange = FindExchangeBy(i++))
		{
			SendToHandler(pExchange, EVT_DE_SET, SET_DE_ACCOUNTINFO, m_AccountPtr);
		}
	}*/

public:
	virtual void OnIdle(unsigned int tick);

protected:
	enum
	{
		FIND_FLAG_NONE				= 0,
		FIND_FLAG_ADD_IFNOTEXIST	= 0X01,
		FIND_FLAG_REMOVE_IFEXIST	= 0X02,
		FIND_FLAG_UPDATE_IFEXIST	= 0X04,
		FIND_FLAG_GET_IFEXIST		= 0X08,
	};

	bool AddAccount(const AccountInfoPtr & objPtr);
	bool RemoveAccount(const AccountInfoPtr & objPtr);
	bool UpdateAccount(const AccountInfoPtr & objPtr);
	bool FindAccount(AccountInfoPtr & objPtr, UINT nFlags = FIND_FLAG_NONE);
	bool FindAccount(AccountInfoPtr & objPtr, LPCSTR lpszName, LPCSTR lpszUser, UINT nFlags = FIND_FLAG_NONE);
	bool FindAccountByPos(AccountInfoPtr & objPtr, int Pos);

	bool AddServer(const ServerInfoPtr & objPtr);
	bool RemoveServer(const ServerInfoPtr & objPtr);
	bool UpdateServer(const ServerInfoPtr & objPtr);
	bool FindServer(ServerInfoPtr & objPtr, UINT nFlags = FIND_FLAG_NONE);
	bool FindServer(ServerInfoPtr & objPtr, LPCSTR lpszName, LPCSTR lpszUser, UINT nFlags = FIND_FLAG_NONE);
	bool FindServerByPos(ServerInfoPtr & objPtr, int Pos);

	bool AddOnline(const OnlineInfoPtr & objPtr);
	bool RemoveOnline(const OnlineInfoPtr & objPtr);
	bool UpdateOnline(const OnlineInfoPtr & objPtr);
	bool FindOnline(OnlineInfoPtr & objPtr, UINT nFlags = FIND_FLAG_NONE);
	bool FindOnline(OnlineInfoPtr & objPtr, LPCSTR lpszName, LPCSTR lpszUser, UINT nFlags = FIND_FLAG_NONE);
	bool FindOnlineByPos(OnlineInfoPtr & objPtr, int Pos);

	DataHandler* OpenHandler(LPCSTR lpszName, LPCSTR lpszUser = NULL);
	void CloseHandler(DataHandler* pHandler);
	DataHandler* FindHandler(LPCSTR lpszName, LPCSTR lpszUser = NULL);

	//////////////////////////////////////////////////////////////////////////
	//这里实现应用层和数据层切换，保证应用层和数据层事件和消息处理只在主线程
	//完成，这样就应用层就不用关心多线程问题了。
protected:
	DataHandler* FindFullQuoter(const unsigned char Exchange);
	DataHandler* FindSupporter(const unsigned long Exchange, bool bTradeOrQuote = false, LPCSTR lpszName = NULL);//可以是市场或KIND
	DataHandler* FindSelector(const unsigned long Exchange, bool bTradeOrQuote = false, LPCSTR lpszName = NULL);//可以是市场或KIND

	DataHandler* FindSuitable(const unsigned long Exchange, bool bTradeOrQuote = false, LPCSTR lpszName = NULL, LPCSTR lpszUser = NULL);
	DataHandler* FindSuitable(const KIND& Kind, bool bTradeOrQuote = false, LPCSTR lpszName = NULL, LPCSTR lpszUser = NULL);
	DataHandler* FindSuitable(const COMREF & Commodity, bool bTradeOrQuote = false, LPCSTR lpszName = NULL, LPCSTR lpszUser = NULL);

	BOOL IsRegister(LPCSTR lpszName);
	BOOL IsExchange(LPCSTR lpszName);
	BOOL IsTrader(LPCSTR lpszName);

	/*BOOL IsRegister(DataHandler* pHandler);
	BOOL IsExchange(DataHandler* pHandler);
	BOOL IsTrader(DataHandler* pHandler);*/

	/*
	DataHandler* FindExchangeBy(const int Pos);
	DataHandler* FindExchangeBy(const char* szExchange);
	DataHandler* FindExchangeBy(const wchar_t* szExchange);
	DataHandler* FindExchangeBy(const unsigned char Exchange);
	DataHandler* FindExchangeBy(const COMREF &  Commodity);

	DataHandler* FindTraderBy(const int Pos);*/
	
public:
	virtual void OnRemoveRequest(const Event& Req,const Event& SubReq);
	virtual void OnAddRequest(const Event& Req, const Event& SubReq);
	virtual void OnUpdateRequest(const Event& Req, const Event& SubReq, long SubReqCount);

protected:
	virtual void OnOffline(OnlineInfoPtr& objPtr);
	virtual void OnInitData(OnlineInfoPtr& objPtr);
	virtual void OnOnline(OnlineInfoPtr& objPtr);
	unsigned char IsOnline(LPCSTR lpszName, LPCSTR lpszUser = NULL);

protected:
	KindInfo m_SelfKind[KIND_INDEX_SELFMAX];
	std::vector<unsigned long> m_SelfKindIdxs;
	COMREFLIST m_SelfCommoditys[KIND_INDEX_SELFMAX];
	struct CommodityAttrLess
	{
		bool operator()(const CommodityAttr& x, const CommodityAttr& y) const
		{
			return x.Commodity < y.Commodity;
		}
	};
	typedef std::set<CommodityAttr,CommodityAttrLess> CommodityAttrs;
	CommodityAttrs m_CommodityAttrs;
	bool m_bSelfChanged;

	void LoadSelfCommodity(LPCTSTR lpszFileName);
	void SaveSelfCommodity(LPCTSTR lpszFileName);

	typedef std::vector<HisDataInfoPtr> HisDataInfos;
	HisDataInfos m_HisDataInfos;
	long RefHisData(HisDataInfoPtr& objPtr);
	void CleanHisData(const COMREF & Commodity, ENUM_TIMEFRAMES Period);
	void CleanHisData(const unsigned char Exchange);
	void UpdateHisData(const COMREF & Commodity, ENUM_TIMEFRAMES Period);

	//事件都在主线程处理，所以不用加锁,请求相关需要加锁，应该需要映射请求和子请求
	BEGIN_EVT_MAP(This)
		//界面过来事件
		ON_EVT(EVT_PLAT_CALL,OnCall)
		ON_EVT(EVT_PLAT_POST,OnRequest)
		//数据层过来事件
		ON_EVT(EVT_DE_NOTIFY,OnNotify)
	END_EVT_MAP()

	long OnCall(Event& evt);
	long OnRequest(Event& evt);
	long OnNotify(Event& evt);
};

//////////////////////////////////////////////////////////////////////////

/*class XDataEngine
	: public XDataManager
	, public Objecter
{
	typedef XDataEngine This;
	typedef XDataManager Base;

public:
	long Instance();
	void Release();
};*/

#endif//_H_XDATAMANAGERIMPL_H_