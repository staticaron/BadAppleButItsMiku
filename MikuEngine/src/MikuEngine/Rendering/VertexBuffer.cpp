#include "VertexBuffer.h"

#include "glad/gl.h"

namespace MikuEngine
{
	VertexBuffer::VertexBuffer( void* data, unsigned int sizeInBytes )
	{
		glCreateBuffers( 1, &m_RendererID );
		glBindBuffer( GL_ARRAY_BUFFER, m_RendererID );
		glBufferData( GL_ARRAY_BUFFER, sizeInBytes, data, GL_DYNAMIC_DRAW );
		glBindBuffer( GL_ARRAY_BUFFER, 0 );
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
}