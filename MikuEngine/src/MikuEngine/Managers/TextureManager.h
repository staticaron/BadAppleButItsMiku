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
		std::unordered_map<std::string_view, std::string_view> m_TexturePaths = {
			// clang-format off

			{ "miku_blue",   RESOURCE_DIR "textures/miku_blue.png"},
			{ "miku_white",	 RESOURCE_DIR "textures/miku_white.png"},
			{ "miku_purple", RESOURCE_DIR "textures/miku_purple.png"},
			{ "miku_pink",   RESOURCE_DIR "textures/miku_pink.png"},
			{ "miku_yellow", RESOURCE_DIR "textures/miku_yellow.png"},
		    { "miku_red",    RESOURCE_DIR "textures/miku_red.png"},
			{ "miku_leaf",   RESOURCE_DIR "textures/miku_leaf.png"},
			{ "miku_water",  RESOURCE_DIR "textures/miku_water.png"},
			{ "miku_cherry", RESOURCE_DIR "textures/miku_cherry.png"},
			{ "miku_paper",  RESOURCE_DIR "textures/miku_paper.png"},
			{ "miku_scary",  RESOURCE_DIR "textures/miku_scary.png"},

			// clang-format on
		};

		std::unordered_map<std::string_view, Texture> m_Textures = {};
	};
} // namespace MikuEngine