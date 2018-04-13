#pragma once
#include "Spell.h"
class GreenSpell :
	public Spell
{
protected:
	virtual void individualFeatures(); 
public:
	GreenSpell();
	~GreenSpell();
};

