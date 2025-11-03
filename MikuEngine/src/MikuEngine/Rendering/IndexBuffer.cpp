#include "IndexBuffer.h"

#include "MikuEngine/Core.h"

namespace MikuEngine
{
	IndexBuffer::IndexBuffer( void* data, unsigned int count ) : m_Count( count )
	{
		glGenBuffers( 1, &m_RendererID );
		Bind();
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( unsigned int ) * m_Count, data, GL_DYNAMIC_DRAW );
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers( 1, &m_RendererID );
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_RendererID );
	}

	void IndexBuffer::UnBind() const
	{
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
	}

	void IndexBuffer::PutData( const void* data, unsigned int count )
	{
		ASSERT( m_RendererID != 0, "Renderer is not Initialized!" );
		ASSERT( count <= m_Count, "Can't put more data into a smaller buffer" );

		Bind();
		glBufferSubData( GL_ELEMENT_ARRAY_BUFFER, 0, sizeof( unsigned int ) * count, data );
	}
} // namespace MikuEngine