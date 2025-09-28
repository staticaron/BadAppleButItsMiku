#pragma once

#include "Core.h"
#include "Scene/Scene.h"

namespace MikuEngine
{
	class MIKU_API BasicSceneImpl : public Scene
	{
	public:
		void Update( double dt ) override;
		void Render( const Renderer& renderer ) override;
		void RenderImGui() override;

	private:
	};
}