#include "BasicSceneImpl.h"

#include "pch.h"

namespace MikuEngine
{
	void BasicSceneImpl::Update( double dt )
	{}

	void BasicSceneImpl::Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff )
	{
		m_GO.Render( renderer, appStuff, m_SceneStuff );
	}

	void BasicSceneImpl::RenderImGui()
	{
		m_GO.RenderImGui();
		m_SceneStuff.camera.RenderImGui();
	}
}