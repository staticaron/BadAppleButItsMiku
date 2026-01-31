#include "FrameBuffer.h"

#include "pch.h"

namespace MikuEngine
{
	FrameBuffer::FrameBuffer( const FrameBufferSpecification& specification ) : m_Specification( specification ), m_RendererID( 0 ), m_TextureID( 0 )
	{
	}

	FrameBuffer::~FrameBuffer()
	{
		Destroy();
	}

	void FrameBuffer::Update( const FrameBufferSpecification& specification )
	{
		Destroy();
		m_Specification = specification;
		CreateFrameBuffer();
	}

	void FrameBuffer::Resize( uint32_t width, uint32_t height )
	{
		m_Specification.width  = width;
		m_Specification.height = height;

		Destroy();
		CreateFrameBuffer();
	}

	void FrameBuffer::CreateFrameBuffer()
	{
		glGenFramebuffers( 1, &m_RendererID );
		glBindFramebuffer( GL_FRAMEBUFFER, m_RendererID );

		glGenTextures( 1, &m_TextureID );
		glBindTexture( GL_TEXTURE_2D, m_TextureID );

		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, m_Specification.width, m_Specification.height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr );

		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

		glFramebufferTexture2D( GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_TextureID, 0 );

		ASSERT( glCheckFramebufferStatus( GL_FRAMEBUFFER ) == GL_FRAMEBUFFER_COMPLETE, "Frame Buffer is not complete to Render\n" );

		glBindTexture( GL_TEXTURE_2D, 0 );
		glBindFramebuffer( GL_FRAMEBUFFER, 0 );
	}

	void FrameBuffer::Destroy()
	{
		glDeleteFramebuffers( 1, &m_RendererID );
		glDeleteTextures( 1, &m_TextureID );
	}

	void FrameBuffer::Bind() const
	{
		glBindFramebuffer( GL_FRAMEBUFFER, m_RendererID );
		glViewport( 0, 0, m_Specification.width, m_Specification.height );
	}

	void FrameBuffer::UnBind() const
	{
		glBindFramebuffer( GL_FRAMEBUFFER, 0 );
	}
} // namespace MikuEngine