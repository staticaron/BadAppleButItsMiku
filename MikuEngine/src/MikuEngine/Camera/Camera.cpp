#include "Camera.h"

#include "pch.h"

namespace MikuEngine
{
	Camera::Camera()
	{
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

	void Camera::Update( double dt )
	{
		if ( m_IsTweening )
		{
			if ( m_IsZoomingIn )
			{
				m_CurrentTweenTime += dt;

				if ( m_CurrentTweenTime > m_TweenTime )
				{
					m_CurrentTweenTime = 0.0f;
					m_IsTweening = false;
					m_Zoom = m_MaxZoom;
				}
				else
					m_Zoom = glm::mix( m_MinZoom, m_MaxZoom, m_CurrentTweenTime / m_TweenTime );
			}
			else
			{
				m_CurrentTweenTime += dt;

				if ( m_CurrentTweenTime > m_TweenTime )
				{
					m_CurrentTweenTime = 0.0f;
					m_IsTweening = false;
					m_Zoom = m_MinZoom;
				}
				else
					m_Zoom = glm::mix( m_MaxZoom, m_MinZoom, m_CurrentTweenTime / m_TweenTime );
			}
		}
	}

	void Camera::RenderImGui()
	{
		ImGui::Begin( "Camera Properties" );

		ImGui::SeparatorText( "Transform" );
		ImGui::DragFloat3( "Position", &m_Position[ 0 ] );
		ImGui::DragFloat3( "Rotation Axis", &m_RotationAxis[ 0 ] );
		ImGui::DragFloat( "Zoom", &m_Zoom, 0.1f, 1.0f, 100.0f );
		ImGui::Separator();

		ImGui::DragFloat( "Zoom Time", &m_TweenTime );
		if ( ImGui::Button( "Zoom Out" ) )
		{
			m_IsTweening = true;
			m_IsZoomingIn = false;
		}

		if ( ImGui::Button( "Zoom In" ) )
		{
			m_IsTweening = true;
			m_IsZoomingIn = true;
		}

		if ( ImGui::Button( "Reset Zoom" ) )
		{
			m_IsTweening = false;
			m_IsZoomingIn = false;
			m_CurrentTweenTime = 0.0f;
		}

		ImGui::End();
	}
} // namespace MikuEngine