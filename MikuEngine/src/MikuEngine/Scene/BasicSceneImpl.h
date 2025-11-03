#pragma once

#include "ApplicationLevelStuff.h"
#include "Core.h"
#include "GameObject.h"
#include "Scene/Scene.h"
#include "Scene/SceneStuff.h"
#include "Video/VideoRenderer.h"

namespace MikuEngine
{
	class MIKU_API BasicSceneImpl : public Scene
	{
	  public:
		BasicSceneImpl();
		~BasicSceneImpl() = default;

		void Update( ApplicationLevelStuff& appStuff, double dt ) override;
		void Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff ) override;
		void RenderImGui( ApplicationLevelStuff& appStuff ) override;

	  private:
		SceneStuff m_SceneStuff;

		VideoRenderer m_VideoRenderer;

		GameObject m_GO;
	};
} // namespace MikuEngine