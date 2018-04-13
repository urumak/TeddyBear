#include "GreenSpell.h"



GreenSpell::GreenSpell()
{
}


GreenSpell::~GreenSpell()
{
}

void GreenSpell::individualFeatures()
{
	m_MinPower = 20;
	m_MaxPower = 25;
	m_TextureSpell = TextureHolder::GetTexture("graphics/magic/green_magic_ball.png");
	m_SpriteSpell.setTexture(m_TextureSpell);
	m_SpriteSpell.setOrigin(34, 34);
}
