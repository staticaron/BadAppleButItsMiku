#pragma once

#include <string>
#include <vector>

namespace MikuEngine
{
	struct MIKU_API VideoFrame
	{
		std::vector<unsigned char> pixelData;
	};

	struct MIKU_API VideoData
	{
		std::vector<VideoFrame> frames;
	};

	class MIKU_API VideoLoader
	{
	public:
		VideoLoader();
		~VideoLoader();

		void FreeLoadedVideo();

		void LoadVideo( const std::string& filepath );
		unsigned char GetPixelData( uint32_t frameNumber, uint32_t x, uint16_t y ) const;

		glm::ivec2 GetVideoDimensions() const { return { m_VideoWidth, m_VideoHeight }; }
		unsigned int GetVideoFrameCount() const { return m_FrameCount; }
		unsigned int GetVideoFPS() const { return m_FPS; }
		float GetVideoLength() const { return m_VideoLength; }

	private:
		VideoData* m_VideoData = nullptr;

		unsigned int m_VideoWidth = 0, m_VideoHeight = 0;
		unsigned int m_FPS = 0;
		unsigned int m_FrameCount = 0;
		float m_VideoLength = 0.0f;
	};
}
