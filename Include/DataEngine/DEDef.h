#ifndef _H_DATAENGINEDEF_H_
#define _H_DATAENGINEDEF_H_

#ifndef DE_DLL
#define DE_DLL
#endif//

#ifdef DE_DLL
#ifdef DE_EXPORTS
#define DE_API __declspec(dllexport)
#else
#define DE_API __declspec(dllimport)
#endif
#else
#ifdef DE_API
#undef DE_API
#endif//
#endif//

#ifndef DE_EXPORTS
#pragma comment(lib, "DataEngine.lib")
#endif//DE_EXPORTS


#endif//_H_DATAENGINEDEF_H_