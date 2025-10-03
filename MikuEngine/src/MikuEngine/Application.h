#pragma once

#include <iostream>

#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include "Core.h"

#include "ApplicationLevelStuff.h"
#include "Managers/ImguiManager.h"
#include "Managers/TextureManager.h"
#include "Rendering/FrameBuffer.h"
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

		FrameBufferSpecification m_FrameBufferSpecification = { 800, 600, 1 };
		FrameBuffer m_FrameBuffer;

		ApplicationLevelStuff m_AppStuff;

		std::unique_ptr<BasicSceneImpl> m_DefaultScene;
	};

	Application* EntryPoint();
}