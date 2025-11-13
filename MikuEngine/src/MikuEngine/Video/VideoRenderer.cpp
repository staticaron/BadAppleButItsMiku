#include "VideoRenderer.h"

#include "pch.h"

namespace MikuEngine
{
	VideoRenderer::VideoRenderer( unsigned int maxParticleCount, const std::string& videoFilePath ) : BatchRenderingManager( maxParticleCount ), m_VideoFilePath( videoFilePath ) {}

	void VideoRenderer::Init()
	{
		m_RenderBatchDetails.Particles.reserve( m_PixelWidth * m_PixelHeight );
		m_RenderBatchDetails.ParticleGap = m_PixelGap.x;
		m_RenderBatchDetails.ParticleSize = m_PixelSize.x;
		m_RenderBatchDetails.BatchStartPosition = m_StartPosition;

		m_VideoLoader.LoadVideo( m_VideoFilePath );

		glm::ivec2 videoDimensions = m_VideoLoader.GetVideoDimensions();

		float xMultiplier = videoDimensions.x / static_cast<float>( m_PixelWidth );
		float yMultiplier = videoDimensions.y / static_cast<float>( m_PixelHeight );

		unsigned int x = 0, y = 0;

		for ( int x = 0; x < m_PixelWidth; x++ )
		{
			for ( int y = 0; y < m_PixelHeight; y++ )
			{
				glm::vec3 quadPosition = { m_StartPosition.x + x * ( m_PixelSize.x + m_PixelGap.x ), m_StartPosition.y + y * ( m_PixelSize.y + m_PixelGap.y ), 0.0f };
				m_RenderBatchDetails.Particles.push_back( { quadPosition, m_PixelSize } );
			}
		}

		m_ImpactPoints = CSVLoader::FetchSingleColumnValues( RESOURCE_DIR "data/peaks.csv" );
		auto inactiveRegion1 = CSVLoader::FetchSingleColumnValues( RESOURCE_DIR "data/inactive_region1.csv" );
		auto inactiveRegion2 = CSVLoader::FetchSingleColumnValues( RESOURCE_DIR "data/inactive_region2.csv" );

		m_InactiveRegions.push_back( { 44.0f, 56.0f, inactiveRegion1 } );
		m_InactiveRegions.push_back( { 112.0f, 142.0f, inactiveRegion2 } );
	}

	void VideoRenderer::Update( ApplicationLevelStuff& appStuff, double dt )
	{
		if ( !m_Playing )
		{
			if ( m_StartTextureSwapping )
			{

				m_TextureTime += dt;
				if ( m_TextureTime > m_TextureChangeTime )
				{
					m_TextureTime = 0.0f;
					m_TextureIndex = ( m_TextureIndex + 1 ) % m_TextureIDs.size();
					m_RenderBatchDetails.textureID = m_TextureIDs.at( m_TextureIndex );
				}
			}

			return;
		}

		m_ElapsedTime += dt;

		/*auto& currentInactiveRegion = m_InactiveRegions[ m_InActiveRegionIndex ];

		if ( m_ElapsedTime > currentInactiveRegion.RegionEndTime )
		{
			m_InActiveRegionIndex = glm::clamp( m_InActiveRegionIndex + 1, static_cast<unsigned int>( 0 ), static_cast<unsigned int>( m_InactiveRegions.size() - 1 ) );
		}
		else if ( m_ElapsedTime > currentInactiveRegion.RegionStartTime )
		{
			if ( m_ElapsedTime > currentInactiveRegion.RegionValues.at( currentInactiveRegion.RegionValueIndex ) )
			{
				currentInactiveRegion.RegionValueIndex++;
				m_TextureIndex = ( m_TextureIndex + 1 ) % m_TextureIDs.size();
				m_RenderBatchDetails.textureID = m_TextureIDs.at( m_TextureIndex );
			}
		}*/

		if ( m_ElapsedTime > m_ImpactPoints.at( m_BeatLookupIndex ) )
		{
			m_BeatLookupIndex++;
			m_TextureIndex = ( m_TextureIndex + 1 ) % m_TextureIDs.size();
			m_RenderBatchDetails.textureID = m_TextureIDs.at( m_TextureIndex );
		}
	}

	void VideoRenderer::UpdateFrame()
	{
		if ( !m_Playing )
			return;

		m_RenderBatchDetails.Particles.clear();

		glm::ivec2 videoDimensions = m_VideoLoader.GetVideoDimensions();

		float xMultiplier = videoDimensions.x / static_cast<float>( m_PixelWidth );
		float yMultiplier = videoDimensions.y / static_cast<float>( m_PixelHeight );

		unsigned int x = 0, y = 0;

		while ( x < m_PixelWidth )
		{
			while ( y < m_PixelHeight )
			{
				unsigned int frameNumber = m_ElapsedTime * m_VideoLoader.GetVideoFPS();

				unsigned int pixelActivated = m_VideoLoader.GetPixelData( frameNumber, x * xMultiplier, y * yMultiplier );

				glm::vec3 quadPosition = { m_StartPosition.x + x * ( m_PixelSize.x + m_PixelGap.x ), m_StartPosition.y + y * ( m_PixelSize.y + m_PixelGap.y ), 0.0f };

				if ( pixelActivated > 10 )
					m_RenderBatchDetails.Particles.push_back( { quadPosition, m_PixelSize } );

				y = y + 1;
			}

			x = x + 1;
			y = 0;
		}
	}

	void VideoRenderer::Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff, const SceneStuff& sceneStuff )
	{
		UpdateFrame();
		RenderBatch( renderer, appStuff, sceneStuff, m_RenderBatchDetails );
	}

	void VideoRenderer::RenderImGui( ApplicationLevelStuff& appStuff )
	{
		ImGui::Begin( "Video Renderer Properties" );

		if ( ImGui::Button( " PLAY " ) )
		{
			appStuff.audioManager.PlayStream( "bad" );
			m_Playing = true;
			m_TextureIndex++;
			m_TextureTime = 0.0;
			m_TextureChangeTime = 0.4347;
		}

		if ( ImGui::Button( " PAUSE " ) )
		{
			appStuff.audioManager.SetPauseStream( "bad", true );
			m_Playing = false;
		}

		if ( ImGui::Button( " RESUME " ) )
		{
			appStuff.audioManager.SetPauseStream( "bad", false );
			m_Playing = true;
		}

		if ( ImGui::Button( " Restart " ) )
			m_ElapsedTime = 0.0;

		if ( ImGui::Button( "Start Texture Swapping " ) )
			m_StartTextureSwapping = true;

		if ( ImGui::DragInt( "TextureID", &m_TextureIndex, 1, 0, 8 ) )
			m_RenderBatchDetails.textureID = m_TextureIDs.at( m_TextureIndex );

		float elapsedTime = static_cast<float>( m_ElapsedTime );
		ImGui::DragFloat( "Elapsed Time", &elapsedTime );

		ImGui::End();
	}
} // namespace MikuEngine
