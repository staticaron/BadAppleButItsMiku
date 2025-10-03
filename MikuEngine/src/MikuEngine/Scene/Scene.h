#pragma once

#include "ApplicationLevelStuff.h"
#include "Rendering/Renderer.h"
#include "Scene/SceneStuff.h"

namespace MikuEngine
{
	class Scene
	{
	public:
		Scene() = default;
		virtual ~Scene() = default;

		virtual void Update( double dt ) {};
		virtual void Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff ) {};
		virtual void RenderImGui() {};

	private:
	};
}