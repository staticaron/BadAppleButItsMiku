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

		static const std::array<unsigned int, 6>& GetDefaultIndices();
		static const std::array<BasicVertex, 4>& GetDefaultVertices();

		static std::array<BasicVertex, 4> GetVertsFromDetails( const SceneStuff& sceneStuff, glm::vec3 position, glm::vec2 size );

	private:
		VertexBuffer m_VB;
		VertexArray m_VA;
		IndexBuffer m_IB;
		VertexBufferLayout m_VBL;
		Shader m_Shader;

		static inline std::array<BasicVertex, 4> m_Verts = {
			BasicVertex( { -0.5f,  0.5f, 0.0f }, { 0.0f, 1.0f } ),
			BasicVertex( {  0.5f,  0.5f, 0.0f }, { 1.0f, 1.0f } ),
			BasicVertex( {  0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f } ),
			BasicVertex( { -0.5f, -0.5f, 0.0f }, { 0.0f, 0.0} )
		};

		static inline std::array<unsigned int, 6> m_Indices = {
			0, 1, 2,
			2, 3, 0
		};
	};
}