#pragma once
#include "Spell.h"
class WhiteSpell :
	public Spell
{
protected:
	virtual void individualFeatures(); 
public:
	WhiteSpell();
	~WhiteSpell();
};

