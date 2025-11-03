#pragma once

#ifdef ME_PLATFORM_WINDOWS
#ifdef ME_BUILD_DLL
#define MIKU_API __declspec(dllexport)
#else
#define MIKU_API __declspec(dllimport)
#endif
#else
#ifdef ME_BUILD_DLL
#define MIKU_API __attribute__((visibility("default")))
#else
#define MIKU_API
#endif
#endif
