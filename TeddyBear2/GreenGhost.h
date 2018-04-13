#pragma once
#include "Monster.h"
#include "GreenSpell.h"

class GreenGhost :
	public Monster
{
	int m_GhostNumber;
protected:
	virtual void setTexture();
	virtual void setStartFeatures();
	virtual Vector2f spellStartPosition();
public:
	static int ghostNumber;
	GreenGhost();
	~GreenGhost();
};

