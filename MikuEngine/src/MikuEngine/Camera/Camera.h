#pragma once

#include "glm.hpp"

namespace MikuEngine
{
	class MIKU_API Camera
	{
	  public:
		Camera();
		~Camera() = default;

		glm::mat4 GetViewProjectionMatrix() const;
		glm::mat4 GetViewMatrix() const;
		glm::mat4 GetMVPFromModelMatrix( glm::mat4 modelMatrix ) const;

		void Translate( glm::vec3 delta );
		void SetPosition( glm::vec3 newPos );

		void SetZoom( float newZoom );
		void Zoom( float amountToZoom );

		void Update( double dt );
		void RenderImGui();

	  private:
		glm::vec3 m_Position = glm::vec3( 450.0f, 340.25f, 0.0f );

		const float m_MinZoom = 1.0f;
		const float m_MaxZoom = 100.0f;
		float m_Zoom = 1.0f;

		glm::vec3 m_RotationAxis = { 0.0f, 1.0f, 0.0f };
		float m_RotationValue = 0.0f;

		double m_CurrentTweenTime = 0.0f;
		float m_TweenTime = 2.0f;
		bool m_IsTweening = false;
		bool m_IsZoomingIn = false;
	};
} // namespace MikuEngine