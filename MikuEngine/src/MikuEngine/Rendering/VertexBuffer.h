#pragma once

namespace MikuEngine
{
	class VertexBuffer
	{
	public:
		VertexBuffer( void* data, unsigned int sizeInBytes );
		~VertexBuffer();

		void Bind() const;
		void UnBind() const;

	private:
		unsigned int m_RendererID = 0;
	};
}