#ifndef _FIELDDEF_H__
#define _FIELDDEF_H__

enum _USED_BY_
{
	UB_REPORT,			// 报表画面和综合排名画面，默认
	UB_FUNDAMENTAL,		// 基本资料画面(11画面)，股改分析器结果输入亦可使用
	UB_LIST,			// 沪深指数统计等列表画面
	UB_RIGHT_PANEL,		// 技术画面或走势画面的右侧信息栏窗口、状态栏
	UB_TREND_TITLE = UB_RIGHT_PANEL,// 走势画面主图标题栏、经纪排位窗口
	UB_TECHNIC_TITLE = UB_RIGHT_PANEL,// 走势画面主图标题栏、经纪排位窗口
	//UB_CURSOR_DETAIL,	// 技术画面或走势画面的左侧游标明细窗口
	UB_END,				// 内部控制用
};

enum _ID_FIELD_
{
	// 证券市场行情数据
	IDF_TIMEZONE,
	IDF_OPENTIME,
	IDF_DELAYTIME,
	IDF_CLOSETIME,
	IDF_TIMEPOINTCOUNT,
	IDF_DATE,
	IDF_TIME,
	IDF_CURTIMEPOINT,
	IDF_INDEX,							// 顺序			是(序号)							能
	IDF_COMMODITY_NAME,					// 商品名称		是(序号)			是				能
	//IDF_COMMODITY_FULL_NAME	=    IDF_COMMODITY_NAME, // 商品全称
	IDF_CLOSE,							// 昨收价		是(元)/是
	IDF_OPEN,							// 开盘价		是(元)/是
	IDF_HIGH,							// 最高价		是(元)/是
	IDF_LOW,							// 最低价		是(元)/是
	IDF_NOW,							// 最新价		是(元)/是
	IDF_VOLUME,							// 总成交量		是(股、张、份)
	IDF_AMOUNT,							// 总成交金额	是(元)
	IDF_COMMODITY_CODE,					// 商品代码		是(序号)			是				能
	IDF_DELTA,							// 涨跌值		是(元)/是
	IDF_DELTA_PERCENT, // 涨跌幅度%	是(%)/是
	IDF_RANGE_PERCENT, // 振幅%		是(%)
	IDF_VOLUME_RATIO, // 量比			是
	IDF_STRONG_WEAK, // 强弱度		是(%)/是
	IDF_CURRENCY, // 货币			是(QL_CURRENCY)		是				能
	IDF_LOT_SIZE, // 交易单位(手比率)	是								能
	IDF_SPREAD_VALUE, // 差价(港交所)	是(元)								能(限港交所)
	IDF_VIRTUAL_PRICE, // 盘前虚拟(平衡)成交价(港交所)	是(元)/是
	IDF_VIRTUAL_VOLUME, // 盘前虚拟(平衡)成交量(港交所)	是(股)
	IDF_RECENT_DELTA_PERCENT, // 快速涨跌%	是(%)/是
	IDF_TURNOVER_RATE, // 换手率%		是(%)
	IDF_CHANGE_HANDS_PERCENT	=   IDF_TURNOVER_RATE, // 换手率%
	IDF_PRICE_EARNING_RATIO, // 市盈率		是(倍)
	IDF_PER						=   IDF_PRICE_EARNING_RATIO, // 市盈率
	IDF_LAST_VOLUME, // 最近快照成交量(现量)	是(股、张、份)
	IDF_BID_PRICE, // 买入价		是(元)/是
	IDF_ASK_PRICE, // 卖出价		是(元)/是
	IDF_CURRENT_VALUE, // 流通市值		是(元)
	IDF_TOTAL_VALUE, // 总市值		是(元)
	IDF_PRICE_BOOK_VALUE_RATIO, // 市净率		是(倍)
	IDF_PBR						=   IDF_PRICE_BOOK_VALUE_RATIO,
	IDF_WEIBI, // 委比%		是(%)/是
	IDF_BID_ASK_VOLUME_DIFF, // 委量差		是(股、张、份)/是
	IDF_BID_AMOUNT, // 总委买金额	是(元)
	IDF_BID_VOLUME, // 总委买量		是(股、张、份)
	IDF_ASK_AMOUNT, // 总委卖金额	是(元)
	IDF_ASK_VOLUME, // 总委卖量		是(股、张、份)
	IDF_AVERAGE_VOLUME, // 5日均量(不含当前交易日)	是(股)
	IDF_AVERAGE_PRICE, // 均价			是(元)/是
	IDF_LAST_AMOUNT, // 现额			是(元)
	IDF_CEILING_PRICE, // 涨幅(涨停)价	是(元)/是
	IDF_FLOOR_PRICE, // 跌幅(跌停)价	是(元)/是
	IDF_PRICE_RATE, // 价格放大倍率	是(倍数)							能
	// 可用于日线、走势等数据中价格的换算，如果oComRef合法的话，保证大于0，否则会返回false(此时为0)
	// 由于返回的是double型，因此当外部需要以整型来使用时则要通过+0.500001并强转成整数来处理
	IDF_DECIMAL_DIGITS, // 价格的小数点后位数	是(倍数)					能
	// 可用于日线、走势等数据中价格(单位：元)的显示控制
	// 由于返回的是double型，因此当外部需要以整型来使用时则要通过+0.500001并强转成整数来处理
	IDF_CONTRACT_MULTIPLIER, // 合约乘数(用于期货)	
	IDF_HIGH_TIME, // 最高价产生时间
	IDF_LOW_TIME, // 最低价产生时间


	IDF_PREMIUM, // 溢价，可用于A-H差价、期货高低水等，注意与IDF_PREMIUM_PERCENT的区别	是(元)/是
	IDF_BOND_VALUATION, // (开盘)债券估值(仅限深圳证券交易所)	是(元)
	IDF_RISE_DROP_DIFF, // 涨跌率(红绿均)之差	是(%)
	IDF_RISING_PERCENT, // 上涨样本率%	是(%)
	IDF_DROPING_PERCENT, // 下跌样本率%	是(%)
	IDF_CEILING_PERCENT, // 涨停样本率%	是(%)
	IDF_FLOOR_PERCENT, // 跌停样本率%	是(%)
	IDF_RISE_COUNT, // 上涨家数		是(家)/是
	IDF_EQUAL_COUNT, // 平盘家数		是(家)/是
	IDF_DROP_COUNT, // 下跌家数		是(家)/是
	IDF_LAST_RISE_COUNT, // 前一次上涨家数	是(家)/是
	IDF_LAST_EQUAL_COUNT, // 前一次平盘家数	是(家)/是
	IDF_LAST_DROP_COUNT, // 前一次下跌家数	是(家)/是
	IDF_AVERAGE_ASK_PRICE, // 委卖均价		是(元)/是
	IDF_AVERAGE_BID_PRICE, // 委买均价		是(元)/是
	IDF_FULL_PRICE, // 债券全价		是(元)
	IDF_INTEREST, // 债券利息		是(元)
	IDF_AH, // AH			是(元)/是
	IDF_NH, // NH			是(元)/是
	IDF_CDP, // CDP			是(元)/是
	IDF_NL, // NL			是(元)/是
	IDF_AL, // AL			是(元)/是
	IDF_TBP, // 多空平衡		是(元)/是
	IDF_DL, // 多头获利		是(元)/是
	IDF_DT, // 多头停损		是(元)/是
	IDF_KL, // 空头回补		是(元)/是
	IDF_KT, // 空头停损		是(元)/是
	IDF_NET_VALUE, // (今日)EFT/LOF(模拟)净值	是(元)
	IDF_PREV_NET_VALUE, // (昨日)LOF/非LOF净值	是(元)
	IDF_YIELD_PERCENT, // 债券收益率%	是(%)
	IDF_BARGAIN	, // 总成交笔数	是(单)
	IDF_AVERAGE_BARGAIN_VOLUME, // 每笔均量		是(股、张、份)
	IDF_LONG_SHORT_POSITION, // 多头或空头	是(0多头,1空头)
	// 由于返回的是double型，因此当外部需要以整型来使用时则要通过+0.500001并强转成整数来处理
	IDF_COMMODITY_ENBRIEF_NAME, // 英文简称		是(序号)			是				能(限港交所)
	IDF_NAME_PREFIX, // 名称前缀(深交所)	是(强转DWORD)	是				能(限深交所)
	IDF_BOUGHT_VOLUME, // 外盘，即买盘	是(股、张、份)/是
	IDF_SOLD_VOLUME, // 内盘，即卖盘	是(股、张、份)/是
	IDF_ASK_ORDERS_5, // 卖五笔数		是(单)
	IDF_ASK_ORDERS_4, // 卖四笔数		是(单)
	IDF_ASK_ORDERS_3, // 卖三笔数		是(单)
	IDF_ASK_ORDERS_2, // 卖二笔数		是(单)
	IDF_ASK_ORDERS_1, // 卖一笔数		是(单)
	IDF_BID_ORDERS_1, // 买一笔数		是(单)
	IDF_BID_ORDERS_2, // 买二笔数		是(单)
	IDF_BID_ORDERS_3, // 买三笔数		是(单)
	IDF_BID_ORDERS_4, // 买四笔数		是(单)
	IDF_BID_ORDERS_5, // 买五笔数		是(单)
	IDF_ASK_PRICE_10, // 卖十价		是(元)/是
	IDF_ASK_PRICE_9, // 卖九价		是(元)/是
	IDF_ASK_PRICE_8, // 卖八价		是(元)/是
	IDF_ASK_PRICE_7, // 卖七价		是(元)/是
	IDF_ASK_PRICE_6, // 卖六价		是(元)/是
	IDF_ASK_PRICE_5, // 卖五价		是(元)/是
	IDF_ASK_PRICE_4, // 卖四价		是(元)/是
	IDF_ASK_PRICE_3, // 卖三价		是(元)/是
	IDF_ASK_PRICE_2, // 卖二价		是(元)/是
	IDF_ASK_PRICE_1, // 卖一价，同卖出价IDF_ASK_PRICE
	IDF_BID_PRICE_1, // 买一价，同买入价IDF_BID_PRICE
	IDF_BID_PRICE_2, // 买二价		是(元)/是
	IDF_BID_PRICE_3, // 买三价		是(元)/是
	IDF_BID_PRICE_4, // 买四价		是(元)/是
	IDF_BID_PRICE_5, // 买五价		是(元)/是
	IDF_BID_PRICE_6, // 买六价		是(元)/是
	IDF_BID_PRICE_7, // 买七价		是(元)/是
	IDF_BID_PRICE_8, // 买八价		是(元)/是
	IDF_BID_PRICE_9, // 买九价		是(元)/是
	IDF_BID_PRICE_10, // 买十价		是(元)/是
	IDF_ASK_VOLUME_10, // 卖十量		是(股、张、份)
	IDF_ASK_VOLUME_9, // 卖九量		是(股、张、份)
	IDF_ASK_VOLUME_8, // 卖八量		是(股、张、份)
	IDF_ASK_VOLUME_7, // 卖七量		是(股、张、份)
	IDF_ASK_VOLUME_6, // 卖六量		是(股、张、份)
	IDF_ASK_VOLUME_5, // 卖五量		是(股、张、份)
	IDF_ASK_VOLUME_4, // 卖四量		是(股、张、份)
	IDF_ASK_VOLUME_3, // 卖三量		是(股、张、份)
	IDF_ASK_VOLUME_2, // 卖二量		是(股、张、份)
	IDF_ASK_VOLUME_1, // 卖一量		是(股、张、份)
	IDF_BID_VOLUME_1, // 买一量		是(股、张、份)
	IDF_BID_VOLUME_2, // 买二量		是(股、张、份)
	IDF_BID_VOLUME_3, // 买三量		是(股、张、份)
	IDF_BID_VOLUME_4, // 买四量		是(股、张、份)
	IDF_BID_VOLUME_5, // 买五量		是(股、张、份)
	IDF_BID_VOLUME_6, // 买六量		是(股、张、份)
	IDF_BID_VOLUME_7, // 买七量		是(股、张、份)
	IDF_BID_VOLUME_8, // 买八量		是(股、张、份)
	IDF_BID_VOLUME_9, // 买九量		是(股、张、份)
	IDF_BID_VOLUME_10, // 买十量		IDF_ASK_VOL_DIFF_

	IDF_AVERAGE_BARGAIN_AMOUNT, // 均笔额 － 当日总金额/成交笔数 
	IDF_RD_RATIO, //涨跌比 － [上涨家数-下跌家数] / [上涨家数+下跌家数]
	IDF_STK_COUNT, //总家数 － 样本股总数量
	IDF_DISCOUNT_RATIO, //基金折价率 － 折价率=[市价-净值]/净值*100%
	IDF_OBJECT_COMMODITY_NOW, //标的价格 － 即权证对应的标的正股的当前价格
	IDF_OBJECT_COMMODITY_DELTA_PERCENT, //标的涨幅 － 即权证对应的标的正股的当前涨幅
	IDF_BS_VOLUME_RATIO, //盘比 － 盘比={[外盘－内盘]÷[外盘+内盘]}*100%
	IDF_PREMIUM_FUND, //基金溢价
	IDF_RISE_AG_COUNT, // 分类A股 上涨家数		是(家)/是
	IDF_EQUAL_AG_COUNT, // 分类A股 平盘家数		是(家)/是
	IDF_DROP_AG_COUNT, // 分类A股 下跌家数		是(家)/是
	IDF_RISE_BG_COUNT, // 分类B股 上涨家数		是(家)/是
	IDF_EQUAL_BG_COUNT, // 分类B股 平盘家数		是(家)/是
	IDF_DROP_BG_COUNT, // 分类B股 下跌家数		是(家)/是
	IDF_RISE_JJ_COUNT, // 分类基金 上涨家数		是(家)/是
	IDF_EQUAL_JJ_COUNT, // 分类基金 平盘家数		是(家)/是
	IDF_DROP_JJ_COUNT, // 分类基金 下跌家数		是(家)/是

	// 盘口数据字段
	IDF_ASK_VOL_DIFF_10, // 卖十量差		是(股、张、份)
	IDF_ASK_VOL_DIFF_9, // 卖九量差		是(股、张、份)
	IDF_ASK_VOL_DIFF_8, // 卖八量差		是(股、张、份)
	IDF_ASK_VOL_DIFF_7, // 卖七量差		是(股、张、份)
	IDF_ASK_VOL_DIFF_6, // 卖六量差		是(股、张、份)
	IDF_ASK_VOL_DIFF_5, // 卖五量差		是(股、张、份)
	IDF_ASK_VOL_DIFF_4, // 卖四量差		是(股、张、份)
	IDF_ASK_VOL_DIFF_3, // 卖三量差		是(股、张、份)
	IDF_ASK_VOL_DIFF_2, // 卖二量差		是(股、张、份)
	IDF_ASK_VOL_DIFF_1, // 卖一量差		是(股、张、份)
	IDF_BID_VOL_DIFF_1, // 买一量差		是(股、张、份)
	IDF_BID_VOL_DIFF_2, // 买二量差		是(股、张、份)
	IDF_BID_VOL_DIFF_3, // 买三量差		是(股、张、份)
	IDF_BID_VOL_DIFF_4, // 买四量差		是(股、张、份)
	IDF_BID_VOL_DIFF_5, // 买五量差		是(股、张、份)
	IDF_BID_VOL_DIFF_6, // 买六量差		是(股、张、份)
	IDF_BID_VOL_DIFF_7, // 买七量差		是(股、张、份)
	IDF_BID_VOL_DIFF_8, // 买八量差		是(股、张、份)
	IDF_BID_VOL_DIFF_9, // 买九量差		是(股、张、份)
	IDF_BID_VOL_DIFF_10, // 买十量差		是(股、张、份)

	// 非证券市场专用行情数据
	// 期货专用数据
	IDF_PREV_POSITION, // 昨日持仓		是(合约)
	IDF_PREV_SETTLEMENT, // 昨日结算价	是(元)/是
	IDF_POSITION, // 今日持仓		是(合约)
	IDF_SETTLEMENT, // (今日)结算价	是(元)/是
	IDF_OPEN_POSITION, // 今日开仓		是(合约)
	IDF_CLOSE_POSITION, // 今日平仓		是(合约)
	IDF_DELTA_POSITION, // 今日仓差		是(合约)/是
	IDF_OPEN_CLOSE_POSITION, // 今日开平仓状况	是(拼音顺序)/是	是
	IDF_LAST_OPEN_POSITION, // 现开仓(最近快照开仓)	是(合约)
	IDF_LAST_CLOSE_POSITION, // 现平仓(最近快照平仓)	是(合约)
	IDF_LAST_DELTA_POSITION, // 现仓差(最后快照仓差)	是(合约)/是
	IDF_LAST_OPEN_CLOSE_POSITION, // 现开平仓状况(最近快照开平仓状况)	是(拼音顺序)/是	是
	IDF_ARBITRAGE_COST_UPPER_1, // 股指期货套利成本价(1年定期存款利率折算)上限	是(元)/是
	IDF_ARBITRAGE_COST_UPPER_2, // 股指期货套利成本价(1年定期贷款利率折算)上限	是(元)/是
	IDF_ARBITRAGE_COST_UPPER_3, // 股指期货套利成本价(1月同业拆借利率折算)上限	是(元)/是
	IDF_ARBITRAGE_COST_UPPER_4, // 股指期货套利成本价(3月同业拆借利率折算)上限	是(元)/是
	IDF_ARBITRAGE_COST_UPPER_5, // 股指期货套利成本价(6月同业拆借利率折算)上限	是(元)/是
	IDF_ARBITRAGE_COST_UPPER_6, // 股指期货套利成本价(9月同业拆借利率折算)上限	是(元)/是
	IDF_WHOLE_HIGH, // 合约期最高价(港期货)	是(元)/是
	IDF_WHOLE_LOW, // 合约期最低价(港期货)	是(元)/是
	IDF_MONTH_HIGH, // 当月最高价(港期货)	是(元)/是
	IDF_MONTH_LOW, // 当月最低价(港期货)	是(元)/是
	IDF_CALCULATED_OPENING, // 拟开盘价(港期指)	是(元)/是
	IDF_EAS, // (今日)可能结算价	是(元)/是

	// 以下为财务资料数据字段
	IDF_LISTING_DATE, // 上市日期		是(YYYYMMDD)
	IDF_VOCATION, // 行业			是(拼音顺序)		是
	IDF_TOTAL_SHARES, // 总股本		是(股)
	IDF_CURRENT_A_SHARES, // 流通A股		是(股)
	IDF_CURRENT_B_SHARES, // 流通B股		是(股)
	IDF_TOTAL_ASSETS, // 总资产		是(元)
	IDF_EQUITY, // 股东权益		是(元)/是
	IDF_NET_ASSETS				= IDF_EQUITY, // 净资产
	IDF_NA						= IDF_NET_ASSETS,
	IDF_ACCUMULATION_FUND, // 资本公积		是(元)
	IDF_NET_ASSETS_PER_SHARE, // 每股净资产	是(元/股)/是
	IDF_NAPS					= IDF_NET_ASSETS_PER_SHARE,
	IDF_TOTAL_PROFIT, // 利润总额		是(元)/是
	IDF_NET_PROFIT, // 净利润		是(元)/是
	IDF_MAIN_EARNINGS, // 主营业务收入	是(元)
	IDF_MIDTERM_EPS, // 中期每股收益	是(元/股)/是
	IDF_YEAR_EPS, // 年度每股收益	是(元/股)/是
	IDF_NET_ASSETS_YIELD, // 净资产收益率	是(%)/是
	IDF_EQUITY_DEBT_RATIO, // 资产负债比%	是(%)
	IDF_EARNINGS_PER_SHARE, // 最新每股收益	是(%)/是
	IDF_EPS						= IDF_EARNINGS_PER_SHARE,
	IDF_CURRENT_SHARES, // 流通股		是(股)
	//IDF_REGION, // 地域			否
	//IDF_TRANSFERABLE_BOND, // 可转换债券	否
	//IDF_CIRCULATING_ASSETS, // 流动资产		否
	IDF_FIXED_ASSETS, // 固定资产		是(元)
	IDF_FA						= IDF_FIXED_ASSETS,
	//IDF_INTANGIBLE_DEFERRED_ASSETS, // 无形及递延资产	否
	//IDF_OTHER_ASSETS, // 其它资产		否
	//IDF_TOTAL_LIABILITIES, // 总负债		否
	//IDF_LONG_TERM_LIABILITIES, // 长期负债		否
	//IDF_CIRCULATING_LIABILITIES, // 流动负债	否
	//IDF_OTHER_LIABILITIES, // 其它负债		否
	IDF_UNDISTRIBUTED_PROFIT, // 未分配利润	是(元)
	//IDF_ADJUSTED_NAPS, // 调整后每股净资产	否
	IDF_MAIN_PROFIT, // 主营业务利润	是(元)
	//IDF_CIRCULATING_RATIO, // 流动比率		否
	//IDF_QUICK_RATIO, // 速动比率		否
	//IDF_EQUITY_PERCENT, // 股东权益比	否
	IDF_LAST_DISTRIBUTING_DATE, // 最近分配日期	是(YYYYMMDD)
	IDF_PRESENT_NUMBER, // 每10股送股数	是(股/10股)
	IDF_MATCH_NUMBER, // 每10股配股数	是(股/10股)
	IDF_HIGH_MATCH_PRICE, // 最高配股价	是(元)
	IDF_LOW_MATCH_PRICE, // 最低配股价	是(元)
	IDF_BONUS_PER_SHARE, // 每股红利		是(元/股)
	IDF_BRIEF, // 简要说明		否					是
	IDF_UPDATING_DATE, // 资料更新日期	是(YYYYMMDD)
	IDF_LAST_YEAR_DIVIDENT, // 上年度派息	是(元/股)
	IDF_LAST_YEAR_TRANSFERS, // 上年度送转股	是(股/股)
	IDF_CURRENT_H_SHARES, // 流通H股		是(股)
	IDF_DIVIDENDYIELD, // 周息率%		是(%)

	IDF_YEAR_EPS2, // 每股动态收益
	IDF_FUND_PER_SHARE, // 每股公积
	IDF_EQUITY_RATIO, // 股东权益比% － 股东权益比＝[股东权益总额÷总资产净额]*100%
	IDF_EPS_FUND, // 基金单位净收益		
	IDF_RUPPERCENT, // 笔涨
	IDF_SNAP_TIME, // 快照时间

	IDF_EQUITY_DEBT, // 资产负债
	IDF_BASE_DATE, // 基准日期
	IDF_REPORT_DATE, // 报告日期


	// 以下为债券基本资料数据字段
	IDF_COMMODITY_FULL_NAME, // 债券全称		是(序号)			是
	IDF_ISSUED_AMOUNT, // 债券发行总额	是(元)
	IDF_PAR_PRICE, // 债券票面价格	是(元)
	IDF_ISSUE_MODE, // 债券发行方式	否					是
	IDF_PAY_INTEREST_TIMES, // 债券付息期数	是(期)
	IDF_PAR_INTEREST_RATE, // 债券票面利率	是(%)
	IDF_PAY_INTEREST_FREQUENCY, // 债券付息频率	是(次/年)
	//IDF_MODIFYING_DATE, // 债券更新日期，见IDF_UPDATING_DATE
	IDF_ISSUE_DATE, // 债券发行日期	是(YYYYMMDD)
	IDF_BEGIN_DATE, // 债券计息日期	是(YYYYMMDD)
	IDF_END_DATE, // 债券到期日期	是(YYYYMMDD)
	IDF_LISTING_EXCHANGE, // 债券上市交易所	是(QL_STOCK_EXCHANGE)
	//IDF_BRIEF, // 简要说明，同IDF_BRIEF
	IDF_COMMODITY_KIND, // 债券种类		是(0,1,2)			是(附息债券、贴现债券、到期一次还本付息债券)
	IDF_BOND_NET_PRICE, // 债券净价				

	IDF_ISSUED_VOLUME, // 权证发行总量	是(份)
	IDF_CURRENT_VOLUME, // 权证流通余额	是(份)
	IDF_EXERCISE_DIRECTION, // 行权方向		是(0,1,2,3,4)		是(认购权证、认沽权证、牛证、熊证、其他)
	IDF_EXERCISE_MODE, // 行权方式		是(0,1,2,3,4,5,6)	是(百慕大权证、美式权证、欧式权证、地区性权证、特种权证、不设余额牛熊证、设有余额牛熊证)
	IDF_IMPLEMENTING_RATE, // 行权比例		是(标的股票/权证)
	IDF_IMPLEMENTING_PRICE, // 行权价格		是(元/股)
	IDF_IMPLEMENTING_COST, // 行权成本		是(元/股)/是
	IDF_LISTING_DATE_, // 权证上市日期	是(YYYYMMDD)
	IDF_EXPIRATION_DATE, // 权证到期日期	是(YYYYMMDD)
	IDF_LEVERAGE_RATE, // 杠杆比例		是(倍)
	IDF_POTENTIAL_PRICE, // 内在价值		是(元)
	IDF_EQUIVALENCE_PERCENT, // 等价比率%	是(%)/是
	IDF_OBJECT_COMMODITY_CODE, // 标的证券代码	是(序号)			是
	IDF_BEGIN_DATE_, // 行权起始		是(YYYYMMDD)
	IDF_END_DATE_, // 行权截止		是(YYYYMMDD)
	IDF_OBJECT_COMMODITY_NAME, // 标的证券名称	是(序号)			是
	IDF_SETTLEMENT_MODE, // 结算方式		是(1,2)				是(实物、现金)
	IDF_SETTLEMENT_PRICE, // 结算价格		是(元)
	IDF_IMPLEMENTING_CODE, // 行权代码		是(序号)			是
	//IDF_UPDATING_DATE_, // 权证更新日期，见IDF_UPDATING_DATE
	IDF_REMAINING_DAYS, // 尚余交易天数	是(天)
	//IDF_BRIEF__, // 简要说明，同IDF_BRIEF
	IDF_LAST_IMPLEMENTING_DATE, // 最后交易日	是(YYYYMMDD)
	IDF_PREMIUM_PERCENT, // 权证溢价率%	是(%)/是
	IDF_ACTUAL_LEVERAGE_RATE, // 实际杠杆		否
	IDF_SENSITIVITY_DELTA, // 对冲值		否
	IDF_INTEREST_RATE, // 权证存续期无风险利率%	是(%)
	IDF_HISTORY_VOLATILITY, // 历史波幅%	是(%)
	IDF_COMMODITY_CATEGORY, // 权证种类		是(1,2,3)			是(标准、非标准、牛熊证)
	IDF_IMPLIED_VOLATILITY, // 引伸波幅%	否
	IDF_TOEND_DAYS, // 权证距到期日天数	是(天)
	IDF_CALL_PRICE, // 牛熊证强制收回价	是(元)
	IDF_OUTSTANDING_QUANTITY,	//街货量
	IDF_OUTSTANDING_QUANTITY_PERCENT, //街货比例
	IDF_CONTRACT_CODE,	// 合约代码 C19	
	IDF_CONTRACT_STATUSFLAG, //期权合约状态信息标签 C8
	//该字段为8位字符串，左起每位表示特定的含义，无定义则填空格。
	//第1位：‘0’表示可开仓，‘1’表示限制卖出开仓（包括备兑开仓）和买入开仓。
	//第2位：‘0’表示未连续停牌，‘1’表示连续停牌。
	//第3位：‘0’表示未临近到期日，‘1’表示距离到期日不足10个交易日。
	//第4位：‘0’表示近期未做调整，‘1’表示最近10个交易日内合约发生过调整。
	//第5位：‘A’表示当日新挂牌的合约，‘E’表示存续的合约，‘D’表示当日摘牌的合约。
	IDF_CONTRACT_TRADEPHASECODE, //期权交易时段状态码 C4
	//该字段为4 位字符串，左起每位表示特定的含义，无定义则填空格。
	//第1 位：‘S’表示启动（开市前）时段，‘C’表示集合竞价时段，‘T’表示连续交易时段，‘B’表示休市时段，‘E’表示闭市时段，‘V’表示波动性中断，‘P’表示临时停牌。
	//第2 位：‘0’表示未连续停牌，‘1’表示连续停牌。
	//如果期权合约的产品代码为“00000000”，则表示全市场行情状态：
	//该字段为8 位字符串，左起每位表示特定的含义，无定义则填空格。
	//第1 位：‘S’表示全市场启动期间（开市前），‘T’表示全市场处于交易期间（含中间休市）， ‘E’表示全市场处于闭市期间。
	//第2 位：‘1’表示开盘集合竞价结束标志，未结束取‘0’。
	//第3 位：‘1’表示市场行情闭市标志，未闭市取‘0’。


	IDF_UP_COMMODITY_NAME, // 领涨商品名称(这个字段仅在CalcFieldsString处理，数据层不作处理)
	IDF_UP_COMMODITY_CODE, // 领涨商品代码(领涨股代码,领涨股市场编号)
	IDF_CTB, // 板块对大盘贡献度

	// 以下为个股财富密码等其他的字段
	IDF_RICH_CODE_RATING, // 个股财富密码评级(高亮字段)	是(级)	是
	IDF_RICH_CODE_DESCRIPTION, // 个股财富密码评级的描述(HINT提示)	是(级)	是
	IDF_RICH_CODE_RATING_COLOR, // 个股财富密码评级(高亮字段)的颜色	是(COLORREF)
	// 由于返回的是double型，因此外部需要通过+0.500001并强转成DWORD来使用

	//以下是实战版本报表的主力监控字段
	IDF_MAIN_WATCH_START, // 主力监控字段的开始 
	IDF_AVERAGE_CONTRACT_VOLUME_5, // 最近5个交易日(不含当前交易日)每成交单均量	是(股)
	IDF_AVERAGE_BOUGHT_CONTRACT_5, // 最近5个交易日(不含当前交易日)日均成交买单数(用于动态指标)	是(单)
	IDF_AVERAGE_SOLD_CONTRACT_5, // 最近5个交易日(不含当前交易日)日均成交卖单数(用于动态指标)	是(单)
	IDF_MAIN_BOUGHT_SOLD_DIFF, // 买卖气(主力净买)	是(%)
	IDF_MAIN_POWER, // 主力强度		是(股/单)
	//IDF_MAIN_BOUGHT_POWER, // 主力买强度	是(股/单)
	//IDF_MAIN_SOLD_POWER, // 主力卖强度	是(股/单)
	IDF_MAIN_ACTIVITY, // 主力活跃度	是(%)
	IDF_MAIN_POSITION, // 主力持仓		是(无量纲)
	IDF_RETAIL_POSITION, // 散户持仓		是(无量纲)
	//IDF_HAWK_EYE, // 鹰眼指标		是(元)
	IDF_DDX, // DDX指标		是(%，港股‰)
	//IDF_DDY,		// DDY指标		是(单)
	//IDF_DDZ,		// DDZ指标		是(%)
	IDF_AVERAGE_DDX_5, // 最近5个交易日(含当前交易日)的DDX的累计
	IDF_AVERAGE_DDX_10, // 最近10个交易日(含当前交易日)的DDX的累计
	IDF_AVERAGE_DDX_20, // 最近20个交易日(含当前交易日)的DDX的累计
	IDF_DDX_POSITIVE_DAYS, // DDX10天内(含当前交易日)红天数	是(天)
	IDF_DDX_CONTINOUS_DAYS, // DDX连续(含当前交易日)红/绿天数	是(天)
	IDF_AVERAGE_BOUGHT_VOLUME, // 买单均量		是(股/单)
	IDF_AVERAGE_SOLD_VOLUME, // 卖单均量		是(股/单)
	IDF_AVERAGE_BS_VOLUME_DIFF, // 买卖单均量差	是(股/单)
	IDF_AVERAGE_BS_VOLUME_RATIO, // 买卖单均量比	是(倍)
	IDF_DELTA_AVERAGE_BS_VOLUME_RATIO, // 1分钟Δ均量比	是(倍)
	IDF_AVERAGE_CONTRACT_VOLUME, // 每单均量		是(股/单)
	IDF_AVERAGE_CONTRACT_TURNOVER_RATE, // 均单换手	是(%/单，并放大10000倍)
	IDF_MAIN_BOUGHT, // 主力买入		是(%)
	IDF_MAIN_SOLD, // 主力卖出		是(%)
	IDF_RETAIL_BOUGHT, // 散户买入		是(%)
	IDF_RETAIL_SOLD, // 散户卖出		是(%)
	IDF_BID_PERCENT, // 委买占比		是(%)
	IDF_ASK_PERCENT, // 委卖占比		是(%)
	IDF_AVERAGE_MAIN_BOUGHT_AMOUNT_5,// 最近5个交易日(不含当前交易日)日均主力总买额(用于动态指标)	是(元)
	IDF_AVERAGE_MAIN_SOLD_AMOUNT_5, // 最近5个交易日(不含当前交易日)日均主力总卖额(用于动态指标)	是(元)
	IDF_LONG_SHORT_RATIO, // 多空比		是(倍)
	IDF_CAPITAL_ENERGY, // 资金动能		是(无量纲)
	IDF_SIL, // 风警值		是(倍)
	IDF_GOLD_LADDER, // 黄金阶梯		是(-1,0,1)			是(转弱,空,转强)
	IDF_ABNORMAL_ACTION, // 主力异动		是(-1,0,1)			是(空头异动,空,多头异动)
	IDF_INSTITUTION_POSITION, // 机构持仓		是(%)
	IDF_LARGE_POSITION, // 大户持仓		是(%)
	IDF_MIDDLE_POSITION, // 中户持仓		是(%)
	IDF_SMALL_POSITION, // 散户持仓		是(%)
	IDF_INSTITUTION_DELTA, // 机构增减		是(%，港股‰)
	IDF_LARGE_DELTA, // 大户增减		是(%，港股‰)
	IDF_MIDDLE_DELTA, // 中户增减		是(%，港股‰)
	IDF_SMALL_DELTA, // 散户增减		是(%，港股‰)
	IDF_INSTITUTION_DELTA_5, // 机构5日增减	是(%，港股‰)
	IDF_LARGE_DELTA_5, // 大户5日增减	是(%，港股‰)
	IDF_MIDDLE_DELTA_5, // 中户5日增减	是(%，港股‰)
	IDF_SMALL_DELTA_5, // 散户5日增减	是(%，港股‰)
	IDF_INSTITUTION_DELTA_10, // 机构10日增减	是(%，港股‰)
	IDF_LARGE_DELTA_10, // 大户10日增减	是(%，港股‰)
	IDF_MIDDLE_DELTA_10, // 中户10日增减	是(%，港股‰)
	IDF_SMALL_DELTA_10, // 散户10日增减	是(%，港股‰)
	IDF_INSTITUTION_DELTA_20, // 机构20日增减	是(%，港股‰)
	IDF_LARGE_DELTA_20, // 大户20日增减	是(%，港股‰)
	IDF_MIDDLE_DELTA_20, // 中户20日增减	是(%，港股‰)
	IDF_SMALL_DELTA_20, // 散户20日增减	是(%，港股‰)
	IDF_MAIN_WATCH_END			= IDF_SMALL_DELTA_20, // 主力监控字段的结束(内容控制用)

	IDF_PREOPENING,//是否是预揭示

	IDF_END,
};

enum _STAT_TYPE_
{
	STA_AVG1	= 0x1,
	STA_AVG2	= 0x2,
	STA_AVG3	= 0x4,
	STA_SUM		= 0x8,
	STA_MAX		= 0x10,
	STA_MIN		= 0x20,
	STA_TOPn	= 0x40,
	STA_BOTTOMn	= 0x80,
	STA_ITEM_END = 0x80,
};

#define MAX_FIELD_STRVALUE_SIZE		96

#pragma pack(1)

enum
{
	FIELD_SORT_NONE,	//不排序
	FIELD_SORT_ASC,		//升序
	FIELD_SORT_DESC,	//降序
};

enum
{
	FIELD_VALUE_NULL = 0,
	FIELD_VALUE_NUMMBER,
	FIELD_VALUE_DATE,
	FIELD_VALUE_TIME,
	FIELD_VALUE_FLOAT,
	FIELD_VALUE_AMOUNT,
	FIELD_VALUE_VOLUME,
	FIELD_VALUE_STRINGA,
	FIELD_VALUE_STRINGW,
#ifndef UNICODE
#define FIELD_VALUE_STRING FIELD_VALUE_STRINGA
#else
#define FIELD_VALUE_STRING FIELD_VALUE_STRINGW
#endif//
};

typedef struct tagQFieldName
{
	long		FieldID:24;
	long		bCalculated:1;
	long		cSort:2;
	long		cValueType:5;
	union
	{
#ifndef UNICODE
		char			szValue[MAX_FIELD_STRVALUE_SIZE*2];
#else
		wchar_t			szValue[MAX_FIELD_STRVALUE_SIZE];
#endif//
		char			szValueA[MAX_FIELD_STRVALUE_SIZE*2];
		wchar_t			szValueW[MAX_FIELD_STRVALUE_SIZE];
	};
}FIELD_NAME,*PFIELD_NAME;

typedef struct tagQFieldValue
{
	long		FieldID:24;
	long		bCalculated:1;
	long		cUpDown:2;
	long		cValueType:5;
	union
	{
		__int64			nValue;
		double			dValue;
#ifndef UNICODE
		char			szValue[MAX_FIELD_STRVALUE_SIZE*2];
#else
		wchar_t			szValue[MAX_FIELD_STRVALUE_SIZE];
#endif//
		char			szValueA[MAX_FIELD_STRVALUE_SIZE*2];
		wchar_t			szValueW[MAX_FIELD_STRVALUE_SIZE];
	};
	unsigned char		cTextType;
	union
	{
#ifndef UNICODE
		char			szText[MAX_FIELD_STRVALUE_SIZE*2];
#else
		wchar_t			szText[MAX_FIELD_STRVALUE_SIZE];
#endif//
		char			szTextA[MAX_FIELD_STRVALUE_SIZE*2];
		wchar_t			szTextW[MAX_FIELD_STRVALUE_SIZE];
	};
} FIELD_VALUE,*PFIELD_VALUE;

#pragma pack()

#endif
