#include "VideoLoader.h"

#include "pch.h"

namespace MikuEngine
{
	VideoLoader::VideoLoader() {}

	VideoLoader::~VideoLoader()
	{
		FreeLoadedVideo();
	}

	void VideoLoader::FreeLoadedVideo()
	{
		if ( m_VideoData != nullptr )
			delete m_VideoData;
	}

	void VideoLoader::LoadVideo( const std::string& filepath )
	{
		FreeLoadedVideo();

		m_VideoData = new VideoData();

		auto videoCapture = cv::VideoCapture( filepath.data() );

		if ( !videoCapture.isOpened() )
		{
			spdlog::error( "Video File was not opened properly {}", filepath.data() );
			return;
		}
		else
			spdlog::info( "Video Loaded Successfully! " );

		m_FPS = videoCapture.get( cv::CAP_PROP_FPS );
		m_FrameCount = static_cast<unsigned int>( videoCapture.get( cv::CAP_PROP_FRAME_COUNT ) );
		m_VideoLength = m_FrameCount / m_FPS;

		cv::Mat firstFrame;
		videoCapture >> firstFrame;

		m_VideoWidth = firstFrame.cols;
		m_VideoHeight = firstFrame.rows;

		for ( size_t f = 0; f < m_FrameCount; f++ )
		{
			VideoFrame newFrame;

			videoCapture.set( cv::CAP_PROP_POS_FRAMES, f );

			cv::Mat frame;
			videoCapture >> frame;

			glm::vec2 frameDimensions = { frame.cols, frame.rows };

			bool readSuccssfull = videoCapture.read( frame );

			if ( frame.empty() )
				continue;

			if ( !readSuccssfull )
				spdlog::error( "Error reading frame! " );

			for ( size_t x = 0; x < frameDimensions.x; x++ )
			{
				for ( size_t y = 0; y < frameDimensions.y; y++ )
				{
					uchar pixelValue = frame.at<uchar>( y, x * 3 );
					newFrame.pixelData.push_back( pixelValue );
				}
			}

			m_VideoData->frames.push_back( newFrame );
		}

		spdlog::info( "Video Data Loaded" );
	}

	unsigned char VideoLoader::GetPixelData( uint32_t frameNumber, uint32_t x, uint16_t y ) const
	{
		if ( frameNumber >= m_FrameCount - 1 )
			return 0;

		auto frame = m_VideoData->frames.at( frameNumber );
		return frame.pixelData.at( x * GetVideoDimensions().y + y );
	}
} // namespace MikuEngine
