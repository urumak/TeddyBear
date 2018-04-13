#include "RedSpell.h"



RedSpell::RedSpell()
{
}


RedSpell::~RedSpell()
{
}

void RedSpell::individualFeatures()
{
	m_MinPower = 15;
	m_MaxPower = 20;
	m_TextureSpell = TextureHolder::GetTexture("graphics/magic/red_magic_ball.png");
	m_SpriteSpell.setTexture(m_TextureSpell);
	m_SpriteSpell.setOrigin(34, 34);
}
