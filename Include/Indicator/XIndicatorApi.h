#ifndef _H_XINDICATORAPI_H_
#define _H_XINDICATORAPI_H_

#include "XIndicatorDef.h"

//---------------------------------------------------------------------------
// API Export/Import Macros
//---------------------------------------------------------------------------
/** Indicates an exported and imported shared library function. */
#ifdef XINDICATOR_EXPORTS
#define XINDICATOR_API __declspec(dllexport)
#else
#define XINDICATOR_API __declspec(dllimport)
#endif
#ifndef XINDICATOR_EXPORTS
#pragma comment(lib, "XIndicator.lib")
#endif//

#if defined(__cplusplus)
extern "C" {
#endif//

//---------------------------------------------------------------------------
// 辅助函数
// C/C++接口提供的位置还是数组索引顺序
// 脚本接口提供的是引用位置，即数组相反，当前交易周期为0，前一交易周期为1，以
// 此类推，可以用iReversePos来互相转换
//---------------------------------------------------------------------------

/**
    * @brief 反向位置 
    * @param[in] pos 正向位置
    * @param[in] count 位置总数
    * @return 反向位置
    */
int iReversePos(int pos, int count);

/**
    * @brief 输出日志 
    * @param[in] level 日志级别
    * @param[in] str 日志内容
    * @return 无
    */
XINDICATOR_API void iLogA(INDICATOR_LOG_LEVEL level, const char* str);
XINDICATOR_API void iLogW(INDICATOR_LOG_LEVEL level, const wchar_t* str);
#ifndef UNICODE
#define iLog iLogA
#else
#define iLog iLogW
#endif//

/**
    * @brief 空值/无效值判断 
    * @param[in] value 需要判断的值
    * @return 返回说明
    *        -<em>0</em> 不是空值，是有效值
    *        -<em>非0</em> 是空值/无效值
    */
XINDICATOR_API int iIsEmptyValue(double value);

//---------------------------------------------------------------------------
// 数据接口
//---------------------------------------------------------------------------

/**
    * @brief iRefData/iRefFieldData/iRefDataEx引用数据
    * @param[in] symbol 代码
	* @param[in] period 周期
	* @param[in] flags 引用标志
    * @return 返回说明
    *        -<em>0</em> 引用失败
    *        -<em>非0</em> 引用数据句柄
	* @note 引用数据成功后，必须使用iReleaseData函数关闭
    * @par 示例:
    * @code
    *        voidptr dataptr = iRefData("600000.SH", INDICATOR_PERIOD_DAY);
	*		 if(dataptr) {
	*			iReleaseData(dataptr);
	*		 }
    * @endcode
    */
XINDICATOR_API voidptr iRefData(const char* symbol, int period);
XINDICATOR_API voidptr iRefFieldData(const char* symbol);
XINDICATOR_API voidptr iRefDataEx(const char* symbol, int period, unsigned long flags);
/**
    * @brief 请求数据 
    * @param[in] dataptr 数据句柄
    * @return 无
    */
XINDICATOR_API void iRequestData(voidptr dataptr);
/**
    * @brief 释放数据 
    * @param[in] dataptr 数据句柄
    * @return 无
    */
XINDICATOR_API void iReleaseData(voidptr dataptr);

/**
    * @brief 获取代码 
    * @param[in] dataptr 数据句柄
    * @return 代码
    */
XINDICATOR_API const char* iSymbol(voidptr dataptr);
/**
    * @brief 获取周期 
    * @param[in] dataptr 数据句柄
    * @return 周期
    */
XINDICATOR_API int iPeriod(voidptr dataptr);
/**
    * @brief 获取价格小数位数 
    * @param[in] dataptr 数据句柄
    * @return 小数位数
    */
XINDICATOR_API int iDigits(voidptr dataptr);

/**
    * @brief 获取快照字段值 
    * @param[in] field 字段
    * @param[in] dataptr 数据句柄
    * @return 字段值
    */
XINDICATOR_API double iField(INDICATOR_FIELD field, voidptr dataptr);

/**
    * @brief 获取句柄数据数目
    * @param[in] dataptr 数据句柄
    * @return 数目
    */
XINDICATOR_API int iDataCount(voidptr dataptr);

/**
    * @brief 获取行情日期/时间 
    * @param[in] offset 数据偏移
    * @param[in] dataptr 数据句柄
    * @return 日期/时间
    */
XINDICATOR_API unsigned int iPriceDate(int offset, voidptr dataptr);
XINDICATOR_API unsigned int iPriceTime(int offset, voidptr dataptr);
/**
    * @brief 获取行情价格 
    * @param[in] price 价格类型
    * @param[in] offset 数据偏移
    * @param[in] dataptr 数据句柄
    * @return 价格
    */
XINDICATOR_API double iPrice(INDICATOR_APPLIED_PRICE price, int offset, voidptr dataptr);

/**
    * @brief 获取财务数据 
    * @param[in] finance 财务数据类型
    * @param[in] offset 数据偏移
    * @param[in] dataptr 数据句柄
    * @return 财务数据值
    */
XINDICATOR_API double iFinance(int finance, int offset, voidptr dataptr);

//---------------------------------------------------------------------------
// 引用指标
//---------------------------------------------------------------------------

/**
    * @brief iRef/iRefPool引用指标/策略
    * @param[in] symbol 代码
	* @param[in] period 周期
    * @param[in] name 指标/策略名
	* @param[in] xml 指标/策略XML格式参数
	* @param[in] xmlflag XML标志
    * @return 指标句柄
	* @note 引用指标/策略成功后，必须使用iRelease函数释放指标/策略
    * @par 示例:
    * @code
    *        iHandle hMA = iRefA("600000.SH", INDICATOR_PERIOD_DAY, "MA", NULL, XML_FLAG_STREAM);
	*		 if(hMA) {
	*			iRelease(hMA);
	*		 }
    * @endcode
    */
XINDICATOR_API iHandle iRefA(const char* symbol, int period, const char* name, const char* xml, int xmlflag);
XINDICATOR_API iHandle iRefW(const char* symbol, int period, const wchar_t* name, const wchar_t* xml, int xmlflag);
XINDICATOR_API iHandle iRefPoolA(const char* name, const char* xml, int xmlflag);
XINDICATOR_API iHandle iRefPoolW(const wchar_t* name, const wchar_t* xml, int xmlflag);
#ifndef UNICODE
#define iRef iRefA
#define iRefPool iRefPoolA
#else
#define iRef iRefW
#define iRefPool iRefPoolW
#endif//
XINDICATOR_API void iRelease(iHandle h);

/**
    * @brief iTest/iTestPool测试指标/策略
    * @param[in] symbol 代码
	* @param[in] period 周期
    * @param[in] name 指标/策略名
	* @param[in] xml 指标/策略XML格式参数
	* @param[in] xmlflag XML标志
    * @return 指标句柄
	* @note 测试指标/策略成功后，必须使用iRelease函数释放指标/策略
    * @par 示例:
    * @code
    *        iHandle hMA = iTestA("600000.SH", INDICATOR_PERIOD_DAY, "MA", NULL, XML_FLAG_STREAM);
	*		 if(hMA) {
	*			iRelease(hMA);
	*		 }
    * @endcode
    */
XINDICATOR_API iHandle iTestA(const char* symbol, int period, const char* name, const char* xml, int xmlflag);
XINDICATOR_API iHandle iTestW(const char* symbol, int period, const wchar_t* name, const wchar_t* xml, int xmlflag);
XINDICATOR_API iHandle iTestPoolA(const char* name, const char* xml, int xmlflag);
XINDICATOR_API iHandle iTestPoolW(const wchar_t* name, const wchar_t* xml, int xmlflag);
#ifndef UNICODE
#define iTest iTestA
#define iTestPool iTestPoolA
#else
#define iTest iTestW
#define iTestPool iTestPoolW
#endif//

//XINDICATOR_API LPCTSTR iGetName(iHandle handle);
/**
    * @brief 获取指标类型 
    * @param[in] handle 指标句柄
    * @return 指标类型
    */
XINDICATOR_API long iGetType(iHandle handle);
/**
    * @brief 获取指标风格 
    * @param[in] handle 指标句柄
    * @return 指标风格
    */
XINDICATOR_API long iGetStyle(iHandle handle);
/**
    * @brief 获取指标输入参数值
    * @param[in] name 参数名
    * @param[out] str 接收参数值数组
    * @param[out] len 接收参数值数组长度
    * @param[in] handle 指标句柄
    * @return 参数值
    */
XINDICATOR_API const char* iGetInputA(const char* name, char* str, int len, iHandle handle);
XINDICATOR_API const wchar_t* iGetInputW(const wchar_t* name, wchar_t* str, int len, iHandle handle);
/**
    * @brief 获取指标输入参数值 
    * @param[in] name 参数名
    * @param[in] handle 指标句柄
    * @return 参数值
    */
XINDICATOR_API double iGetInputValueA(const char* name, iHandle handle);
XINDICATOR_API double iGetInputValueW(const wchar_t* name, iHandle handle);
#ifndef UNICODE
#define iGetInput iGetInputA
#define iGetInputValue iGetInputValueA
#else
#define iGetInput iGetInputW
#define iGetInputValue iGetInputValueW
#endif//

/**
    * @brief 获取指标线数目
    * @param[in] handle 指标句柄
    * @return 指标线数
    */
XINDICATOR_API long iGetIndexCount(iHandle handle);
/**
    * @brief 获取指标线名字
    * @param[in] index 指标线索引
    * @param[out] str 接收指标线名字数组
    * @param[out] len 接收指标线名字数组长度
    * @param[in] handle 指标句柄
    * @return 指标线名字
    */
XINDICATOR_API const char* iGetIndexNameA(int index, char* str, int len, iHandle handle);
XINDICATOR_API const wchar_t* iGetIndexNameW(int index, wchar_t* str, int len, iHandle handle);
#ifndef UNICODE
#define iGetIndexName iGetIndexNameA
#else
#define iGetIndexName iGetIndexNameW
#endif//
/**
    * @brief 获取指标线风格
    * @param[in] index 指标线索引
    * @param[in] handle 指标句柄
    * @return 指标线风格
    */
XINDICATOR_API long iGetIndexStyle(int index, iHandle handle);
/**
    * @brief 获取指标线小数位数
    * @param[in] index 指标线索引
    * @param[in] handle 指标句柄
    * @return 指标线小数位数
    */
XINDICATOR_API long iGetIndexDigits(int index, iHandle handle);
/**
    * @brief 获取指标线偏移
    * @param[in] index 指标线索引
    * @param[in] handle 指标句柄
    * @return 指标线偏移
    */
XINDICATOR_API long iGetIndexShift(int index, iHandle handle);
/**
    * @brief 获取指标线绘制开始位置
    * @param[in] index 指标线索引
    * @param[in] handle 指标句柄
    * @return 指标线绘制开始位置
    */
XINDICATOR_API long iGetIndexDrawBegin(int index, iHandle handle);
/**
    * @brief 获取指标线绘制方式
    * @param[in] index 指标线索引
    * @param[in] handle 指标句柄
    * @return 指标线绘制方式
    */
XINDICATOR_API long iGetIndexDraw(int index, iHandle handle);
/**
    * @brief 获取指标线线型
    * @param[in] index 指标线索引
    * @param[in] handle 指标句柄
    * @return 指标线线型
    */
XINDICATOR_API long iGetIndexLine(int index, iHandle handle);
/**
    * @brief 获取指标线关联指标线
    * @param[in] index 指标线索引
    * @param[in] handle 指标句柄
    * @return 指标线关联指标线
    */
XINDICATOR_API long iGetIndexNext(int index, iHandle handle);
/**
    * @brief 获取指标线宽度
    * @param[in] index 指标线索引
    * @param[in] handle 指标句柄
    * @return 指标线宽度
    */
XINDICATOR_API long iGetIndexWidth(int index, iHandle handle);
/**
    * @brief 获取指标线颜色
    * @param[in] index 指标线索引
    * @param[in] handle 指标句柄
    * @return 指标线颜色
    */
XINDICATOR_API COLORREF iGetIndexColor(int index, iHandle handle);

/**
    * @brief 获取指标数据数目
    * @param[in] handle 指标句柄
    * @return 指标数据数目
    */
XINDICATOR_API long iGetPriceCount(iHandle handle);
/**
    * @brief 获取指标数据日期/时间
    * @param[in] offset 数据偏移
    * @param[in] handle 指标句柄
    * @return 指标数据日期/时间
    */
XINDICATOR_API unsigned long iGetPriceDate(int offset, iHandle handle);
XINDICATOR_API unsigned long iGetPriceTime(int offset, iHandle handle);
/**
    * @brief 获取指标数据值
    * @param[in] index/line 指标线索引
    * @param[in] offset 数据偏移
    * @param[in] handle 指标句柄
    * @return 指标数据值
    */
XINDICATOR_API double iGetIndexValue(int index, int offset, iHandle handle);
XINDICATOR_API double iGetLineValue(int line , int offset, iHandle handle);
/**
    * @brief 获取指标价格
    * @param[in] price 价格类型
    * @param[in] offset 数据偏移
    * @param[in] handle 指标句柄
    * @return 价格值
    */
XINDICATOR_API double iGetPriceValue(int price, int offset, iHandle handle);
#define iGetVolumeValue(offset,handle) iGetPriceValue(PRICE_VOLUME,offset,handle)
#define iGetAmountValue(offset,handle) iGetPriceValue(PRICE_AMOUNT,offset,handle)
/**
    * @brief 获取指标财务数据
    * @param[in] field 财务字段
    * @param[in] offset 数据偏移
    * @param[in] handle 指标句柄
    * @return 价格值
    */
XINDICATOR_API double iGetFinanceValue(int finance, int offset, iHandle handle);
/**
    * @brief 获取指标快照字段值
    * @param[in] field 字段类型
    * @param[in] handle 指标句柄
    * @return 字段值
    */
XINDICATOR_API double iGetFieldValue(INDICATOR_FIELD field, iHandle handle);
/**
    * @brief 获取指标mmx值
    * @param[in] mmx mmx类型
    * @param[in] handle 指标句柄
    * @return mmx值
    */
XINDICATOR_API long iGetMmxOffset(int index, int mmx, iHandle handle);
XINDICATOR_API double iGetMmxValue(int index, int mmx, iHandle handle);

/**
    * @brief 获取策略池监控商品数量
    * @param[in] handle 指标句柄
    * @return 商品数量
    */
XINDICATOR_API int iPoolsTotal(iHandle handle);
/**
    * @brief 获取策略池监控商品
    * @param[in] offset 商品索引
    * @param[in] str 接收商品代码数组
    * @param[in] len 接收商品代码数组长度
    * @param[in] handle 指标句柄
    * @return 返回说明
    *        -<em>0</em> 失败
    *        -<em>非0</em> 成功
    */
XINDICATOR_API int iPoolSelect(int offset, char* str, int len, iHandle handle);

/**
    * @brief 判断指标是不是交易指标/策略
    * @param[in] handle 指标句柄
    * @return 返回说明
    *        -<em>0</em> 不是
    *        -<em>非0</em> 是
    */
XINDICATOR_API int iIsTrade(iHandle handle);
/**
    * @brief 判断指标是否可以交易
    * @param[in] handle 指标句柄
    * @return 返回说明
    *        -<em>0</em> 不可以
    *        -<em>非0</em> 可以
    */
XINDICATOR_API int iIsTradeable(iHandle handle);
/**
    * @brief 判断指标是否计算过
    * @param[in] handle 指标句柄
    * @return 返回说明
    *        -<em>0</em> 没有
    *        -<em>非0</em> 可以
    */
XINDICATOR_API int iIsCalculate(iHandle handle);


/**
    * @brief 计算指标反向偏移
    * @param[in] offset 正向偏移
    * @param[in] handle 指标句柄
    * @return 反向偏移
    */
XINDICATOR_API int iReverseOffset(int offset, iHandle handle);
/**
    * @brief 计算指标是否穿越
    * @param[in] src 指标线索引
    * @param[in] dst 指标线索引
    * @param[in] offset 判断穿越位置，即判断src在offset位置是否穿越了dst
    * @param[in] handle 指标句柄
    * @return 返回说明
    *        -<em>小于0</em> 向下穿越
    *        -<em>0</em> 没有
    *        -<em>大于0</em> 向上穿越
    */
XINDICATOR_API int iIsCross(int src, int dst, int offset, iHandle handle);


//---------------------------------------------------------------------------
// 代码函数
//---------------------------------------------------------------------------

/**
    * @brief 代码查找
    * @param[in] key 关键字
    * @param[in] flags 标志
    * @param[in] handle 指标句柄
    * @return 代码数量
    */
XINDICATOR_API int iObjectsFindA(const char* key, unsigned long flags, iHandle handle);
XINDICATOR_API int iObjectsFindW(const wchar_t* key, unsigned long flags, iHandle handle);
#ifdef UNICODE
#define iObjectsFind iObjectsFindW
#else
#define iObjectsFind iObjectsFindA
#endif//
/**
    * @brief 代码总数
    * @param[in] market 市场
    * @param[in] handle 指标句柄
    * @return 代码数量
    */
XINDICATOR_API int iObjectsTotalA(const char* market, iHandle handle);
XINDICATOR_API int iObjectsTotalW(const wchar_t* market, iHandle handle);
#ifdef UNICODE
#define iObjectsTotal iObjectsTotalW
#else
#define iObjectsTotal iObjectsTotalA
#endif//
/**
    * @brief 获取代码
    * @param[in] offset 代码索引
    * @param[out] str 接收指标线名字数组
    * @param[out] len 接收指标线名字数组长度
    * @param[in] handle 指标句柄
    * @return 代码
    */
XINDICATOR_API const char* iObjectSelect(int offset, char* str, int len, iHandle handle);


//---------------------------------------------------------------------------
// 账户管理函数
//---------------------------------------------------------------------------

/**
    * @brief 用户总数
    * @return 用户总数
    */
XINDICATOR_API int iUsersTotal();
/**
    * @brief 选择用户ByIndex/ByName
    * @return 返回说明
    *        -<em>小于0</em> 失败
    *        -<em>大于等于0</em> 成功，值为索引
    */
XINDICATOR_API int iUserSelectByIndex(int index);
XINDICATOR_API int iUserSelectByNameA(const char* name);
XINDICATOR_API int iUserSelectByNameW(const wchar_t* name);
#ifdef UNICODE
#define iUserSelectByName iUserSelectByNameW
#else
#define iUserSelectByName iUserSelectByNameA
#endif//
/**
    * @brief 选择支持指定代码交易账户
    * @param[in] symbol 代码
    * @return 返回说明
    *        -<em>小于0</em> 失败
    *        -<em>大于等于0</em> 成功，值为索引
    */
XINDICATOR_API int iUserSelectBySymbol(const char* symbol);

/**
    * @brief 获取用户相关数据
    * @param[in] field 数据名
    * @return 返回数据值
    */
XINDICATOR_API double iUserFieldValueA(const char* field);
XINDICATOR_API double iUserFieldValueW(const wchar_t* field);
/**
    * @brief 获取用户相关数据
    * @param[in] field 数据名
    * @param[out] str 接收指标线名字数组
    * @param[out] len 接收指标线名字数组长度
    * @return 返回数据值
    */
XINDICATOR_API const char* iUserFieldStringA(const char* field, char* str, int len);
XINDICATOR_API const wchar_t* iUserFieldStringW(const wchar_t* field, wchar_t* str, int len);
#ifdef UNICODE
#define iUserFieldValue iUserFieldValueW
#define iUserFieldString iUserFieldStringW
#else
#define iUserFielValued iUserFieldValueA
#define iUserFieldString iUserFieldStringA
#endif//
/**
    * @brief 获取用户名
    * @param[out] str 接收指标线名字数组
    * @param[out] len 接收指标线名字数组长度
    * @return 返回用户名
    */
XINDICATOR_API const char* iUserAccountA(char* str, int len);
XINDICATOR_API const wchar_t* iUserAccountW(wchar_t* str, int len);
/**
    * @brief 获取账户货币符号
    * @param[out] str 接收指标线名字数组
    * @param[out] len 接收指标线名字数组长度
    * @return 返回账户货币符号
    */
XINDICATOR_API const char* iUserMoneySymbolA(char* str, int len);
XINDICATOR_API const wchar_t* iUserMoneySymbolW(wchar_t* str, int len);
#ifdef UNICODE
#define iUserAccount iUserAccountA
#define iUserMoneySymbol iUserMoneySymbolA
#else
#define iUserAccount iUserAccountW
#define iUserMoneySymbol iUserMoneySymbolW
#endif//
/**
    * @brief 获取账户总资金
    * @return 返回账户总资金
    */
XINDICATOR_API double iUserMoneyTotal();
/**
    * @brief 获取账户可用资金
    * @return 返回账户可用资金
    */
XINDICATOR_API double iUserMoneyAvailable();
/**
    * @brief 获取账户冻结资金
    * @return 返回账户冻结资金
    */
XINDICATOR_API double iUserMoneyFreeze();
/**
    * @brief 获取账户可取资金
    * @return 返回账户可取资金
    */
XINDICATOR_API double iUserMoneyFree();
/**
    * @brief 获取账户转入资金
    * @return 返回账户转入资金
    */
XINDICATOR_API double iUserMoneyIn();
/**
    * @brief 获取账户转出资金
    * @return 返回账户转出资金
    */
XINDICATOR_API double iUserMoneyOut();

//---------------------------------------------------------------------------
// 交易函数
//---------------------------------------------------------------------------

/**
    * @brief 发送委托订单
    * @param[in] symbol 代码
	* @param[in] cmd 委托订单指令
	* @param[in] volume 委托订单量
	* @param[in] price 委托订单价
	* @param[in] slippage 委托订单允许滑点数
	* @param[in] stoploss 委托订单止损价
	* @param[in] takeprofit 委托订单止盈价
	* @param[in] comment 委托订单注释说明
	* @param[in] magic 委托订单魔术字
	* @param[in] date 委托订单日期
	* @param[in] time 委托订单时间
    * @return 返回说明
    *        -<em>小于0</em> 失败
    *        -<em>大于等于0</em> 发送委托订单请求成功
    * @par 示例:
    * @code
    *        iOrderSendA("600000.SH", OP_BUY, 100, 12.67, 1, 0, 0, "", 0, 0, 0);
    * @endcode
    */
XINDICATOR_API int iOrderSendA(const char* symbol,int cmd, double volume,double price,int slippage, double stoploss, double takeprofit,
							   const char* comment,int magic,unsigned long date,unsigned long time);
XINDICATOR_API int iOrderSendW(const char* symbol,int cmd, double volume,double price,int slippage, double stoploss, double takeprofit,
							   const wchar_t* comment,int magic,unsigned long date,unsigned long time);
//XINDICATOR_API int OrderBuy();
//XINDICATOR_API int OrderSell();
//XINDICATOR_API int OrderBuyShort();
//XINDICATOR_API int OrderSellShort();
#ifdef UNICODE
#define iOrderSend iOrderSendW
#else
#define iOrderSend iOrderSendA
#endif//

/**
    * @brief 选择订单列表类型
    * @return 返回订单列表类型
    */
XINDICATOR_API int iOrdersSelect(int pool);
/**
    * @brief 获取订单数量
    * @return 返回订单数量
    */
XINDICATOR_API int iOrdersTotal();
/**
    * @brief 选择订单ByIndex/ByTicket/ByMagic
    * @param[in] index 订单索引
    * @param[in] ticket 订单编号
    * @param[in] magic 订单魔术字
    * @return 返回订单索引
    */
XINDICATOR_API int iOrderSelectByIndex(int index);
XINDICATOR_API int iOrderSelectByTicketA(const char* ticket);
XINDICATOR_API int iOrderSelectByTicketW(const wchar_t* ticket);
#ifdef UNICODE
#define iOrderSelectByTicket iOrderSelectByTicketW
#else
#define iOrderSelectByTicket iOrderSelectByTicketA
#endif//
XINDICATOR_API int iOrderSelectByMagic(int magic);

/**
    * @brief 获取订单类型
    * @return 返回订单类型
    */
XINDICATOR_API int iOrderType();
/**
    * @brief 获取订单编号
    * @param[out] str 接收订单编号数组
    * @param[out] len 接收订单编号数组长度
    * @return 返回订单编号
    */
XINDICATOR_API const char* iOrderTicket(char* str, int len);

/**
    * @brief 平仓
    * @param[in] lots 平仓手数
    * @param[in] price 平仓价格
    * @param[in] slippage 允许滑点数
    * @return 返回说明
    *        -<em>小于0</em> 失败
    *        -<em>大于等于0</em> 发送平仓请求成功
    */
XINDICATOR_API int iOrderClose(double lots, double price, int slippage);
/**
    * @brief 平仓并反向开仓
    * @param[in] opposite 是否方向开仓
    * @return 返回说明
    *        -<em>小于0</em> 失败
    *        -<em>大于等于0</em> 发送平仓并反向开仓请求成功
    */
XINDICATOR_API int iOrderCloseBy(int opposite);
/**
    * @brief 删除订单
    * @return 返回说明
    *        -<em>小于0</em> 失败
    *        -<em>大于等于0</em> 发送删除订单请求成功
    */
XINDICATOR_API int iOrderDelete();
/**
    * @brief 修改订单
    * @param[in] price 修改委托开仓价格
    * @param[in] stoploss 修改止损价格
    * @param[in] takeprofit 修改止盈价格
    * @param[in] expiration 修改超时时间
    * @return 返回说明
    *        -<em>小于0</em> 失败
    *        -<em>大于等于0</em> 发送修改订单请求成功
    */
XINDICATOR_API int iOrderModify(double price,double stoploss,double takeprofit,unsigned long expiration);

/**
    * @brief 获取订单标的代码
    * @param[out] str 接收订单标的代码数组
    * @param[out] len 接收订单标的代码数组长度
    * @return 返回订单标的代码
    */
XINDICATOR_API const char* iOrderSymbol(char* str, int len);

/**
    * @brief 获取订单开仓价格
    * @return 返回订单开仓价格
    */
XINDICATOR_API double iOrderOpenPrice();
/**
    * @brief 获取订单平仓价格
    * @return 返回订单平仓价格
    */
XINDICATOR_API double iOrderClosePrice();

/**
    * @brief 获取订单开仓时间
    * @param[out] date 接收订单开仓日期字段
    * @return 返回订单开仓时间
    */
XINDICATOR_API unsigned long iOrderOpenTime(unsigned long* date);
/**
    * @brief 获取订单平仓时间
    * @param[out] date 接收订单平仓日期字段
    * @return 返回订单平仓时间
    */
XINDICATOR_API unsigned long iOrderCloseTime(unsigned long* date);
/**
    * @brief 获取订单超时时间
    * @param[out] date 接收订单超时日期字段
    * @return 返回订单超时时间
    */
XINDICATOR_API unsigned long iOrderExpiration(unsigned long* date);

/**
    * @brief 获取订单手比例
    * @return 返回订单手比例
    */
XINDICATOR_API double iOrderLots();
/**
    * @brief 获取订单利润
    * @return 返回订单利润
    */
XINDICATOR_API double iOrderProfit();
/**
    * @brief 获取订单止盈点
    * @return 返回订单止盈点
    */
XINDICATOR_API double iOrderTakeProfit();
/**
    * @brief 获取订单止损点
    * @return 返回订单止损点
    */
XINDICATOR_API double iOrderStopLoss();
/**
    * @brief 获取订单佣金
    * @return 返回订单佣金
    */
XINDICATOR_API double iOrderCommission();
/**
    * @brief 获取订单魔术字
    * @return 返回订单魔术字
    */
XINDICATOR_API int iOrderMagicNumber();
/**
    * @brief 获取订单注释
    * @param[out] str 接收订单注释数组
    * @param[out] len 接收订单注释数组长度
    * @return 返回订单注释
    */
XINDICATOR_API const char* iOrderComment(char* str, int len);

/**
    * @brief 获取订单其他字段
    * @param[out] str 接收订单其他字段数组
    * @param[out] len 接收订单其他字段数组长度
    * @return 返回订单其他字段
    */
XINDICATOR_API const char* iOrderFieldString(const char* field, char* str, int len);

#if defined(__cplusplus)
}

class XINDICATOR_API XIndicatorSpi
{
public:
	//Global
	virtual void OnLog(INDICATOR_LOG_LEVEL level, const char* str) {}

	virtual void OnInit() {}
	virtual void OnTerm() {}

	//Data
	virtual void OnUpdateHisData(const char* symbol) {}
	virtual void OnUpdateFinanceData(const char* symbol) {}
	virtual void OnUpdateFieldData(const char* symbol) {}
	virtual void OnUpdateOrderData() {}
	
	//Calc
	virtual void OnTest(iHandle handle) {}
	virtual void OnCalc(iHandle handle) {}
};

class XINDICATOR_API XIndicatorQuoteProvider
{
public:
	//Symbol
	virtual int OnSymbolsFind(const char* key, unsigned int flags) { return 0; }
	virtual int OnSymbolsTotal(const char* market) { return 0; }
	virtual const char* OnSymbolSelect(int index, char* str, int len) { return str; }

	//Calc Data
	virtual voidptr OnRefCalcData(const char* symbol, int period, unsigned int flags = REF_CALCDATA_DEFAULT) { return 0; }
	virtual void OnReleaseCalcData(voidptr dataptr) {}
	virtual const char* OnGetSymbol(voidptr dataptr, char* str, int len) { return str; }
	virtual int OnGetPeriod(voidptr dataptr) { return 0; }
	virtual int OnGetPriceCount(voidptr dataptr) { return 0; }
	virtual unsigned int OnGetPriceDate(voidptr dataptr, int offset) { return 0; }
	virtual unsigned int OnGetPriceTime(voidptr dataptr, int offset) { return 0; }
	virtual double OnGetPriceValue(voidptr dataptr, int price, int offset) { return 0.; }
	virtual double OnGetFinanceValue(voidptr dataptr, int finance, int offset) { return 0.; }
	virtual double OnGetFieldValue(voidptr dataptr, INDICATOR_FIELD field) { return 0.; }
};

class XINDICATOR_API XIndicatorTradeProvider
{
public:
	//User
	virtual int OnUsersTotal() { return 0; }
	virtual int OnUserSelectReset() { return -1; }
	virtual int OnUserSelectByIndex(int index) { return -1; }
	virtual int OnUserSelectByName(const char* name) { return -1; }
	virtual int OnUserSelectByObject(const char* symbol) { return -1; }
	virtual double OnGetUserFieldValue(const char* field) { return 0.; }
	virtual const char* OnGetUserFieldString(const char* field, char* str, int len) { return str; }

	//Trade
	virtual int OnOrderSend(const char* symbol, int cmd, double volume, double price
		, int slippage, double stoploss, double takeprofit
		, const char* comment, int magic) { return -1; }
	virtual int OnOrdersSelect(int pool) { return -1; }
	virtual int OnOrdersTotal() { return 0; }
	virtual int OnOrderSelectReset() { return -1; }
	virtual int OnOrderSelectByIndex(int index) { return -1; }
	virtual int OnOrderSelectByTicket(const char* ticket) { return -1; }
	virtual int OnOrderSelectByMagic(int magic) { return -1; }

	virtual int OnOrderClose(double lots, double price, int slippage) { return -1; }
	virtual int OnOrderCloseBy(int opposite) { return -1; }
	virtual int OnOrderDelete() { return -1; }
	virtual int OnOrderModify(double price,double stoploss,double takeprofit,unsigned long expiration) { return -1; }

	virtual double OnGetOrderFieldValue(const char* field) { return 0.; }
	virtual const char* OnGetOrderFieldString(const char* field, char* str, int len) { return str; }

	virtual int OnGetOrderType() { return OP_NONE; }
	virtual const char* OnGetOrderTicket(char* str, int len) { return str; }

	virtual const char* OnGetOrderSymbol(char* str, int len) { return str; }

	virtual double OnGetOrderOpenPrice() { return EMPTY_VALUE; }
	virtual double OnGetOrderClosePrice() { return EMPTY_VALUE; }

	virtual unsigned int OnGetOrderOpenTime(unsigned long* date) { return 0; }
	virtual unsigned int OnGetOrderCloseTime(unsigned long* date) { return 0; }
	virtual unsigned int OnGetOrderExpiration(unsigned long* date) { return 0; }

	virtual double OnGetOrderLots() { return 0.; }
	virtual double OnGetOrderProfit() { return 0.; }
	virtual double OnGetOrderTakeProfit() { return 0.; }
	virtual double OnGetOrderStopLoss() { return 0.; }
	virtual double OnGetOrderCommission() { return 0.; }
	virtual int OnGetOrderMagicNumber() { return 0; }
	virtual const char* OnGetOrderComment(char* str, int len) { return str; }
};

class XINDICATOR_API XIndicatorApi
{
public:
	static XIndicatorApi* GetInstance();
	static XIndicatorApi* GetInstanceA(const char* workdir, const char* datadir);
	static XIndicatorApi* GetInstanceW(const wchar_t* workdir, const wchar_t* datadir);
	static void ReleaseInstance();

public:
	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	//virtual void Init() = 0;
	//virtual void Term() = 0;

	/**
    * @brief 注册回调接口
    * @param[in] pSpi 派生自回调接口类的实例
    * @return 无
    */
	virtual void RegisterSpi(XIndicatorSpi *pSpi) = 0;
	/**
    * @brief 注册行情回调接口
    * @param[in] pProvider 派生自行情回调接口类的实例
    * @return 无
    */
	virtual void RegisterQuoteProvider(XIndicatorQuoteProvider *pProvider) = 0;
	/**
    * @brief 注册交易回调接口
    * @param[in] pProvider 派生自交易回调接口类的实例
    * @return 无
    */
	virtual void RegisterTradeProvider(XIndicatorTradeProvider *pProvider) = 0;

	/**
    * @brief 处理接口，需要接口使用者不停调用，这样指标系统方能正常工作
    * @return 无
    */
	virtual void Handle() = 0;

	/**
    * @brief 更新历史数据接口，
	*
	* 如果接口使用者自己提供行情数据，即RegisterQuoteProvider了，就需要每次历史数据变化时调用此接口
    * @return 无
    */
	virtual void UpdateHisData(const char* symbol) = 0;

	/**
    * @brief 更新财务数据接口，
	*
	* 如果接口使用者自己提供行情数据，即RegisterQuoteProvider了，就需要每次财务数据变化时调用此接口
    * @return 无
    */
	virtual void UpdateFinanceData(const char* symbol) = 0;

	/**
    * @brief 更新实时快照数据接口，
	*
	* 如果接口使用者自己提供行情数据，即RegisterQuoteProvider了，就需要每次实时快照数据变化时调用此接口
    * @return 无
    */
	virtual void UpdateFieldData(const char* symbol) = 0;

	/**
    * @brief 更新交易数据接口，
	*
	* 如果接口使用者自己提供交易接口和数据，即RegisterTradeProvider了，就需要每次交易数据变化时调用此接口
    * @return 无
    */
	virtual void UpdateOrderData() = 0;

protected:
	virtual ~XIndicatorApi() {};
};

#endif//

#endif//_H_XINDICATORAPI_H_
