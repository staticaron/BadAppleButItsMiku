#pragma once

#include "Managers/BatchRenderingManager.h"
#include "Managers/VideoManager.h"
#include "VideoLoader.h"

namespace MikuEngine
{
	class MIKU_API VideoRenderer : public BatchRenderingManager
	{
	  public:
		VideoRenderer( unsigned int maxParticleCount, const std::string& videoFilePath );
		~VideoRenderer() = default;

		void Init();

		void Update( ApplicationLevelStuff& appStuff, double dt );
		void UpdateFrame();

		void Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff, const SceneStuff& sceneStuff );
		void RenderImGui( ApplicationLevelStuff& appStuff );

	  private:
		std::string m_VideoFilePath;

		VideoLoader m_VideoLoader;

		bool m_Playing = false;
		bool m_StartTextureSwapping = false;
		double m_ElapsedTime = 0.0f;

		const unsigned int m_PixelWidth = 86;
		const unsigned int m_PixelHeight = 64;

		const glm::ivec2 m_StartPosition = { 10, 10 };
		const glm::ivec2 m_PixelSize = { 8, 8 };
		const glm::ivec2 m_PixelGap = { 2, 2 };

		std::array<std::string_view, 10> m_TextureIDs = {
			"miku_blue",
			"miku_pink",
			"miku_yellow",
			"miku_scary",
			"miku_red",
			"miku_purple",
			"miku_leaf",
			"miku_water",
			"miku_cherry",
			"miku_paper",
		};

		int m_TextureIndex = 0;
		double m_TextureTime = 0.0;
		double m_TextureChangeTime = 1.0;

		std::vector<float> m_ImpactPoints;
		unsigned int m_BeatLookupIndex = 0;

		RenderBatchDetails m_RenderBatchDetails;
	};
} // namespace MikuEngine