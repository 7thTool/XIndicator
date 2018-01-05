#ifndef _FIELDDEF_H__
#define _FIELDDEF_H__

enum _USED_BY_
{
	UB_REPORT,			// ��������ۺ��������棬Ĭ��
	UB_FUNDAMENTAL,		// �������ϻ���(11����)���ɸķ���������������ʹ��
	UB_LIST,			// ����ָ��ͳ�Ƶ��б���
	UB_RIGHT_PANEL,		// ������������ƻ�����Ҳ���Ϣ�����ڡ�״̬��
	UB_TREND_TITLE = UB_RIGHT_PANEL,// ���ƻ�����ͼ��������������λ����
	UB_TECHNIC_TITLE = UB_RIGHT_PANEL,// ���ƻ�����ͼ��������������λ����
	//UB_CURSOR_DETAIL,	// ������������ƻ��������α���ϸ����
	UB_END,				// �ڲ�������
};

enum _ID_FIELD_
{
	// ֤ȯ�г���������
	IDF_TIMEZONE,
	IDF_OPENTIME,
	IDF_DELAYTIME,
	IDF_CLOSETIME,
	IDF_TIMEPOINTCOUNT,
	IDF_DATE,
	IDF_TIME,
	IDF_CURTIMEPOINT,
	IDF_INDEX,							// ˳��			��(���)							��
	IDF_COMMODITY_NAME,					// ��Ʒ����		��(���)			��				��
	//IDF_COMMODITY_FULL_NAME	=    IDF_COMMODITY_NAME, // ��Ʒȫ��
	IDF_CLOSE,							// ���ռ�		��(Ԫ)/��
	IDF_OPEN,							// ���̼�		��(Ԫ)/��
	IDF_HIGH,							// ��߼�		��(Ԫ)/��
	IDF_LOW,							// ��ͼ�		��(Ԫ)/��
	IDF_NOW,							// ���¼�		��(Ԫ)/��
	IDF_VOLUME,							// �ܳɽ���		��(�ɡ��š���)
	IDF_AMOUNT,							// �ܳɽ����	��(Ԫ)
	IDF_COMMODITY_CODE,					// ��Ʒ����		��(���)			��				��
	IDF_DELTA,							// �ǵ�ֵ		��(Ԫ)/��
	IDF_DELTA_PERCENT, // �ǵ�����%	��(%)/��
	IDF_RANGE_PERCENT, // ���%		��(%)
	IDF_VOLUME_RATIO, // ����			��
	IDF_STRONG_WEAK, // ǿ����		��(%)/��
	IDF_CURRENCY, // ����			��(QL_CURRENCY)		��				��
	IDF_LOT_SIZE, // ���׵�λ(�ֱ���)	��								��
	IDF_SPREAD_VALUE, // ���(�۽���)	��(Ԫ)								��(�޸۽���)
	IDF_VIRTUAL_PRICE, // ��ǰ����(ƽ��)�ɽ���(�۽���)	��(Ԫ)/��
	IDF_VIRTUAL_VOLUME, // ��ǰ����(ƽ��)�ɽ���(�۽���)	��(��)
	IDF_RECENT_DELTA_PERCENT, // �����ǵ�%	��(%)/��
	IDF_TURNOVER_RATE, // ������%		��(%)
	IDF_CHANGE_HANDS_PERCENT	=   IDF_TURNOVER_RATE, // ������%
	IDF_PRICE_EARNING_RATIO, // ��ӯ��		��(��)
	IDF_PER						=   IDF_PRICE_EARNING_RATIO, // ��ӯ��
	IDF_LAST_VOLUME, // ������ճɽ���(����)	��(�ɡ��š���)
	IDF_BID_PRICE, // �����		��(Ԫ)/��
	IDF_ASK_PRICE, // ������		��(Ԫ)/��
	IDF_CURRENT_VALUE, // ��ͨ��ֵ		��(Ԫ)
	IDF_TOTAL_VALUE, // ����ֵ		��(Ԫ)
	IDF_PRICE_BOOK_VALUE_RATIO, // �о���		��(��)
	IDF_PBR						=   IDF_PRICE_BOOK_VALUE_RATIO,
	IDF_WEIBI, // ί��%		��(%)/��
	IDF_BID_ASK_VOLUME_DIFF, // ί����		��(�ɡ��š���)/��
	IDF_BID_AMOUNT, // ��ί����	��(Ԫ)
	IDF_BID_VOLUME, // ��ί����		��(�ɡ��š���)
	IDF_ASK_AMOUNT, // ��ί�����	��(Ԫ)
	IDF_ASK_VOLUME, // ��ί����		��(�ɡ��š���)
	IDF_AVERAGE_VOLUME, // 5�վ���(������ǰ������)	��(��)
	IDF_AVERAGE_PRICE, // ����			��(Ԫ)/��
	IDF_LAST_AMOUNT, // �ֶ�			��(Ԫ)
	IDF_CEILING_PRICE, // �Ƿ�(��ͣ)��	��(Ԫ)/��
	IDF_FLOOR_PRICE, // ����(��ͣ)��	��(Ԫ)/��
	IDF_PRICE_RATE, // �۸�Ŵ���	��(����)							��
	// ���������ߡ����Ƶ������м۸�Ļ��㣬���oComRef�Ϸ��Ļ�����֤����0������᷵��false(��ʱΪ0)
	// ���ڷ��ص���double�ͣ���˵��ⲿ��Ҫ��������ʹ��ʱ��Ҫͨ��+0.500001��ǿת������������
	IDF_DECIMAL_DIGITS, // �۸��С�����λ��	��(����)					��
	// ���������ߡ����Ƶ������м۸�(��λ��Ԫ)����ʾ����
	// ���ڷ��ص���double�ͣ���˵��ⲿ��Ҫ��������ʹ��ʱ��Ҫͨ��+0.500001��ǿת������������
	IDF_CONTRACT_MULTIPLIER, // ��Լ����(�����ڻ�)	
	IDF_HIGH_TIME, // ��߼۲���ʱ��
	IDF_LOW_TIME, // ��ͼ۲���ʱ��


	IDF_PREMIUM, // ��ۣ�������A-H��ۡ��ڻ��ߵ�ˮ�ȣ�ע����IDF_PREMIUM_PERCENT������	��(Ԫ)/��
	IDF_BOND_VALUATION, // (����)ծȯ��ֵ(��������֤ȯ������)	��(Ԫ)
	IDF_RISE_DROP_DIFF, // �ǵ���(���̾�)֮��	��(%)
	IDF_RISING_PERCENT, // ����������%	��(%)
	IDF_DROPING_PERCENT, // �µ�������%	��(%)
	IDF_CEILING_PERCENT, // ��ͣ������%	��(%)
	IDF_FLOOR_PERCENT, // ��ͣ������%	��(%)
	IDF_RISE_COUNT, // ���Ǽ���		��(��)/��
	IDF_EQUAL_COUNT, // ƽ�̼���		��(��)/��
	IDF_DROP_COUNT, // �µ�����		��(��)/��
	IDF_LAST_RISE_COUNT, // ǰһ�����Ǽ���	��(��)/��
	IDF_LAST_EQUAL_COUNT, // ǰһ��ƽ�̼���	��(��)/��
	IDF_LAST_DROP_COUNT, // ǰһ���µ�����	��(��)/��
	IDF_AVERAGE_ASK_PRICE, // ί������		��(Ԫ)/��
	IDF_AVERAGE_BID_PRICE, // ί�����		��(Ԫ)/��
	IDF_FULL_PRICE, // ծȯȫ��		��(Ԫ)
	IDF_INTEREST, // ծȯ��Ϣ		��(Ԫ)
	IDF_AH, // AH			��(Ԫ)/��
	IDF_NH, // NH			��(Ԫ)/��
	IDF_CDP, // CDP			��(Ԫ)/��
	IDF_NL, // NL			��(Ԫ)/��
	IDF_AL, // AL			��(Ԫ)/��
	IDF_TBP, // ���ƽ��		��(Ԫ)/��
	IDF_DL, // ��ͷ����		��(Ԫ)/��
	IDF_DT, // ��ͷͣ��		��(Ԫ)/��
	IDF_KL, // ��ͷ�ز�		��(Ԫ)/��
	IDF_KT, // ��ͷͣ��		��(Ԫ)/��
	IDF_NET_VALUE, // (����)EFT/LOF(ģ��)��ֵ	��(Ԫ)
	IDF_PREV_NET_VALUE, // (����)LOF/��LOF��ֵ	��(Ԫ)
	IDF_YIELD_PERCENT, // ծȯ������%	��(%)
	IDF_BARGAIN	, // �ܳɽ�����	��(��)
	IDF_AVERAGE_BARGAIN_VOLUME, // ÿ�ʾ���		��(�ɡ��š���)
	IDF_LONG_SHORT_POSITION, // ��ͷ���ͷ	��(0��ͷ,1��ͷ)
	// ���ڷ��ص���double�ͣ���˵��ⲿ��Ҫ��������ʹ��ʱ��Ҫͨ��+0.500001��ǿת������������
	IDF_COMMODITY_ENBRIEF_NAME, // Ӣ�ļ��		��(���)			��				��(�޸۽���)
	IDF_NAME_PREFIX, // ����ǰ׺(���)	��(ǿתDWORD)	��				��(�����)
	IDF_BOUGHT_VOLUME, // ���̣�������	��(�ɡ��š���)/��
	IDF_SOLD_VOLUME, // ���̣�������	��(�ɡ��š���)/��
	IDF_ASK_ORDERS_5, // �������		��(��)
	IDF_ASK_ORDERS_4, // ���ı���		��(��)
	IDF_ASK_ORDERS_3, // ��������		��(��)
	IDF_ASK_ORDERS_2, // ��������		��(��)
	IDF_ASK_ORDERS_1, // ��һ����		��(��)
	IDF_BID_ORDERS_1, // ��һ����		��(��)
	IDF_BID_ORDERS_2, // �������		��(��)
	IDF_BID_ORDERS_3, // ��������		��(��)
	IDF_BID_ORDERS_4, // ���ı���		��(��)
	IDF_BID_ORDERS_5, // �������		��(��)
	IDF_ASK_PRICE_10, // ��ʮ��		��(Ԫ)/��
	IDF_ASK_PRICE_9, // ���ż�		��(Ԫ)/��
	IDF_ASK_PRICE_8, // ���˼�		��(Ԫ)/��
	IDF_ASK_PRICE_7, // ���߼�		��(Ԫ)/��
	IDF_ASK_PRICE_6, // ������		��(Ԫ)/��
	IDF_ASK_PRICE_5, // �����		��(Ԫ)/��
	IDF_ASK_PRICE_4, // ���ļ�		��(Ԫ)/��
	IDF_ASK_PRICE_3, // ������		��(Ԫ)/��
	IDF_ASK_PRICE_2, // ������		��(Ԫ)/��
	IDF_ASK_PRICE_1, // ��һ�ۣ�ͬ������IDF_ASK_PRICE
	IDF_BID_PRICE_1, // ��һ�ۣ�ͬ�����IDF_BID_PRICE
	IDF_BID_PRICE_2, // �����		��(Ԫ)/��
	IDF_BID_PRICE_3, // ������		��(Ԫ)/��
	IDF_BID_PRICE_4, // ���ļ�		��(Ԫ)/��
	IDF_BID_PRICE_5, // �����		��(Ԫ)/��
	IDF_BID_PRICE_6, // ������		��(Ԫ)/��
	IDF_BID_PRICE_7, // ���߼�		��(Ԫ)/��
	IDF_BID_PRICE_8, // ��˼�		��(Ԫ)/��
	IDF_BID_PRICE_9, // ��ż�		��(Ԫ)/��
	IDF_BID_PRICE_10, // ��ʮ��		��(Ԫ)/��
	IDF_ASK_VOLUME_10, // ��ʮ��		��(�ɡ��š���)
	IDF_ASK_VOLUME_9, // ������		��(�ɡ��š���)
	IDF_ASK_VOLUME_8, // ������		��(�ɡ��š���)
	IDF_ASK_VOLUME_7, // ������		��(�ɡ��š���)
	IDF_ASK_VOLUME_6, // ������		��(�ɡ��š���)
	IDF_ASK_VOLUME_5, // ������		��(�ɡ��š���)
	IDF_ASK_VOLUME_4, // ������		��(�ɡ��š���)
	IDF_ASK_VOLUME_3, // ������		��(�ɡ��š���)
	IDF_ASK_VOLUME_2, // ������		��(�ɡ��š���)
	IDF_ASK_VOLUME_1, // ��һ��		��(�ɡ��š���)
	IDF_BID_VOLUME_1, // ��һ��		��(�ɡ��š���)
	IDF_BID_VOLUME_2, // �����		��(�ɡ��š���)
	IDF_BID_VOLUME_3, // ������		��(�ɡ��š���)
	IDF_BID_VOLUME_4, // ������		��(�ɡ��š���)
	IDF_BID_VOLUME_5, // ������		��(�ɡ��š���)
	IDF_BID_VOLUME_6, // ������		��(�ɡ��š���)
	IDF_BID_VOLUME_7, // ������		��(�ɡ��š���)
	IDF_BID_VOLUME_8, // �����		��(�ɡ��š���)
	IDF_BID_VOLUME_9, // �����		��(�ɡ��š���)
	IDF_BID_VOLUME_10, // ��ʮ��		IDF_ASK_VOL_DIFF_

	IDF_AVERAGE_BARGAIN_AMOUNT, // ���ʶ� �� �����ܽ��/�ɽ����� 
	IDF_RD_RATIO, //�ǵ��� �� [���Ǽ���-�µ�����] / [���Ǽ���+�µ�����]
	IDF_STK_COUNT, //�ܼ��� �� ������������
	IDF_DISCOUNT_RATIO, //�����ۼ��� �� �ۼ���=[�м�-��ֵ]/��ֵ*100%
	IDF_OBJECT_COMMODITY_NOW, //��ļ۸� �� ��Ȩ֤��Ӧ�ı�����ɵĵ�ǰ�۸�
	IDF_OBJECT_COMMODITY_DELTA_PERCENT, //����Ƿ� �� ��Ȩ֤��Ӧ�ı�����ɵĵ�ǰ�Ƿ�
	IDF_BS_VOLUME_RATIO, //�̱� �� �̱�={[���̣�����]��[����+����]}*100%
	IDF_PREMIUM_FUND, //�������
	IDF_RISE_AG_COUNT, // ����A�� ���Ǽ���		��(��)/��
	IDF_EQUAL_AG_COUNT, // ����A�� ƽ�̼���		��(��)/��
	IDF_DROP_AG_COUNT, // ����A�� �µ�����		��(��)/��
	IDF_RISE_BG_COUNT, // ����B�� ���Ǽ���		��(��)/��
	IDF_EQUAL_BG_COUNT, // ����B�� ƽ�̼���		��(��)/��
	IDF_DROP_BG_COUNT, // ����B�� �µ�����		��(��)/��
	IDF_RISE_JJ_COUNT, // ������� ���Ǽ���		��(��)/��
	IDF_EQUAL_JJ_COUNT, // ������� ƽ�̼���		��(��)/��
	IDF_DROP_JJ_COUNT, // ������� �µ�����		��(��)/��

	// �̿������ֶ�
	IDF_ASK_VOL_DIFF_10, // ��ʮ����		��(�ɡ��š���)
	IDF_ASK_VOL_DIFF_9, // ��������		��(�ɡ��š���)
	IDF_ASK_VOL_DIFF_8, // ��������		��(�ɡ��š���)
	IDF_ASK_VOL_DIFF_7, // ��������		��(�ɡ��š���)
	IDF_ASK_VOL_DIFF_6, // ��������		��(�ɡ��š���)
	IDF_ASK_VOL_DIFF_5, // ��������		��(�ɡ��š���)
	IDF_ASK_VOL_DIFF_4, // ��������		��(�ɡ��š���)
	IDF_ASK_VOL_DIFF_3, // ��������		��(�ɡ��š���)
	IDF_ASK_VOL_DIFF_2, // ��������		��(�ɡ��š���)
	IDF_ASK_VOL_DIFF_1, // ��һ����		��(�ɡ��š���)
	IDF_BID_VOL_DIFF_1, // ��һ����		��(�ɡ��š���)
	IDF_BID_VOL_DIFF_2, // �������		��(�ɡ��š���)
	IDF_BID_VOL_DIFF_3, // ��������		��(�ɡ��š���)
	IDF_BID_VOL_DIFF_4, // ��������		��(�ɡ��š���)
	IDF_BID_VOL_DIFF_5, // ��������		��(�ɡ��š���)
	IDF_BID_VOL_DIFF_6, // ��������		��(�ɡ��š���)
	IDF_BID_VOL_DIFF_7, // ��������		��(�ɡ��š���)
	IDF_BID_VOL_DIFF_8, // �������		��(�ɡ��š���)
	IDF_BID_VOL_DIFF_9, // �������		��(�ɡ��š���)
	IDF_BID_VOL_DIFF_10, // ��ʮ����		��(�ɡ��š���)

	// ��֤ȯ�г�ר����������
	// �ڻ�ר������
	IDF_PREV_POSITION, // ���ճֲ�		��(��Լ)
	IDF_PREV_SETTLEMENT, // ���ս����	��(Ԫ)/��
	IDF_POSITION, // ���ճֲ�		��(��Լ)
	IDF_SETTLEMENT, // (����)�����	��(Ԫ)/��
	IDF_OPEN_POSITION, // ���տ���		��(��Լ)
	IDF_CLOSE_POSITION, // ����ƽ��		��(��Լ)
	IDF_DELTA_POSITION, // ���ղֲ�		��(��Լ)/��
	IDF_OPEN_CLOSE_POSITION, // ���տ�ƽ��״��	��(ƴ��˳��)/��	��
	IDF_LAST_OPEN_POSITION, // �ֿ���(������տ���)	��(��Լ)
	IDF_LAST_CLOSE_POSITION, // ��ƽ��(�������ƽ��)	��(��Լ)
	IDF_LAST_DELTA_POSITION, // �ֲֲ�(�����ղֲ�)	��(��Լ)/��
	IDF_LAST_OPEN_CLOSE_POSITION, // �ֿ�ƽ��״��(������տ�ƽ��״��)	��(ƴ��˳��)/��	��
	IDF_ARBITRAGE_COST_UPPER_1, // ��ָ�ڻ������ɱ���(1�궨�ڴ����������)����	��(Ԫ)/��
	IDF_ARBITRAGE_COST_UPPER_2, // ��ָ�ڻ������ɱ���(1�궨�ڴ�����������)����	��(Ԫ)/��
	IDF_ARBITRAGE_COST_UPPER_3, // ��ָ�ڻ������ɱ���(1��ͬҵ�����������)����	��(Ԫ)/��
	IDF_ARBITRAGE_COST_UPPER_4, // ��ָ�ڻ������ɱ���(3��ͬҵ�����������)����	��(Ԫ)/��
	IDF_ARBITRAGE_COST_UPPER_5, // ��ָ�ڻ������ɱ���(6��ͬҵ�����������)����	��(Ԫ)/��
	IDF_ARBITRAGE_COST_UPPER_6, // ��ָ�ڻ������ɱ���(9��ͬҵ�����������)����	��(Ԫ)/��
	IDF_WHOLE_HIGH, // ��Լ����߼�(���ڻ�)	��(Ԫ)/��
	IDF_WHOLE_LOW, // ��Լ����ͼ�(���ڻ�)	��(Ԫ)/��
	IDF_MONTH_HIGH, // ������߼�(���ڻ�)	��(Ԫ)/��
	IDF_MONTH_LOW, // ������ͼ�(���ڻ�)	��(Ԫ)/��
	IDF_CALCULATED_OPENING, // �⿪�̼�(����ָ)	��(Ԫ)/��
	IDF_EAS, // (����)���ܽ����	��(Ԫ)/��

	// ����Ϊ�������������ֶ�
	IDF_LISTING_DATE, // ��������		��(YYYYMMDD)
	IDF_VOCATION, // ��ҵ			��(ƴ��˳��)		��
	IDF_TOTAL_SHARES, // �ܹɱ�		��(��)
	IDF_CURRENT_A_SHARES, // ��ͨA��		��(��)
	IDF_CURRENT_B_SHARES, // ��ͨB��		��(��)
	IDF_TOTAL_ASSETS, // ���ʲ�		��(Ԫ)
	IDF_EQUITY, // �ɶ�Ȩ��		��(Ԫ)/��
	IDF_NET_ASSETS				= IDF_EQUITY, // ���ʲ�
	IDF_NA						= IDF_NET_ASSETS,
	IDF_ACCUMULATION_FUND, // �ʱ�����		��(Ԫ)
	IDF_NET_ASSETS_PER_SHARE, // ÿ�ɾ��ʲ�	��(Ԫ/��)/��
	IDF_NAPS					= IDF_NET_ASSETS_PER_SHARE,
	IDF_TOTAL_PROFIT, // �����ܶ�		��(Ԫ)/��
	IDF_NET_PROFIT, // ������		��(Ԫ)/��
	IDF_MAIN_EARNINGS, // ��Ӫҵ������	��(Ԫ)
	IDF_MIDTERM_EPS, // ����ÿ������	��(Ԫ/��)/��
	IDF_YEAR_EPS, // ���ÿ������	��(Ԫ/��)/��
	IDF_NET_ASSETS_YIELD, // ���ʲ�������	��(%)/��
	IDF_EQUITY_DEBT_RATIO, // �ʲ���ծ��%	��(%)
	IDF_EARNINGS_PER_SHARE, // ����ÿ������	��(%)/��
	IDF_EPS						= IDF_EARNINGS_PER_SHARE,
	IDF_CURRENT_SHARES, // ��ͨ��		��(��)
	//IDF_REGION, // ����			��
	//IDF_TRANSFERABLE_BOND, // ��ת��ծȯ	��
	//IDF_CIRCULATING_ASSETS, // �����ʲ�		��
	IDF_FIXED_ASSETS, // �̶��ʲ�		��(Ԫ)
	IDF_FA						= IDF_FIXED_ASSETS,
	//IDF_INTANGIBLE_DEFERRED_ASSETS, // ���μ������ʲ�	��
	//IDF_OTHER_ASSETS, // �����ʲ�		��
	//IDF_TOTAL_LIABILITIES, // �ܸ�ծ		��
	//IDF_LONG_TERM_LIABILITIES, // ���ڸ�ծ		��
	//IDF_CIRCULATING_LIABILITIES, // ������ծ	��
	//IDF_OTHER_LIABILITIES, // ������ծ		��
	IDF_UNDISTRIBUTED_PROFIT, // δ��������	��(Ԫ)
	//IDF_ADJUSTED_NAPS, // ������ÿ�ɾ��ʲ�	��
	IDF_MAIN_PROFIT, // ��Ӫҵ������	��(Ԫ)
	//IDF_CIRCULATING_RATIO, // ��������		��
	//IDF_QUICK_RATIO, // �ٶ�����		��
	//IDF_EQUITY_PERCENT, // �ɶ�Ȩ���	��
	IDF_LAST_DISTRIBUTING_DATE, // �����������	��(YYYYMMDD)
	IDF_PRESENT_NUMBER, // ÿ10���͹���	��(��/10��)
	IDF_MATCH_NUMBER, // ÿ10�������	��(��/10��)
	IDF_HIGH_MATCH_PRICE, // �����ɼ�	��(Ԫ)
	IDF_LOW_MATCH_PRICE, // �����ɼ�	��(Ԫ)
	IDF_BONUS_PER_SHARE, // ÿ�ɺ���		��(Ԫ/��)
	IDF_BRIEF, // ��Ҫ˵��		��					��
	IDF_UPDATING_DATE, // ���ϸ�������	��(YYYYMMDD)
	IDF_LAST_YEAR_DIVIDENT, // �������Ϣ	��(Ԫ/��)
	IDF_LAST_YEAR_TRANSFERS, // �������ת��	��(��/��)
	IDF_CURRENT_H_SHARES, // ��ͨH��		��(��)
	IDF_DIVIDENDYIELD, // ��Ϣ��%		��(%)

	IDF_YEAR_EPS2, // ÿ�ɶ�̬����
	IDF_FUND_PER_SHARE, // ÿ�ɹ���
	IDF_EQUITY_RATIO, // �ɶ�Ȩ���% �� �ɶ�Ȩ��ȣ�[�ɶ�Ȩ���ܶ�����ʲ�����]*100%
	IDF_EPS_FUND, // ����λ������		
	IDF_RUPPERCENT, // ����
	IDF_SNAP_TIME, // ����ʱ��

	IDF_EQUITY_DEBT, // �ʲ���ծ
	IDF_BASE_DATE, // ��׼����
	IDF_REPORT_DATE, // ��������


	// ����Ϊծȯ�������������ֶ�
	IDF_COMMODITY_FULL_NAME, // ծȯȫ��		��(���)			��
	IDF_ISSUED_AMOUNT, // ծȯ�����ܶ�	��(Ԫ)
	IDF_PAR_PRICE, // ծȯƱ��۸�	��(Ԫ)
	IDF_ISSUE_MODE, // ծȯ���з�ʽ	��					��
	IDF_PAY_INTEREST_TIMES, // ծȯ��Ϣ����	��(��)
	IDF_PAR_INTEREST_RATE, // ծȯƱ������	��(%)
	IDF_PAY_INTEREST_FREQUENCY, // ծȯ��ϢƵ��	��(��/��)
	//IDF_MODIFYING_DATE, // ծȯ�������ڣ���IDF_UPDATING_DATE
	IDF_ISSUE_DATE, // ծȯ��������	��(YYYYMMDD)
	IDF_BEGIN_DATE, // ծȯ��Ϣ����	��(YYYYMMDD)
	IDF_END_DATE, // ծȯ��������	��(YYYYMMDD)
	IDF_LISTING_EXCHANGE, // ծȯ���н�����	��(QL_STOCK_EXCHANGE)
	//IDF_BRIEF, // ��Ҫ˵����ͬIDF_BRIEF
	IDF_COMMODITY_KIND, // ծȯ����		��(0,1,2)			��(��Ϣծȯ������ծȯ������һ�λ�����Ϣծȯ)
	IDF_BOND_NET_PRICE, // ծȯ����				

	IDF_ISSUED_VOLUME, // Ȩ֤��������	��(��)
	IDF_CURRENT_VOLUME, // Ȩ֤��ͨ���	��(��)
	IDF_EXERCISE_DIRECTION, // ��Ȩ����		��(0,1,2,3,4)		��(�Ϲ�Ȩ֤���Ϲ�Ȩ֤��ţ֤����֤������)
	IDF_EXERCISE_MODE, // ��Ȩ��ʽ		��(0,1,2,3,4,5,6)	��(��Ľ��Ȩ֤����ʽȨ֤��ŷʽȨ֤��������Ȩ֤������Ȩ֤���������ţ��֤���������ţ��֤)
	IDF_IMPLEMENTING_RATE, // ��Ȩ����		��(��Ĺ�Ʊ/Ȩ֤)
	IDF_IMPLEMENTING_PRICE, // ��Ȩ�۸�		��(Ԫ/��)
	IDF_IMPLEMENTING_COST, // ��Ȩ�ɱ�		��(Ԫ/��)/��
	IDF_LISTING_DATE_, // Ȩ֤��������	��(YYYYMMDD)
	IDF_EXPIRATION_DATE, // Ȩ֤��������	��(YYYYMMDD)
	IDF_LEVERAGE_RATE, // �ܸ˱���		��(��)
	IDF_POTENTIAL_PRICE, // ���ڼ�ֵ		��(Ԫ)
	IDF_EQUIVALENCE_PERCENT, // �ȼ۱���%	��(%)/��
	IDF_OBJECT_COMMODITY_CODE, // ���֤ȯ����	��(���)			��
	IDF_BEGIN_DATE_, // ��Ȩ��ʼ		��(YYYYMMDD)
	IDF_END_DATE_, // ��Ȩ��ֹ		��(YYYYMMDD)
	IDF_OBJECT_COMMODITY_NAME, // ���֤ȯ����	��(���)			��
	IDF_SETTLEMENT_MODE, // ���㷽ʽ		��(1,2)				��(ʵ��ֽ�)
	IDF_SETTLEMENT_PRICE, // ����۸�		��(Ԫ)
	IDF_IMPLEMENTING_CODE, // ��Ȩ����		��(���)			��
	//IDF_UPDATING_DATE_, // Ȩ֤�������ڣ���IDF_UPDATING_DATE
	IDF_REMAINING_DAYS, // ���ཻ������	��(��)
	//IDF_BRIEF__, // ��Ҫ˵����ͬIDF_BRIEF
	IDF_LAST_IMPLEMENTING_DATE, // �������	��(YYYYMMDD)
	IDF_PREMIUM_PERCENT, // Ȩ֤�����%	��(%)/��
	IDF_ACTUAL_LEVERAGE_RATE, // ʵ�ʸܸ�		��
	IDF_SENSITIVITY_DELTA, // �Գ�ֵ		��
	IDF_INTEREST_RATE, // Ȩ֤�������޷�������%	��(%)
	IDF_HISTORY_VOLATILITY, // ��ʷ����%	��(%)
	IDF_COMMODITY_CATEGORY, // Ȩ֤����		��(1,2,3)			��(��׼���Ǳ�׼��ţ��֤)
	IDF_IMPLIED_VOLATILITY, // ���첨��%	��
	IDF_TOEND_DAYS, // Ȩ֤�ൽ��������	��(��)
	IDF_CALL_PRICE, // ţ��֤ǿ���ջؼ�	��(Ԫ)
	IDF_OUTSTANDING_QUANTITY,	//�ֻ���
	IDF_OUTSTANDING_QUANTITY_PERCENT, //�ֻ�����
	IDF_CONTRACT_CODE,	// ��Լ���� C19	
	IDF_CONTRACT_STATUSFLAG, //��Ȩ��Լ״̬��Ϣ��ǩ C8
	//���ֶ�Ϊ8λ�ַ���������ÿλ��ʾ�ض��ĺ��壬�޶�������ո�
	//��1λ����0����ʾ�ɿ��֣���1����ʾ�����������֣��������ҿ��֣������뿪�֡�
	//��2λ����0����ʾδ����ͣ�ƣ���1����ʾ����ͣ�ơ�
	//��3λ����0����ʾδ�ٽ������գ���1����ʾ���뵽���ղ���10�������ա�
	//��4λ����0����ʾ����δ����������1����ʾ���10���������ں�Լ������������
	//��5λ����A����ʾ�����¹��Ƶĺ�Լ����E����ʾ�����ĺ�Լ����D����ʾ����ժ�Ƶĺ�Լ��
	IDF_CONTRACT_TRADEPHASECODE, //��Ȩ����ʱ��״̬�� C4
	//���ֶ�Ϊ4 λ�ַ���������ÿλ��ʾ�ض��ĺ��壬�޶�������ո�
	//��1 λ����S����ʾ����������ǰ��ʱ�Σ���C����ʾ���Ͼ���ʱ�Σ���T����ʾ��������ʱ�Σ���B����ʾ����ʱ�Σ���E����ʾ����ʱ�Σ���V����ʾ�������жϣ���P����ʾ��ʱͣ�ơ�
	//��2 λ����0����ʾδ����ͣ�ƣ���1����ʾ����ͣ�ơ�
	//�����Ȩ��Լ�Ĳ�Ʒ����Ϊ��00000000�������ʾȫ�г�����״̬��
	//���ֶ�Ϊ8 λ�ַ���������ÿλ��ʾ�ض��ĺ��壬�޶�������ո�
	//��1 λ����S����ʾȫ�г������ڼ䣨����ǰ������T����ʾȫ�г����ڽ����ڼ䣨���м����У��� ��E����ʾȫ�г����ڱ����ڼ䡣
	//��2 λ����1����ʾ���̼��Ͼ��۽�����־��δ����ȡ��0����
	//��3 λ����1����ʾ�г�������б�־��δ����ȡ��0����


	IDF_UP_COMMODITY_NAME, // ������Ʒ����(����ֶν���CalcFieldsString�������ݲ㲻������)
	IDF_UP_COMMODITY_CODE, // ������Ʒ����(���ǹɴ���,���ǹ��г����)
	IDF_CTB, // ���Դ��̹��׶�

	// ����Ϊ���ɲƸ�������������ֶ�
	IDF_RICH_CODE_RATING, // ���ɲƸ���������(�����ֶ�)	��(��)	��
	IDF_RICH_CODE_DESCRIPTION, // ���ɲƸ���������������(HINT��ʾ)	��(��)	��
	IDF_RICH_CODE_RATING_COLOR, // ���ɲƸ���������(�����ֶ�)����ɫ	��(COLORREF)
	// ���ڷ��ص���double�ͣ�����ⲿ��Ҫͨ��+0.500001��ǿת��DWORD��ʹ��

	//������ʵս�汾�������������ֶ�
	IDF_MAIN_WATCH_START, // ��������ֶεĿ�ʼ 
	IDF_AVERAGE_CONTRACT_VOLUME_5, // ���5��������(������ǰ������)ÿ�ɽ�������	��(��)
	IDF_AVERAGE_BOUGHT_CONTRACT_5, // ���5��������(������ǰ������)�վ��ɽ�����(���ڶ�ָ̬��)	��(��)
	IDF_AVERAGE_SOLD_CONTRACT_5, // ���5��������(������ǰ������)�վ��ɽ�������(���ڶ�ָ̬��)	��(��)
	IDF_MAIN_BOUGHT_SOLD_DIFF, // ������(��������)	��(%)
	IDF_MAIN_POWER, // ����ǿ��		��(��/��)
	//IDF_MAIN_BOUGHT_POWER, // ������ǿ��	��(��/��)
	//IDF_MAIN_SOLD_POWER, // ������ǿ��	��(��/��)
	IDF_MAIN_ACTIVITY, // ������Ծ��	��(%)
	IDF_MAIN_POSITION, // �����ֲ�		��(������)
	IDF_RETAIL_POSITION, // ɢ���ֲ�		��(������)
	//IDF_HAWK_EYE, // ӥ��ָ��		��(Ԫ)
	IDF_DDX, // DDXָ��		��(%���۹ɡ�)
	//IDF_DDY,		// DDYָ��		��(��)
	//IDF_DDZ,		// DDZָ��		��(%)
	IDF_AVERAGE_DDX_5, // ���5��������(����ǰ������)��DDX���ۼ�
	IDF_AVERAGE_DDX_10, // ���10��������(����ǰ������)��DDX���ۼ�
	IDF_AVERAGE_DDX_20, // ���20��������(����ǰ������)��DDX���ۼ�
	IDF_DDX_POSITIVE_DAYS, // DDX10����(����ǰ������)������	��(��)
	IDF_DDX_CONTINOUS_DAYS, // DDX����(����ǰ������)��/������	��(��)
	IDF_AVERAGE_BOUGHT_VOLUME, // �򵥾���		��(��/��)
	IDF_AVERAGE_SOLD_VOLUME, // ��������		��(��/��)
	IDF_AVERAGE_BS_VOLUME_DIFF, // ������������	��(��/��)
	IDF_AVERAGE_BS_VOLUME_RATIO, // ������������	��(��)
	IDF_DELTA_AVERAGE_BS_VOLUME_RATIO, // 1���Ӧ�������	��(��)
	IDF_AVERAGE_CONTRACT_VOLUME, // ÿ������		��(��/��)
	IDF_AVERAGE_CONTRACT_TURNOVER_RATE, // ��������	��(%/�������Ŵ�10000��)
	IDF_MAIN_BOUGHT, // ��������		��(%)
	IDF_MAIN_SOLD, // ��������		��(%)
	IDF_RETAIL_BOUGHT, // ɢ������		��(%)
	IDF_RETAIL_SOLD, // ɢ������		��(%)
	IDF_BID_PERCENT, // ί��ռ��		��(%)
	IDF_ASK_PERCENT, // ί��ռ��		��(%)
	IDF_AVERAGE_MAIN_BOUGHT_AMOUNT_5,// ���5��������(������ǰ������)�վ����������(���ڶ�ָ̬��)	��(Ԫ)
	IDF_AVERAGE_MAIN_SOLD_AMOUNT_5, // ���5��������(������ǰ������)�վ�����������(���ڶ�ָ̬��)	��(Ԫ)
	IDF_LONG_SHORT_RATIO, // ��ձ�		��(��)
	IDF_CAPITAL_ENERGY, // �ʽ���		��(������)
	IDF_SIL, // �羯ֵ		��(��)
	IDF_GOLD_LADDER, // �ƽ����		��(-1,0,1)			��(ת��,��,תǿ)
	IDF_ABNORMAL_ACTION, // �����춯		��(-1,0,1)			��(��ͷ�춯,��,��ͷ�춯)
	IDF_INSTITUTION_POSITION, // �����ֲ�		��(%)
	IDF_LARGE_POSITION, // �󻧳ֲ�		��(%)
	IDF_MIDDLE_POSITION, // �л��ֲ�		��(%)
	IDF_SMALL_POSITION, // ɢ���ֲ�		��(%)
	IDF_INSTITUTION_DELTA, // ��������		��(%���۹ɡ�)
	IDF_LARGE_DELTA, // ������		��(%���۹ɡ�)
	IDF_MIDDLE_DELTA, // �л�����		��(%���۹ɡ�)
	IDF_SMALL_DELTA, // ɢ������		��(%���۹ɡ�)
	IDF_INSTITUTION_DELTA_5, // ����5������	��(%���۹ɡ�)
	IDF_LARGE_DELTA_5, // ��5������	��(%���۹ɡ�)
	IDF_MIDDLE_DELTA_5, // �л�5������	��(%���۹ɡ�)
	IDF_SMALL_DELTA_5, // ɢ��5������	��(%���۹ɡ�)
	IDF_INSTITUTION_DELTA_10, // ����10������	��(%���۹ɡ�)
	IDF_LARGE_DELTA_10, // ��10������	��(%���۹ɡ�)
	IDF_MIDDLE_DELTA_10, // �л�10������	��(%���۹ɡ�)
	IDF_SMALL_DELTA_10, // ɢ��10������	��(%���۹ɡ�)
	IDF_INSTITUTION_DELTA_20, // ����20������	��(%���۹ɡ�)
	IDF_LARGE_DELTA_20, // ��20������	��(%���۹ɡ�)
	IDF_MIDDLE_DELTA_20, // �л�20������	��(%���۹ɡ�)
	IDF_SMALL_DELTA_20, // ɢ��20������	��(%���۹ɡ�)
	IDF_MAIN_WATCH_END			= IDF_SMALL_DELTA_20, // ��������ֶεĽ���(���ݿ�����)

	IDF_PREOPENING,//�Ƿ���Ԥ��ʾ

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
	FIELD_SORT_NONE,	//������
	FIELD_SORT_ASC,		//����
	FIELD_SORT_DESC,	//����
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
