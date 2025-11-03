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

			{ "miku_blue", RESOURCE_DIR "textures/miku_blue.png"},
			{ "miku_white",	RESOURCE_DIR "textures/miku_white.png"},
		    { "miku_green", RESOURCE_DIR "textures/miku_green.png"},
			{ "miku_purple", RESOURCE_DIR "textures/miku_purple.png"},
			{ "miku_cyan", RESOURCE_DIR "textures/miku_cyan.png"},
			{ "miku_yellow",	RESOURCE_DIR "textures/miku_yellow.png"},
		    { "miku_red", RESOURCE_DIR "textures/miku_red.png"},
			{ "miku_black", RESOURCE_DIR "textures/miku_black.png"},
			{ "miku_skyblue", RESOURCE_DIR "textures/miku_skyblue.png"},

			// clang-format on
		};

		std::unordered_map<std::string_view, Texture> m_Textures = {};
	};
} // namespace MikuEngine