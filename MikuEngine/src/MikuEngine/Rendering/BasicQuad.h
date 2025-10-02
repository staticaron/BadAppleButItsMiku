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
#include "Scene/SceneStuff.h"

namespace MikuEngine
{
	class MIKU_API BasicQuad
	{
	public:
		BasicQuad();
		~BasicQuad() = default;

		const VertexBuffer& GetVB() const { return m_VB; };
		const VertexArray& GetVA() const { return m_VA; };
		const IndexBuffer& GetIB() const { return m_IB; };
		const Shader& GetShader() const { return m_Shader; };

		const std::array<unsigned int, 6>& GetDefaultIndices() const;
		const std::array<float, 28>& GetDefaultVertices() const;

	private:
		VertexBuffer m_VB;
		VertexArray m_VA;
		IndexBuffer m_IB;
		VertexBufferLayout m_VBL;
		Shader m_Shader;
	};
}