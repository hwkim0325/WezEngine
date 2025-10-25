#pragma once


#ifdef WEZ_PLATFORM_WINDOWS
	#ifdef WEZ_BUILD_DLL
		#define WEZ_API __declspec(dllexport)
	#else
		#define WEZ_API __declspec(dllimport)
	#endif
#else
	#error Wez only support Windows!
#endif