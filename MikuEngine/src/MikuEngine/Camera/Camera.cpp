#include "Camera.h"

#include "pch.h"

namespace MikuEngine
{
	glm::mat4 Camera::GetViewProjectionMatrix() const
	{
		auto viewPortDimension = Application::GetDataContainer().GetViewportDimensions();
		glm::mat4 projMatrix = glm::ortho( 0.0f, viewPortDimension.x, viewPortDimension.y, 0.0f, -1000.0f, 1000.0f );
		return projMatrix * GetViewMatrix();
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		glm::mat4 positionMatrix = glm::translate( glm::mat4( 1.0f ), -m_Position );
		glm::mat4 rotationMatrix = glm::rotate( glm::mat4( 1.0f ), -m_RotationValue, m_RotationAxis );

		return rotationMatrix * positionMatrix;
	}

	glm::mat4 Camera::GetMVPFromModelMatrix( glm::mat4 modelMatrix ) const
	{
		auto viewPortDimension = Application::GetDataContainer().GetViewportDimensions();

		glm::mat4 projMatrix = glm::ortho( 0.0f, viewPortDimension.x, viewPortDimension.y, 0.0f, -1000.0f, 1000.0f );
		glm::mat4 viewMatrix = GetViewMatrix();

		return projMatrix * viewMatrix * modelMatrix;
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