#pragma once
#include <SFML/Graphics.hpp>
#include "Monster.h"

using namespace sf;

class Spider :
	public Monster
{
	int m_SpiderNumber;
protected:
	virtual void setTexture();
	virtual void setStartFeatures();
	virtual Vector2f spellStartPosition();
public:
	static int spiderNumber;
	Spider();
	~Spider();
};

