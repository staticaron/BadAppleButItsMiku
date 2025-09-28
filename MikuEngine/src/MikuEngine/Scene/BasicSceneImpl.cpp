#include "BasicSceneImpl.h"

namespace MikuEngine
{
	void BasicSceneImpl::Update( double dt )
	{}

	void BasicSceneImpl::Render( const Renderer& renderer )
	{
		spdlog::info( "Rendering!" );
	}

	void BasicSceneImpl::RenderImGui()
	{
		ImGui::Begin( "Basic Scene Impl" );
		ImGui::End();

		ImGui::ShowDemoWindow();
	}
}