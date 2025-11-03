#include "Renderer.h"

namespace MikuEngine
{
	void Renderer::Draw( const VertexArray& va, const IndexBuffer& ib, const Shader& shader ) const
	{
		va.Bind();
		ib.Bind();
		shader.Bind();

		glDrawElements( GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr );
	}

	void Renderer::DrawPoints( const VertexArray& va, const IndexBuffer& ib, const Shader& shader, unsigned int countToDraw ) const
	{
		va.Bind();
		ib.Bind();
		shader.Bind();

		countToDraw = countToDraw == -1 ? ib.GetCount() : countToDraw;

		glDrawElements( GL_POINTS, countToDraw, GL_UNSIGNED_INT, nullptr );
	}
} // namespace MikuEngine