#include "PoisonSpider.h"

int PoisonSpider::spiderNumber = 0;

PoisonSpider::PoisonSpider()
{
	spiderNumber++;
	m_SpiderNumber = spiderNumber;
	m_ThisShootTime = 0;
}


PoisonSpider::~PoisonSpider()
{
}

void PoisonSpider::setTexture()
{
	m_MonsterTexture = TextureHolder::GetTexture("graphics/monsters/poison_spider.png");
}

void PoisonSpider::setStartFeatures()
{
	m_MaxHealth = 90;
	m_Health = m_MaxHealth;
	m_Stay = 1;
	m_Spell.resize(20);
	for (int i = 0; i < m_Spell.size(); i++)
	{
		m_Spell[i] = new Poison;
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
	individualSpeed = 1.5f * (1 - 0.05 * m_SpiderNumber);
	m_MinPower = 5;
	m_MaxPower = 15;
	individualCorrection = m_SpiderNumber * 7;
	if (m_SpiderNumber % 2 == 0)
	{
		m_TimeToShoot = 6;
	}
	else
	{
		m_TimeToShoot = 6;
	}
	m_StopCorrection = individualCorrection;
	m_CanStopTeddy = false;
	timeToHit = 7;
}

Vector2f PoisonSpider::spellStartPosition()
{
	return m_Position;
}

