#pragma once

#include "ApplicationLevelStuff.h"
#include "Core.h"
#include "GameObject.h"
#include "Scene/Scene.h"
#include "Scene/SceneStuff.h"

namespace MikuEngine
{
	class MIKU_API BasicSceneImpl : public Scene
	{
	public:
		BasicSceneImpl() = default;
		~BasicSceneImpl() = default;

		void Update( double dt ) override;
		void Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff ) override;
		void RenderImGui() override;

	private:
		SceneStuff m_SceneStuff;

		GameObject m_GO;
	};
}