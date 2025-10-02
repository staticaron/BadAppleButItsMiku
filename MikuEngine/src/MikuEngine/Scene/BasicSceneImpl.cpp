#include "BasicSceneImpl.h"

namespace MikuEngine
{
	void BasicSceneImpl::Update( double dt )
	{}

	void BasicSceneImpl::Render( const Renderer& renderer )
	{
		m_GO.Render( renderer, m_SceneStuff );
	}

	void BasicSceneImpl::RenderImGui()
	{
		m_GO.RenderImGui();
		m_SceneStuff.camera.RenderImGui();
	}
}