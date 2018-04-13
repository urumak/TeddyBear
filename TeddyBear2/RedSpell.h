#pragma once
#include "Spell.h"
class RedSpell :
	public Spell
{
protected:
	virtual void individualFeatures();
public:
	RedSpell();
	~RedSpell();
};

