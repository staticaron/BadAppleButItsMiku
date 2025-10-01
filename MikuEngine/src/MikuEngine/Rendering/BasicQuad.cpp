#include "Rendering/BasicQuad.h"

#include "pch.h"

namespace MikuEngine
{
	BasicQuad::BasicQuad() : m_VB( nullptr, sizeof( float ) * 32 ), m_IB( nullptr, 6 )
	{
		std::array<unsigned int, 6> indices = {
			0, 1, 2,
			2, 3, 0
		};

		std::array<float, 28> verts = {
			-1.0f, -1.0f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
			 1.0f, -1.0f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
			 1.05f, 1.0f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,
			-1.0f,  1.0f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f
		};

		m_VBL.Push<float>( 3 );
		m_VBL.Push<float>( 4 );
		m_VA.AddBuffer( m_VB, m_VBL );

		m_VB.PutData( verts.data(), sizeof( float ) * verts.size() );
		m_IB.PutData( indices.data(), indices.size() );

		m_Shader.LoadFromFile( RESOURCE_DIR "shaders/base.shader" );
		m_Shader.Bind();
	}

	void BasicQuad::Render( const Renderer& renderer )
	{
		// m_Shader.SetUniform( "u_MVP", sceneLevelValues.camera.GetViewProjectionMatrix() );
		renderer.Draw( m_VA, m_IB, m_Shader );
	}

	void BasicQuad::RenderImGui()
	{
		ImGui::Begin( "Quad Properties" );

		ImGui::SeparatorText( "Transform" );
		ImGui::DragFloat3( "Position", &m_Position[0] );
		ImGui::DragFloat3( "Rotation Axis", &m_RotationAxis[0] );
		ImGui::DragFloat3( "Scale", &m_Scale[0] );

		ImGui::End();
	}
}