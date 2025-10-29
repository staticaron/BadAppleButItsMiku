#pragma once

namespace MikuEngine
{
	struct FrameBufferSpecification
	{
		uint32_t width;
		uint32_t height;
		uint32_t samples;
	};

	class MIKU_API FrameBuffer
	{
	public:
		FrameBuffer( const FrameBufferSpecification& specification );
		~FrameBuffer();

		void CreateFrameBuffer();
		void Update( const FrameBufferSpecification& specification );
		void Resize( uint32_t width, uint32_t height );

		void Destroy();

		void Bind() const;
		void UnBind() const;

		unsigned int GetTexture() const { return m_TextureID; }
		const FrameBufferSpecification& GetSpecification() const { return m_Specification; }

	private:
		FrameBufferSpecification m_Specification;

		unsigned int m_RendererID;
		unsigned int m_TextureID;
	};
}