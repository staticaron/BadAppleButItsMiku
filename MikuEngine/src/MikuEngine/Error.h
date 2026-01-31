#pragma once

#include "Core.h"

#include "glad/gl.h"

#include "spdlog/spdlog.h"

namespace MikuEngine
{
#define ASSERT( condition, msg )                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       \
	if ( !( condition ) )                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              \
	{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  \
		std::cerr << "Assertion Failed in " << __FILE__ << " at line " << __LINE__ << ": " << msg << std::endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        \
		std::abort();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  \
	}

	class Error
	{
	  public:
		static void glDebugOutput( GLenum source, GLenum type, unsigned int id, GLenum severity, GLsizei length, const char* message, const void* userParam )
		{
			std::cerr << "--- OpenGL Debug Message ---" << std::endl;
			std::cerr << "Source: " << source << ", Type: " << type << ", Severity: " << severity << std::endl;
			std::cerr << "Message: " << message << std::endl;
		}

		static void glfwErrorCallback( int error, const char* description )
		{
			spdlog::error( "GLFW ERRROR" );
		};
	};
} // namespace MikuEngine
