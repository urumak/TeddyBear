#pragma once
#include "Spell.h"
class Poison :
	public Spell
{
	void individualFeatures();
	int m_TextureNumber;
public:
	Poison();
	~Poison();
};

