#include "VideoRenderer.h"

#include "pch.h"

namespace MikuEngine
{
	VideoRenderer::VideoRenderer( unsigned int maxParticleCount, std::string_view textureIdentifier ) : BatchRenderingManager( maxParticleCount, textureIdentifier )
	{
		m_ParticleDetails.reserve( m_PixelWidth * m_PixelHeight );
		// m_VideoManager.LoadVideo( RESOURCE_DIR "videos/base.mp4" );
		m_VideoLoader.LoadVideo( RESOURCE_DIR "videos/bad.mp4" );
		UpdateFrame();
	}

	void VideoRenderer::Update( double dt )
	{
		// m_VideoManager.Update( dt );
		if( m_Playing ) m_ElapsedTime += dt;
	}

	void VideoRenderer::UpdateFrame()
	{
		m_ParticleDetails.clear();

		glm::ivec2 videoDimensions = m_VideoLoader.GetVideoDimensions();

		float xMultiplier = videoDimensions.x / static_cast<float>( m_PixelWidth );
		float yMultiplier = videoDimensions.y / static_cast<float>( m_PixelHeight );

		unsigned int x = 0, y = 0;

		while( x < m_PixelWidth )
		{
			while( y < m_PixelHeight )
			{
				// auto pixelCoordinate = glm::ivec2( x * xMultiplier, y * yMultiplier );
				// unsigned int pixelActivated = m_VideoManager.GetPixelValue( pixelCoordinate );

				unsigned int frameNumber = m_ElapsedTime * m_VideoLoader.GetVideoFPS();

				unsigned int pixelActivated = m_VideoLoader.GetPixelData( frameNumber, x * xMultiplier, y * yMultiplier );

				glm::vec3 quadPosition = { m_StartPosition.x + x * ( m_PixelSize.x + m_PixelGap.x ), m_StartPosition.y + y * ( m_PixelSize.y + m_PixelGap.y ), 0.0f };

				if( pixelActivated > 10 ) m_ParticleDetails.push_back( { quadPosition, m_PixelSize } );

				y = y + 1;
			}

			x = x + 1;
			y = 0;
		}
	}

	void VideoRenderer::Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff, const SceneStuff& sceneStuff )
	{
		UpdateFrame();

		RenderBatch( renderer, appStuff, sceneStuff, m_ParticleDetails );
	}

	void VideoRenderer::RenderImGui()
	{
		ImGui::Begin( "Video Renderer Properties" );

		if( ImGui::Button( " PLAY " ) )
			m_Playing = true;

		if( ImGui::Button( " STOP " ) )
			m_Playing = false;

		if( ImGui::Button( " Restart " ) )
			m_ElapsedTime = 0.0;


		ImGui::End();
	}
}