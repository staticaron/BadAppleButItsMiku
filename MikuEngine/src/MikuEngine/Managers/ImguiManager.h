#pragma once

#include "Core.h"

#include "Rendering/FrameBuffer.h"

namespace MikuEngine
{
	class MIKU_API ImguiManager
	{
	public:
		ImguiManager();
		~ImguiManager();

		void Init( GLFWwindow* glfwWindow );

		void NewFrame() const;
		void RenderFrame() const;

		void RenderFrameBuffer( const FrameBufferSpecification& specification, unsigned int textureID ) const;

	private:
	};
}