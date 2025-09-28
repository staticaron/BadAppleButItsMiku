#include "Rendering/BasicQuad.h"

#include "pch.h"

namespace MikuEngine
{
	BasicQuad::BasicQuad() : m_VB( nullptr, sizeof( BasicVertex ) * 4 ), m_IB( nullptr, sizeof( unsigned int ) * 6 )
	{
		m_VBL.Push<float>( 3 );
		m_VBL.Push<float>( 4 );
		m_VA.AddBuffer( m_VB, m_VBL );

		m_Shader.LoadFromFile( RESOURCE_DIR "shaders/base.shader" );

		m_DefaultIndices = {
			0, 1, 2,
			2, 3, 0
		};

		m_DefaultVerts = {
			BasicVertex{ { -0.5f, -0.5f, 0.0f }, {1.0f, 1.0f, 1.0f, 1.0f } },
			BasicVertex{ {  0.5f, -0.5f, 0.0f }, {1.0f, 1.0f, 1.0f, 1.0f } },
			BasicVertex{ {  0.5f,  0.5f, 0.0f }, {1.0f, 1.0f, 1.0f, 1.0f } },
			BasicVertex{ { -0.5f,  0.5f, 0.0f }, {1.0f, 1.0f, 1.0f, 1.0f } }
		};

		m_VB.PutData( m_DefaultVerts.data(), sizeof( m_DefaultVerts ) );
		m_IB.PutData( m_DefaultIndices.data(), m_DefaultIndices.size() );
	}

	void BasicQuad::Render( const Renderer& renderer )
	{
		renderer.Draw( m_VA, m_IB, m_Shader );
	}

	const std::array<unsigned int, 6>& BasicQuad::GetDefaultIndices() const
	{
		return m_DefaultIndices;
	}

	const std::array<BasicVertex, 4>& BasicQuad::GetDefaultVertices() const
	{
		return m_DefaultVerts;
	}
}