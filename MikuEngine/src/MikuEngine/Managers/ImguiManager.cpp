#include "ImguiManager.h"

#include "pch.h"

namespace MikuEngine
{
	ImguiManager::ImguiManager() {}

	ImguiManager::~ImguiManager()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImguiManager::Init( GLFWwindow* glfwWindow )
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;	  // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;	  // Enable Multi-Viewport / Platform Windows
		io.ConfigFlags |= ImGuiDockNodeFlags_PassthruCentralNode;

		auto defaultFont = io.Fonts->AddFontFromFileTTF( IMGUI_FONT, 13 );
		io.FontDefault = defaultFont;

		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL( glfwWindow, true );
		ImGui_ImplOpenGL3_Init();
	}

	void ImguiManager::NewFrame() const
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// ImGui::DockSpaceOverViewport();
	}

	void ImguiManager::RenderFrame() const
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );

		ImGuiIO& io = ImGui::GetIO();

		if( io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable )
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent( backup_current_context );

		}
	}
}