#include "BasicSceneImpl.h"

#include "pch.h"

namespace MikuEngine
{
	BasicSceneImpl::BasicSceneImpl() : m_VideoRenderer( 6400, RESOURCE_DIR "videos/bad.mp4" )
	{
		m_VideoRenderer.Init();
	}

	void BasicSceneImpl::Update( ApplicationLevelStuff& appStuff, double dt )
	{
		m_VideoRenderer.Update( appStuff, dt );
		m_SceneStuff.camera.Update( dt );
	}

	void BasicSceneImpl::Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff )
	{
		m_VideoRenderer.Render( renderer, appStuff, m_SceneStuff );
	}

	void BasicSceneImpl::RenderImGui( ApplicationLevelStuff& appStuff )
	{
		m_GO.RenderImGui();
		m_SceneStuff.camera.RenderImGui();
		m_VideoRenderer.RenderImGui( appStuff );
	}
} // namespace MikuEngine