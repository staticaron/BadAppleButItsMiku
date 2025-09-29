#include "Rendering/BasicQuad.h"

#include "pch.h"

namespace MikuEngine
{
	BasicQuad::BasicQuad() : m_VB( nullptr, sizeof( BasicVertex ) * 4 ), m_IB( nullptr, 6 )
	{
		m_VBL.Push<float>( 3 );
		m_VA.AddBuffer( m_VB, m_VBL );

		m_Shader.LoadFromFile( RESOURCE_DIR "shaders/base.shader" );
		m_Shader.Bind();

		m_DefaultIndices = {
			0, 1, 2,
			2, 3, 0
		};

		m_DefaultVerts = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		m_IB.PutData( m_DefaultIndices.data(), m_DefaultIndices.size() );
		m_VB.PutData( m_DefaultVerts.data(), sizeof( float ) * m_DefaultVerts.size() );
	}

	void BasicQuad::Render( const Renderer& renderer, const SceneLevelValues& sceneLevelValues )
	{
		m_Shader.SetUniform( "u_MVP", glm::mat4( 1.0f ) );
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

	const std::array<unsigned int, 6>& BasicQuad::GetDefaultIndices() const
	{
		return m_DefaultIndices;
	}

	const std::array<float, 28>& BasicQuad::GetDefaultVertices() const
	{
		return m_DefaultVerts;
	}
}