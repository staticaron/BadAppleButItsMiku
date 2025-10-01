#include "BasicSceneImpl.h"

namespace MikuEngine
{
	BasicSceneImpl::BasicSceneImpl()
	{

	}

	void BasicSceneImpl::Update( double dt )
	{}

	void BasicSceneImpl::Render( const Renderer& renderer )
	{
		m_Quad.Render( renderer );
	}

	void BasicSceneImpl::RenderImGui()
	{
		m_Quad.RenderImGui();
	}
}