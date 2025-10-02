#include "Rendering/VertexArray.h"

namespace MikuEngine
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays( 1, &m_RendererID );
		Bind();
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays( 1, &m_RendererID );
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray( m_RendererID );
	}

	void VertexArray::UnBind() const
	{
		glBindVertexArray( 0 );
	}

	void VertexArray::AddBuffer( const VertexBuffer& vb, const VertexBufferLayout& vbl )
	{
		Bind();
		vb.Bind();

		const auto& elements = vbl.GetElements();
		unsigned int offset = 0;

		for( unsigned int i = 0; i < elements.size(); i++ )
		{
			const auto& element = elements[i];
			glEnableVertexAttribArray( i );
			glVertexAttribPointer( i, element.count, element.type, element.normalized, vbl.GetStride(), (const void*)offset );

			offset += element.count * VertexBufferElement::GetSizeOfType( element.type );
		}
	}
}