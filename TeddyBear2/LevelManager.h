#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Monster.h"
#include "Spider.h"
#include "PoisonSpider.h"
#include "Ghost.h"
#include "RedGhost.h"
#include "GreenGhost.h"
#include "Witch.h"
#include <vector>

using namespace sf;

class LevelManager
{
private:
	TextureHolder m_TextureHolder;
	Texture m_TextureBackground;
	Sprite m_Sprite2;
	Sprite m_Sprite3;
	Sprite m_Sprite5;
	FloatRect m_Size2;
	FloatRect m_Size3;
	FloatRect m_size5;
	vector <Monster*> m_Monsters;
	int m_LevelNum;
	int m_MonstersNumber;
public:
	Sprite nextLevel(int levelNum);
	int getLevelSize();
	vector <Monster*> getMonsters(int levelNum);
	int getMonstersNumber(int levelNum);
	int getBlockTime(int levelNum);
	LevelManager();
	~LevelManager();
};

