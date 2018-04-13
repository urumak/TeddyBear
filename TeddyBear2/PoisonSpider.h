#pragma once
#include "Monster.h"
#include "Spell.h"
#include "Poison.h"
#include <vector>

class PoisonSpider :
	public Monster
{
	int m_SpiderNumber;
protected:
	virtual void setTexture();
	virtual void setStartFeatures();
	virtual Vector2f spellStartPosition();
public:
	static int spiderNumber;
	PoisonSpider();
	~PoisonSpider();
};

