#include "Rendering/VertexBuffer.h"

#include "pch.h"

namespace MikuEngine
{
	VertexBuffer::VertexBuffer( const void* data, unsigned int size )
	{
		glGenBuffers( 1, &m_RendererID );
		Bind();
		glBufferData( GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW );
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers( 1, &m_RendererID );
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer( GL_ARRAY_BUFFER, m_RendererID );
	}

	void VertexBuffer::UnBind() const
	{
		glBindBuffer( GL_ARRAY_BUFFER, 0 );
	}

	void VertexBuffer::PutData( const void* data, size_t size )
	{
		Bind();
		glBufferSubData( GL_ARRAY_BUFFER, 0, size, data );
	}
}