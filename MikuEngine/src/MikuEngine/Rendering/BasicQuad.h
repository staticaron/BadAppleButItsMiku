#pragma once

#include <array>

#include "Rendering/IndexBuffer.h"
#include "Rendering/Renderer.h"
#include "Rendering/Shader.h"
#include "Rendering/VertexArray.h"
#include "Rendering/VertexBuffer.h"
#include "Rendering/VertexBufferLayout.h"
#include "Rendering/Vertices.h"

namespace MikuEngine
{
	class BasicQuad
	{
	public:
		BasicQuad();
		~BasicQuad() = default;

		void Render( const Renderer& renderer );

		const std::array<unsigned int, 6>& GetDefaultIndices() const;
		const std::array<BasicVertex, 4>& GetDefaultVertices() const;

	private:
		VertexBuffer m_VB;
		VertexArray m_VA;
		IndexBuffer m_IB;
		VertexBufferLayout m_VBL;
		Shader m_Shader;

		std::array<unsigned int, 6> m_DefaultIndices;
		std::array<BasicVertex, 4> m_DefaultVerts;
	};
}