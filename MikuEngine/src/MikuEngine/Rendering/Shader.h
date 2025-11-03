#pragma once

#include <array>
#include <string>
#include <unordered_map>

#include "glad/gl.h"
#include "glm.hpp"

#include "Core.h"

namespace MikuEngine
{
	class Shader
	{
	  public:
		void Bind() const;
		void UnBind() const;

		void LoadFromFile( const std::string& filepath );
		int GetUniformLocation( const std::string& uniformName );

		template <typename T> void SetUniform( const std::string& uniformName, T value )
		{
			std::cout << "Set Uniform Not Defined";
		}

	  private:
		unsigned int m_RendererID = 0;

		std::unordered_map<std::string, int> m_UniformLocations = {};
	};

	template <> inline void Shader::SetUniform<float>( const std::string& uniformName, float value )
	{
		auto index = GetUniformLocation( uniformName );
		glUniform1f( index, value );
	}

	template <> inline void Shader::SetUniform<unsigned int>( const std::string& uniformName, unsigned int value )
	{
		auto index = GetUniformLocation( uniformName );
		glUniform1i( index, value );
	}

	template <> inline void Shader::SetUniform<glm::vec3>( const std::string& uniformName, glm::vec3 value )
	{
		auto index = GetUniformLocation( uniformName );
		glUniform3f( index, value.x, value.y, value.z );
	}

	template <> inline void Shader::SetUniform<glm::vec4>( const std::string& uniformName, glm::vec4 value )
	{
		auto index = GetUniformLocation( uniformName );
		glUniform4f( index, value.x, value.y, value.z, value.w );
	}

	template <> inline void Shader::SetUniform<glm::mat4>( const std::string& uniformName, glm::mat4 value )
	{
		auto index = GetUniformLocation( uniformName );
		glUniformMatrix4fv( index, 1, GL_FALSE, &value[ 0 ][ 0 ] );
	}

	template <> inline void Shader::SetUniform<std::array<int, 2>>( const std::string& uniformName, std::array<int, 2> value )
	{
		auto index = GetUniformLocation( uniformName );
		glUniform1iv( index, 1, &value[ 0 ] );
	}
} // namespace MikuEngine
