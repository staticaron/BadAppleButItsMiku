#pragma once

namespace MikuEngine
{
	class ImguiManager
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