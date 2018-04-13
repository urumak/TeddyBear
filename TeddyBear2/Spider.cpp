#include "Spider.h"

int Spider::spiderNumber = 0;

Spider::Spider()
{
	spiderNumber++;
	m_SpiderNumber = spiderNumber;
}


Spider::~Spider()
{
}

void Spider::setTexture()
{
	m_MonsterTexture = TextureHolder::GetTexture("graphics/monsters/spider.png");
}

void Spider::setStartFeatures()
{
	m_MaxHealth = 60;
	m_Health = m_MaxHealth;
	m_Stay = 1;
	m_Spell.resize(20);
	for (int i = 0; i < m_Spell.size(); i++)
	{
		m_Spell[i] = nullptr;
	}
	m_Shape = m_MonsterSprite.getGlobalBounds();
	if (m_SpiderNumber % 2 == 0)
	{
		srand((int)time(0) * (m_SpiderNumber + 10));
	}
	else
	{
		srand((int)time(0) / (m_SpiderNumber + 10));
	}
	m_Position.x = (rand() % BCG_SIZE * m_LevelSize);
	m_Position.y = m_Resolution.y - m_Shape.height;
	individualSpeed = 1.7f * (1 - 0.05 * m_SpiderNumber);
	m_MinPower = 5;
	m_MaxPower = 20;
	individualCorrection = 15 + m_SpiderNumber * 7;
	m_StopCorrection = 10;
	m_CanStopTeddy = false;
	timeToHit = 5;
}

Vector2f Spider::spellStartPosition()
{
	return m_Position;
}

