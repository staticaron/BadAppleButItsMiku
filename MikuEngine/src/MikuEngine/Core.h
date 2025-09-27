#pragma once

#include "pch.h"

#ifdef ME_PLATFORM_WINDOWS
#ifdef ME_BUILD_DLL
#define MIKU_API __declspec(dllexport)
#else
#define MIKU_API __declspec(dllimport)
#endif
#else
#error MikuEngine Only Supports Windows
#endif