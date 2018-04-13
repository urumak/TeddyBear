#include "Poison.h"



Poison::Poison()
{
}


Poison::~Poison()
{
}

void Poison::individualFeatures()
{
	m_MinPower = 5;
	m_MaxPower = 10;
	m_TextureSpell = TextureHolder::GetTexture("graphics/magic/poison.png");
	m_SpriteSpell.setTexture(m_TextureSpell);
	m_TextureNumber = 1;
	m_SpriteSpell.setOrigin(10, 7);
}

