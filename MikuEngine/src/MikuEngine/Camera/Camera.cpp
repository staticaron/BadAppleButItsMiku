#include "Camera.h"

#include "pch.h"

namespace MikuEngine
{
	glm::mat4 Camera::GetViewProjectionMatrix() const
	{
		glm::mat4 proj = glm::ortho( 0, 800, 600, 0, -2, 2 );
		return proj * GetViewMatrix();
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		glm::mat4 positionMatrix = glm::translate( glm::mat4( 1.0f ), -m_Position );
		glm::mat4 rotationMatrix = glm::rotate( glm::mat4( 1.0f ), -m_RotationValue, m_RotationAxis );

		return rotationMatrix * positionMatrix;
	}

	void Camera::Translate( glm::vec3 delta )
	{
		m_Position += delta;
	}

	void Camera::SetPosition( glm::vec3 newPos )
	{
		m_Position = newPos;
	}

	void Camera::RenderImGui()
	{
		ImGui::Begin( "Camera Properties" );

		ImGui::SeparatorText( "Transform" );
		ImGui::DragFloat3( "Position", &m_Position[0] );
		ImGui::DragFloat3( "Rotation Axis", &m_RotationAxis[0] );
		ImGui::DragFloat3( "Scale", &m_Scale[0] );

		ImGui::End();
	}
}