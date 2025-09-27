#pragma once

namespace MikuEngine
{
	class Shader
	{
	public:
		void Bind() const;
		void UnBind() const;

	private:
		unsigned int m_RendererID = 0;
	};
}