#include "Rendering/BasicQuad.h"

#include "pch.h"

namespace MikuEngine
{
	BasicQuad::BasicQuad() : m_VB( nullptr, sizeof( float ) * 12 ), m_IB( nullptr, 6 )
	{
		std::array<unsigned int, 6> indices = {
			0, 1, 2,
			2, 3, 0
		};

		std::array<float, 12> verts = {
			0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f
		};

		m_VB.PutData( verts.data(), sizeof( float ) * verts.size() );
		m_IB.PutData( indices.data(), indices.size() );

		m_VBL.Push<float>( 3 );
		m_VA.AddBuffer( m_VB, m_VBL );

		m_Shader.LoadFromFile( RESOURCE_DIR "shaders/base.shader" );
		m_Shader.Bind();
	}
}