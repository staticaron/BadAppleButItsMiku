#include "Application.h"

#include "Core.h"
#include "pch.h"

namespace MikuEngine
{
	Application::Application()
	{
		if( !glfwInit() )
		{
			spdlog::error( "GLFW failed to initialize!" );
		}

		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 6 );
		glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

		m_Window = glfwCreateWindow( 800, 600, "MikuEngine", nullptr, nullptr );
		glfwMakeContextCurrent( m_Window );

		if( !gladLoadGL( glfwGetProcAddress ) )
		{
			glfwTerminate();
		}

		glfwSetErrorCallback( glfwErrorCallback );

		glEnable( GL_DEBUG_OUTPUT );
		glEnable( GL_DEBUG_OUTPUT_SYNCHRONOUS );
		glDebugMessageCallback( GLDebugMessageCallback, nullptr );

		glEnable( GL_BLEND );
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

		glEnable( GL_DEPTH_TEST );

		glEnable( GL_CULL_FACE );
		glCullFace( GL_FRONT );
		glFrontFace( GL_CW );

		spdlog::info( reinterpret_cast<const char*>( glGetString( GL_VERSION ) ) );

		m_ImguiManager.Init( m_Window );
	}

	Application::~Application() {}

	void Application::Run()
	{
		while( !glfwWindowShouldClose( m_Window ) )
		{
			/*LAST = NOW;
			NOW = std::chrono::high_resolution_clock::now();
			m_DeltaTime = std::chrono::duration<float>( NOW - LAST ).count();*/

			glfwPollEvents();

			Update();
			Render();
		}
	}

	void Application::Update() {}

	void Application::Render()
	{
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		RenderGeometry();
		RenderImgui();

		glfwSwapBuffers( m_Window );
	}

	void Application::RenderGeometry() {}

	void Application::RenderImgui()
	{
		m_ImguiManager.NewFrame();

		m_DefaultScene.RenderImGui();

		m_ImguiManager.RenderFrame();
	}
}