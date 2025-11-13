#include "BatchRenderingManager.h"

#include "pch.h"

namespace MikuEngine
{
	BatchRenderingManager::BatchRenderingManager( unsigned int maxParticleCount ) : m_MaxParticleCount( maxParticleCount ), m_VB( nullptr, maxParticleCount * 4 * sizeof( BasicVertex ) ), m_IB( nullptr, maxParticleCount * 6 )
	{
		m_VBL.Push<float>( 3 );
		m_VA.AddBuffer( m_VB, m_VBL );

		m_Shader.LoadFromFile( RESOURCE_DIR "shaders/geo.shader" );
		m_Shader.SetUniform( "u_Tex", 0 );
	}

	void BatchRenderingManager::RenderBatch( const Renderer& renderer, const ApplicationLevelStuff& appStuff, const SceneStuff& sceneStuff, const RenderBatchDetails& batchDetails )
	{
		std::vector<BareboneVertex> vertices;
		std::vector<unsigned int> indices;

		for ( int x = 0; x < batchDetails.Particles.size(); x++ )
		{
			BareboneVertex newVert = { batchDetails.Particles.at( x ).position };
			vertices.push_back( newVert.ApplyTransform( sceneStuff.camera.GetMVPFromModelMatrix( glm::mat4( 1.0f ) ) ) );

			indices.push_back( x );
		}

		m_Shader.SetUniform<glm::mat4>( "u_MVP", sceneStuff.camera.GetMVPFromModelMatrix( glm::mat4( 1.0f ) ) );
		m_Shader.SetUniform<float>( "u_QuadWidth", batchDetails.ParticleSize * 0.5f );

		auto texture = appStuff.textureManager.GetTextureByIdentifier( batchDetails.textureID );
		texture.Bind( 0 );

		m_VB.PutData( vertices.data(), sizeof( BareboneVertex ) * vertices.size() );
		m_IB.PutData( indices.data(), indices.size() );

		renderer.DrawPoints( m_VA, m_IB, m_Shader, vertices.size() );
	}
} // namespace MikuEngine
