#pragma once
#include "Monster.h"
#include "BlackSpell.h"

class Witch :
	public Monster
{
protected:
	virtual void setTexture();
	virtual void setStartFeatures();
	virtual Vector2f spellStartPosition();
public:
	Witch();
	~Witch();
};

