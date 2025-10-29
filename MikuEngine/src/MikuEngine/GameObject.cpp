#include "GameObject.h"

#include "pch.h"

namespace MikuEngine
{
	void GameObject::Update( double dt ) {}

	void GameObject::Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff, const SceneStuff& sceneStuff )
	{
		auto shader = m_BasicQuad.GetShader();

		glm::mat4 mvp = sceneStuff.camera.GetMVPFromModelMatrix( GetModelMatrix() );

		shader.SetUniform<glm::mat4>( "u_MVP", mvp );

		auto texture = appStuff.textureManager.GetTextureByIdentifier( m_TextureIdentifier );
		texture.Bind();
		shader.SetUniform<unsigned int>( "u_Texture", 0 );

		renderer.Draw( m_BasicQuad.GetVA(), m_BasicQuad.GetIB(), m_BasicQuad.GetShader() );
	}

	void GameObject::RenderImGui()
	{
		ImGui::Begin( "Quad GO Properties" );

		ImGui::SeparatorText( "Transform" );
		ImGui::DragFloat3( "Position", &m_Position[0] );
		ImGui::DragFloat3( "Rotation Axis", &m_RotationAxis[0] );
		ImGui::DragFloat3( "Scale", &m_Scale[0] );

		ImGui::End();
	}

	glm::mat4 GameObject::GetModelMatrix() const
	{
		glm::mat4 posMatrix = glm::translate( glm::mat4( 1.0f ), m_Position );
		glm::mat4 rotMatrix = glm::rotate( glm::mat4( 1.0f ), m_RotationValue, m_RotationAxis );
		glm::mat4 scaleMatrix = glm::scale( glm::mat4( 1.0f ), m_Scale );

		return posMatrix * rotMatrix * scaleMatrix * glm::mat4( 1.0f );
	}

}