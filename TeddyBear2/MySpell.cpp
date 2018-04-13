#include "MySpell.h"



MySpell::MySpell()
{
}


MySpell::~MySpell()
{
}

void MySpell::individualFeatures()
{
	m_MinPower = 20;
	m_MaxPower = 30;
	m_TextureSpell = TextureHolder::GetTexture("graphics/magic/magic_ball.png");
	m_SpriteSpell.setTexture(m_TextureSpell);
	m_SpriteSpell.setOrigin(34, 34);
}
