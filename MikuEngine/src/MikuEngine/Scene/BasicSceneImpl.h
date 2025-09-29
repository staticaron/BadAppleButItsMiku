#pragma once

#include "Camera/Camera.h"
#include "Core.h"
#include "Rendering/BasicQuad.h"
#include "Scene/Scene.h"

namespace MikuEngine
{
	class MIKU_API BasicSceneImpl : public Scene
	{
	public:
		BasicSceneImpl();
		~BasicSceneImpl() = default;

		void Update( double dt ) override;
		void Render( const Renderer& renderer ) override;
		void RenderImGui() override;

	private:
		BasicQuad m_Quad;
		Camera m_Camera;
	};
}