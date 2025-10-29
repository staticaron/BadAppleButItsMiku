#pragma once

#include <opencv2/opencv.hpp>
#include <string_view>

#include "Core.h"

namespace MikuEngine
{
	class MIKU_API VideoManager
	{
	public:
		VideoManager();
		~VideoManager();

		void Update( double dt );

		void LoadVideo( std::string_view filepath );
		unsigned int GetPixelValue( glm::ivec2 position );

		glm::ivec2 GetVideoDimensions() const { return m_VideoDimension; }

	private:
		cv::VideoCapture m_Video;

		glm::ivec2 m_VideoDimension = {};

		unsigned int m_FPS = 0;
		unsigned int m_TotalFrameCount = 0;

		double m_VideoLength = 0.0f;

		double m_ElapsedTime = 0.0f;
	};
}