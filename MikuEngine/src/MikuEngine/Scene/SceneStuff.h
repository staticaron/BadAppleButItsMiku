#pragma once

#include "Camera/Camera.h"

namespace MikuEngine
{
	struct MIKU_API SceneStuff
	{
	public:
		SceneStuff() = default;
		~SceneStuff() = default;

		Camera camera;
	};
}