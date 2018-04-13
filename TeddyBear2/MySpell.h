#pragma once
#include "Spell.h"
class MySpell :
	public Spell
{
protected:
	virtual void individualFeatures(); 
public:
	MySpell();
	~MySpell();
};

