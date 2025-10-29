#pragma once

#include "Managers/BatchRenderingManager.h"
#include "Managers/VideoManager.h"
#include "VideoLoader.h"

namespace MikuEngine
{
	class MIKU_API VideoRenderer : public BatchRenderingManager
	{
	public:
		VideoRenderer( unsigned int maxParticleCount, std::string_view textureIdentifier );
		~VideoRenderer() = default;

		void Update( double dt );
		void UpdateFrame();

		void Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff, const SceneStuff& sceneStuff );
		void RenderImGui();

	private:
		VideoLoader m_VideoLoader;

		bool m_Playing = false;
		double m_ElapsedTime = 0.0f;

		const unsigned int m_PixelWidth = 86;
		const unsigned int m_PixelHeight = 64;

		const glm::ivec2 m_StartPosition = { 50, 50 };
		const glm::ivec2 m_PixelSize = { 6, 6 };
		const glm::ivec2 m_PixelGap = { 1, 1 };

		std::vector<BatchParticleDetails> m_ParticleDetails;
	};
}