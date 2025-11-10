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
		( void )io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		io.ConfigFlags |= ImGuiDockNodeFlags_PassthruCentralNode;

		auto defaultFont = io.Fonts->AddFontFromFileTTF( IMGUI_FONT, 13 );
		io.FontDefault = defaultFont;

		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL( glfwWindow, true );
		ImGui_ImplOpenGL3_Init();
	}

	void ImguiManager::Update( double deltaTime )
	{
		m_DeltaTime = deltaTime;
	}

	void ImguiManager::NewFrame() const
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::DockSpaceOverViewport();
	}

	void ImguiManager::RenderFrame() const
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );

		ImGuiIO& io = ImGui::GetIO();

		if ( io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable )
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent( backup_current_context );
		}
	}

	void ImguiManager::RenderFrameBuffer( FrameBuffer& frameBuffer, unsigned int textureID, DataContainer& dataContainer )
	{
		ImGui::Begin( "Viewport " );

		ImVec2 windowSize = ImGui::GetWindowSize();

		if ( dataContainer.GetViewportDimensions() != *( glm::vec2* )&windowSize )
		{
			frameBuffer.Resize( static_cast<float>( windowSize.x ), static_cast<float>( windowSize.y ) );
			dataContainer.SetViewportDimensions( *( glm::vec2* )&windowSize );
		}

		ImGui::Image( ( void* )( intptr_t )textureID, { static_cast<float>( frameBuffer.GetSpecification().width ), static_cast<float>( frameBuffer.GetSpecification().height ) }, { 0, 1 }, { 1, 0 } );

		ImGui::End();

		ImGui::Begin( "Viewport Details" );

		int frameRate = 1 / m_DeltaTime;

		IMGUI_DISABLED( ImGui::DragInt( "FrameRate", &frameRate ) );

		ImGui::End();
	}
} // namespace MikuEngine