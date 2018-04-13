#include "Witch.h"



Witch::Witch()
{
	m_ThisShootTime = 0;
}


Witch::~Witch()
{
}

void Witch::setTexture()
{
	m_MonsterTexture = TextureHolder::GetTexture("graphics/monsters/witch.png");
}


void Witch::setStartFeatures()
{
	m_MaxHealth = 1000;
	m_Health = m_MaxHealth;
	m_Stay = 0;
	m_Spell.resize(20);
	for (int i = 0; i < m_Spell.size(); i++)
	{
		m_Spell[i] = new BlackSpell;
	}
	m_Shape = m_MonsterSprite.getGlobalBounds();
	m_Position.x = 5 * BCG_SIZE - 640;
	m_Position.y = m_Resolution.y - m_Shape.height;
	individualSpeed = 1.5f;
	m_MinPower = 10;
	m_MaxPower = 30;
	individualCorrection = 10;
	m_TimeToShoot = 1.5;
	m_CanStopTeddy = true;
}


Vector2f Witch::spellStartPosition()
{
	Vector2f start;
	start.x = m_Position.x + 80;
	start.y = m_Position.y + 144;
	return start;
}