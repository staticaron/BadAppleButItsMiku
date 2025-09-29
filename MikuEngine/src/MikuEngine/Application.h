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
		Renderer m_Renderer;

		ImguiManager m_ImguiManager;

		std::unique_ptr<BasicSceneImpl> m_DefaultScene;
	};

	Application* EntryPoint();
}