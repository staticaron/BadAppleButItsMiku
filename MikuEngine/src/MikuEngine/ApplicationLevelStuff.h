#pragma once

#include "Managers/ImguiManager.h"
#include "Managers/TextureManager.h"

namespace MikuEngine
{
	struct MIKU_API ApplicationLevelStuff
	{
		TextureManager textureManager;
		ImguiManager imguiManager;
	};
}