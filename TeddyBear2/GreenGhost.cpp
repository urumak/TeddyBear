#include "GreenGhost.h"

int GreenGhost::ghostNumber = 0;

GreenGhost::GreenGhost()
{
	ghostNumber++;
	m_GhostNumber = ghostNumber;
	m_ThisShootTime = 0;
}


GreenGhost::~GreenGhost()
{
}
void GreenGhost::setTexture()
{
	m_MonsterTexture = TextureHolder::GetTexture("graphics/monsters/green_ghost.png");
}


void GreenGhost::setStartFeatures()
{
	m_MaxHealth = 180;
	m_Health = m_MaxHealth;
	m_Stay = 1;
	m_Spell.resize(20);
	for (int i = 0; i < m_Spell.size(); i++)
	{
		m_Spell[i] = new GreenSpell;
	}
	m_Shape = m_MonsterSprite.getGlobalBounds();
	switch (m_LevelNumber)
	{
	case 6:
		switch (m_GhostNumber)
		{
		case 1:
			m_Position.x = BCG_SIZE;
			break;
		case 2:
			m_Position.x = 2 * BCG_SIZE - 360;
			break;
		}
		break;
	case 7:
		switch (m_GhostNumber)
		{
		case 1:
			m_Position.x = BCG_SIZE;
			break;
		case 2:
			m_Position.x = 2 * BCG_SIZE - 360;
			break;
		case 3:
			m_Position.x = 2 * BCG_SIZE - 410;
			break;
		}
		break;
	case 8:
		if (m_GhostNumber % 2 == 0)
		{
			srand((int)time(0) / (m_GhostNumber + 10));
		}
		else
		{
			srand((int)time(0) * (m_GhostNumber + 10));
		}
		m_Position.x = ((rand() % ((BCG_SIZE * m_LevelSize) - 860)) + 500);
		break;

	}
	m_Position.y = m_Resolution.y - m_Shape.height;
	individualSpeed = 1.5f * (1 - 0.05 * m_GhostNumber);
	m_MinPower = 5;
	m_MaxPower = 10;
	individualCorrection = 1075 + 30 * m_GhostNumber;
	if (m_GhostNumber % 2 == 0)
	{
		m_TimeToShoot = 3;
	}
	else
	{
		m_TimeToShoot = 2.7f;
	}
	m_StopCorrection = 30 * m_GhostNumber;
	m_CanStopTeddy = true;
	timeToHit = 1;
}

Vector2f GreenGhost::spellStartPosition()
{
	Vector2f start;
	start.x = m_Position.x + m_MonsterSprite.getGlobalBounds().width / 2;
	start.y = m_Position.y + m_MonsterSprite.getGlobalBounds().height / 2;
	return start;
}
