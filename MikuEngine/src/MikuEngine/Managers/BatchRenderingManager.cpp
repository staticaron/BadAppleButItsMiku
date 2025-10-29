#include "BatchRenderingManager.h"

#include "pch.h"

namespace MikuEngine
{
	BatchRenderingManager::BatchRenderingManager( unsigned int maxParticleCount, std::string_view textureIdentifier ) : m_MaxParticleCount( maxParticleCount ), m_VB( nullptr, maxParticleCount * 4 * sizeof( BasicVertex ) ), m_IB( nullptr, maxParticleCount * 6 ), m_TextureID( textureIdentifier )
	{
		m_VBL.Push<float>( 3 );
		m_VBL.Push<float>( 2 );
		m_VA.AddBuffer( m_VB, m_VBL );

		m_Shader.LoadFromFile( RESOURCE_DIR "shaders/base.shader" );
		m_Shader.SetUniform<glm::mat4>( "u_MVP", glm::mat4( 1.0f ) );
		m_Shader.SetUniform<unsigned int>( "u_Texture", 1 );
	}

	void BatchRenderingManager::RenderBatch( const Renderer& renderer, const ApplicationLevelStuff& appStuff, const SceneStuff& sceneStuff, const std::vector<BatchParticleDetails>& batchDetails )
	{
		std::vector<BasicVertex> vertices;
		std::vector<unsigned int> indices;

		for( int x = 0; x < batchDetails.size(); x++ )
		{
			auto transformedVerts = BasicQuad::GetVertsFromDetails( sceneStuff, batchDetails.at( x ).position, batchDetails.at( x ).size );
			vertices.insert( vertices.end(), transformedVerts.begin(), transformedVerts.end() );

			auto transformedIndices = BasicQuad::GetDefaultIndices();
			std::for_each( transformedIndices.begin(), transformedIndices.end(), [x]( unsigned int& n ) { n += 4 * x; } );  // update the indices so that they reflect the current quad.

			indices.insert( indices.end(), transformedIndices.begin(), transformedIndices.end() );
		}

		m_Shader.SetUniform( "u_MVP", glm::mat4( 1.0f ) );

		auto particleTexture = appStuff.textureManager.GetTextureByIdentifier( m_TextureID );
		particleTexture.Bind( 1 );

		m_VB.PutData( vertices.data(), sizeof( BasicVertex ) * vertices.size() );
		m_IB.PutData( indices.data(), indices.size() );

		renderer.Draw( m_VA, m_IB, m_Shader );
	}
}