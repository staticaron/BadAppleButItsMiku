#pragma once

#include <string_view>

#include "ApplicationLevelStuff.h"
#include "Rendering/BasicQuad.h"
#include "Rendering/Renderer.h"
#include "Scene/SceneStuff.h"

namespace MikuEngine
{
	class MIKU_API GameObject
	{
	public:
		GameObject() = default;
		~GameObject() = default;

		void Update( double dt );
		void Render( const Renderer& renderer, const ApplicationLevelStuff& appStuff, const SceneStuff& sceneStuff );
		void RenderImGui();

		glm::mat4 GetModelMatrix() const;

	private:
		glm::vec3 m_Position = glm::vec3( 100.0f, 100.0f, 0.0f );
		glm::vec3 m_RotationAxis = { 0.0f, 0.0f, 1.0f };
		float m_RotationValue = 0.0f;
		glm::vec3 m_Scale = glm::vec3( 100.0f );

		BasicQuad m_BasicQuad;
		std::string_view m_TextureIdentifier = "miku";
	};
}