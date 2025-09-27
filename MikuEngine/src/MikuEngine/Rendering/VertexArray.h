#pragma once

#include "MikuEngine/Rendering/VertexBuffer.h"
#include "MikuEngine/Rendering/VertexBufferLayout.h"

namespace MikuEngine
{
	class VertexArray
	{
	public:
		VertexArray() {};
		~VertexArray() {};

		void Bind() const;
		void UnBind() const;

		void AddBuffer( VertexBuffer vb, VertexBufferLayout vbl )
		{
			Bind();
			vb.Bind();

		}
	private:
		unsigned int m_RendererID = 0;
	};
}