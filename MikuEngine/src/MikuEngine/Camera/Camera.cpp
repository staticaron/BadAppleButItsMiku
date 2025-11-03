#include "Camera.h"

#include "pch.h"

namespace MikuEngine
{
	Camera::Camera()
	{
		m_Position = { glm::vec3( Application::GetDataContainer().GetViewportDimensions().x / 2.0f, Application::GetDataContainer().GetViewportDimensions().y / 2.0f, 0.0f ) };
		m_RotationValue = 0.0f;
	}

	glm::mat4 Camera::GetViewProjectionMatrix() const
	{
		auto viewPortDimension = Application::GetDataContainer().GetViewportDimensions();

		float hw = viewPortDimension.x / ( 2 * m_Zoom );
		float hh = viewPortDimension.y / ( 2 * m_Zoom );

		glm::mat4 projMatrix = glm::ortho( -hw, hw, hh, -hh, -1000.0f, 1000.0f );
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
		return GetViewProjectionMatrix() * modelMatrix;
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
		m_Position = { glm::vec3( Application::GetDataContainer().GetViewportDimensions().x / 2.0f, Application::GetDataContainer().GetViewportDimensions().y / 2.0f, 0.0f ) };

		ImGui::Begin( "Camera Properties" );

		ImGui::SeparatorText( "Transform" );
		ImGui::DragFloat3( "Position", &m_Position[ 0 ] );
		ImGui::DragFloat3( "Rotation Axis", &m_RotationAxis[ 0 ] );
		ImGui::DragFloat( "Zoom", &m_Zoom, 0.1f, 1.0f, 100.0f );

		ImGui::End();
	}
} // namespace MikuEngine