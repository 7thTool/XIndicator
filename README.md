# XIndicator

## XIndicator概览

XIndicator是一套证券行情交易系统解决方案，和市场上的东方财富、同花顺、大智慧、万得、以及富途、彭博、文华财经等信息软件厂商相比，XIndicator除了能实现这些传统厂商证券行情交易软件的功能外，XIndicator拥有更好的系统架构，更特别的是XIndicator天然支持量化交易，用户可以基于XIndicator系统构建自己的证券行情交易系统以及量化交易系统等。

说到量化交易，这里想多说一下，现在网上也有很多基于Python开发的量化交易系统，比如各种Quant，这些系统做策略回测和验证倒是可以，但是做实盘策略交易，比如高频交易就肯定不行，速度绝对跟不上；因为Python的慢决定了这样的系统肯定慢，即使你使用多进程什么的优化也不行；当然也不是说不能用Python，而是用的方式不对，就像在错误的道路上，不管你做的多对都是错；那么应该怎样使用Python呢？你始终记住Python是胶水语言，你就使用它的胶水特点就好了，核心的行情交易系统用性能更好的语言来实现，然后再用Python集成核心行情交易系统，然后再集成其他Python有优势的系统，比如再和人工智能分析系统对接。

XIndicator核心优势:

* XIndicator核心技术优势是指标分析交易系统，提供统一的金融行情数据（数据和指标）、账户和资金管理以及交易指令轻松可编程的访问方式；
* XIndicator核心数据优势是为用户提供高速行情服务，提供历史行情财务数据服务，提供便捷高效的交易服务；
* XIndicator核心架构优势是高度模块化架构，支持C/C++、Lua、Python以及传统指标编程方式的自定义开发等，推荐使用C/C++和Lua语言开发XIndicator。

对于XIndicator的理解不应该仅仅局限于量化交易方面，可以从XIndicator可以提供统一数据接口和统一交易接口来看；
1. 从数据接口来看，可以用于数据分析领域，比如行情分析软件，大数据分析系统，人工智能分析系统等
2. 从交易接口来看，可以用于传统行情交易系统，量化交易系统，人工智能交易系统等。

***
## XIndicator的项目资源

XIndicator技术上是基于XLib、UILite以及行情交易服务构建的支持多层次定制开发的高可用证券行情指标分析交易系统，其中
* thirtd_party：[https://github.com/7thTool/third_party.git](https://github.com/7thTool/third_party.git)
* XLib项目地址：[https://github.com/7thTool/XLib.git](https://github.com/7thTool/XLib.git) 
* UILite项目地址：[https://github.com/7thTool/UILite.git](https://github.com/7thTool/UILite.git)
* XIndicator项目地址：[https://gitee.com/7thTool/XIndicator.git](https://gitee.com/7thTool/XIndicator.git)
* XIndicatorApi项目地址：[https://github.com/7thTool/XIndicatorApi.git](https://github.com/7thTool/XIndicatorApi.git)
* XTrade项目地址：[https://gitee.com/7thTool/XTrade.git](https://gitee.com/7thTool/XTrade.git)

***
## 目录

* [平台支持](#平台支持)
* [环境搭建](#环境搭建)
  * [XIndicator](#xindicator)
  * [Lua](#lua)
  * [XIndicatorApi](#XIndicatorApi)
  * [XTrade](#XTrade)
* [用法简介](#用法简介)
  * [XIndicator](#C/C++使用XIndicator)
  * [用Lua编写技术指标/量化交易系统](#使用Lua编写技术指标/量化交易系统)
  * [XIndicatorApi](#使用XIndicatorApi快速集成XIndicator系统)
  * [基于XIndicatorApi使用Python/JavaScript等其他语言快速集成XIndicator系统](#基于XIndicatorApi使用Python/JavaScript等其他语言快速集成XIndicator系统)
  * [基于XIndicator源码深度定制开发XIndicator系统](#基于XIndicator源码深度定制开发XIndicator系统)
  * [基于XIndicator模块化接口，为XIndicator增加更多行情、交易模块](#基于XIndicator模块化接口，为XIndicator增加更多行情、交易模块)
  * [基于XTrade项目原型开发基于XIndicator的应用](#基于XTrade项目原型开发基于XIndicator的应用)
* [许可](#许可)

***

### 平台支持
`XIndicator` 现在主要支持Windows平台，XIndicator的架构设计是可以支持跨平台的，这也是今后XIndicator技术演进的方向.

| 平台 / 架构 | 
|       ---       |
| Windows / x86  |


## 环境搭建

XIndicator技术上是基于XLib、UILite以及行情交易服务的，所以在使用XIndicator前您需要配置基本环境。

首先，您需要先拉取XIndicator：[https://gitee.com/7thTool/XIndicator.git](https://gitee.com/7thTool/XIndicator.git)，这里您可以选择几种开发方式
* 直接基于XIndicator开发
* 如果想要基于XIndicatorApi开发，您需要再拉取XIndicatorApi：[https://github.com/7thTool/XIndicatorApi.git]
* 如果想要基于XTrade开发，您需要再拉取XTrade：[https://gitee.com/7thTool/XTrade.git](https://gitee.com/7thTool/XTrade.git)

然后，你需要拉取依赖的第三方库，XLib、UILite
* thirtd_party：[https://github.com/7thTool/third_party.git](https://github.com/7thTool/third_party.git)
* XLib项目地址：[https://github.com/7thTool/XLib.git](https://github.com/7thTool/XLib.git) 
* UILite项目地址：[https://github.com/7thTool/UILite.git](https://github.com/7thTool/UILite.git)

#### 拉取好环境之后的目录结构应该如下：
* [环境根目录]
  * third_party
  * XLib
  * UILite
  * XIndicator
  * XIndicatorApi
  * XTrade

#### XIndicator

[XIndicator](https://gitee.com/7thTool/XIndicator.git)是证券行情交易系统以及量化交易系统解决方案。

如果您直接使用`XIndicator`开发，你需要先获取[XIndicator](https://gitee.com/7thTool/XIndicator.git)项目，然后按照下面步骤搭建开发环境：

1. 将XLib的Lib目录里的Debug或者Release动态库复制到`XIndicator`对应的Debug或者Release目录；
2. 将UILite的Lib目录里的Debug或者Release动态库复制到`XIndicator`对应的Debug或者Release目录；
3. 将XIndicator的Lib目录里的Debug或者Release动态库复制到`XIndicator`对应的Debug或者Release目录；
4. 这样可以建立您自己的解决方案了，可以参考`XIndicator`自带的例子工程，例子工程已经设置好了C/C++ include、lib等。

以下是您搭建完环境的项目目录结构：
* [环境根目录]
	* third_party
	* XLib
	* UILite
	* XIndicator

接下来，您就可以开始开发了，这之前您可能还需要熟悉一下XIndicator技术架构：


#### Lua

Lua是一个小巧的脚本语言。是巴西里约热内卢天主教大学（Pontifical Catholic University of Rio de Janeiro）里的一个研究小组，由Roberto Ierusalimschy、Waldemar Celes 和 Luiz Henrique de Figueiredo所组成并于1993年开发。 其设计目的是为了嵌入应用程序中，从而为应用程序提供灵活的扩展和定制功能。Lua由标准C编写而成，几乎在所有操作系统和平台上都可以编译，运行。Lua并没有提供强大的库，这是由它的定位决定的。所以Lua不适合作为开发独立应用程序的语言。Lua 有一个同时进行的JIT项目，提供在特定平台上的即时编译功能。

Lua脚本可以很容易的被C/C++ 代码调用，也可以反过来调用C/C++的函数，这使得Lua在应用程序中可以被广泛应用。不仅仅作为扩展脚本，也可以作为普通的配置文件，代替XML,ini等文件格式，并且更容易理解和维护。Lua由标准C编写而成，代码简洁优美，几乎在所有操作系统和平台上都可以编译，运行。一个完整的Lua解释器不过200k，在目前所有脚本引擎中，Lua的速度是最快的。这一切都决定了Lua是作为嵌入式脚本的最佳选择。

XIndicator使用Lua作为默认指标系统编程语言，您可以使用Lua编写普通技术指标、脚本等，也可以编写复杂的策略交易系统，下面是XIndicator支持的Lua语法：

```bash
--日志类型
LOGLEVEL_DEBUG = 0; --调试
LOGLEVEL_INFO = 1; --信息
LOGLEVEL_WARN = 2; --警告
LOGLEVEL_ERROR = 3; --错误

--指标类型
INDICATOR_TYPE_MAIN = 0; --主图指标
INDICATOR_TYPE_SECOND = 1; --幅图指标
INDICATOR_TYPE_POOL = 2; --策略/池指标

--指标线类型
INDEX_LINE = 0; --指标线
INDEX_CALC = 1; --辅助计算

--画线方式
DRAW_LINE = 0; --画线
DRAW_SECTION = 1; --线条
DRAW_STICK = 2; --柱状线
DRAW_HISTOGRAM = 3; --柱状图
DRAW_HISTOGRAM2 = 4; --两个指标命令的柱状图

--画线类型
LINE_SOLID = 0; --实线
LINE_DASH = 1; --折线
LINE_DOT = 2; --虚线
LINE_DASHDOT = 3; --折点线
LINE_DASHDOTDOT = 4; --双折点线

--价格类型
PRICE_CLOSE=0; --收盘价
PRICE_OPEN=1; --开盘价
PRICE_HIGH=2; --最高价
PRICE_LOW=3; --最低价
PRICE_MEDIAN=4; --中间值（高+低）/2
PRICE_TYPICAL=5; --典型价格（高+低+收盘价）/3
PRICE_WEIGHTED=6; --平均价格（高+低+收盘价格+开盘价格）/4
PRICE_VOLUME=7; --成交额
PRICE_AMOUNT=8; --成交量
PRICE_TICKVOLUME=9; --跳动量
PRICE_AVPRICE=10; --平均价（成交额/成交量）


--周期
PERIOD_TICK = 0 --明细
PERIOD_1SEC = 1 --1秒
PERIOD_5SEC = 5 --5秒
PERIOD_1MIN = 60 --分钟
PERIOD_5MIN = 60*5 --5分钟
PERIOD_15MIN = 60*15 --15分钟
PERIOD_30MIN = 60*30 --30分钟
PERIOD_HOUR = 60*60 --时
PERIOD_4HOUR = 60*60*4 --4小时
PERIOD_DAY = 60*60*24 --日
PERIOD_WEEK = 60*60*24*7 --周
PERIOD_MONTH = 60*60*24*30 --月
PERIOD_SEASON = 60*60*24*90 --季
PERIOD_YEAR = 60*60*24*365 --年

--快照字段
INDICATOR_FIELD_0 = 0; --无
INDICATOR_FIELD_DATE = 1; --日期
INDICATOR_FIELD_TIME = 2; --时间
INDICATOR_FIELD_CLOSE = 3; --收盘价
INDICATOR_FIELD_OPEN = 4; --开盘价
INDICATOR_FIELD_HIGH = 5; --最高价
INDICATOR_FIELD_LOW = 6; --最低价
INDICATOR_FIELD_NOW = 7; --最新价
INDICATOR_FIELD_VOLUME = 8; --成交量
INDICATOR_FIELD_LAST_VOLUME = 9; --5-9
INDICATOR_FIELD_AMOUNT = 10;
INDICATOR_FIELD_AVERAGE_PRICE = 11;
INDICATOR_FIELD_DELTA = 12;
INDICATOR_FIELD_RANGE_PERCENT = 13;
INDICATOR_FIELD_DELTA_PERCENT = 14; --10-14
INDICATOR_FIELD_WEIBI = 15;
INDICATOR_FIELD_BID_ASK_VOLUME_DIFF = 16;
INDICATOR_FIELD_VOLUME_RATIO = 17;
INDICATOR_FIELD_BID_VOLUME = 18;
INDICATOR_FIELD_ASK_VOLUME = 19; --15-19
INDICATOR_FIELD_BID_PRICE = 20;
INDICATOR_FIELD_ASK_PRICE = 21;
INDICATOR_FIELD_SOLD_VOLUME = 22;
INDICATOR_FIELD_BOUGHT_VOLUME = 23;
INDICATOR_FIELD_RECENT_DELTA_PERCENT = 24;  --20-24
INDICATOR_FIELD_TURNOVER_RATE = 25;
INDICATOR_FIELD_AVERAGE_VOLUME = 26;
INDICATOR_FIELD_PRICE_EARNING_RATIO = 27;
INDICATOR_FIELD_POSITION = 28;
INDICATOR_FIELD_INTEREST = 29;  --25-29
INDICATOR_FIELD_FULL_PRICE = 30;
INDICATOR_FIELD_BARGAIN = 31;
INDICATOR_FIELD_AVERAGE_BARGAIN_VOLUME = 32;
INDICATOR_FIELD_CEILING_PRICE = 33;
INDICATOR_FIELD_FLOOR_PRICE = 34; --30-34
INDICATOR_FIELD_TOTAL_VALUE = 35;
INDICATOR_FIELD_CURRENT_VALUE = 36;
INDICATOR_FIELD_PRICE_BOOK_VALUE_RATIO = 37;
INDICATOR_FIELD_PREV_POSITION = 38;
INDICATOR_FIELD_PREV_SETTLEMENT = 39; --35-39
INDICATOR_FIELD_SETTLEMENT = 40;
INDICATOR_FIELD_LAST_DELTA_POSITION = 41;
INDICATOR_FIELD_DELTA_POSITION = 42;
INDICATOR_FIELD_LAST_OPEN_CLOSE_POSITION = 43;
INDICATOR_FIELD_RISE_COUNT = 44; --40-44
INDICATOR_FIELD_DROP_COUNT = 45;
INDICATOR_FIELD_EQUAL_COUNT = 46; --45-46
INDICATOR_FIELD_DIGITS = 47;
INDICATOR_FIELD_ASK_PRICE_10 = 48; -- 卖十价		是(元)/是
INDICATOR_FIELD_ASK_PRICE_9 = 49; -- 卖九价		是(元)/是
INDICATOR_FIELD_ASK_PRICE_8 = 50; -- 卖八价		是(元)/是
INDICATOR_FIELD_ASK_PRICE_7 = 51; -- 卖七价		是(元)/是
INDICATOR_FIELD_ASK_PRICE_6 = 52; -- 卖六价		是(元)/是
INDICATOR_FIELD_ASK_PRICE_5 = 53; -- 卖五价		是(元)/是
INDICATOR_FIELD_ASK_PRICE_4 = 54; -- 卖四价		是(元)/是
INDICATOR_FIELD_ASK_PRICE_3 = 55; -- 卖三价		是(元)/是
INDICATOR_FIELD_ASK_PRICE_2 = 56; -- 卖二价		是(元)/是
INDICATOR_FIELD_ASK_PRICE_1 = 57; -- 卖一价，同卖出价IDF_ASK_PRICE
INDICATOR_FIELD_BID_PRICE_1 = 58; -- 买一价，同买入价IDF_BID_PRICE
INDICATOR_FIELD_BID_PRICE_2 = 59; -- 买二价		是(元)/是
INDICATOR_FIELD_BID_PRICE_3 = 60; -- 买三价		是(元)/是
INDICATOR_FIELD_BID_PRICE_4 = 61; -- 买四价		是(元)/是
INDICATOR_FIELD_BID_PRICE_5 = 62; -- 买五价		是(元)/是
INDICATOR_FIELD_BID_PRICE_6 = 63; -- 买六价		是(元)/是
INDICATOR_FIELD_BID_PRICE_7 = 64; -- 买七价		是(元)/是
INDICATOR_FIELD_BID_PRICE_8 = 65; -- 买八价		是(元)/是
INDICATOR_FIELD_BID_PRICE_9 = 66; -- 买九价		是(元)/是
INDICATOR_FIELD_BID_PRICE_10 = 67; -- 买十价		是(元)/是
INDICATOR_FIELD_ASK_VOLUME_10 = 68; -- 卖十量		是(股、张、份)
INDICATOR_FIELD_ASK_VOLUME_9 = 69; -- 卖九量		是(股、张、份)
INDICATOR_FIELD_ASK_VOLUME_8 = 70; -- 卖八量		是(股、张、份)
INDICATOR_FIELD_ASK_VOLUME_7 = 71; -- 卖七量		是(股、张、份)
INDICATOR_FIELD_ASK_VOLUME_6 = 72; -- 卖六量		是(股、张、份)
INDICATOR_FIELD_ASK_VOLUME_5 = 73; -- 卖五量		是(股、张、份)
INDICATOR_FIELD_ASK_VOLUME_4 = 74; -- 卖四量		是(股、张、份)
INDICATOR_FIELD_ASK_VOLUME_3 = 75; -- 卖三量		是(股、张、份)
INDICATOR_FIELD_ASK_VOLUME_2 = 76; -- 卖二量		是(股、张、份)
INDICATOR_FIELD_ASK_VOLUME_1 = 77; -- 卖一量		是(股、张、份)
INDICATOR_FIELD_BID_VOLUME_1 = 78; -- 买一量		是(股、张、份)
INDICATOR_FIELD_BID_VOLUME_2 = 79; -- 买二量		是(股、张、份)
INDICATOR_FIELD_BID_VOLUME_3 = 80; -- 买三量		是(股、张、份)
INDICATOR_FIELD_BID_VOLUME_4 = 81; -- 买四量		是(股、张、份)
INDICATOR_FIELD_BID_VOLUME_5 = 82; -- 买五量		是(股、张、份)
INDICATOR_FIELD_BID_VOLUME_6 = 83; -- 买六量		是(股、张、份)
INDICATOR_FIELD_BID_VOLUME_7 = 84; -- 买七量		是(股、张、份)
INDICATOR_FIELD_BID_VOLUME_8 = 85; -- 买八量		是(股、张、份)
INDICATOR_FIELD_BID_VOLUME_9 = 86; -- 买九量		是(股、张、份)
INDICATOR_FIELD_BID_VOLUME_10 = 87; -- 买十量 		是(股、张、份)
	
--MA方法
MODE_SMA=0; --简单移动平均线 (SMA)：Simple Moving Average
MODE_EMA=1; --指数移动平均线 (EMA)：Exponential MA
MODE_SMMA=2; --通畅移动平均线 (SMMA)：Smoothed MA
MODE_LWMA=3; --线性权数移动平均线 (LWMA)：Linear Weighted MA
MODE_DMA=4; --动态移动平均线 Dynamic Moving Average


--订单列表类型
MODE_ORDERS=1 --委托
MODE_HISTORY_ORDERS=2 --历史委托
MODE_TRADES=3 --成交
MODE_HISTORY_TRADES=4 --历史成交
MODE_POSITION=5 --持仓

--委托方式
OP_NONE	= 0;
OP_BUY = 1;	--Buy operation
OP_SELL	= 2;	--Sell operation
OP_BUYLIMIT	= 3;	--Buy limit pending order
OP_SELLLIMIT = 4;	--Sell limit pending order
OP_BUYSTOP = 5;	--Buy stop pending order
OP_SELLSTOP	= 6;	--Sell stop pending order


--指标函数说明
--设置指标，用于定义指标类型（指标/策略），是否交易指标，输入参数，指标线等
--iSet(table)
--定义完指标后，根据指标类型，您需要处理指标响应函数，
--首先是OnInit函数，OnInit只在第一次初始化指标的时候调用一次，后面不再调用，您可以在这里进一步计算并定义指标和指标线，当然如果您的指标很简单完全可以不用实现OnInit，用iSet就够了
--function OnInit() {}
--然后是OnFilter，只有您的指标是策略指标（INDICATOR_TYPE_POOL），才需要响应OnFilter，在OnFilter您可以添加和删除标的代码，这样系统在检测到标的代码的行情和交易发生任何变化的时候，就会触发策略指标的计算
--function OnFilter() {}
--最后就是计算函数OnCalculate，OnCalculate函数在标的代码的行情和交易发生任何变化的时候，都会触发计算，您可以在计算函数里实时更新指标值和状态，并查询账户和持仓、委托信息以及触发买卖交易等
--function OnCalculate(count,calculated) { return(count); }

--接下来将介绍系统为您提供的指标相关函数，部分函数如果您传入指定指标句柄的话，就是获取指定指标的数据，指标句柄一般是最后一个参数，您可以选择不传，这样就是获取和设置当前指标数据
--设置输入参数
--iSetInput(name,value)
--设置指标线名
--iSetIndexName(index,name)
--设置指标线类型
--iSetIndexType(index,type)
--设置指标线小数位数
--iSetIndexDigits(index,digits)
--设置指标线偏移
--iSetIndexShift(index,shift)
--设置指标线画线开始位置
--iSetIndexBegin(index,begin)
--设置指标线画线方式
--iSetIndexDraw(index,draw)
--设置指标线线型
--iSetIndexLine(index,line)
--设置指标线关联指标线
--iSetIndexNext(index,next)
--设置指标线offset位置的值
--iSetIndexValue(index,offset,value)
--策略指标添加标的代码到策略池
--iAddPool(object)
--策略指标从策略池移除标的代码
--iRemovePool(object)
--获取指标输入参数字符串
--iGetInput(name)
--获取指标输入参数值
--iGetInputValue(name)
--获取指标指标线offset位置的值
--iGetIndexValue(index,offset)
--获取指标当前标的offset位置的价格
--iGetPriceValue(price,offset)
--获取指标当前标的offset位置的日期
--iGetPriceDate(offset)
--获取指标当前标的offset位置的时间
--iGetPriceTime(offset)
--获取指标当前标的offset位置的财务数据
--iGetFinanceValue(finance,offset)
--获取指标当前标的快照字段值
--iGetFieldValue(field)
--计算位置的反向位置
--iReversePos(pos)
--判断指标有没有计算过
--iIsCalculate(handle)
--引用其他指标，可以通过这个函数引用系统指标或者您自定义的指标
--iRef(name,object,period,...)
--释放指标，如果您不再使用该指标的话，可以释放它。默认情况下，您不需要考虑释放，系统会自动帮您处理
--iRelease(handle)
--系统指标MA
--iMA(object, period, ma_period, ma_shift, ma_method, applied_price)
--系统指标iStochastic
--iStochastic(object, period, Kperiod, Dperiod, slowing, ma_method, sto_price)
--系统算法MA
--iMAIndexOnPrice(index, period, method, price, handle)
--iMAIndexOnLine(index, period, method, line, handle)
--信号判断
--iIsCross(src, dst, offset, handle)
--交易指标判断
--iIsTrade
--是否可交易判断
--iIsTradeable
--获取当前登录账户数
--iUsersTotal()
--选择操作账户
--iUserSelectByIndex(index)
--iUserSelectByName(name)
--根据标的代码选择合适的交易账户
--iUserSelectBySymbol(symbol)
--获取账户信息
--iUserFieldValue(field)
--iUserFieldString(field)
--获取账户账号
--iUserAccount()
--获取账户交易货币
--iUserMoneySymbol()
--获取账户总资产
--iUserMoneyTotal()
--获取账户可用资金
--iUserMoneyAvailable()
--获取账户冻结资金
--iUserMoneyFreeze()
--获取账户可取资金
--iUserMoneyFree()
--获取账户入金金额
--iUserMoneyIn()
--获取账户出金金额
--iUserMoneyOut()
--发出委托订单
--iOrderSend(object, cmd, volume, price, slippage, stoploss, takeprofit, comment, magic, date, time)
--修改委托订单
--iOrderModify(price,stoploss,takeprofit,expiration)
--卖出平仓
--iOrderClose(lots,price,slippage)
--反向开仓
--iOrderCloseBy(opposite)
--删除委托订单
--iOrderDelete()
--选择操作的订单列表
--iOrdersSelect(pool)
--获取订单列表订单数
--iOrdersTotal()
--选择操作的订单
--iOrderSelectByIndex(index)
--iOrderSelectByTicketA(ticket)
--iOrderSelectByMagic(magic)
--获取订单类型
--iOrderType()
--获取订单编号
--iOrderTicket()
--获取订单标的代码
--iOrderSymbol()
--获取订单开仓价
--iOrderOpenPrice()
--获取订单平仓价
--iOrderClosePrice()
--获取订单开仓时间
--iOrderOpenTime()
--获取订单平仓时间
--iOrderCloseTime()
--获取订单有效期
--iOrderExpiration()
--获取订单大小
--iOrderLots()
--获取订单利润
--iOrderProfit()
--获取订单止盈价
--iOrderTakeProfit()
--获取订单止损价
--iOrderStopLoss()
--获取订单佣金
--iOrderCommission()
--获取订单魔术字
--iOrderMagicNumber()
--获取订单说明注释
--iOrderComment()
--获取订单其他字段
--iOrderFieldString(field)

--对于iSet设置的输入参数，可以像其他变量一样随便使用

--对于指标/策略，系统会内置常用的快照数据，如下:
--Object 标的代码
--Period 周期
--Date 日期
--Time 时间

--对于交易指标/策略，系统会内置常用的快照数据，如下:
--Close 收盘价
--Open 开盘价
--High 最高价
--Low 最低价
--Now 最新价
--Volume 成交量
--Amount 成交额
--BidPrice 委买价
--AskPrice 委卖价
--BidVolume 委买量
--AskVolume 委卖量
--AvgPrice 均价
--AvgVolume 均量
--UpperPrice 涨停价
--LowerPrice 跌停价
```

#### XIndicatorApi

[XIndicatorApi](https://github.com/7thTool/XIndicatorApi.git)是快速集成XIndicator的Api接口。

您需要先获取[XIndicatorApi](https://github.com/7thTool/XIndicatorApi.git)项目，然后参考下面步骤集成XIndicatorApi：

1. 将XIndicatorApi的bin目录运行依赖数据复制到`您的项目`对应的Debug或者Release开发目录；
2. 将XIndicatorApi的lib目录里的Debug或者Release动态库复制到`您的项目`对应的Debug或者Release开发目录；
3. 接着您可以建立`您的项目`了。

以下是您搭建完环境的项目目录结构：
* [环境根目录]
  * XIndicatorApi
  * 您的项目

接下来，您就可以开始集成XIndicator了。


#### XTrade

[XTrade](https://gitee.com/7thTool/XTrade.git)是基于XIndicator原型项目，您可以在这个基础上开发您自己的应用。

您需要先获取[XTrade](https://gitee.com/7thTool/XTrade.git)项目和[XIndicator](https://github.com/7thTool/XIndicator.git)SDK或者[XIndicator](https://gitee.com/7thTool/XIndicator.git)项目，然后参考下面步骤搭建XTrade开发环境：

1. 将XLib的Lib目录里的Debug或者Release动态库复制到`XTrade`对应的Debug或者Release目录；
2. 将UILite的Lib目录里的Debug或者Release动态库复制到`XTrade`对应的Debug或者Release目录；
3. 将XIndicator的Lib目录里的Debug或者Release动态库复制到`XTrade`对应的Debug或者Release目录；
4. 这样就搭建好了您的`XTrade`开发环境了。

拉取好环境之后的目录结构应该如下：
* [环境根目录]
  * third_party
  * XLib
  * UILite
  * XIndicator
  * XTrade

接下来，您就可以开始开发了，这之前您可能还需要熟悉一下XIndicator技术架构：


## 用法简介

### C/C++使用XIndicator

```c/c++
  //定义事件loop
	EvtDispatcher theLoop;

	//定义平台
	XPlatform Plat;

	//初始化平台

	_Platform->SetAppName(szAppName);
	_Platform->SetAppPath(szAppPath);
	_Platform->SetAppData(szAppData);

	_Platform->Init();

	//初始化网络层
	char szNetXml[1024] = { 0 };
	sprintf((char*)szNetXml, "<root workdir=\"%s\" datadir=\"%s\"><module name=\"QNetModule.dll\"></module></root>", szAppPathA, szAppDataA);
	printf("Start NetIOEngine:\n%s\n", szNetXml);
	_NetIOEngine->Start((char*)szNetXml);
	printf("Start NetIOEngine OK.\n");

	//初始化数据层
	char szDEXml[1024] = { 0 };
	sprintf((char*)szDEXml, "<root workdir=\"%s\" datadir=\"%s\"><module name=\"QDataModule.dll\"></module><module name=\"CTPTrader.dll\"></module></root>", szAppPathA, szAppDataA);
	printf("Start DataEngine:\n%s\n", szDEXml);
	_DataEngine->Start(szDEXml);
	printf("Start DataEngine OK.\n");

	_Platform->SetDataManager(new XDataManager);

	//初始化指标系统
	TCHAR szIndicatorPath[MAX_PATH] = { 0 };
	_tmakepath(szIndicatorPath, NULL, szAppPath, _T("XIndicator.dll"), NULL);
	//iLogW(LOGLEVEL_INFO,szIndicatorPath);
	_Platform->SetIndicatorModule(LoadLibrary(szIndicatorPath));

	//平台运行
	_Platform->Instance();

	//定义登录模块
	XLoginManager Login;

	//登录运行
	_LoginMgr->Instance();

	_LoginMgr->PostEvent(EVT_PLAT_CALL, MAKEVALUE(MCALL_PLAT_LOGIN, CCALL_LOGIN_LOGIN), 0);

	//事件循环
	theLoop.Run();

	//释放登录模块
	_LoginMgr->Release();

	//停止平台
	_Platform->Release();

	//停止数据层
	_DataEngine->Stop();

	//停止网络层
	_NetIOEngine->Stop();

	//销毁平台
	_Platform->Term();
```


### 使用Lua编写技术指标/量化交易系统

指标是技术分析的基础，下面演示如何使用Lua编写Ichimoku指标：
```lua
require("..lua.indicator")

iSet({
		type=INDICATOR_TYPE_MAIN,
		InpTenkan=9,
		InpKijun=26,
		InpSenkou=52
})

local Tenkan=0
local Kijun=1
local SpanA=2
local SpanB=3
local Chikou=4
local SpanA2=5
local SpanB2=6

local ExtBegin=0

function OnInit()

		--index settings
		iSetIndexName(Tenkan,"Tenkan");
		iSetIndexName(Kijun,"Kijun");
		iSetIndexName(SpanA,"SpanA");
		iSetIndexName(SpanB,"SpanB");
		iSetIndexName(Chikou,"Chikou");
		iSetIndexName(SpanA2,"SpanA2");
		iSetIndexName(SpanB2,"SpanB2");
		
		iSetIndexType(Tenkan,INDEX_LINE);
		iSetIndexType(Kijun,INDEX_LINE);
		iSetIndexType(SpanA,INDEX_LINE);
		iSetIndexType(SpanB,INDEX_CALC);
		iSetIndexType(Chikou,INDEX_LINE);
		iSetIndexType(SpanA2,INDEX_LINE);
		iSetIndexType(SpanB2,INDEX_LINE);

		iSetIndexBegin(Tenkan,InpTenkan);
		
		iSetIndexBegin(Kijun,InpKijun);
		
		ExtBegin=InpKijun;
		if(ExtBegin<InpTenkan)
		then
		   ExtBegin=InpTenkan;
		end
		   
		iSetIndexDraw(SpanA,DRAW_HISTOGRAM2);
		iSetIndexLine(SpanA,LINE_DOT);
		iSetIndexBegin(SpanA,InpKijun+ExtBegin);
		iSetIndexShift(SpanA,InpKijun);
		iSetIndexNext(SpanA,SpanB);
		
		iSetIndexDraw(SpanB,DRAW_HISTOGRAM2);
		iSetIndexLine(SpanB,LINE_DOT);
		iSetIndexBegin(SpanB,InpKijun+InpSenkou);
		iSetIndexShift(SpanB,InpKijun);
		
		iSetIndexDraw(Chikou,DRAW_LINE);
		iSetIndexShift(Chikou,-InpKijun);
		
		iSetIndexDraw(SpanA2,DRAW_LINE);
		iSetIndexLine(SpanA2,LINE_DOT);
		iSetIndexBegin(SpanA2,InpKijun+ExtBegin);
		iSetIndexShift(SpanA2,InpKijun);
		   
		iSetIndexDraw(SpanB2,DRAW_LINE);
		iSetIndexLine(SpanB2,LINE_DOT);
		iSetIndexBegin(SpanB2,InpKijun+InpSenkou);
		iSetIndexShift(SpanB2,InpKijun);
		
end
  
function OnCalculate(count,calculated)
		if(count<=0) 
		then
 				return(0);
 		end
		
		--begin calculated
		i = 0;
 		k = 0;
 		pos = 0;
    high_value = 0;
    low_value = 0;
    limit=0;
		--last calculated bar will be recounted
  	limit=count-calculated;
  	if(calculated>0) 
  	then
    		limit = limit + 1;
    end


   if(count<InpTenkan or count<InpKijun or count<InpSenkou)
   then
      return(0);
   end
--initial zero
   if(calculated<1)
   then
   		for i=0,InpTenkan do
         iSetIndexValue(Tenkan, iReversePos(i), 0);
      end
      for i=0,InpKijun do
         iSetIndexValue(Kijun, iReversePos(i), 0);
      end
      for i=0,ExtBegin do
         iSetIndexValue(SpanA, iReversePos(i), 0);
         iSetIndexValue(SpanA2, iReversePos(i), 0);
      end
      for i=0,InpSenkou do
         iSetIndexValue(SpanB, iReversePos(i), 0);
         iSetIndexValue(SpanB2, iReversePos(i), 0);
      end
    end

   pos=InpTenkan-1;
   if(calculated>InpTenkan)
   then
      pos=calculated-1;
   end
   for i=pos,count-1 do
      high_value=iGetPriceValue(PRICE_HIGH,iReversePos(i));
      low_value=iGetPriceValue(PRICE_LOW,iReversePos(i));
      k=i+1-InpTenkan;
      while(k<=i) do
         if(high_value<iGetPriceValue(PRICE_HIGH,iReversePos(k))) then
            high_value=iGetPriceValue(PRICE_HIGH,iReversePos(k));
         end
         if(low_value>iGetPriceValue(PRICE_LOW,iReversePos(k))) then
            low_value=iGetPriceValue(PRICE_LOW,iReversePos(k));
         end
         k = k + 1;
      end
      iSetIndexValue(Tenkan, iReversePos(i), (high_value+low_value)/2);
   end
--Kijun Sen
   pos=InpKijun-1;
   if(calculated>InpKijun)
   then
      pos=calculated-1;
   end
   for i=pos,count-1 do
      high_value=iGetPriceValue(PRICE_HIGH,iReversePos(i));
      low_value=iGetPriceValue(PRICE_LOW,iReversePos(i));
      k=i+1-InpKijun;
      while(k<=i) do
         if(high_value<iGetPriceValue(PRICE_HIGH,iReversePos(k))) then
            high_value=iGetPriceValue(PRICE_HIGH,iReversePos(k));
         end
         if(low_value>iGetPriceValue(PRICE_LOW,iReversePos(k))) then
            low_value=iGetPriceValue(PRICE_LOW,iReversePos(k));
         end
         k = k + 1;
      end
      iSetIndexValue(Kijun, iReversePos(i), (high_value+low_value)/2);
   end
--Senkou Span A
   pos=ExtBegin-1;
   if(calculated>ExtBegin)
   then
      pos=calculated-1;
   end
   for i=pos,count-1 do
      iSetIndexValue(SpanA, iReversePos(i), (iGetIndexValue(Kijun,iReversePos(i))+iGetIndexValue(Tenkan,iReversePos(i)))/2);
      iSetIndexValue(SpanA2, iReversePos(i), iGetIndexValue(SpanA,iReversePos(i)));
   end
--Senkou Span B
   pos=InpSenkou-1;
   if(calculated>InpSenkou)
   then
      pos=calculated-1;
   end
   for i=pos,count-1 do
      high_value=iGetPriceValue(PRICE_HIGH,iReversePos(i));
      low_value=iGetPriceValue(PRICE_LOW,iReversePos(i));
      k=i+1-InpSenkou;
      while(k<=i) do
         if(high_value<iGetPriceValue(PRICE_HIGH,iReversePos(k))) then
            high_value=iGetPriceValue(PRICE_HIGH,iReversePos(k));
         end
         if(low_value>iGetPriceValue(PRICE_LOW,iReversePos(k))) then
            low_value=iGetPriceValue(PRICE_LOW,iReversePos(k));
         end
         k = k + 1;
      end
      iSetIndexValue(SpanB, iReversePos(i), (high_value+low_value)/2);
      iSetIndexValue(SpanB2, iReversePos(i), iGetIndexValue(SpanB,iReversePos(i)));
   end
--Chikou Span
   pos=0;
   if(calculated>1)
   then
      pos=calculated-1;
   end
   for i=pos,count-1 do
      iSetIndexValue(Chikou, iReversePos(i), iGetPriceValue(PRICE_CLOSE,iReversePos(i)));
   end

   return(count);
end
```

策略池使得您可以通过使用Lua编写策略实时跟踪池中标的代码的价格变动：
```lua
require("..lua.indicator")

iSet({
		type=INDICATOR_TYPE_POOL,
		InpFastEMA=12,
		InpSlowEMA=26,
		InpSignalSMA=9,
		index_name1="DIF",
		index_name2="DEA",
		index_name3="MACD",
		index0 = {
			digits=3
		},
		index1 = {
			draw=DRAW_STICK,
			digits=3
		},
		index2 = {
			digits=3
		}
})

function OnFilter()
	iAddPool("600000.SH");
	iAddPool("600004.SH");
	iAddPool("000001.SZ");
end

function OnCalculate(count,calculated)
		if(count<=0) 
		then
 				return(0);
 		end
		
		--ref indicator
		hFastMA = iMA("",0,InpFastEMA,0,MODE_EMA,PRICE_CLOSE);
		hSlowMA = iMA("",0,InpSlowEMA,0,MODE_EMA,PRICE_CLOSE);
		
		--
  	
		--return calculated
  	return(count);
end
```

当指标或者策略发出买入卖出信号时，您可以通过调用交易接口执行交易指令：
```lua
require("..lua.indicator")

iSet({
		type=INDICATOR_TYPE_SECOND,
		trade=true,
		InpFastEMA=12,
		InpSlowEMA=26,
		InpSignalSMA=9,
		index0 = {
			name="DIF",
			digits=3
		},
		index1 = {
			name="DEA",
			draw=DRAW_STICK,
			digits=3
		},
		index2 = {
			name="MACD",
			digits=3
		}
})

function OnCalculate(count,calculated)
		if(count<=0) 
		then
 				return(0);
 		end
 
		--ref indicator
		hFastMA = iMA("",0,InpFastEMA,0,MODE_EMA,PRICE_CLOSE);
		hSlowMA = iMA("",0,InpSlowEMA,0,MODE_EMA,PRICE_CLOSE);
		
  	i=0;
  	limit=0;
		--last calculated bar will be recounted
  	limit=count-calculated;
  	if(calculated>0) 
  	then
    		limit = limit + 1;
    end
    		
		--DIF
  	for i=0,limit-1 do
  			dif = iGetIndexValue(0,i,hFastMA)-iGetIndexValue(0,i,hSlowMA);
    		iSetIndexValue(0, i, dif);
    end
    
    --DEA
    iMAIndexOnLine(1, InpSignalSMA, MODE_EMA, 0);
    
		--MACD
  	for i=0,limit-1 do
  			macd = (iGetIndexValue(0,i)-iGetIndexValue(1,i))*2;
    		iSetIndexValue(2, i, macd);
    end
    
    --if Cross do Buy or Sell 
    cross = iIsCross(0,1);
    if(cross>=0) 
  	then
    		iOrderSend("",OP_BUY,100);
    end
    if(cross<0) 
  	then
    		iOrderSend("",OP_SELL,100);
    end
    
		iOrderClose();
		iOrdersSelect();
		iOrdersTotal();
		iOrderSelectByIndex();
		iOrderSelectByTicket();
		iOrderSelectByMagic();
		iOrderType();
		iOrderTicket();
		iOrderSymbol();
		iOrderOpenPrice();
		iOrderClosePrice();
		iOrderOpenTime();
		iOrderCloseTime();
		iOrderExpiration();
		iOrderLots();
		iOrderProfit();
		iOrderTakeProfit();
		iOrderStopLoss();
		iOrderCommission();
		iOrderMagicNumber();
		iOrderComment();
		iOrderExtra();
  	
		--return calculated
  	return(count);
end
```

### 使用XIndicatorApi快速集成XIndicator系统

只需简单几行代码，即可集成XIndicator
```c/c++
  XPlatformApi* pApi = XPlatformApi::GetInstance();
	if(pApi) {
		pApi->RegisterSpi(&g_Platform);
		pApi->Init(szAppNameA,szAppPathA,szAppDataA);
		pApi->Login("","");
		pApi->Run();
		pApi->Term();
	}
```
更多细节请参考示例项目。

### 基于XIndicatorApi使用Python/JavaScript等其他语言快速集成XIndicator系统


### 基于XIndicator源码深度定制开发XIndicator系统


### 基于XIndicator模块化接口，为XIndicator增加更多行情、交易模块


### 基于XTrade项目原型开发基于XIndicator的应用


## 许可
XIndicator是[MIT许可](LICENSE)并且所有的依赖项也是MIT或BSD许可。
