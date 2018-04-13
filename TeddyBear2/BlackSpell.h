#pragma once
#include "Spell.h"
class BlackSpell :
	public Spell
{
protected:
	virtual void individualFeatures(); 
public:
	BlackSpell();
	~BlackSpell();
};

