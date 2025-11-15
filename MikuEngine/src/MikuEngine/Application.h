#pragma once

#include <chrono>
#include <iostream>

#include "glad/gl.h"

#include "GLFW/glfw3.h"

#include "Core.h"

#include "ApplicationLevelStuff.h"
#include "Data/DataContainer.h"
#include "Rendering/FrameBuffer.h"
#include "Scene/BasicSceneImpl.h"

namespace MikuEngine
{
	class MIKU_API Application
	{
	  public:
		Application();
		~Application();

		static Application& Get();

		void Run();

		void Update();
		void UpdateDeltaTime();
		void Render();

		void RenderGeometry();
		void RenderImgui();

		static const DataContainer& GetDataContainer() { return Get().m_DataContainer; }

	  private:
		GLFWwindow* m_Window = nullptr;
		Renderer m_Renderer;

		bool m_StartDeltaTime = false;
		std::chrono::high_resolution_clock::time_point LAST, NOW;
		double m_DeltaTime = 0.0f;

		FrameBufferSpecification m_FrameBufferSpecification = { 800, 600, 1 };
		FrameBuffer m_FrameBuffer;

		ApplicationLevelStuff m_AppStuff;
		DataContainer m_DataContainer;

		std::unique_ptr<BasicSceneImpl> m_DefaultScene;
	};

	Application* EntryPoint();
} // namespace MikuEngine
