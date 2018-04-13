#pragma once
#include "Monster.h"
#include "WhiteSpell.h"

class Ghost :
		public Monster
{
	int m_GhostNumber;
protected:
	virtual void setTexture();
	virtual void setStartFeatures();
	virtual Vector2f spellStartPosition();
public:
	static int ghostNumber;
	Ghost();
	~Ghost();
};

