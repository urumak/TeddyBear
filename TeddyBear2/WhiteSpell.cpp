#include "WhiteSpell.h"



WhiteSpell::WhiteSpell()
{
}


WhiteSpell::~WhiteSpell()
{
}

void WhiteSpell::individualFeatures()
{
	m_MinPower = 10;
	m_MaxPower = 15;
	m_TextureSpell = TextureHolder::GetTexture("graphics/magic/white_magic_ball.png");
	m_SpriteSpell.setTexture(m_TextureSpell);
	m_SpriteSpell.setOrigin(34, 34);
}