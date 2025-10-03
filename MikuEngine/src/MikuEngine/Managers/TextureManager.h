#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

#include "Rendering/Texture.h"

namespace MikuEngine
{
	class MIKU_API TextureManager
	{
	public:
		TextureManager() = default;
		~TextureManager() = default;

		void LoadAllTextures();
		void LoadTexture( std::string_view identifier, std::string_view filepath );

		const Texture& GetTextureByIdentifier( std::string_view identifier ) const;

	private:
		std::unordered_map<std::string_view, std::string_view> m_TexturePaths =
		{
			{"miku", RESOURCE_DIR "textures/miku.png"}
		};

		std::unordered_map<std::string_view, Texture> m_Textures = {};
	};
}