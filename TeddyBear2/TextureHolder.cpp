#include "TextureHolder.h"

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(std::string const& filename)
{
	map<string, Texture>& m = m_s_Instance->m_Textures;
	map<string,Texture>::iterator keyValuePair = m.find(filename);
	if (keyValuePair != m.end())
	{
		return keyValuePair->second;
	}
	else
	{
		Texture& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}