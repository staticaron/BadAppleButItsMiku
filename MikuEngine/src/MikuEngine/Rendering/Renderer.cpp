#include "Renderer.h"

namespace MikuEngine
{
	Renderer::Renderer() {}
	Renderer::~Renderer() {}

	void Renderer::Draw( VertexArray va, IndexBuffer ib, Shader shader )
	{
		va.Bind();
		ib.Bind();
		shader.Bind();

		glDrawElements( GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr );
	}
}