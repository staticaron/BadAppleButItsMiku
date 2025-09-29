#pragma once

#include <vector>

#include "Rendering/Vertices.h"

namespace MikuEngine
{
	class MIKU_API VertexBuffer
	{
	public:
		VertexBuffer( const void* data, unsigned int sizeInBytes );
		~VertexBuffer();

		void Bind() const;
		void UnBind() const;

		void PutData( const void* data, size_t size );

	private:
		unsigned int m_RendererID = 0;
	};
}