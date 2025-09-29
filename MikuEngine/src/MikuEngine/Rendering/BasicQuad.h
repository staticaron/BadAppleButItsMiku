#pragma once

#include <array>

#include "glm.hpp"

#include "Rendering/IndexBuffer.h"
#include "Rendering/Renderer.h"
#include "Rendering/Shader.h"
#include "Rendering/VertexArray.h"
#include "Rendering/VertexBuffer.h"
#include "Rendering/VertexBufferLayout.h"
#include "Rendering/Vertices.h"
#include "Scene/SceneLevelValues.h"

namespace MikuEngine
{
	class MIKU_API BasicQuad
	{
	public:
		BasicQuad();
		~BasicQuad() = default;

		void Update( double dt ) {};
		void Render( const Renderer& renderer, const SceneLevelValues& sceneLevelValues );
		void RenderImGui();

		const std::array<unsigned int, 6>& GetDefaultIndices() const;
		const std::array<float, 28>& GetDefaultVertices() const;

	private:
		glm::vec3 m_Position = glm::vec3( 0.0f );
		glm::vec3 m_RotationAxis = { 0.0f, 0.0f, 1.0f };
		float m_RotationValue = 0.0f;
		glm::vec3 m_Scale = glm::vec3( 1.0f );

		VertexBuffer m_VB;
		VertexArray m_VA;
		IndexBuffer m_IB;
		VertexBufferLayout m_VBL;
		Shader m_Shader;

		std::array<unsigned int, 6> m_DefaultIndices;
		std::array<float, 28> m_DefaultVerts;
	};
}