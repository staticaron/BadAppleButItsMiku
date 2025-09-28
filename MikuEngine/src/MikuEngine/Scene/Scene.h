#pragma once

#include "Rendering/Renderer.h"

namespace MikuEngine
{
	class Scene
	{
	public:
		Scene() = default;
		virtual ~Scene() = default;

		virtual void Update( double dt ) {};
		virtual void Render( const Renderer& renderer ) {};
		virtual void RenderImGui() {};

	private:
	};
}