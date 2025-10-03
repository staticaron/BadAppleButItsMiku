#include "Application.h"

#include "Core.h"
#include "pch.h"

namespace MikuEngine
{
	Application::Application() : m_FrameBuffer( m_FrameBufferSpecification )
	{
		if( !glfwInit() )
		{
			spdlog::error( "GLFW failed to initialize!" );
		}

		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 6 );
		glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

		glfwWindowHint( GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE );

		m_Window = glfwCreateWindow( 800, 600, "MikuEngine", nullptr, nullptr );
		glfwMakeContextCurrent( m_Window );

		if( !gladLoadGL( glfwGetProcAddress ) )
		{
			glfwTerminate();
		}

		glfwSetErrorCallback( MikuEngine::Error::glfwErrorCallback );

		glEnable( GL_DEBUG_OUTPUT );
		glEnable( GL_DEBUG_OUTPUT_SYNCHRONOUS );
		glDebugMessageCallback( MikuEngine::Error::glDebugOutput, nullptr );

		glEnable( GL_BLEND );
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

		glEnable( GL_CULL_FACE );
		glCullFace( GL_FRONT );
		glFrontFace( GL_CCW );

		spdlog::info( reinterpret_cast<const char*>( glGetString( GL_VERSION ) ) );

		m_FrameBuffer.CreateFrameBuffer();

		m_DefaultScene = std::make_unique<BasicSceneImpl>();
		m_AppStuff.imguiManager.Init( m_Window );
		m_AppStuff.textureManager.LoadAllTextures();
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
		m_FrameBuffer.Bind();

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

		m_AppStuff.imguiManager.RenderFrameBuffer( m_FrameBufferSpecification, m_FrameBuffer.GetTexture() );
		m_DefaultScene->RenderImGui();

		m_AppStuff.imguiManager.RenderFrame();
	}
}