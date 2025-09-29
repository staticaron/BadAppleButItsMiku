#include "Camera.h"

namespace MikuEngine
{
	glm::mat4 Camera::GetViewProjectionMatrix() const
	{
		glm::mat4 proj = glm::ortho( 0.0f, 800.0f, 600.0f, 0.0f, 2.0f, -2.0f );
		glm::mat4 view = GetViewMatrix();

		return proj * view;
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		glm::mat4 rotationMatrix = glm::rotate( glm::mat4( 1.0f ), -m_RotationValue, m_RotationAxis );
		glm::mat4 translateMatrix = glm::translate( glm::mat4( 1.0f ), -m_Position );

		return rotationMatrix * translateMatrix;
	}

	void Camera::Translate( glm::vec3 delta )
	{
		m_Position += delta;
	}

	void Camera::SetPosition( glm::vec3 newPosition )
	{
		m_Position = newPosition;
	}
}