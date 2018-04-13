#include "BlackSpell.h"



BlackSpell::BlackSpell()
{
}


BlackSpell::~BlackSpell()
{
}

void BlackSpell::individualFeatures()
{
	m_MinPower = 20;
	m_MaxPower = 40;
	m_TextureSpell = TextureHolder::GetTexture("graphics/magic/black_magic_ball.png");
	m_SpriteSpell.setTexture(m_TextureSpell);
	m_SpriteSpell.setOrigin(34, 34);
}