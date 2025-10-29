#pragma once

namespace MikuEngine
{
	class MIKU_API IndexBuffer
	{
	public:
		IndexBuffer( void* data, unsigned int count );
		~IndexBuffer();

		void Bind() const;
		void UnBind() const;

		void PutData( const void* data, unsigned int count );

		inline unsigned int GetCount() const { return m_Count; }

	private:
		unsigned int m_RendererID = 0;
		unsigned int m_Count = 0;
	};
}