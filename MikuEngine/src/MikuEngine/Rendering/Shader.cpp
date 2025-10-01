#include "Rendering/Shader.h"

#include "pch.h"

namespace MikuEngine
{
	void Shader::Bind() const
	{
		glUseProgram( m_RendererID );
	}

	void Shader::UnBind() const
	{
		glUseProgram( 0 );
		spdlog::warn( "VertexBuffer Deleted" );
	}

	void Shader::LoadFromFile( const std::string& filepath )
	{
		std::string vertexShader = "", fragmentShader = "";
		ShaderParser::ParseShader( filepath, vertexShader, fragmentShader );
		m_RendererID = ShaderParser::CreateShader( vertexShader, fragmentShader );
	}

	int Shader::GetUniformLocation( const std::string& uniformName )
	{
		Bind();

		if( m_UniformLocations.find( uniformName ) != m_UniformLocations.end() )
			return m_UniformLocations.at( uniformName );

		int location = glGetUniformLocation( m_RendererID, uniformName.c_str() );

		if( location < 0 ) std::cout << "Error Occured while trying to GetUniform named " << uniformName << std::endl;

		m_UniformLocations[uniformName] = location;

		return location;
	}
}