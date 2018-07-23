/// <summary>
/// @authors: Przemek Tomczyk - C00218004
/// </summary>

#include "ResourceManager.h"

ResourceManager::ResourceManager() // default constructor
{
	// load all assets into holders
	loadTextures();
	loadFonts();
	loadBuffers();
}

ResourceManager::~ResourceManager() // default destructor
{
}

sf::Texture & ResourceManager::getTexture(TextureID t_textureID)
{
	return m_textureHolder[t_textureID];
}

sf::Font & ResourceManager::getFont(FontID t_fontID)
{
	return m_fontHolder[t_fontID];
}

sf::SoundBuffer & ResourceManager::getBuffer(SoundBufferID t_bufferID)
{
	return m_bufferHolder[t_bufferID];
}

void ResourceManager::loadTextures()
{
	try
	{
		//eg below
		//m_textureHolder.acquire(TextureID::PLAYER_TEXTURE, thor::Resources::fromFile<sf::Texture>("ASSETS\\IMAGES\\Player.png"));
	}
	catch (thor::ResourceLoadingException& e)
	{
		std::cout << "Error with texture: " << e.what() << std::endl;
	}
}

void ResourceManager::loadFonts()
{
	try
	{
		m_fontHolder.acquire(FontID::ARIBLK, thor::Resources::fromFile<sf::Font>("ASSETS\\fonts\\ariblk.ttf"));
		m_fontHolder.acquire(FontID::ORDINARY, thor::Resources::fromFile<sf::Font>("ASSETS\\fonts\\Ordinary.ttf"));

	}
	catch (thor::ResourceLoadingException& e)
	{
		std::cout << "Error with font: " << e.what() << std::endl;
	}
}

void ResourceManager::loadBuffers()
{
	try
	{
		//eg below
		//m_bufferHolder.acquire(SoundBufferID::BUTTON_CLICK, thor::Resources::fromFile<sf::SoundBuffer>("ASSETS\\SOUNDS\\buttonClick.wav"));
	}
	catch (thor::ResourceLoadingException& e)
	{
		std::cout << "Error with buffer: " << e.what() << std::endl;
	}
}

