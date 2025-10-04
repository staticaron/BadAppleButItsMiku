#pragma once

#include "glm.hpp"

#include "Core.h"

#include "Data/DataContainer.h"
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

		void RenderFrameBuffer( FrameBuffer& frameBuffer, unsigned int textureID, DataContainer& dataContainer );

	private:
	};
}