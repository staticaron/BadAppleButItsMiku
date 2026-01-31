#pragma once

#include "glm.hpp"

#include "Core.h"

#include "Data/DataContainer.h"
#include "Rendering/FrameBuffer.h"

namespace MikuEngine
{
#define IMGUI_DISABLED(x)\
ImGui::BeginDisabled();\
x;\
ImGui::EndDisabled()\

	class MIKU_API ImguiManager
	{
	public:
		ImguiManager();
		~ImguiManager();

		void Init( GLFWwindow* glfwWindow );

		void Update( double deltaTime );

		void NewFrame() const;
		void RenderFrame() const;

		void RenderFrameBuffer( FrameBuffer& frameBuffer, unsigned int textureID, DataContainer& dataContainer );

	private:
		double m_DeltaTime = 0.0f;
	};
}