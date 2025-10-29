#pragma once

#include "MikuEngine/Rendering/VertexBuffer.h"
#include "MikuEngine/Rendering/VertexBufferLayout.h"

namespace MikuEngine
{
	class MIKU_API VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind() const;
		void UnBind() const;

		void AddBuffer( const VertexBuffer& vb, const VertexBufferLayout& vbl );

	private:
		unsigned int m_RendererID = 0;
	};
}