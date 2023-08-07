#pragma once

#ifdef AZ_PLATFORM_WINDOWS
	#ifdef AZ_BUILD_DLL
		#define AZURE_API __declspec(dllexport)
	#else
		#define AZURE_API __declspec(dllimport)
#endif // AZ_BUILD_DLL
#else
	#error AZURE is currently Windows only!
#endif

#ifdef AZ_ENABLE_ASSERTS
	#define AZ_ASSERT(x, ...) { if(!(x)) { AZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AZ_CORE_ASSERT(x, ...) { if(!(x)) { AZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AZ_ASSERT(x, ...)
	#define AZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)