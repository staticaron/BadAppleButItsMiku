#pragma once

namespace MikuEngine
{
	class MIKU_API Texture
	{
	public:
		Texture() {};
		Texture( const std::string& filepath );

		void Bind( unsigned int slot = 0 ) const;
		void UnBind() const;

		void Destroy() const;

		int GetWidth() const;
		int GetHeight() const;

	private:
		unsigned int m_RendererID = 0;

		int m_Width = 0, m_Height = 0, m_Channels = 0;
	};
}