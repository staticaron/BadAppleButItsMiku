#pragma once

#include "Core.h" 

#include "glad/gl.h"

#include "spdlog/spdlog.h"

#define ASSERT(expr) \
    if (!(expr)) \
        __debugbreak()

namespace MikuEngine
{
	class MIKU_API Error
	{
	public:
		static void glDebugOutput( GLenum source, GLenum type, unsigned int id, GLenum severity, GLsizei length, const char* message, const void* userParam )
		{
			std::cerr << "--- OpenGL Debug Message ---" << std::endl;
			std::cerr << "Source: " << source << ", Type: " << type << ", Severity: " << severity << std::endl;
			std::cerr << "Message: " << message << std::endl;

#ifdef DEBUG
			__debugbreak();
#endif
		}

		static void glfwErrorCallback( int error, const char* description )
		{
			spdlog::error( "GLFW Error ", error, description );
#ifdef DEBUG
			__debugbreak();
#endif
		}
	};
}