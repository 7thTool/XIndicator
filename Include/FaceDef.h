#ifndef _H_FACEDEF_H_
#define _H_FACEDEF_H_

//输出对齐
//mode 水平对齐方式
#define QL_ALIGN_CENTER			0
#define QL_ALIGN_LEFT			1
#define QL_ALIGN_RIGHT			2

//vMode 垂直对齐方式
#define QL_VALIGN_CENTER		0
#define QL_VALIGN_TOP			1
#define QL_VALIGN_BOTTOM		2

//putQlString中 fontSpInfo的信息
#define QL_SPFONT_NULL			0
#define QL_SPFONT_UNDLINE		1
#define QL_SPFONT_SUBUNDLINE	2
#define QL_SPFONT_UNDLINE_WITHTRI	3 //带有上下三角形的下划线 + 上三角 ， - 下三角
#define QL_SPFONT_UNDLINE_SMALLWND	4 //小窗口下的下划线数字字体

//一些系统固定的颜色。这些颜色只能作为缺省的情况下的使用。
#define QCOLOR_SYS_TRANSPARENT				RGB(255,0,0)
#define QCOLOR_SYS_RED						RGB(252, 84, 84)
#define QCOLOR_SYS_YELLOW					RGB(252, 252, 84)
#define QCOLOR_SYS_CYAN						RGB(84, 252, 252)
#define QCOLOR_SYS_WHITE					RGB(252, 252, 252)
#define QCOLOR_SYS_BLACK					RGB(0, 0, 0)
#define QCOLOR_SYS_PURPLE					RGB(252, 84, 252)
#define QCOLOR_SYS_GRAY						RGB(168, 168, 168)
#define QCOLOR_SYS_GREEN					RGB(84, 252, 84)
#define QCOLOR_SYS_BLUE						RGB(84, 84, 252)
#define QCOLOR_SYS_DARK_RED					RGB(168, 0, 0)
#define QCOLOR_SYS_DARK_GRAY				RGB(84, 84, 84)
#define QCOLOR_SYS_DARK_BLUE				RGB(0, 0, 168)
#define QCOLOR_SYS_DARK_GREEN				RGB(0, 168, 0)
#define QCOLOR_SYS_DARK_CYAN				RGB(0, 168, 168)
#define QCOLOR_SYS_DARK_PURPLE				RGB(140, 30, 200)
#define QCOLOR_SYS_DARK_YELLOW				RGB(168, 84, 0)
#define QCOLOR_SYS_DARK_WHITE				RGB(225, 225, 225)
#define QCOLOR_SYS_LIGHT_PURPLE				RGB(200, 192, 255)
#define QCOLOR_SYS_RAISING_RED				RGB(255, 80, 80)
#define QCOLOR_SYS_FALLING_GREEN			RGB(84, 252, 84)
#define QCOLOR_SYS_CAMBRIDGE_BLUE			RGB(80, 248, 255)
#define QCOLOR_SYS_PLAIN_WHITE				RGB(255, 255, 255)
#define QCOLOR_SYS_HIGHTLIGHT_BG			RGB(0,0,128)//RGB(84,84,252)
#define QCOLOR_SYS_LIGHT_GRAY				RGB(192,192,192)

//符号类型
#define  QLSIGN_UPTRI		1	//上三角
#define  QLSIGN_DOWNTRI		2	//下三角
#define  QLSIGN_UPARROW		3	//上箭头
#define  QLSIGN_DOWNARROW	4	//下箭头
#define  QLSIGN_DIAMOND		5	//菱形
#define	 QLSIGN_STICK1		6   // -
#define  QLSIGN_STICK2		7   /* \*/
#define  QLSIGN_STICK3		8	/*| */
#define  QLSIGN_STICK4		9	// /
#define  QLSIGN_UPARROW2	10	// 红绿军的上箭头
#define  QLSIGN_DOWNARROW2	11	// 红绿军的下箭头
#define  QLSIGN_EQUAL		12	// 红绿军的= 
#define  QLSIGN_INVALIDE_DATA	13 //无意义数字的－－
#define  QLSIGN_DUPTRI      14   //两个上三角  drawQlSign2支持
#define  QLSIGN_DDOWNTRI    15	// 两个下三角	drawQlSign2支持
#define	 QLSIGN_RPTRAD		16  //报表雷达

//以下是一些默认颜色,这些颜色只能作为缺省的情况下的使用
#define QCOLOR_DEF_XAXIS_VALUE				QCOLOR_SYS_GRAY //默认的走势或技术画面的x轴值颜色
#define QCOLOR_DEF_YAXIS_VALUE				QCOLOR_SYS_WHITE//默认的走势或技术画面的Y轴值颜色
#define QCOLOR_DEF_TABSELECTEDBG			RGB(64,0,0)
#define QCOLOR_DEF_TABTEXT					RGB(192, 192, 192)
#define QCOLOR_DEF_LINE_INDEX1				QCOLOR_SYS_WHITE	
#define	QCOLOR_DEF_LINE_INDEX2				QCOLOR_SYS_YELLOW	
#define	QCOLOR_DEF_LINE_INDEX3				QCOLOR_SYS_PURPLE
#define	QCOLOR_DEF_LINE_INDEX4				RGB(84,232,61)
#define	QCOLOR_DEF_LINE_INDEX5				RGB(255,109,0)
#define	QCOLOR_DEF_LINE_INDEX6				RGB(185,120,234)
#define	QCOLOR_DEF_LINE_INDEX7				RGB(107,142,212)
#define	QCOLOR_DEF_LINE_INDEX8				RGB(164,164,137)

#define QCOLOR_DEF_INFO_TEXT				RGB(168,168,168)
#define QCOLOR_DEF_RPT_TITLEBG				RGB(27,27,27)
#define QCOLOR_DEF_RPT_TITLESPLITLINE		RGB(81,81,81)
#define QCOLOR_DEF_RPT_RAD					RGB(255,0,255)
#define QCOLOR_DEF_RPT_POSITION_TAG			RGB(255,0,255)
#define QCOLOR_DEF_RPT_PREOPENING			RGB(68,68,68)


#define QCOLOR_DEF_ROLLINFO_TEXT			RGB(252, 252, 84)

//以下是支持的颜色。
enum _ID_COLOR
{
	
//	IDcr_DELTA										=	1,//涨跌色

 	IDcr_VIEWBG = 1,//所有视图背景颜色
	IDcr_HIGHLIGNT_BG=2,//高亮的背景颜色。
	IDcr_WORKTABLE_NORMAL = 3,//工作台普通颜色
	IDcr_WORKTABLE_SELECT = 4, //工作台选中颜色
	IDcr_WORKTABLE_HOVER = 5,//工作台选题颜色
	
	IDcr_PRICE_RISING = 20,//上涨颜色
	IDcr_PRICE_PLAIN=21,//平盘颜色
	IDcr_PRICE_FALLING=22,//下跌颜色

	IDcr_COMMODITY_CODE = 30,//代码的颜色
	IDcr_COMMODITY_NAME = 31,//商品名称颜色
	IDcr_COMMODITY_CLOSE = 32,//商品昨收颜色


	IDcr_PIC_TITLE = 40,//画面标题颜色、个股画面中指标图形窗口标题文本[非输出数据]的颜色
	IDcr_GRID_LINE = 41,//表格线、以及分割线的颜色。
	IDcr_YAXIS_VALUE = 42,//走势或技术y轴值的颜色。
	IDcr_XAXIS_VALUE = 43,//走势或技术x轴值的颜色。
	IDcr_DATETIME_COORD = 44,//走势或技术画面时间游标的颜色
	IDcr_FRAME_XYLINE = 45, //坐标轴框颜色
	IDcr_INFOCOL_TEXT = 46,//信息栏文字
	IDcr_LINE_CURSOR = 47,//指十字游标线的颜色。
	IDcr_LINE_RISING = 48,//阳线
	IDcr_LINE_FALLING = 49,//阴线
	IDcr_LINE_SELFDRAWING = 50,//自画线

	IDcr_PAGETAG_TEXT = 60,//标签文字
	IDcr_PAGETAG_SELBK = 61, //标签选中背景
	IDcr_PAGETAG_SELTEXT = 62, //标签选中文字
	IDcr_PAGETAG_HOVERBK = 63, //标签悬停背景
	IDcr_PAGETAG_HOVERTEXT = 64,//标签悬停文字

	IDcr_RPT_TITLE = 80,//报表标题颜色
	IDcr_RPT_TITLEBG = 81,//报表标题背景色
	IDcr_RPT_SELROWBG = 82,//报表选中行颜色
	IDcr_RPT_TITLESPLITLINE = 83,//报表标题中分割线的颜色
	IDcr_RPT_RAD = 84,//报表画面的雷达颜色。
	IDcr_RPT_POSITION_TAG = 85,//报表画面的持仓标记颜色
	IDcr_RPTTAG_TEXT = IDcr_PAGETAG_TEXT,//报表标签文字
	IDcr_RPTTAG_SELBK = IDcr_PAGETAG_SELBK, //报表标签选中背景
	IDcr_RPTTAG_SELTEXT = IDcr_PAGETAG_SELTEXT, //报表标签选中文字
	IDcr_RPTTAG_HOVERBK = IDcr_PAGETAG_HOVERBK, //报表标签悬停背景
	IDcr_RPTTAG_HOVERTEXT = IDcr_PAGETAG_HOVERTEXT,//报表标签悬停文字
	

	IDcr_LINE_INDEX_BEGIN = 100,
	IDcr_LINE_INDEX1 = IDcr_LINE_INDEX_BEGIN,	//指标线
	IDcr_LINE_INDEX2 = 101,
	IDcr_LINE_INDEX3 = 102,
	IDcr_LINE_INDEX4 = 103,
	IDcr_LINE_INDEX5 = 104,
	IDcr_LINE_INDEX6 = 105,
	IDcr_LINE_INDEX7 = 106,
	IDcr_LINE_INDEX8 = 107,
	IDcr_LINE_INDEX_END = IDcr_LINE_INDEX8,
	IDcr_LINE_INDEX_RESERVE = IDcr_LINE_INDEX_END+64,//给指标线保留64个席位


	IDcr_ROLLINFO_BEGIN = 150,
	IDcr_ROLLINFO_TEXT = 150,//滚动资讯文字的颜色
	IDcr_ROLLINFO_END = 160,
	



	IDcr_COMM_VOLUME = IDcr_COMMODITY_NAME,//一般是量的颜色。
	IDcr_COMM_AMOUNT = IDcr_COMMODITY_NAME,//一般是额的颜色。
	IDcr_COMM_SUBVALUE = IDcr_COMMODITY_NAME,//一般是分量的颜色

	//行情颜色值
	IDcr_COMMODITY_SERIAL = 500,//商品次序
	IDcr_VOLUME,//总量
	IDcr_AMOUNT,//成交金额
	IDcr_VOLUME_RATION,//量比
	IDcr_CHANGE_HANDS_PERCENT,//换手率
	IDcr_PER,//市盈率
	IDcr_LAST_VOLUME,//现量
	IDcr_CURRENT_VALUE,//流通市值
	IDcr_TOTAL_VALUE,//总市值
	IDcr_PBR,//市净率
	IDcr_BID_ASK_VOLUME_DIFF,//委量差
	IDcr_BID_AMOUNT, //委买额
	IDcr_BID_VOLUME,//委买量
	IDcr_ASK_AMOUNT,//委卖额
	IDcr_ASK_VOLUME, //委卖量
	IDcr_PREV_NET_VALUE, //净值
	IDcr_YIELD_PERCENT,//收益率%
	IDcr_FULL_PRICE,//全价
	IDcr_INTEREST,//利息
	IDcr_NAME_PREFIX,//前缀

	//期货颜色值
	IDcr_POSITION,//持仓
	IDcr_OPEN_POSITION,//开仓
	IDcr_CLOSE_POSITION,//平仓
	IDcr_LAST_OPEN_POSITION,//现开
	IDcr_LAST_CLOSE_POSITION,//现平
	IDcr_OPEN_CLOSE_POSITION,//开平
	IDcr_LAST_OPEN_CLOSE_POSITION,//现开平
	IDcr_SETTLEMENT,//结算
	IDcr_PREV_POSITION,//昨持
	IDcr_PREV_SETTLEMENT,//昨结


	//财务数据颜色值
	IDcr_LISTING_DATE,//上市日期
	IDcr_VOCATION,//行业
	IDcr_TOTAL_SHARES,//总股本
	IDcr_CURRENT_A_SHARES,//流通A股
	IDcr_CURRENT_B_SHARES,//流通B股
	IDcr_TOTAL_ASSETS,//总资产
	IDcr_ACCUMULATION_FUND,//资本公积
	IDcr_MAIN_EARNINGS	,//主营收入
	IDcr_EQUITY_DEBT_RATIO	,//资产负债%
	IDcr_CURRENT_SHARES	,//流通盘
	IDcr_FIXED_ASSETS,//固定资产
	IDcr_END_DATE,//国债到期日期
	IDcr_DIVIDENDYIELD,//周息率


	//权证字段的颜色值
	IDcr_IMPLEMENTING_PRICE,//行权价
	IDcr_IMPLEMENTING_COST,//行权成本
	IDcr_IMPLEMENTING_RATE,//行权比例
	IDcr_ISSUED_VOLUME,//权证总量
	IDcr_CURRENT_VOLUME,//权证余额
	IDcr_COMMODITY_KIND_, //类型
	IDcr_LISTING_DATE_,//上市日期"
	IDcr_EXPIRATION_DATE,//到期日期
	IDcr_REMAINING_DAYS,//尚余天数
	IDcr_IMPLEMENTING_MODE,//行权方式
	IDcr_LEVERAGE_RATE,//杠杆比例
	IDcr_POTENTIAL_PRICE,//内在价值
	IDcr_OBJECT_COMMODITY_NAME,//标的证券
	IDcr_BEGIN_DATE_,//行权起始
	IDcr_END_DATE_, //行权截止
	IDcr_LAST_IMPLEMENTING_DATE,//最后交易日
	IDcr_TOEND_DAYS,//距到期日

	//静态统计
	IDcr_STAT_VALUME,//统计字段用到的量的颜色
	IDcr_STAT_CONTINUE_DELTA,//连续上涨或下跌的颜色
	
	//指数栏
	IDcr_INDEXBAR_DARKRED,
	IDcr_INDEXBAR_DARKGREEN,
	IDcr_INDEXBAR_REDGREEN_BORDER,
	IDcr_INDEXBAR_RED = IDcr_PRICE_RISING,
	IDcr_INDEXBAR_GREEN = IDcr_PRICE_FALLING,

};


//以下是支持的字体，注意一旦确定，其值不可改变，现在用enum类型，是程序在开发阶段可以变化。
enum
{
	QFONT_TABPAGE							= 1,						//各种标签字体。
	QFONT_TABPAGE_CH						= QFONT_TABPAGE,			//各种标签中文字体。
	QFONT_TABPAGE_EN						= 2,						//各种标签西文字体。
	QFONT_PIC_COMM							= 3,						//画面普通字体
	QFONT_PIC_COMM_CH						= QFONT_PIC_COMM,			//画面普通中文字体
	QFONT_PIC_COMM_EN						= 4,
	QFONT_PIC_TITLE							= 5,						//画面标题
	QFONT_PIC_TITLE_CH						= QFONT_PIC_TITLE,			//画面标题中文字体
	QFONT_PIC_TITLE_EN						= 6,
	QFONT_DIALOG_TITLE_CH					= 7,

	//报表画面字体
	QFONT_RPT_TITLE							= 20,						//报表标题字体
	QFONT_RPT_TITLE_CH						= QFONT_RPT_TITLE,			//报表标题中文字体
	QFONT_RPT_TITLE_EN						= 21,						//报表标题西文字体
	QFONT_RPT_CONTENT						= 22,						//报表内容字体
	QFONT_RPT_CONTENT_CH					= 22,						//报表内容中文字体。
	QFONT_RPT_CONTENT_EN					= 23,						//报表画面的西文字体。
	QFONT_RPT_STAT_CH						= QFONT_RPT_CONTENT_CH,		//报表统计栏中文字体。
	QFONT_RPT_STAT_EN						= QFONT_RPT_CONTENT_EN,		//报表统计栏的西文字体。
	QFONT_MSORTRPT_CONTENT_CH				= QFONT_RPT_CONTENT_CH,		//综合排名报表内容中文字体。
	QFONT_MSORTRPT_CONTENT_EN				= QFONT_RPT_CONTENT_EN,		//综合排名报表内容西文字体。
	QFONT_RPT_SHORTFAIRY					= 24,						//报表中短线精灵字体

	//信息栏小画面字体[40-80)
	QFONT_INFOCOL							= QFONT_PIC_COMM,			//信息栏字体。
	QFONT_INFOCOL_CH						= QFONT_PIC_COMM_CH,		//信息栏汉字字体。
	QFONT_INFOCOL_EN						= QFONT_PIC_COMM_EN,		//信息栏数字或西文字体
	QFONT_INFOCOL_MMP_CH					= QFONT_INFOCOL_CH,			//信息栏买卖盘中文字体
	QFONT_INFOCOL_MMP_EN					= QFONT_INFOCOL_EN,			//信息栏买卖盘西文文字体
	QFONT_INFOCOL_CANCEL_CH					= QFONT_INFOCOL_CH,			//信息栏撤单中文字体
	QFONT_INFOCOL_CANCEL_EN					= QFONT_INFOCOL_EN,			//信息栏买撤单西文文字体
	QFONT_INFOCOL_CANCEL_TIME_CH			= QFONT_INFOCOL_CH,			//信息栏撤单时间中文字体
	QFONT_INFOCOL_CANCEL_TIME_EN			= QFONT_INFOCOL_EN,			//信息栏撤单时间西文字体
	QFONT_INFOCOL_CONTRACT_CH				= QFONT_INFOCOL_CH,			//信息栏逐笔中文字体
	QFONT_INFOCOL_CONTRACT_EN				= QFONT_INFOCOL_EN,			//信息栏逐笔西文字体
	QFONT_INFOCOL_TICK_CH					= QFONT_INFOCOL_CH,			//信息栏快照中文字体
	QFONT_INFOCOL_TICK_EN					= QFONT_INFOCOL_EN,			//信息栏快照西文字体
	QFONT_INFOCOL_FINA_CH					= QFONT_INFOCOL_CH,			//信息栏财中文字体
	QFONT_INFOCOL_FINA_EN					= QFONT_INFOCOL_EN,			//信息栏财西文字体
	QFONT_INFOCOL_WJL_CH					= QFONT_INFOCOL_CH,			//信息栏委、即、累中文字体
	QFONT_INFOCOL_WJL_EN					= QFONT_INFOCOL_EN,			//信息栏委、即、累西文字体
	QFONT_INFOCOL_CONTRIBUTE_CH				= QFONT_INFOCOL_CH,			//信息栏贡献度中文字体
	QFONT_INFOCOL_CONTRIBUTE_EN				= QFONT_INFOCOL_EN,			//信息栏贡献度西文字体
	QFONT_INFOCOL_TOP_CH					= QFONT_INFOCOL_CH,			//信息栏领中文字体
	QFONT_INFOCOL_TOP_EN					= QFONT_INFOCOL_EN,			//信息栏领西文字体
	QFONT_INFOCOL_IDX_CH					= QFONT_INFOCOL_CH,			//信息栏指中文字体
	QFONT_INFOCOL_IDX_EN					= QFONT_INFOCOL_EN,			//信息栏指西文字体
	QFONT_INFOCOL_PRICE_CH					= QFONT_INFOCOL_CH,			//信息栏价中文字体
	QFONT_INFOCOL_PRICE_EN					= QFONT_INFOCOL_EN,			//信息栏价西文字体

	QFONT_INFOCOL_SMALL						= 40,						//信息栏中小的中文字体。
	QFONT_INFOCOL_SMALL_CH					= QFONT_INFOCOL_SMALL,		//信息栏中小的中文字体
	QFONT_INFOCOL_SMALL_EN					= 41,						//信息栏中小的西文字体
	QFONT_INFOCOL_WJL_TIME_CH				= 42,						//信息栏委、即、累时间中文字体
	QFONT_INFOCOL_WJL_TIME_EN				= 43,						//信息栏委、即、累时间西文字体
	

	//个股走势和技术分析画面字体[80,100)
	QFONT_IDX_AXIS							= QFONT_PIC_TITLE,			//走势和技术画面的坐标等字体。	
	QFONT_IDX_RLT							= QFONT_PIC_TITLE,			//指标画面的结果域字体。
	QFONT_IDX_RLT_CH						= QFONT_PIC_TITLE_CH,		//指标画面的结果域中文字体。
	QFONT_IDX_RLT_EN						= QFONT_PIC_TITLE_EN,		//指标画面的结果域西文字体。

	QFONT_IDX_CURSOR_CH						= QFONT_PIC_TITLE_CH,		//指标画面游标中文字体
	QFONT_IDX_CURSOR_EN						= QFONT_PIC_TITLE_EN,		//指标画面游标西文字体
	QFONT_IDX_AXIS_CH						= 80,						//走势和技术画面的坐标等汉字字体。
	QFONT_IDX_AXIS_EN						= 81,						//走势和技术画面的坐标等数字字体。
	QFONT_IDX_DATETIME_CH					= QFONT_IDX_AXIS_CH,		//指标时间中文字体
	QFONT_IDX_DATETIME_EN					= QFONT_IDX_AXIS_EN,		//指标时间西文字体
	//其他个股画面字体[100,120)
	QFONT_SC_WEIGHT_CH						= QFONT_INFOCOL_CH,			//个股权息资料中文字体
	QFONT_SC_WEIGHT_EN						= QFONT_INFOCOL_EN,			//个股全系资料西文字体
	QFONT_SC_WEIGHT_TITLE_CH				= QFONT_INFOCOL_CH,			//个股权息资料标题中文字体
	QFONT_SC_WEITHT_TITLE_EN				= QFONT_INFOCOL_EN,			//个股全系资料标题西文字体
	QFONT_SC_SMALL_HISTREND_INFO_CH			= QFONT_INFOCOL_CH,			//个股历史走势信息中文字体
	QFONT_SC_SMALL_HISTREND_INFO_EN			= QFONT_INFOCOL_EN,			//个股历史走势信息西文字体
	QFONT_SC_GAIN_INFO_CH					= QFONT_INFOCOL_CH,			//个股大利市信息中文字体
	QFONT_SC_GAIN_INFO_EN					= QFONT_INFOCOL_EN,			//个股大利市信息西文字体
	QFONT_SC_PRICE_CH						= QFONT_INFOCOL_CH,			//个股量价分析中文字体
	QFONT_SC_PRICE_EN						= QFONT_INFOCOL_EN,			//个股量价分析西文字体
	QFONT_SC_SEATSERIAL_CH					= QFONT_INFOCOL_CH,			//个股经济排位中文字体
	QFONT_SC_SEATSERIAL_EN					= QFONT_INFOCOL_EN,			//个股经济排位西文字体
	QFONT_SC_GAIN_MMP_CH					= QFONT_INFOCOL_CH,			//个股大利市买卖盘中文字体
	QFONT_SC_GAIN_MMP_EN					= QFONT_INFOCOL_EN,			//个股大利市买卖盘西文字体
	QFONT_SC_ORDERLIST_CH					= QFONT_INFOCOL_CH,			//个股买卖队列中文字体
	QFONT_SC_ORDERLIST_EN					= QFONT_INFOCOL_EN,			//个股买卖队列西文字体
	QFONT_SC_ORDERLIST_HINT_CH				= 100,						//个股买卖队列Hint中文字体
	QFONT_SC_ORDERLIST_HINT_EN				= 101,						//个股买卖队列Hint西文字体
	QFONT_SC_PRICELIST_CH					= 102,						//个股量价分析列表中文字体
	QFONT_SC_PRICELIST_EN					= 103,						//个股量价分析列表西文字体
	QFONT_SC_SEATSERIAL_SMALLBTN_CH			= 104,						//个股经济排位小按钮中文字体
	QFONT_SC_SEATSERIAL_SMALLBTN_EN			= 105,						//个股经济排位小按钮西文字体


	//各类tab字体[120-140)
	QFONT_RPT_TAB							= QFONT_TABPAGE,			//报表上tab字体
	QFONT_RPT_TAB_LEFT_CH					= QFONT_TABPAGE_CH,			//报表上tab左标签中文字体
	QFONT_RPT_TAB_LEFT_EN					= QFONT_TABPAGE_EN,			//报表上tab左标签西文字体
	QFONT_RPT_TAB_BOT_CH					= QFONT_TABPAGE_CH,			//报表上tab下标签中文字体
	QFONT_RPT_TAB_BOT_EN					= QFONT_TABPAGE_EN,			//报表上tab小标签西文字体
	QFONT_SC_TAB_LEFT_CH					= QFONT_TABPAGE_CH,			//个股上tab左标签中文字体
	QFONT_SC_TAB_LEFT_EN					= QFONT_TABPAGE_EN,			//个股上tab左标签西文字体
	QFONT_SC_TAB_BOT_CH						= QFONT_TABPAGE_CH,			//个股上tab下标签中文字体
	QFONT_SC_TAB_BOT_EN						= QFONT_TABPAGE_EN,			//个股上tab下标签西文字体
	QFONT_MC_TAB_LEFT_CH					= QFONT_TABPAGE_CH,			//多股上tab左标签中文字体
	QFONT_MC_TAB_LEFT_EN					= QFONT_TABPAGE_EN,			//多股上tab左标签西文字体
	QFONT_MC_TAB_BOT_CH						= QFONT_TABPAGE_CH,			//多股上tab下标签中文字体
	QFONT_MC_TAB_BOT_EN						= QFONT_TABPAGE_EN,			//多股上tab下标签西文字体
	QFONT_SC_MIX_TAB_LEFT_CH				= QFONT_TABPAGE_CH,			//个股上关联和买卖队列混合标签中文字体
	QFONT_SC_MIX_TAB_LEFT_EN				= QFONT_TABPAGE_EN,			//个股上关联和买卖队列混合标签西文字体
	

	//其他杂类字体[200,240)
	QFONT_RIGHT_TITLE_CH					= 200,						//右侧栏股票名称字体
	QFONT_RIGHT_TITLE_NUM					= 201,						//右侧栏股票代码字体
	QFONT_RIGHT_TITLE_EN					= QFONT_RIGHT_TITLE_NUM,
	QFONT_HINT_TITLE						= 202,						//hint标题的字体。
	QFONT_HINT_CONTENT						= 203,						//hint内容字体。
	QFONT_IDXBAR_NAME						= 204,						//指数栏商品名称和量的字体
	QFONT_IDXBAR_NAME_CH					= QFONT_IDXBAR_NAME,		//指数栏商品名称和量的中文字体
	QFONT_IDXBAR_NAME_EN					= 205,						//指数栏商品名称和量的西文和数字字体
	QFONT_SMARTKB_CH						= 206,						//智能键盘中文字体
	QFONT_SMARTKB_EN						= 207,						//智能键盘西文字体
	QFONT_WORKTABLE_CH						= 210,						//工作台中文字体
	QFONT_WORKTABLE_EN						= 211,						//工作台西文字体
	QFONT_PMD_SHORTFAIRY_CH					= 212,						//短线精灵跑马灯中文字体
	QFONT_PMD_SHORTFAIRY_EN					= 213,						//短线精灵跑马灯西文字体。

	QFONT_CONNECT_STAT_DLG_CH				= 214,						//连接状态对话框中文
	QFONT_CONNECT_STAT_DLG_EN				= 215,						//连接状态对话框英文
	QFONT_CONNECT_STAT_DLG_BOLD_CH			= 216,						//连接状态对话框中文粗体
	QFONT_CONNECT_STAT_DLG_BOLD_EN			= 217,						//连接状态对话框英文粗体

	QFONT_LOGIN_STAT_DLG_CH					= 218,						//登录状态对话框中文
	QFONT_LOGIN_STAT_DLG_EN					= 219,						//登录状态对话框英文
	QFONT_LOGIN_STAT_DLG_BOLD_CH			= 220,						//登录状态对话框中文粗体
	QFONT_LOGIN_STAT_DLG_BOLD_EN			= 221,						//登录状态对话框英文粗体

	//目前系统内置的一些字体
	QFONT_SYS_COMM							= 2000,						//普通字体	system
	QFONT_SYS_SMALL							= 2001,						//小字体
	QFONT_SYS_SYSTEM						= QFONT_SYS_COMM,			//SYSTEM
	QFONT_SYS_SIMSUN_12						= 2020,						//宋体12
	QFONT_SYS_SIMSUN_10_5					= 2021,						//宋体10.5
	QFONT_SYS_SIMSUN_9						= 2022,						//宋体9
	QFONT_SYS_SIMSUN_9B						= 2023,						//宋体9粗体
	QFONT_SYS_KAITI_14						= 2040,						//楷体14
	QFONT_SYS_KAITI_15						= 2041,
	QFONT_MS_SANS_SERIF_8					= 2060,
	QFONT_SYS_MSSANSSERIF_8					= QFONT_MS_SANS_SERIF_8,
	QFONT_TAHOMA_8							= 2080,
	QFONT_SYS_TAHMOA_8						= QFONT_TAHOMA_8,
	QFONT_SYS_TAHMOA_8B						= 2081,
	QFONT_SYS_ARIAL_14						= 2100,
	QFONT_SYS_ARIAL_14B						= 2101,
	QFONT_SYS_ARIAL_12B						= 2102,
	QFONT_SYS_NEWROMAN_16					= 2120,
	QFONT_SYS_SYLFAEN_14					= 2140,
	QFONT_SYS_SYLFAEN_12					= 2141,
	
	QFONT_SYS_DEFCOUNT						= 11,






	//以下是对应的默认字体。

	//报表默认字体。
	QFONT_DEF_RPT_CONTENT_CH				= QFONT_SYS_KAITI_15,			//报表内容中文默认字体
	QFONT_DEF_RPT_CONTENT_EN				= QFONT_SYS_ARIAL_12B,			//报表内容西文默认字体
	QFONT_DEF_RPT_TITLE_CH					= QFONT_DEF_RPT_CONTENT_CH,		//报表默认标题中文默认字体
	QFONT_DEF_RPT_TITLE_EN					= QFONT_DEF_RPT_CONTENT_EN,		//报表默认标题西文默认字体	
	QFONT_DEF_RPT_STAT_CH					= QFONT_DEF_RPT_CONTENT_CH,		//报表默认统计中文默认字体
	QFONT_DEF_RPT_STAT_EN					= QFONT_DEF_RPT_CONTENT_EN,		//报表默认统计西文默认字体
	QFONT_DEF_MSORTRPT_CONTENT_CH			= QFONT_RPT_CONTENT_CH,			//综合排名报表内容中文默认字体。
	QFONT_DEF_MSORTRPT_CONTENT_EN			= QFONT_RPT_CONTENT_EN,			//综合排名报表内容西文默认字体。
	QFONT_DEF_RPT_RPT_SHORTFAIRY			= QFONT_SYS_SIMSUN_9,			//报表中短线精灵默认字体。

	//信息栏默认字体。
	QFONT_DEF_INFO_COMMNAME					= QFONT_SYS_SIMSUN_12,			//信息栏商品名称默认字体。
	QFONT_DEF_INFO_COMMCODE					= QFONT_SYS_NEWROMAN_16,		//信息栏商品代码默认字体。
	QFONT_DEF_INFOCOL_CH					= QFONT_DEF_RPT_CONTENT_CH,		//信息栏中文默认字体
	QFONT_DEF_INFOCOL_EN					= QFONT_DEF_RPT_CONTENT_EN,		//信息栏西文默认字体
	QFONT_DEF_INFOCOL_MMP_CH				= QFONT_DEF_INFOCOL_CH,			//信息栏买卖盘中文默认
	QFONT_DEF_INFOCOL_MMP_EN				= QFONT_DEF_INFOCOL_EN,			//信息栏买卖盘西文文默认
	QFONT_DEF_INFOCOL_CANCEL_CH				= QFONT_DEF_INFOCOL_CH,			//信息栏撤单中文默认字体
	QFONT_DEF_INFOCOL_CANCEL_EN				= QFONT_DEF_INFOCOL_EN,			//信息栏撤单西文默认字体
	QFONT_DEF_INFOCOL_CANCEL_TIME_CH		= QFONT_DEF_INFOCOL_CH,			//信息栏撤单时间中文默认字体		
	QFONT_DEF_INFOCOL_CANCEL_TIME_EN		= QFONT_DEF_INFOCOL_EN,			//信息栏撤单时间西文默认字体
	QFONT_DEF_INFOCOL_CONTRACT_CH			= QFONT_DEF_INFOCOL_CH,			//信息栏逐笔中文默认字体
	QFONT_DEF_INFOCOL_CONTRACT_EN			= QFONT_DEF_INFOCOL_EN,			//信息栏逐笔西文默认字体
	QFONT_DEF_INFOCOL_TICK_CH				= QFONT_DEF_INFOCOL_CH,			//信息栏快照中文默认字体
	QFONT_DEF_INFOCOL_TICK_EN				= QFONT_DEF_INFOCOL_EN,			//信息栏快照西文默认字体
	QFONT_DEF_INFOCOL_FINA_CH				= QFONT_DEF_INFOCOL_CH,			//信息栏财中文默认字体
	QFONT_DEF_INFOCOL_FINA_EN				= QFONT_DEF_INFOCOL_EN,			//信息栏财西文默认字体
	QFONT_DEF_INFOCOL_WJL_CH				= QFONT_DEF_INFOCOL_CH,			//信息栏委、即、累中文默认字体
	QFONT_DEF_INFOCOL_WJL_EN				= QFONT_DEF_INFOCOL_EN,			//信息栏委、即、累西文默认字体
	QFONT_DEF_INFOCOL_CONTRIBUTE_CH			= QFONT_DEF_INFOCOL_CH,			//信息栏贡献度中文默认字体
	QFONT_DEF_INFOCOL_CONTRIBUTE_EN			= QFONT_DEF_INFOCOL_EN,			//信息栏贡献度西文默认字体
	QFONT_DEF_INFOCOL_TOP_CH				= QFONT_DEF_INFOCOL_CH,			//信息栏领中文默认字体
	QFONT_DEF_INFOCOL_TOP_EN				= QFONT_DEF_INFOCOL_EN,			//信息栏领西文默认字体
	QFONT_DEF_INFOCOL_IDX_CH				= QFONT_DEF_INFOCOL_CH,			//信息栏指中文默认字体
	QFONT_DEF_INFOCOL_IDX_EN				= QFONT_DEF_INFOCOL_EN,			//信息栏指西文默认字体
	QFONT_DEF_INFOCOL_WJL_TIME_CH			= QFONT_SYS_MSSANSSERIF_8,		//信息栏委、即、累时间中文字体
	QFONT_DEF_INFOCOL_WJL_TIME_EN			= QFONT_SYS_MSSANSSERIF_8,		//信息栏委、即、累时间西文字体
	QFONT_DEF_INFOCOL_PRICE_CH				= QFONT_DEF_INFOCOL_CH,			//信息栏价中文默认字体
	QFONT_DEF_INFOCOL_PRICE_EN				= QFONT_DEF_INFOCOL_EN,			//信息栏价西文默认字体

	//走势和技术画面默认字体。
	QFONT_DEF_AXIS							= QFONT_SYS_MSSANSSERIF_8,		//走势或技术画面坐标默认字体。
	QFONT_DEF_AXIS_CH						= QFONT_SYS_MSSANSSERIF_8,		//走势或技术画面坐标中文默认字体。
	QFONT_DEF_AXIS_EN						= QFONT_SYS_MSSANSSERIF_8,		//走势或技术画面坐标西文默认字体。
	QFONT_DEF_RESULT						= QFONT_SYS_MSSANSSERIF_8,		//走势或技术画面的结果域默认字体。
	QFONT_DEF_RESULT_CH						= QFONT_SYS_MSSANSSERIF_8,		//走势或技术画面的结果域中文默认字体。
	QFONT_DEF_RESULT_EN						= QFONT_SYS_MSSANSSERIF_8,		//走势或技术画面的结果域西文默认字体。
	QFONT_DEF_IDX_DATETIME_CH				= QFONT_SYS_MSSANSSERIF_8,		//指标时间中文默认字体
	QFONT_DEF_IDX_DATETIME_EN				= QFONT_SYS_MSSANSSERIF_8,		//指标时间西文默认字体
	QFONT_DEF_IDX_CURSOR_CH					= QFONT_SYS_MSSANSSERIF_8,		//指标画面游标中文默认字体
	QFONT_DEF_IDX_CURSOR_EN					= QFONT_SYS_MSSANSSERIF_8,		//指标画面游标西文默认字体


	//其他个股画面字体
	QFONT_DEF_SC_WEIGHT_CH					= QFONT_DEF_INFOCOL_CH,			//个股权息资料中文默认字体
	QFONT_DEF_SC_WEIGHT_EN					= QFONT_DEF_INFOCOL_EN,			//个股全系资料西文默认字体
	QFONT_DEF_SC_WEIGHT_TITLE_CH			= QFONT_DEF_INFOCOL_CH,			//个股权息资料标题中文默认字体
	QFONT_DEF_SC_WEITHT_TITLE_EN			= QFONT_DEF_INFOCOL_EN,			//个股全系资料标题西文默认字体
	QFONT_DEF_SC_SMALL_HISTREND_INFO_CH		= QFONT_DEF_INFOCOL_CH,			//个股历史走势信息中文默认字体
	QFONT_DEF_SC_SMALL_HISTREND_INFO_EN		= QFONT_DEF_INFOCOL_EN,			//个股历史走势信息西文默认字体
	QFONT_DEF_SC_GAIN_INFO_CH				= QFONT_DEF_INFOCOL_CH,			//个股大利市信息中文默认字体
	QFONT_DEF_SC_GAIN_INFO_EN				= QFONT_DEF_INFOCOL_EN,			//个股大利市信息西文默认字体
	QFONT_DEF_SC_PRICE_CH					= QFONT_DEF_INFOCOL_CH,			//个股量价分析中文默认字体
	QFONT_DEF_SC_PRICE_EN					= QFONT_DEF_INFOCOL_EN,			//个股量价分析西文默认字体
	QFONT_DEF_SC_SEATSERIAL_CH				= QFONT_DEF_INFOCOL_CH,			//个股经济排位中文默认字体
	QFONT_DEF_SC_SEATSERIAL_EN				= QFONT_DEF_INFOCOL_EN,			//个股经济排位西文默认字体
	QFONT_DEF_SC_GAIN_MMP_CH				= QFONT_DEF_INFOCOL_CH,			//个股大利市买卖盘中文默认字体
	QFONT_DEF_SC_GAIN_MMP_EN				= QFONT_DEF_INFOCOL_EN,			//个股大利市买卖盘西文默认字体
	QFONT_DEF_SC_ORDERLIST_CH				= QFONT_DEF_INFOCOL_CH,			//个股买卖队列中文默认字体
	QFONT_DEF_SC_ORDERLIST_EN				= QFONT_DEF_INFOCOL_EN,			//个股买卖队列西文默认字体
	QFONT_DEF_SC_ORDERLIST_HINT_CH			= QFONT_SYS_SMALL,				//个股买卖队列Hint中文默认字体
	QFONT_DEF_SC_ORDERLIST_HINT_EN			= QFONT_SYS_SMALL,				//个股买卖队列Hint西文默认字体
	QFONT_DEF_SC_PRICELIST_CH				= QFONT_SYS_MSSANSSERIF_8,		//个股量价分析列表中文默认字体
	QFONT_DEF_SC_PRICELIST_EN				= QFONT_SYS_MSSANSSERIF_8,		//个股量价分析列表西文默认字体
	QFONT_DEF_SC_SEATSERIAL_SMALLBTN_CH		= QFONT_SYS_SMALL,				//个股经济排位小按钮中文默认字体
	QFONT_DEF_SC_SEATSERIAL_SMALLBTN_EN		= QFONT_SYS_SMALL,				//个股经济排位小按钮西文默认字体


	//各类标签默认字体。
	QFONT_DEF_TABPAGE						= QFONT_SYS_TAHMOA_8,			//标签默认字体。
	QFONT_DEF_TABPAGE_CH					= QFONT_SYS_TAHMOA_8,
	QFONT_DEF_TABPAGE_EN					= QFONT_SYS_TAHMOA_8,
	QFONT_DEF_RPT_TAB_LEFT_CH				= QFONT_DEF_TABPAGE_CH,			//报表上tab左标签默认中文字体
	QFONT_DEF_RPT_TAB_LEFT_EN				= QFONT_DEF_TABPAGE_EN,			//报表上tab左标签默认西文字体
	QFONT_DEF_RPT_TAB_BOT_CH				= QFONT_DEF_TABPAGE_CH,			//报表上tab下标签默认中文字体
	QFONT_DEF_RPT_TAB_BOT_EN				= QFONT_DEF_TABPAGE_EN,			//报表上tab小标签默认西文字体
	QFONT_DEF_SC_TAB_LEFT_CH				= QFONT_DEF_TABPAGE_CH,			//个股上tab左标签默认中文字体
	QFONT_DEF_SC_TAB_LEFT_EN				= QFONT_DEF_TABPAGE_EN,			//个股上tab左标签默认西文字体
	QFONT_DEF_SC_TAB_BOT_CH					= QFONT_DEF_TABPAGE_CH,			//个股上tab下标签默认中文字体
	QFONT_DEF_SC_TAB_BOT_EN					= QFONT_DEF_TABPAGE_EN,			//个股上tab下标签默认西文字体
	QFONT_DEF_MC_TAB_LEFT_CH				= QFONT_DEF_TABPAGE_CH,			//多股上tab左标签默认中文字体
	QFONT_DEF_MC_TAB_LEFT_EN				= QFONT_DEF_TABPAGE_EN,			//多股上tab左标签默认西文字体
	QFONT_DEF_MC_TAB_BOT_CH					= QFONT_DEF_TABPAGE_CH,			//多股上tab下标签默认中文字体
	QFONT_DEF_MC_TAB_BOT_EN					= QFONT_DEF_TABPAGE_EN,			//多股上tab下标签默认西文字体
	QFONT_DEF_SC_MIX_TAB_LEFT_CH			= QFONT_DEF_TABPAGE_CH,			//个股上关联和买卖队列混合标签中文默认字体
	QFONT_DEF_SC_MIX_TAB_LEFT_EN			= QFONT_DEF_TABPAGE_EN,			//个股上关联和买卖队列混合标签西文默认字体

	//其他杂类默认字体
	QFONT_DEF_RIGHT_TITLE_CH				= QFONT_DEF_INFO_COMMNAME,		//右侧栏股票名称字体
	QFONT_DEF_RIGHT_TITLE_NUM				= QFONT_DEF_INFO_COMMCODE,		//右侧栏股票代码字体
	QFONT_DEF_RIGHT_TITLE_EN				= QFONT_RIGHT_TITLE_NUM,
	QFONT_DEF_HINT_TITLE					= QFONT_SYS_TAHMOA_8,		//hint标题的字体。
	QFONT_DEF_HINT_CONTENT					= QFONT_SYS_TAHMOA_8,		//hint内容字体。
	QFONT_DEF_OWNEDBLOCK					= QFONT_SYS_SIMSUN_9,
	QFONT_DEF_IDXBAR_NAME					= QFONT_SYS_SIMSUN_12,			//指数栏商品名称和量的字体
	QFONT_DEF_IDXBAR_NAME_CH				= QFONT_DEF_IDXBAR_NAME,		//指数栏商品名称和量的中文字体
	QFONT_DEF_IDXBAR_NAME_EN				= QFONT_SYS_SYSTEM,				//指数栏商品名称和量的西文和数字字体
	QFONT_DEF_SMARTKB_CH					= QFONT_SYS_TAHMOA_8,			//智能键盘中文默认字体
	QFONT_DEF_SMARTKB_EN					= QFONT_SYS_TAHMOA_8,			//智能键盘西文默认字体
	QFONT_DEF_WORKTABLE_CH					= QFONT_SYS_SIMSUN_10_5,		//工作台中文默认字体，
	QFONT_DEF_WORKTABLE_EN					= QFONT_SYS_SYSTEM,				//工作台西文默认字体，
	QFONT_DEF_PMD_SHORTFAIRY_CH				= QFONT_SYS_SIMSUN_12,			//短线精灵跑马灯中文字体
	QFONT_DEF_PMD_SHORTFAIRY_EN				= QFONT_SYS_SYSTEM,				//短线精灵跑马灯西文字体。

	QFONT_DEF_CONNECT_STAT_DLG_CH			= QFONT_SYS_SIMSUN_9,			//连接状态对话框默认中文
	QFONT_DEF_CONNECT_STAT_DLG_EN			= QFONT_SYS_TAHMOA_8,			//连接状态对话框默认英文
	QFONT_DEF_CONNECT_STAT_DLG_BOLD_CH		= QFONT_SYS_SIMSUN_9B,			//连接状态对话框默认中文粗体
	QFONT_DEF_CONNECT_STAT_DLG_BOLD_EN		= QFONT_SYS_TAHMOA_8B,			//连接状态对话框默认英文粗体

	QFONT_DEF_LOGIN_STAT_DLG_CH				= QFONT_SYS_SIMSUN_9,			//登录状态对话框默认中文
	QFONT_DEF_LOGIN_STAT_DLG_EN				= QFONT_SYS_TAHMOA_8,			//登录状态对话框默认英文
	QFONT_DEF_LOGIN_STAT_DLG_BOLD_CH		= QFONT_SYS_SIMSUN_9B,			//登录状态对话框默认中文粗体
	QFONT_DEF_LOGIN_STAT_DLG_BOLD_EN		= QFONT_SYS_TAHMOA_8B,			//登录状态对话框默认英文粗体
};

#endif
