#include "Application.h"

#include "Core.h"
#include "pch.h"

namespace MikuEngine
{
	Application* s_App;

	Application::Application() : m_FrameBuffer( m_FrameBufferSpecification )
	{
		s_App = this;

		if ( !glfwInit() )
		{
			spdlog::error( "GLFW failed to initialize!" );
		}

		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 6 );
		glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

		glfwWindowHint( GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE );

		m_Window = glfwCreateWindow( 1600, 900, "MikuEngine", nullptr, nullptr );
		glfwMaximizeWindow( m_Window );

		glfwMakeContextCurrent( m_Window );

		if ( !gladLoadGL( glfwGetProcAddress ) )
		{
			glfwTerminate();
		}

		glfwSetErrorCallback( MikuEngine::Error::glfwErrorCallback );

		glEnable( GL_DEBUG_OUTPUT );
		glEnable( GL_DEBUG_OUTPUT_SYNCHRONOUS );
		glDebugMessageCallback( MikuEngine::Error::glDebugOutput, nullptr );

		glEnable( GL_BLEND );
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

		spdlog::info( reinterpret_cast<const char*>( glGetString( GL_VERSION ) ) );

		m_FrameBuffer.CreateFrameBuffer();

		m_DefaultScene = std::make_unique<BasicSceneImpl>();
		m_AppStuff.imguiManager.Init( m_Window );
		m_AppStuff.textureManager.LoadAllTextures();
		m_AppStuff.audioManager.Init();
	}

	Application::~Application() {}

	Application& Application::Get()
	{
		ASSERT( s_App, "App doesn't Exist!" );
		return *s_App;
	}

	void Application::Run()
	{
		while ( !glfwWindowShouldClose( m_Window ) )
		{
			glfwPollEvents();

			Update();
			Render();
		}
	}

	void Application::Update()
	{
		UpdateDeltaTime();

		m_AppStuff.imguiManager.Update( m_DeltaTime );
		m_DefaultScene->Update( m_AppStuff, m_DeltaTime );
	}

	void Application::UpdateDeltaTime()
	{
		LAST = NOW;
		NOW = std::chrono::high_resolution_clock::now();
		m_DeltaTime = std::chrono::duration<float>( NOW - LAST ).count();

		if ( !m_StartDeltaTime )
		{
			m_DeltaTime = 0.0;
			m_StartDeltaTime = true;
		}
	}

	void Application::Render()
	{
		m_FrameBuffer.Bind();

		glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT );
		RenderGeometry();

		m_FrameBuffer.UnBind();

		glClear( GL_COLOR_BUFFER_BIT );
		RenderImgui();

		glfwSwapBuffers( m_Window );
	}

	void Application::RenderGeometry()
	{
		m_DefaultScene->Render( m_Renderer, m_AppStuff );
	}

	void Application::RenderImgui()
	{
		m_AppStuff.imguiManager.NewFrame();

		m_AppStuff.imguiManager.RenderFrameBuffer( m_FrameBuffer, m_FrameBuffer.GetTexture(), m_DataContainer );
		m_DefaultScene->RenderImGui( m_AppStuff );

		m_AppStuff.imguiManager.RenderFrame();
	}
} // namespace MikuEngine
