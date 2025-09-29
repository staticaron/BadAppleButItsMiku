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
		SceneLevelValues values = { m_Camera };
		m_Quad.Render( renderer, values );
	}

	void BasicSceneImpl::RenderImGui()
	{
		m_Quad.RenderImGui();
	}
}