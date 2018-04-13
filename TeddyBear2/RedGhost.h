#pragma once
#include "Monster.h"
#include "RedSpell.h"

class RedGhost :
	public Monster
{
	int m_GhostNumber;
protected:
	virtual void setTexture();
	virtual void setStartFeatures();
	virtual Vector2f spellStartPosition();
public:
	static int ghostNumber;
	RedGhost();
	~RedGhost();
};

