#include "BasicSceneImpl.h"

#include "pch.h"

namespace MikuEngine
{
	BasicSceneImpl::BasicSceneImpl() : m_VideoRenderer( 6400, "miku" ) {}

	void BasicSceneImpl::Update( double dt )
	{
		m_VideoRenderer.Update( dt );
	}

	void BasicSceneImpl::Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff )
	{
		m_VideoRenderer.Render( renderer, appStuff, m_SceneStuff );
	}

	void BasicSceneImpl::RenderImGui()
	{
		m_GO.RenderImGui();
		m_SceneStuff.camera.RenderImGui();
		m_VideoRenderer.RenderImGui();
	}
}