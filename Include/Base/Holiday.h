#ifndef _H_BASE_HOLIDAY_H_
#define _H_BASE_HOLIDAY_H_

#include "Base.h"
#include <XLib/XTime.h>

class BASE_API QHoliday
{
protected:
	typedef std::set<unsigned long> HolidaySet;
	typedef map<unsigned char, HolidaySet> Exch2HolidaySet;
	Exch2HolidaySet m_Exch2Holidays;
public:
	QHoliday();
	~QHoliday();

	long Load(LPCTSTR lpszFile);
	void Clear();

	bool IsHoliday(const unsigned long Date, const COMREF *pCommodity = NULL);
};

//////////////////////////////////////////////////////////////////////////

class BASE_API QTime : public Time
{
public:
	static void InitHoliday(LPCTSTR lpszFile);
public:
	QTime();
	QTime( __time64_t time );
	QTime( int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec, int nDST = -1 );
	QTime( WORD wDosDate, WORD wDosTime, int nDST = -1 );
	QTime( const SYSTEMTIME& st, int nDST = -1 );
	QTime( const FILETIME& ft, int nDST = -1 );
#ifdef __oledb_h__
	QTime( const DBTIMESTAMP& dbts, int nDST = -1 );
#endif
	QTime( int Date, int Time = 0);

	bool IsWeekend();
	bool IsHoliday(const COMREF *pCommodity = NULL);

	QTime& OffsetDay(int nOffset, const COMREF *pCommodity = NULL);
	QTime& ToNextDay(const COMREF *pCommodity = NULL);
	QTime& ToPrevDay(const COMREF *pCommodity = NULL);
	
	int GetYYMMDD();
	int GetHHMMSS();
};

#endif//_H_BASE_HOLIDAY_H_
