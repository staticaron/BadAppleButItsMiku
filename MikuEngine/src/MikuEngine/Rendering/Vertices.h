#pragma once

#include "glm.hpp"

namespace MikuEngine
{
	struct BasicVertex
	{
		glm::vec3 Position = { 0, 0, 0 };
		glm::vec2 UV	   = { 0, 0 };

		BasicVertex ApplyTransform( glm::mat4 transformationMatrix ) const
		{
			glm::vec4 transformReadyPos = glm::vec4( Position, 1.0f );
			glm::vec4 newPosition		= transformationMatrix * transformReadyPos;

			return { newPosition, UV };
		}
	};

	struct BareboneVertex
	{
		glm::vec3 Position = { 0, 0, 0 };

		BareboneVertex ApplyTransform( glm::mat4 transformationMatrix ) const
		{
			glm::vec4 transformReadyPos = glm::vec4( Position, 1.0f );
			glm::vec4 newPosition		= transformationMatrix * transformReadyPos;

			return { newPosition };
		}
	};
} // namespace MikuEngine