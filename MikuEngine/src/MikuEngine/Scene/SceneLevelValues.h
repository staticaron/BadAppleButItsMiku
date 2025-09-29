#pragma once

#include "Camera/Camera.h"

namespace MikuEngine
{
	struct MIKU_API SceneLevelValues
	{
		const Camera& GetCamera() const { return camera; }

		Camera& camera;
	};
}