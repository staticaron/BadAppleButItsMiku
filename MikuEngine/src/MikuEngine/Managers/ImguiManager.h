#pragma once

#include "Core.h"

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

	private:
	};
}