#pragma once

#include "glm.hpp"

namespace MikuEngine
{
	class DataContainer
	{
	public:
		glm::vec2 GetViewportDimensions() const { return m_ViewportDimensions; }
		void SetViewportDimensions( glm::vec2 dimensions ) { m_ViewportDimensions = dimensions; }

	private:
		glm::vec2 m_ViewportDimensions = glm::vec2( 100.0f );
	};
}