#include "TextureManager.h"

#include "../stb/include/stb_image.h"
#include "pch.h"

namespace MikuEngine
{
	void TextureManager::LoadAllTextures()
	{
		stbi_set_flip_vertically_on_load( true );

		for ( const auto& [ identifier, path ] : m_TexturePaths )
		{
			spdlog::info( path.data() );

			auto t = path.data();

			m_Textures[ identifier ] = Texture( path.data() );
		}
	}
	void TextureManager::LoadTexture( std::string_view identifier, std::string_view filepath )
	{
		stbi_set_flip_vertically_on_load( true );

		m_Textures[ identifier ] = Texture( filepath.data() );
	}

	const Texture& TextureManager::GetTextureByIdentifier( std::string_view identifier ) const
	{
		auto alreadyExistingTex = m_Textures.find( identifier );

		ASSERT( alreadyExistingTex != m_Textures.end(), "No Texture by the name " << identifier << " exists" );

		return alreadyExistingTex->second;
	}
} // namespace MikuEngine
