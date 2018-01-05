#ifndef _H_INDICATOREX_H_
#define _H_INDICATOREX_H_

#include <DataStd.h>
#include <FaceDef.h>

#include "Indicator.h"
#include "XIndicatorEx.h"

//#if defined(__cplusplus)
//extern "C" {
//#endif//

//////////////////////////////////////////////////////////////////////////

//#endif//

//ÄÚ½¨º¯Êý

//#if defined(__cplusplus)
//}

//////////////////////////////////////////////////////////////////////////

//class TechView;

XINDICATOR_API int iTemplatesTotal();
XINDICATOR_API int iTemplateGet(int offset, wchar_t* str, int len);
XINDICATOR_API int iTemplateSelect(Objecter* pObject, LPCTSTR lpszTemplate);
XINDICATOR_API int iTemplateSelectDefault(Objecter* pObject);

//#endif//

#endif//_H_INDICATOREX_H_

