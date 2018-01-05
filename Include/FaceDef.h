#ifndef _H_FACEDEF_H_
#define _H_FACEDEF_H_

//�������
//mode ˮƽ���뷽ʽ
#define QL_ALIGN_CENTER			0
#define QL_ALIGN_LEFT			1
#define QL_ALIGN_RIGHT			2

//vMode ��ֱ���뷽ʽ
#define QL_VALIGN_CENTER		0
#define QL_VALIGN_TOP			1
#define QL_VALIGN_BOTTOM		2

//putQlString�� fontSpInfo����Ϣ
#define QL_SPFONT_NULL			0
#define QL_SPFONT_UNDLINE		1
#define QL_SPFONT_SUBUNDLINE	2
#define QL_SPFONT_UNDLINE_WITHTRI	3 //�������������ε��»��� + ������ �� - ������
#define QL_SPFONT_UNDLINE_SMALLWND	4 //С�����µ��»�����������

//һЩϵͳ�̶�����ɫ����Щ��ɫֻ����Ϊȱʡ������µ�ʹ�á�
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

//��������
#define  QLSIGN_UPTRI		1	//������
#define  QLSIGN_DOWNTRI		2	//������
#define  QLSIGN_UPARROW		3	//�ϼ�ͷ
#define  QLSIGN_DOWNARROW	4	//�¼�ͷ
#define  QLSIGN_DIAMOND		5	//����
#define	 QLSIGN_STICK1		6   // -
#define  QLSIGN_STICK2		7   /* \*/
#define  QLSIGN_STICK3		8	/*| */
#define  QLSIGN_STICK4		9	// /
#define  QLSIGN_UPARROW2	10	// ���̾����ϼ�ͷ
#define  QLSIGN_DOWNARROW2	11	// ���̾����¼�ͷ
#define  QLSIGN_EQUAL		12	// ���̾���= 
#define  QLSIGN_INVALIDE_DATA	13 //���������ֵģ���
#define  QLSIGN_DUPTRI      14   //����������  drawQlSign2֧��
#define  QLSIGN_DDOWNTRI    15	// ����������	drawQlSign2֧��
#define	 QLSIGN_RPTRAD		16  //�����״�

//������һЩĬ����ɫ,��Щ��ɫֻ����Ϊȱʡ������µ�ʹ��
#define QCOLOR_DEF_XAXIS_VALUE				QCOLOR_SYS_GRAY //Ĭ�ϵ����ƻ��������x��ֵ��ɫ
#define QCOLOR_DEF_YAXIS_VALUE				QCOLOR_SYS_WHITE//Ĭ�ϵ����ƻ��������Y��ֵ��ɫ
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

//������֧�ֵ���ɫ��
enum _ID_COLOR
{
	
//	IDcr_DELTA										=	1,//�ǵ�ɫ

 	IDcr_VIEWBG = 1,//������ͼ������ɫ
	IDcr_HIGHLIGNT_BG=2,//�����ı�����ɫ��
	IDcr_WORKTABLE_NORMAL = 3,//����̨��ͨ��ɫ
	IDcr_WORKTABLE_SELECT = 4, //����̨ѡ����ɫ
	IDcr_WORKTABLE_HOVER = 5,//����̨ѡ����ɫ
	
	IDcr_PRICE_RISING = 20,//������ɫ
	IDcr_PRICE_PLAIN=21,//ƽ����ɫ
	IDcr_PRICE_FALLING=22,//�µ���ɫ

	IDcr_COMMODITY_CODE = 30,//�������ɫ
	IDcr_COMMODITY_NAME = 31,//��Ʒ������ɫ
	IDcr_COMMODITY_CLOSE = 32,//��Ʒ������ɫ


	IDcr_PIC_TITLE = 40,//���������ɫ�����ɻ�����ָ��ͼ�δ��ڱ����ı�[���������]����ɫ
	IDcr_GRID_LINE = 41,//����ߡ��Լ��ָ��ߵ���ɫ��
	IDcr_YAXIS_VALUE = 42,//���ƻ���y��ֵ����ɫ��
	IDcr_XAXIS_VALUE = 43,//���ƻ���x��ֵ����ɫ��
	IDcr_DATETIME_COORD = 44,//���ƻ�������ʱ���α����ɫ
	IDcr_FRAME_XYLINE = 45, //���������ɫ
	IDcr_INFOCOL_TEXT = 46,//��Ϣ������
	IDcr_LINE_CURSOR = 47,//ָʮ���α��ߵ���ɫ��
	IDcr_LINE_RISING = 48,//����
	IDcr_LINE_FALLING = 49,//����
	IDcr_LINE_SELFDRAWING = 50,//�Ի���

	IDcr_PAGETAG_TEXT = 60,//��ǩ����
	IDcr_PAGETAG_SELBK = 61, //��ǩѡ�б���
	IDcr_PAGETAG_SELTEXT = 62, //��ǩѡ������
	IDcr_PAGETAG_HOVERBK = 63, //��ǩ��ͣ����
	IDcr_PAGETAG_HOVERTEXT = 64,//��ǩ��ͣ����

	IDcr_RPT_TITLE = 80,//���������ɫ
	IDcr_RPT_TITLEBG = 81,//������ⱳ��ɫ
	IDcr_RPT_SELROWBG = 82,//����ѡ������ɫ
	IDcr_RPT_TITLESPLITLINE = 83,//��������зָ��ߵ���ɫ
	IDcr_RPT_RAD = 84,//��������״���ɫ��
	IDcr_RPT_POSITION_TAG = 85,//������ĳֱֲ����ɫ
	IDcr_RPTTAG_TEXT = IDcr_PAGETAG_TEXT,//�����ǩ����
	IDcr_RPTTAG_SELBK = IDcr_PAGETAG_SELBK, //�����ǩѡ�б���
	IDcr_RPTTAG_SELTEXT = IDcr_PAGETAG_SELTEXT, //�����ǩѡ������
	IDcr_RPTTAG_HOVERBK = IDcr_PAGETAG_HOVERBK, //�����ǩ��ͣ����
	IDcr_RPTTAG_HOVERTEXT = IDcr_PAGETAG_HOVERTEXT,//�����ǩ��ͣ����
	

	IDcr_LINE_INDEX_BEGIN = 100,
	IDcr_LINE_INDEX1 = IDcr_LINE_INDEX_BEGIN,	//ָ����
	IDcr_LINE_INDEX2 = 101,
	IDcr_LINE_INDEX3 = 102,
	IDcr_LINE_INDEX4 = 103,
	IDcr_LINE_INDEX5 = 104,
	IDcr_LINE_INDEX6 = 105,
	IDcr_LINE_INDEX7 = 106,
	IDcr_LINE_INDEX8 = 107,
	IDcr_LINE_INDEX_END = IDcr_LINE_INDEX8,
	IDcr_LINE_INDEX_RESERVE = IDcr_LINE_INDEX_END+64,//��ָ���߱���64��ϯλ


	IDcr_ROLLINFO_BEGIN = 150,
	IDcr_ROLLINFO_TEXT = 150,//������Ѷ���ֵ���ɫ
	IDcr_ROLLINFO_END = 160,
	



	IDcr_COMM_VOLUME = IDcr_COMMODITY_NAME,//һ����������ɫ��
	IDcr_COMM_AMOUNT = IDcr_COMMODITY_NAME,//һ���Ƕ����ɫ��
	IDcr_COMM_SUBVALUE = IDcr_COMMODITY_NAME,//һ���Ƿ�������ɫ

	//������ɫֵ
	IDcr_COMMODITY_SERIAL = 500,//��Ʒ����
	IDcr_VOLUME,//����
	IDcr_AMOUNT,//�ɽ����
	IDcr_VOLUME_RATION,//����
	IDcr_CHANGE_HANDS_PERCENT,//������
	IDcr_PER,//��ӯ��
	IDcr_LAST_VOLUME,//����
	IDcr_CURRENT_VALUE,//��ͨ��ֵ
	IDcr_TOTAL_VALUE,//����ֵ
	IDcr_PBR,//�о���
	IDcr_BID_ASK_VOLUME_DIFF,//ί����
	IDcr_BID_AMOUNT, //ί���
	IDcr_BID_VOLUME,//ί����
	IDcr_ASK_AMOUNT,//ί����
	IDcr_ASK_VOLUME, //ί����
	IDcr_PREV_NET_VALUE, //��ֵ
	IDcr_YIELD_PERCENT,//������%
	IDcr_FULL_PRICE,//ȫ��
	IDcr_INTEREST,//��Ϣ
	IDcr_NAME_PREFIX,//ǰ׺

	//�ڻ���ɫֵ
	IDcr_POSITION,//�ֲ�
	IDcr_OPEN_POSITION,//����
	IDcr_CLOSE_POSITION,//ƽ��
	IDcr_LAST_OPEN_POSITION,//�ֿ�
	IDcr_LAST_CLOSE_POSITION,//��ƽ
	IDcr_OPEN_CLOSE_POSITION,//��ƽ
	IDcr_LAST_OPEN_CLOSE_POSITION,//�ֿ�ƽ
	IDcr_SETTLEMENT,//����
	IDcr_PREV_POSITION,//���
	IDcr_PREV_SETTLEMENT,//���


	//����������ɫֵ
	IDcr_LISTING_DATE,//��������
	IDcr_VOCATION,//��ҵ
	IDcr_TOTAL_SHARES,//�ܹɱ�
	IDcr_CURRENT_A_SHARES,//��ͨA��
	IDcr_CURRENT_B_SHARES,//��ͨB��
	IDcr_TOTAL_ASSETS,//���ʲ�
	IDcr_ACCUMULATION_FUND,//�ʱ�����
	IDcr_MAIN_EARNINGS	,//��Ӫ����
	IDcr_EQUITY_DEBT_RATIO	,//�ʲ���ծ%
	IDcr_CURRENT_SHARES	,//��ͨ��
	IDcr_FIXED_ASSETS,//�̶��ʲ�
	IDcr_END_DATE,//��ծ��������
	IDcr_DIVIDENDYIELD,//��Ϣ��


	//Ȩ֤�ֶε���ɫֵ
	IDcr_IMPLEMENTING_PRICE,//��Ȩ��
	IDcr_IMPLEMENTING_COST,//��Ȩ�ɱ�
	IDcr_IMPLEMENTING_RATE,//��Ȩ����
	IDcr_ISSUED_VOLUME,//Ȩ֤����
	IDcr_CURRENT_VOLUME,//Ȩ֤���
	IDcr_COMMODITY_KIND_, //����
	IDcr_LISTING_DATE_,//��������"
	IDcr_EXPIRATION_DATE,//��������
	IDcr_REMAINING_DAYS,//��������
	IDcr_IMPLEMENTING_MODE,//��Ȩ��ʽ
	IDcr_LEVERAGE_RATE,//�ܸ˱���
	IDcr_POTENTIAL_PRICE,//���ڼ�ֵ
	IDcr_OBJECT_COMMODITY_NAME,//���֤ȯ
	IDcr_BEGIN_DATE_,//��Ȩ��ʼ
	IDcr_END_DATE_, //��Ȩ��ֹ
	IDcr_LAST_IMPLEMENTING_DATE,//�������
	IDcr_TOEND_DAYS,//�ൽ����

	//��̬ͳ��
	IDcr_STAT_VALUME,//ͳ���ֶ��õ���������ɫ
	IDcr_STAT_CONTINUE_DELTA,//�������ǻ��µ�����ɫ
	
	//ָ����
	IDcr_INDEXBAR_DARKRED,
	IDcr_INDEXBAR_DARKGREEN,
	IDcr_INDEXBAR_REDGREEN_BORDER,
	IDcr_INDEXBAR_RED = IDcr_PRICE_RISING,
	IDcr_INDEXBAR_GREEN = IDcr_PRICE_FALLING,

};


//������֧�ֵ����壬ע��һ��ȷ������ֵ���ɸı䣬������enum���ͣ��ǳ����ڿ����׶ο��Ա仯��
enum
{
	QFONT_TABPAGE							= 1,						//���ֱ�ǩ���塣
	QFONT_TABPAGE_CH						= QFONT_TABPAGE,			//���ֱ�ǩ�������塣
	QFONT_TABPAGE_EN						= 2,						//���ֱ�ǩ�������塣
	QFONT_PIC_COMM							= 3,						//������ͨ����
	QFONT_PIC_COMM_CH						= QFONT_PIC_COMM,			//������ͨ��������
	QFONT_PIC_COMM_EN						= 4,
	QFONT_PIC_TITLE							= 5,						//�������
	QFONT_PIC_TITLE_CH						= QFONT_PIC_TITLE,			//���������������
	QFONT_PIC_TITLE_EN						= 6,
	QFONT_DIALOG_TITLE_CH					= 7,

	//����������
	QFONT_RPT_TITLE							= 20,						//�����������
	QFONT_RPT_TITLE_CH						= QFONT_RPT_TITLE,			//���������������
	QFONT_RPT_TITLE_EN						= 21,						//���������������
	QFONT_RPT_CONTENT						= 22,						//������������
	QFONT_RPT_CONTENT_CH					= 22,						//���������������塣
	QFONT_RPT_CONTENT_EN					= 23,						//��������������塣
	QFONT_RPT_STAT_CH						= QFONT_RPT_CONTENT_CH,		//����ͳ�����������塣
	QFONT_RPT_STAT_EN						= QFONT_RPT_CONTENT_EN,		//����ͳ�������������塣
	QFONT_MSORTRPT_CONTENT_CH				= QFONT_RPT_CONTENT_CH,		//�ۺ��������������������塣
	QFONT_MSORTRPT_CONTENT_EN				= QFONT_RPT_CONTENT_EN,		//�ۺ��������������������塣
	QFONT_RPT_SHORTFAIRY					= 24,						//�����ж��߾�������

	//��Ϣ��С��������[40-80)
	QFONT_INFOCOL							= QFONT_PIC_COMM,			//��Ϣ�����塣
	QFONT_INFOCOL_CH						= QFONT_PIC_COMM_CH,		//��Ϣ���������塣
	QFONT_INFOCOL_EN						= QFONT_PIC_COMM_EN,		//��Ϣ�����ֻ���������
	QFONT_INFOCOL_MMP_CH					= QFONT_INFOCOL_CH,			//��Ϣ����������������
	QFONT_INFOCOL_MMP_EN					= QFONT_INFOCOL_EN,			//��Ϣ������������������
	QFONT_INFOCOL_CANCEL_CH					= QFONT_INFOCOL_CH,			//��Ϣ��������������
	QFONT_INFOCOL_CANCEL_EN					= QFONT_INFOCOL_EN,			//��Ϣ���򳷵�����������
	QFONT_INFOCOL_CANCEL_TIME_CH			= QFONT_INFOCOL_CH,			//��Ϣ������ʱ����������
	QFONT_INFOCOL_CANCEL_TIME_EN			= QFONT_INFOCOL_EN,			//��Ϣ������ʱ����������
	QFONT_INFOCOL_CONTRACT_CH				= QFONT_INFOCOL_CH,			//��Ϣ�������������
	QFONT_INFOCOL_CONTRACT_EN				= QFONT_INFOCOL_EN,			//��Ϣ�������������
	QFONT_INFOCOL_TICK_CH					= QFONT_INFOCOL_CH,			//��Ϣ��������������
	QFONT_INFOCOL_TICK_EN					= QFONT_INFOCOL_EN,			//��Ϣ��������������
	QFONT_INFOCOL_FINA_CH					= QFONT_INFOCOL_CH,			//��Ϣ������������
	QFONT_INFOCOL_FINA_EN					= QFONT_INFOCOL_EN,			//��Ϣ������������
	QFONT_INFOCOL_WJL_CH					= QFONT_INFOCOL_CH,			//��Ϣ��ί����������������
	QFONT_INFOCOL_WJL_EN					= QFONT_INFOCOL_EN,			//��Ϣ��ί����������������
	QFONT_INFOCOL_CONTRIBUTE_CH				= QFONT_INFOCOL_CH,			//��Ϣ�����׶���������
	QFONT_INFOCOL_CONTRIBUTE_EN				= QFONT_INFOCOL_EN,			//��Ϣ�����׶���������
	QFONT_INFOCOL_TOP_CH					= QFONT_INFOCOL_CH,			//��Ϣ������������
	QFONT_INFOCOL_TOP_EN					= QFONT_INFOCOL_EN,			//��Ϣ������������
	QFONT_INFOCOL_IDX_CH					= QFONT_INFOCOL_CH,			//��Ϣ��ָ��������
	QFONT_INFOCOL_IDX_EN					= QFONT_INFOCOL_EN,			//��Ϣ��ָ��������
	QFONT_INFOCOL_PRICE_CH					= QFONT_INFOCOL_CH,			//��Ϣ������������
	QFONT_INFOCOL_PRICE_EN					= QFONT_INFOCOL_EN,			//��Ϣ������������

	QFONT_INFOCOL_SMALL						= 40,						//��Ϣ����С���������塣
	QFONT_INFOCOL_SMALL_CH					= QFONT_INFOCOL_SMALL,		//��Ϣ����С����������
	QFONT_INFOCOL_SMALL_EN					= 41,						//��Ϣ����С����������
	QFONT_INFOCOL_WJL_TIME_CH				= 42,						//��Ϣ��ί��������ʱ����������
	QFONT_INFOCOL_WJL_TIME_EN				= 43,						//��Ϣ��ί��������ʱ����������
	

	//�������ƺͼ���������������[80,100)
	QFONT_IDX_AXIS							= QFONT_PIC_TITLE,			//���ƺͼ����������������塣	
	QFONT_IDX_RLT							= QFONT_PIC_TITLE,			//ָ�껭��Ľ�������塣
	QFONT_IDX_RLT_CH						= QFONT_PIC_TITLE_CH,		//ָ�껭��Ľ�����������塣
	QFONT_IDX_RLT_EN						= QFONT_PIC_TITLE_EN,		//ָ�껭��Ľ�����������塣

	QFONT_IDX_CURSOR_CH						= QFONT_PIC_TITLE_CH,		//ָ�껭���α���������
	QFONT_IDX_CURSOR_EN						= QFONT_PIC_TITLE_EN,		//ָ�껭���α���������
	QFONT_IDX_AXIS_CH						= 80,						//���ƺͼ������������Ⱥ������塣
	QFONT_IDX_AXIS_EN						= 81,						//���ƺͼ��������������������塣
	QFONT_IDX_DATETIME_CH					= QFONT_IDX_AXIS_CH,		//ָ��ʱ����������
	QFONT_IDX_DATETIME_EN					= QFONT_IDX_AXIS_EN,		//ָ��ʱ����������
	//�������ɻ�������[100,120)
	QFONT_SC_WEIGHT_CH						= QFONT_INFOCOL_CH,			//����ȨϢ������������
	QFONT_SC_WEIGHT_EN						= QFONT_INFOCOL_EN,			//����ȫϵ������������
	QFONT_SC_WEIGHT_TITLE_CH				= QFONT_INFOCOL_CH,			//����ȨϢ���ϱ�����������
	QFONT_SC_WEITHT_TITLE_EN				= QFONT_INFOCOL_EN,			//����ȫϵ���ϱ�����������
	QFONT_SC_SMALL_HISTREND_INFO_CH			= QFONT_INFOCOL_CH,			//������ʷ������Ϣ��������
	QFONT_SC_SMALL_HISTREND_INFO_EN			= QFONT_INFOCOL_EN,			//������ʷ������Ϣ��������
	QFONT_SC_GAIN_INFO_CH					= QFONT_INFOCOL_CH,			//���ɴ�������Ϣ��������
	QFONT_SC_GAIN_INFO_EN					= QFONT_INFOCOL_EN,			//���ɴ�������Ϣ��������
	QFONT_SC_PRICE_CH						= QFONT_INFOCOL_CH,			//�������۷�����������
	QFONT_SC_PRICE_EN						= QFONT_INFOCOL_EN,			//�������۷�����������
	QFONT_SC_SEATSERIAL_CH					= QFONT_INFOCOL_CH,			//���ɾ�����λ��������
	QFONT_SC_SEATSERIAL_EN					= QFONT_INFOCOL_EN,			//���ɾ�����λ��������
	QFONT_SC_GAIN_MMP_CH					= QFONT_INFOCOL_CH,			//���ɴ�������������������
	QFONT_SC_GAIN_MMP_EN					= QFONT_INFOCOL_EN,			//���ɴ�������������������
	QFONT_SC_ORDERLIST_CH					= QFONT_INFOCOL_CH,			//��������������������
	QFONT_SC_ORDERLIST_EN					= QFONT_INFOCOL_EN,			//��������������������
	QFONT_SC_ORDERLIST_HINT_CH				= 100,						//������������Hint��������
	QFONT_SC_ORDERLIST_HINT_EN				= 101,						//������������Hint��������
	QFONT_SC_PRICELIST_CH					= 102,						//�������۷����б���������
	QFONT_SC_PRICELIST_EN					= 103,						//�������۷����б���������
	QFONT_SC_SEATSERIAL_SMALLBTN_CH			= 104,						//���ɾ�����λС��ť��������
	QFONT_SC_SEATSERIAL_SMALLBTN_EN			= 105,						//���ɾ�����λС��ť��������


	//����tab����[120-140)
	QFONT_RPT_TAB							= QFONT_TABPAGE,			//������tab����
	QFONT_RPT_TAB_LEFT_CH					= QFONT_TABPAGE_CH,			//������tab���ǩ��������
	QFONT_RPT_TAB_LEFT_EN					= QFONT_TABPAGE_EN,			//������tab���ǩ��������
	QFONT_RPT_TAB_BOT_CH					= QFONT_TABPAGE_CH,			//������tab�±�ǩ��������
	QFONT_RPT_TAB_BOT_EN					= QFONT_TABPAGE_EN,			//������tabС��ǩ��������
	QFONT_SC_TAB_LEFT_CH					= QFONT_TABPAGE_CH,			//������tab���ǩ��������
	QFONT_SC_TAB_LEFT_EN					= QFONT_TABPAGE_EN,			//������tab���ǩ��������
	QFONT_SC_TAB_BOT_CH						= QFONT_TABPAGE_CH,			//������tab�±�ǩ��������
	QFONT_SC_TAB_BOT_EN						= QFONT_TABPAGE_EN,			//������tab�±�ǩ��������
	QFONT_MC_TAB_LEFT_CH					= QFONT_TABPAGE_CH,			//�����tab���ǩ��������
	QFONT_MC_TAB_LEFT_EN					= QFONT_TABPAGE_EN,			//�����tab���ǩ��������
	QFONT_MC_TAB_BOT_CH						= QFONT_TABPAGE_CH,			//�����tab�±�ǩ��������
	QFONT_MC_TAB_BOT_EN						= QFONT_TABPAGE_EN,			//�����tab�±�ǩ��������
	QFONT_SC_MIX_TAB_LEFT_CH				= QFONT_TABPAGE_CH,			//�����Ϲ������������л�ϱ�ǩ��������
	QFONT_SC_MIX_TAB_LEFT_EN				= QFONT_TABPAGE_EN,			//�����Ϲ������������л�ϱ�ǩ��������
	

	//������������[200,240)
	QFONT_RIGHT_TITLE_CH					= 200,						//�Ҳ�����Ʊ��������
	QFONT_RIGHT_TITLE_NUM					= 201,						//�Ҳ�����Ʊ��������
	QFONT_RIGHT_TITLE_EN					= QFONT_RIGHT_TITLE_NUM,
	QFONT_HINT_TITLE						= 202,						//hint��������塣
	QFONT_HINT_CONTENT						= 203,						//hint�������塣
	QFONT_IDXBAR_NAME						= 204,						//ָ������Ʒ���ƺ���������
	QFONT_IDXBAR_NAME_CH					= QFONT_IDXBAR_NAME,		//ָ������Ʒ���ƺ�������������
	QFONT_IDXBAR_NAME_EN					= 205,						//ָ������Ʒ���ƺ��������ĺ���������
	QFONT_SMARTKB_CH						= 206,						//���ܼ�����������
	QFONT_SMARTKB_EN						= 207,						//���ܼ�����������
	QFONT_WORKTABLE_CH						= 210,						//����̨��������
	QFONT_WORKTABLE_EN						= 211,						//����̨��������
	QFONT_PMD_SHORTFAIRY_CH					= 212,						//���߾����������������
	QFONT_PMD_SHORTFAIRY_EN					= 213,						//���߾���������������塣

	QFONT_CONNECT_STAT_DLG_CH				= 214,						//����״̬�Ի�������
	QFONT_CONNECT_STAT_DLG_EN				= 215,						//����״̬�Ի���Ӣ��
	QFONT_CONNECT_STAT_DLG_BOLD_CH			= 216,						//����״̬�Ի������Ĵ���
	QFONT_CONNECT_STAT_DLG_BOLD_EN			= 217,						//����״̬�Ի���Ӣ�Ĵ���

	QFONT_LOGIN_STAT_DLG_CH					= 218,						//��¼״̬�Ի�������
	QFONT_LOGIN_STAT_DLG_EN					= 219,						//��¼״̬�Ի���Ӣ��
	QFONT_LOGIN_STAT_DLG_BOLD_CH			= 220,						//��¼״̬�Ի������Ĵ���
	QFONT_LOGIN_STAT_DLG_BOLD_EN			= 221,						//��¼״̬�Ի���Ӣ�Ĵ���

	//Ŀǰϵͳ���õ�һЩ����
	QFONT_SYS_COMM							= 2000,						//��ͨ����	system
	QFONT_SYS_SMALL							= 2001,						//С����
	QFONT_SYS_SYSTEM						= QFONT_SYS_COMM,			//SYSTEM
	QFONT_SYS_SIMSUN_12						= 2020,						//����12
	QFONT_SYS_SIMSUN_10_5					= 2021,						//����10.5
	QFONT_SYS_SIMSUN_9						= 2022,						//����9
	QFONT_SYS_SIMSUN_9B						= 2023,						//����9����
	QFONT_SYS_KAITI_14						= 2040,						//����14
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






	//�����Ƕ�Ӧ��Ĭ�����塣

	//����Ĭ�����塣
	QFONT_DEF_RPT_CONTENT_CH				= QFONT_SYS_KAITI_15,			//������������Ĭ������
	QFONT_DEF_RPT_CONTENT_EN				= QFONT_SYS_ARIAL_12B,			//������������Ĭ������
	QFONT_DEF_RPT_TITLE_CH					= QFONT_DEF_RPT_CONTENT_CH,		//����Ĭ�ϱ�������Ĭ������
	QFONT_DEF_RPT_TITLE_EN					= QFONT_DEF_RPT_CONTENT_EN,		//����Ĭ�ϱ�������Ĭ������	
	QFONT_DEF_RPT_STAT_CH					= QFONT_DEF_RPT_CONTENT_CH,		//����Ĭ��ͳ������Ĭ������
	QFONT_DEF_RPT_STAT_EN					= QFONT_DEF_RPT_CONTENT_EN,		//����Ĭ��ͳ������Ĭ������
	QFONT_DEF_MSORTRPT_CONTENT_CH			= QFONT_RPT_CONTENT_CH,			//�ۺ�����������������Ĭ�����塣
	QFONT_DEF_MSORTRPT_CONTENT_EN			= QFONT_RPT_CONTENT_EN,			//�ۺ�����������������Ĭ�����塣
	QFONT_DEF_RPT_RPT_SHORTFAIRY			= QFONT_SYS_SIMSUN_9,			//�����ж��߾���Ĭ�����塣

	//��Ϣ��Ĭ�����塣
	QFONT_DEF_INFO_COMMNAME					= QFONT_SYS_SIMSUN_12,			//��Ϣ����Ʒ����Ĭ�����塣
	QFONT_DEF_INFO_COMMCODE					= QFONT_SYS_NEWROMAN_16,		//��Ϣ����Ʒ����Ĭ�����塣
	QFONT_DEF_INFOCOL_CH					= QFONT_DEF_RPT_CONTENT_CH,		//��Ϣ������Ĭ������
	QFONT_DEF_INFOCOL_EN					= QFONT_DEF_RPT_CONTENT_EN,		//��Ϣ������Ĭ������
	QFONT_DEF_INFOCOL_MMP_CH				= QFONT_DEF_INFOCOL_CH,			//��Ϣ������������Ĭ��
	QFONT_DEF_INFOCOL_MMP_EN				= QFONT_DEF_INFOCOL_EN,			//��Ϣ��������������Ĭ��
	QFONT_DEF_INFOCOL_CANCEL_CH				= QFONT_DEF_INFOCOL_CH,			//��Ϣ����������Ĭ������
	QFONT_DEF_INFOCOL_CANCEL_EN				= QFONT_DEF_INFOCOL_EN,			//��Ϣ����������Ĭ������
	QFONT_DEF_INFOCOL_CANCEL_TIME_CH		= QFONT_DEF_INFOCOL_CH,			//��Ϣ������ʱ������Ĭ������		
	QFONT_DEF_INFOCOL_CANCEL_TIME_EN		= QFONT_DEF_INFOCOL_EN,			//��Ϣ������ʱ������Ĭ������
	QFONT_DEF_INFOCOL_CONTRACT_CH			= QFONT_DEF_INFOCOL_CH,			//��Ϣ���������Ĭ������
	QFONT_DEF_INFOCOL_CONTRACT_EN			= QFONT_DEF_INFOCOL_EN,			//��Ϣ���������Ĭ������
	QFONT_DEF_INFOCOL_TICK_CH				= QFONT_DEF_INFOCOL_CH,			//��Ϣ����������Ĭ������
	QFONT_DEF_INFOCOL_TICK_EN				= QFONT_DEF_INFOCOL_EN,			//��Ϣ����������Ĭ������
	QFONT_DEF_INFOCOL_FINA_CH				= QFONT_DEF_INFOCOL_CH,			//��Ϣ��������Ĭ������
	QFONT_DEF_INFOCOL_FINA_EN				= QFONT_DEF_INFOCOL_EN,			//��Ϣ��������Ĭ������
	QFONT_DEF_INFOCOL_WJL_CH				= QFONT_DEF_INFOCOL_CH,			//��Ϣ��ί������������Ĭ������
	QFONT_DEF_INFOCOL_WJL_EN				= QFONT_DEF_INFOCOL_EN,			//��Ϣ��ί������������Ĭ������
	QFONT_DEF_INFOCOL_CONTRIBUTE_CH			= QFONT_DEF_INFOCOL_CH,			//��Ϣ�����׶�����Ĭ������
	QFONT_DEF_INFOCOL_CONTRIBUTE_EN			= QFONT_DEF_INFOCOL_EN,			//��Ϣ�����׶�����Ĭ������
	QFONT_DEF_INFOCOL_TOP_CH				= QFONT_DEF_INFOCOL_CH,			//��Ϣ��������Ĭ������
	QFONT_DEF_INFOCOL_TOP_EN				= QFONT_DEF_INFOCOL_EN,			//��Ϣ��������Ĭ������
	QFONT_DEF_INFOCOL_IDX_CH				= QFONT_DEF_INFOCOL_CH,			//��Ϣ��ָ����Ĭ������
	QFONT_DEF_INFOCOL_IDX_EN				= QFONT_DEF_INFOCOL_EN,			//��Ϣ��ָ����Ĭ������
	QFONT_DEF_INFOCOL_WJL_TIME_CH			= QFONT_SYS_MSSANSSERIF_8,		//��Ϣ��ί��������ʱ����������
	QFONT_DEF_INFOCOL_WJL_TIME_EN			= QFONT_SYS_MSSANSSERIF_8,		//��Ϣ��ί��������ʱ����������
	QFONT_DEF_INFOCOL_PRICE_CH				= QFONT_DEF_INFOCOL_CH,			//��Ϣ��������Ĭ������
	QFONT_DEF_INFOCOL_PRICE_EN				= QFONT_DEF_INFOCOL_EN,			//��Ϣ��������Ĭ������

	//���ƺͼ�������Ĭ�����塣
	QFONT_DEF_AXIS							= QFONT_SYS_MSSANSSERIF_8,		//���ƻ�����������Ĭ�����塣
	QFONT_DEF_AXIS_CH						= QFONT_SYS_MSSANSSERIF_8,		//���ƻ���������������Ĭ�����塣
	QFONT_DEF_AXIS_EN						= QFONT_SYS_MSSANSSERIF_8,		//���ƻ���������������Ĭ�����塣
	QFONT_DEF_RESULT						= QFONT_SYS_MSSANSSERIF_8,		//���ƻ�������Ľ����Ĭ�����塣
	QFONT_DEF_RESULT_CH						= QFONT_SYS_MSSANSSERIF_8,		//���ƻ�������Ľ��������Ĭ�����塣
	QFONT_DEF_RESULT_EN						= QFONT_SYS_MSSANSSERIF_8,		//���ƻ�������Ľ��������Ĭ�����塣
	QFONT_DEF_IDX_DATETIME_CH				= QFONT_SYS_MSSANSSERIF_8,		//ָ��ʱ������Ĭ������
	QFONT_DEF_IDX_DATETIME_EN				= QFONT_SYS_MSSANSSERIF_8,		//ָ��ʱ������Ĭ������
	QFONT_DEF_IDX_CURSOR_CH					= QFONT_SYS_MSSANSSERIF_8,		//ָ�껭���α�����Ĭ������
	QFONT_DEF_IDX_CURSOR_EN					= QFONT_SYS_MSSANSSERIF_8,		//ָ�껭���α�����Ĭ������


	//�������ɻ�������
	QFONT_DEF_SC_WEIGHT_CH					= QFONT_DEF_INFOCOL_CH,			//����ȨϢ��������Ĭ������
	QFONT_DEF_SC_WEIGHT_EN					= QFONT_DEF_INFOCOL_EN,			//����ȫϵ��������Ĭ������
	QFONT_DEF_SC_WEIGHT_TITLE_CH			= QFONT_DEF_INFOCOL_CH,			//����ȨϢ���ϱ�������Ĭ������
	QFONT_DEF_SC_WEITHT_TITLE_EN			= QFONT_DEF_INFOCOL_EN,			//����ȫϵ���ϱ�������Ĭ������
	QFONT_DEF_SC_SMALL_HISTREND_INFO_CH		= QFONT_DEF_INFOCOL_CH,			//������ʷ������Ϣ����Ĭ������
	QFONT_DEF_SC_SMALL_HISTREND_INFO_EN		= QFONT_DEF_INFOCOL_EN,			//������ʷ������Ϣ����Ĭ������
	QFONT_DEF_SC_GAIN_INFO_CH				= QFONT_DEF_INFOCOL_CH,			//���ɴ�������Ϣ����Ĭ������
	QFONT_DEF_SC_GAIN_INFO_EN				= QFONT_DEF_INFOCOL_EN,			//���ɴ�������Ϣ����Ĭ������
	QFONT_DEF_SC_PRICE_CH					= QFONT_DEF_INFOCOL_CH,			//�������۷�������Ĭ������
	QFONT_DEF_SC_PRICE_EN					= QFONT_DEF_INFOCOL_EN,			//�������۷�������Ĭ������
	QFONT_DEF_SC_SEATSERIAL_CH				= QFONT_DEF_INFOCOL_CH,			//���ɾ�����λ����Ĭ������
	QFONT_DEF_SC_SEATSERIAL_EN				= QFONT_DEF_INFOCOL_EN,			//���ɾ�����λ����Ĭ������
	QFONT_DEF_SC_GAIN_MMP_CH				= QFONT_DEF_INFOCOL_CH,			//���ɴ���������������Ĭ������
	QFONT_DEF_SC_GAIN_MMP_EN				= QFONT_DEF_INFOCOL_EN,			//���ɴ���������������Ĭ������
	QFONT_DEF_SC_ORDERLIST_CH				= QFONT_DEF_INFOCOL_CH,			//����������������Ĭ������
	QFONT_DEF_SC_ORDERLIST_EN				= QFONT_DEF_INFOCOL_EN,			//����������������Ĭ������
	QFONT_DEF_SC_ORDERLIST_HINT_CH			= QFONT_SYS_SMALL,				//������������Hint����Ĭ������
	QFONT_DEF_SC_ORDERLIST_HINT_EN			= QFONT_SYS_SMALL,				//������������Hint����Ĭ������
	QFONT_DEF_SC_PRICELIST_CH				= QFONT_SYS_MSSANSSERIF_8,		//�������۷����б�����Ĭ������
	QFONT_DEF_SC_PRICELIST_EN				= QFONT_SYS_MSSANSSERIF_8,		//�������۷����б�����Ĭ������
	QFONT_DEF_SC_SEATSERIAL_SMALLBTN_CH		= QFONT_SYS_SMALL,				//���ɾ�����λС��ť����Ĭ������
	QFONT_DEF_SC_SEATSERIAL_SMALLBTN_EN		= QFONT_SYS_SMALL,				//���ɾ�����λС��ť����Ĭ������


	//�����ǩĬ�����塣
	QFONT_DEF_TABPAGE						= QFONT_SYS_TAHMOA_8,			//��ǩĬ�����塣
	QFONT_DEF_TABPAGE_CH					= QFONT_SYS_TAHMOA_8,
	QFONT_DEF_TABPAGE_EN					= QFONT_SYS_TAHMOA_8,
	QFONT_DEF_RPT_TAB_LEFT_CH				= QFONT_DEF_TABPAGE_CH,			//������tab���ǩĬ����������
	QFONT_DEF_RPT_TAB_LEFT_EN				= QFONT_DEF_TABPAGE_EN,			//������tab���ǩĬ����������
	QFONT_DEF_RPT_TAB_BOT_CH				= QFONT_DEF_TABPAGE_CH,			//������tab�±�ǩĬ����������
	QFONT_DEF_RPT_TAB_BOT_EN				= QFONT_DEF_TABPAGE_EN,			//������tabС��ǩĬ����������
	QFONT_DEF_SC_TAB_LEFT_CH				= QFONT_DEF_TABPAGE_CH,			//������tab���ǩĬ����������
	QFONT_DEF_SC_TAB_LEFT_EN				= QFONT_DEF_TABPAGE_EN,			//������tab���ǩĬ����������
	QFONT_DEF_SC_TAB_BOT_CH					= QFONT_DEF_TABPAGE_CH,			//������tab�±�ǩĬ����������
	QFONT_DEF_SC_TAB_BOT_EN					= QFONT_DEF_TABPAGE_EN,			//������tab�±�ǩĬ����������
	QFONT_DEF_MC_TAB_LEFT_CH				= QFONT_DEF_TABPAGE_CH,			//�����tab���ǩĬ����������
	QFONT_DEF_MC_TAB_LEFT_EN				= QFONT_DEF_TABPAGE_EN,			//�����tab���ǩĬ����������
	QFONT_DEF_MC_TAB_BOT_CH					= QFONT_DEF_TABPAGE_CH,			//�����tab�±�ǩĬ����������
	QFONT_DEF_MC_TAB_BOT_EN					= QFONT_DEF_TABPAGE_EN,			//�����tab�±�ǩĬ����������
	QFONT_DEF_SC_MIX_TAB_LEFT_CH			= QFONT_DEF_TABPAGE_CH,			//�����Ϲ������������л�ϱ�ǩ����Ĭ������
	QFONT_DEF_SC_MIX_TAB_LEFT_EN			= QFONT_DEF_TABPAGE_EN,			//�����Ϲ������������л�ϱ�ǩ����Ĭ������

	//��������Ĭ������
	QFONT_DEF_RIGHT_TITLE_CH				= QFONT_DEF_INFO_COMMNAME,		//�Ҳ�����Ʊ��������
	QFONT_DEF_RIGHT_TITLE_NUM				= QFONT_DEF_INFO_COMMCODE,		//�Ҳ�����Ʊ��������
	QFONT_DEF_RIGHT_TITLE_EN				= QFONT_RIGHT_TITLE_NUM,
	QFONT_DEF_HINT_TITLE					= QFONT_SYS_TAHMOA_8,		//hint��������塣
	QFONT_DEF_HINT_CONTENT					= QFONT_SYS_TAHMOA_8,		//hint�������塣
	QFONT_DEF_OWNEDBLOCK					= QFONT_SYS_SIMSUN_9,
	QFONT_DEF_IDXBAR_NAME					= QFONT_SYS_SIMSUN_12,			//ָ������Ʒ���ƺ���������
	QFONT_DEF_IDXBAR_NAME_CH				= QFONT_DEF_IDXBAR_NAME,		//ָ������Ʒ���ƺ�������������
	QFONT_DEF_IDXBAR_NAME_EN				= QFONT_SYS_SYSTEM,				//ָ������Ʒ���ƺ��������ĺ���������
	QFONT_DEF_SMARTKB_CH					= QFONT_SYS_TAHMOA_8,			//���ܼ�������Ĭ������
	QFONT_DEF_SMARTKB_EN					= QFONT_SYS_TAHMOA_8,			//���ܼ�������Ĭ������
	QFONT_DEF_WORKTABLE_CH					= QFONT_SYS_SIMSUN_10_5,		//����̨����Ĭ�����壬
	QFONT_DEF_WORKTABLE_EN					= QFONT_SYS_SYSTEM,				//����̨����Ĭ�����壬
	QFONT_DEF_PMD_SHORTFAIRY_CH				= QFONT_SYS_SIMSUN_12,			//���߾����������������
	QFONT_DEF_PMD_SHORTFAIRY_EN				= QFONT_SYS_SYSTEM,				//���߾���������������塣

	QFONT_DEF_CONNECT_STAT_DLG_CH			= QFONT_SYS_SIMSUN_9,			//����״̬�Ի���Ĭ������
	QFONT_DEF_CONNECT_STAT_DLG_EN			= QFONT_SYS_TAHMOA_8,			//����״̬�Ի���Ĭ��Ӣ��
	QFONT_DEF_CONNECT_STAT_DLG_BOLD_CH		= QFONT_SYS_SIMSUN_9B,			//����״̬�Ի���Ĭ�����Ĵ���
	QFONT_DEF_CONNECT_STAT_DLG_BOLD_EN		= QFONT_SYS_TAHMOA_8B,			//����״̬�Ի���Ĭ��Ӣ�Ĵ���

	QFONT_DEF_LOGIN_STAT_DLG_CH				= QFONT_SYS_SIMSUN_9,			//��¼״̬�Ի���Ĭ������
	QFONT_DEF_LOGIN_STAT_DLG_EN				= QFONT_SYS_TAHMOA_8,			//��¼״̬�Ի���Ĭ��Ӣ��
	QFONT_DEF_LOGIN_STAT_DLG_BOLD_CH		= QFONT_SYS_SIMSUN_9B,			//��¼״̬�Ի���Ĭ�����Ĵ���
	QFONT_DEF_LOGIN_STAT_DLG_BOLD_EN		= QFONT_SYS_TAHMOA_8B,			//��¼״̬�Ի���Ĭ��Ӣ�Ĵ���
};

#endif
