#include "VideoManager.h"

#include <sstream>

#include "pch.h"

namespace MikuEngine
{
	VideoManager::VideoManager() {}
	VideoManager::~VideoManager() {}

	void VideoManager::Update( double dt )
	{
		m_ElapsedTime += dt;
	}

	void VideoManager::LoadVideo( std::string_view filepath )
	{
		m_Video = cv::VideoCapture( filepath.data() );

		if( !m_Video.isOpened() )
		{
			spdlog::error( "Video File was not opened properly {}", filepath.data() );
			return;
		}

		m_FPS = m_Video.get( cv::CAP_PROP_FPS );
		m_TotalFrameCount = static_cast<unsigned int>( m_Video.get( cv::CAP_PROP_FRAME_COUNT ) );
		m_VideoLength = m_TotalFrameCount / m_FPS;

		cv::Mat frame;
		m_Video >> frame;

		m_VideoDimension = { frame.cols, frame.rows };

		spdlog::info( "Video Loaded Successfully! " );
	}

	unsigned int VideoManager::GetPixelValue( glm::ivec2 position )
	{
		if( position.x >= m_VideoDimension.x || position.y >= m_VideoDimension.y )
			return 0;

		unsigned int currentFrameCount = ( m_ElapsedTime * m_TotalFrameCount ) / m_VideoLength;

		m_Video.set( cv::CAP_PROP_POS_FRAMES, currentFrameCount );

		cv::Mat frame;

		bool readSuccssfull = m_Video.read( frame );

		if( !readSuccssfull )
		{
			spdlog::error( "Error reading frame! " );
			return 0;
		}

		return frame.at<uchar>( position.y, position.x * 3 );
	}
}