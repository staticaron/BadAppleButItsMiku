#pragma once

#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "Core.h"

namespace MikuEngine
{
	class MIKU_API Application
	{
	public:
		Application();
		~Application();

		void Run();

		void Update();
		void Render();
	private:
		GLFWwindow* m_Window = nullptr;

	};

	Application* EntryPoint();
}