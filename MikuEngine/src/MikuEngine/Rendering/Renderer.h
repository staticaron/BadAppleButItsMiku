#pragma once

#include "Rendering/IndexBuffer.h"
#include "Rendering/Shader.h"
#include "Rendering/VertexArray.h"
#include "Rendering/VertexBufferLayout.h"

namespace MikuEngine
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Draw( VertexArray va, IndexBuffer ib, Shader shader ) const;
	private:
	};
}