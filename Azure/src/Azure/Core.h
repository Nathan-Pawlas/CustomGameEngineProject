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

#define BIT(x) (1 << x)