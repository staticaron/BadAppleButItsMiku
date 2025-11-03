#pragma once

#include "Managers/AudioManager.h"
#include "Managers/ImguiManager.h"
#include "Managers/TextureManager.h"

namespace MikuEngine
{
	struct MIKU_API ApplicationLevelStuff
	{
		TextureManager textureManager;
		ImguiManager imguiManager;
		AudioManager audioManager;
	};
} // namespace MikuEngine