#include "Rendering/BasicQuad.h"

#include "pch.h"

namespace MikuEngine
{
	BasicQuad::BasicQuad() : m_VB( nullptr, sizeof( float ) * 20 ), m_IB( nullptr, 6 )
	{
		m_VB.PutData( m_Verts.data(), sizeof( BasicVertex ) * m_Verts.size() );
		m_IB.PutData( m_Indices.data(), m_Indices.size() );

		m_VBL.Push<float>( 3 );
		m_VBL.Push<float>( 2 );
		m_VA.AddBuffer( m_VB, m_VBL );

		m_Shader.LoadFromFile( RESOURCE_DIR "shaders/base.shader" );
		m_Shader.Bind();
	}

	const std::array<unsigned int, 6>& BasicQuad::GetDefaultIndices()
	{
		return m_Indices;
	}

	const std::array<BasicVertex, 4>& BasicQuad::GetDefaultVertices()
	{
		return m_Verts;
	}

	std::array<BasicVertex, 4> BasicQuad::GetVertsFromDetails( const SceneStuff& sceneStuff, glm::vec3 position, glm::vec2 size )
	{
		std::array<BasicVertex, 4> verts;

		glm::mat4 translationMatrix = glm::translate( glm::mat4( 1.0f ), position );
		glm::mat4 scaleMatrix = glm::scale( glm::mat4( 1.0f ), glm::vec3( size, 1 ) );
		glm::mat4 modelMatrix = translationMatrix * scaleMatrix;

		glm::mat4 mvp = sceneStuff.camera.GetMVPFromModelMatrix( modelMatrix );

		for( int x = 0; x < GetDefaultVertices().size(); x++ )
		{
			auto updatedVert = GetDefaultVertices().at( x ).ApplyTransform( mvp );
			verts[x] = updatedVert;
		}

		return verts;
	}
}