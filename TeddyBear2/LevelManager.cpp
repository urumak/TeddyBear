#include "LevelManager.h"



LevelManager::LevelManager()
{
}


LevelManager::~LevelManager()
{
}

Sprite LevelManager::nextLevel(int levelNum)
{
	m_LevelNum = levelNum;
	switch (levelNum)
	{
	case 1:
		m_TextureBackground = TextureHolder::GetTexture("graphics/levels/kitchen.png");
		m_Sprite2.setTexture(m_TextureBackground);
		m_Sprite2.setPosition(0, 0);
		return m_Sprite2;
	case 2:
		m_TextureBackground = TextureHolder::GetTexture("graphics/levels/dining_room.png");
		m_Sprite2.setTexture(m_TextureBackground);
		m_Sprite2.setPosition(0, 0);
		return m_Sprite2;
	case 3:
		m_TextureBackground = TextureHolder::GetTexture("graphics/levels/living_room.png");
		m_Sprite3.setTexture(m_TextureBackground);
		m_Sprite3.setPosition(0, 0);
		return m_Sprite3;
	case 4:
		m_TextureBackground = TextureHolder::GetTexture("graphics/levels/bathroom.png");
		m_Sprite2.setTexture(m_TextureBackground);
		m_Sprite2.setPosition(0, 0);
		return m_Sprite2;
	case 5:
		m_TextureBackground = TextureHolder::GetTexture("graphics/levels/room.png");
		m_Sprite2.setTexture(m_TextureBackground);
		m_Sprite2.setPosition(0, 0);
		return m_Sprite2;
	case 6:
		m_TextureBackground = TextureHolder::GetTexture("graphics/levels/bedroom.png");
		m_Sprite2.setTexture(m_TextureBackground);
		m_Sprite2.setPosition(0, 0);
		return m_Sprite2;
	case 7:
		m_TextureBackground = TextureHolder::GetTexture("graphics/levels/office.png");
		m_Sprite2.setTexture(m_TextureBackground);
		m_Sprite2.setPosition(0, 0);
		return m_Sprite2;
	case 8:
		m_TextureBackground = TextureHolder::GetTexture("graphics/levels/roof.png");
		m_Sprite5.setTexture(m_TextureBackground);
		m_Sprite5.setPosition(0, 0);
		return m_Sprite5;
	}
}

int LevelManager::getLevelSize()
{
	switch (m_LevelNum)
	{
	case 3:
		return 3;
	case 8:
		return 5;
	default:
		return 2;
	}
}



int LevelManager::getMonstersNumber(int levelNum)
{
	switch (levelNum)
	{
	case 1:
		return 8;
	case 2:
		return 10;
	case 3:
		return 18;
	case 4:
		return 12;
	case 5:
		return 12;
	case 6:
		return 12;
	case 7:
		return 15;
	case 8:
		return 31;
	}
}

int LevelManager::getBlockTime(int levelNum)
{
	switch (levelNum)
	{
	case 6:
		return 7;
	case 7:
		return 5;
	case 8:
		return 3;
	default:
		return 10;
	}
}