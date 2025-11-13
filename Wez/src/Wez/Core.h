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

#ifdef WEZ_DEBUG
#define WEZ_ENABLE_ASSERTS
#endif

#ifdef WEZ_ENABLE_ASSERTS
#define WEZ_ASSERT(x, ...) { if(!(x)) { WEZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define WEZ_CORE_ASSERT(x, ...) { if(!(x)) { WEZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define WEZ_ASSERT(x, ...)
#define WEZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define WEZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)