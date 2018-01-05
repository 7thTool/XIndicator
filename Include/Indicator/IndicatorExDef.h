#ifndef _H_INDICATOREXDEF_H_
#define _H_INDICATOREXDEF_H_

#include <DataStd.h>
#include <FaceDef.h>

#include "IndicatorDef.h"

#pragma pack(1) 

//����Ĳ�����Ӱ�������
typedef struct tagInputValue
{
	wchar_t name[MAX_INDICATOR_NAME];
	wchar_t value[MAX_INDICATOR_STRING];
	int number:1;
	int digits:4;
	int visible:1;
	int reserved:26;
}INPUTVALUE,*PINPUTVALUE;
typedef struct tagInputInfo
{
	int count;
	INPUTVALUE input[MAX_INPUT_VALUE];
}INPUTINFO,*PINPUTINFO;

//REFLINE
typedef struct tagRefline
{
	wchar_t name[MAX_INDICATOR_NAME];
	int type:4;				//ENUM_REFLINE_TYPE
	int width:4;			//�߿�
	int style:4;			//INDICATOR_LINE_STYLE
	int digits:4;			//ָ�꾫��,���ָ���˾��ȾͲ�ʹ����Ʒ��digits
	COLORREF color;			//ָ����ɫ
	double dvalue;			//�ο�ֵ
}REFLINE,*PREFLINE;

typedef struct tagIndexInfo
{
	wchar_t name[MAX_INDICATOR_NAME];
	int type:4;				//INDICATOR_INDEX_TYPE
	int shift:8;			//ָ��ƫ��
	int begin:8;			//ָ�꿪ʼ
	int draw:4;				//INDICATOR_DRAW_TYPE
	int line:4;				//INDICATOR_LINE_TYPE
	int next:4;				//���߹���ָ����
	int :0;
	int digits:4;			//ָ�꾫��,���ָ���˾��ȾͲ�ʹ����Ʒ��digits
	int width:4;			//�߿�
	COLORREF color;			//ָ����ɫ
	//double min_value;		//ָ�����ֵ
	//double max_value;		//ָ����Сֵ
	//double base_value;	//��׼ֵ
	//int level_count:8;	//ˮƽ����Ŀ
	//int level_style:24;	//ˮƽ�߷��
	//COLORREF level_color;	//ˮƽ����ɫ
}INDEXINFO,*PINDEXINFO;

typedef struct tagIndexValue
{
	union
	{
		double dvalue;
		char value[8];
	};
}INDEXVALUE,*PINDEXVALUE;

typedef struct tagCalcData
{
	COMREF object;			//��ǰ��Ʒ
	int period;				//��ǰ����Ʒ�ֵ�����,����Ϊ��λ������1��=1 1����=60 5����=300......��
	int digits;				//��ǰ����Ʒ�ֵļ۸�ȷ��

	int count;				//K����Ŀ
	BAR* bars;				//K������
	BAR* original_bars;		//K��ԭʼ����
	BAR* dw_bars;			//K�߳���Ȩ����

	int weight_count;		//ȨϢ��Ŀ
	WEIGHT* weight;			//ȨϢ
	ENUM_DWTYPE dwtype;		//��Ȩ����
	unsigned long dwdate;   //ָ��ȨϢ��

	double field[INDICATOR_FIELD_MAX];//��̬����
}CALCDATA,*PCALCDATA;

//context
typedef struct tagIndicatorContextInfo
{
	wchar_t name[MAX_INDICATOR_NAME];						//ָ������
	unsigned long type:8;
	unsigned long style:24;									//���
	INPUTINFO input;										//������Ϣ,������ʾ��Ϣ��Ŀ����û��޸ĵļ�����Ϣ
	int tradeable:1;										//�Ƿ���Խ���
	int shift:7;											//ָ��ƫ��
	int refcount:24;										//�ο�����Ŀ
	double refline[MAX_INDICATOR_REFLINE];					//�ο���
	int count;												//index����
	INDEXINFO index[MAX_INDICATOR_INDEX];					//index��Ϣ
}INDICATORCONTEXTINFO,*PINDICATORCONTEXTINFO;

typedef struct tagIndicatorCalcContextInfo
{
	COMREF object;											//��ǰ��Ʒ
	int period;												//��ǰ����Ʒ�ֵ�����,����Ϊ��λ������1��=1 1����=60 5����=300......��

	ENUM_DWTYPE dwtype;										//��Ȩ����
	unsigned long dwdate;									//ָ��ȨϢ��

	voidptr dataptr;										//�����������
}INDICATORCALCCONTEXTINFO,*PINDICATORCALCCONTEXTINFO;

typedef struct tagIndicatorCalcInfo
{
	int count;												//ָ������Ŀ
	int counted;											//�Ѿ�����ָ����Ŀ
	double* index[MAX_INDICATOR_INDEX];						//ָ��������ָ�룬���MAX_INDICATOR_INDEX��ָ��
}INDICATORCALCINFO,*PINDICATORCALCINFO;

#pragma pack()

#if defined(__cplusplus)
extern "C" {
#endif//

//////////////////////////////////////////////////////////////////////////
//C�ӿ�
typedef long (*pfninit)(PINDICATORCONTEXTINFO ctx);
typedef long (*pfncalc)(PINDICATORCONTEXTINFO ctx, PINDICATORCALCCONTEXTINFO clx, PINDICATORCALCINFO clc);
typedef void (*pfndeinit)(PINDICATORCONTEXTINFO ctx);
/*Cָ����Ҫʵ��һ�½ӿ�
int init(const PIN_INDICATORINFO in, POUT_INDICATORINFO out);
void deinit();
int	calc(PINDICATORCALCINFO in);*/

#if defined(__cplusplus)
}

#endif//

#endif//_H_INDICATOREXDEF_H_

