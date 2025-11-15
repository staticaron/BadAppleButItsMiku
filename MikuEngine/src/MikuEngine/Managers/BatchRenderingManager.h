#pragma once

#include <string_view>
#include <vector>

#include "ApplicationLevelStuff.h"
#include "glm.hpp"
#include "Managers/TextureManager.h"
#include "Rendering/IndexBuffer.h"
#include "Rendering/Shader.h"
#include "Rendering/VertexArray.h"
#include "Rendering/VertexBuffer.h"
#include "Rendering/VertexBufferLayout.h"
#include "Scene/SceneStuff.h"

namespace MikuEngine
{
	struct MIKU_API BatchParticleDetails
	{
		glm::vec3 position = glm::vec3( 0.0f );
		glm::vec2 size = glm::vec2( 100.0f, 100.0f );
		bool show = true;
		glm::vec4 tint = glm::vec4( 1.0f );
	};

	struct MIKU_API RenderBatchDetails
	{
		std::vector<BatchParticleDetails> Particles;
		glm::ivec2 BatchStartPosition = {};
		unsigned int ParticleSize = 0, ParticleGap = 0;
		std::string_view textureID = "miku_leaf";
	};

	class BatchRenderingManager
	{
	  public:
		BatchRenderingManager( unsigned int maxParticleCount );
		~BatchRenderingManager() = default;

		void RenderBatch( const Renderer& renderer, const ApplicationLevelStuff& appStuff, const SceneStuff& sceneStuff, const RenderBatchDetails& batchDetails );

	  protected:
		unsigned int m_MaxParticleCount;

		VertexBuffer m_VB;
		VertexBufferLayout m_VBL;
		IndexBuffer m_IB;
		VertexArray m_VA;
		Shader m_Shader;
	};
} // namespace MikuEngine