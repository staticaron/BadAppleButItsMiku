#pragma once

#include <iostream>

#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include "Core.h"
#include "Managers/ImguiManager.h"
#include "Scene/BasicSceneImpl.h"

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

		void RenderGeometry();
		void RenderImgui();

	private:
		GLFWwindow* m_Window = nullptr;

		ImguiManager m_ImguiManager;

		BasicSceneImpl m_DefaultScene;
	};

	Application* EntryPoint();
}