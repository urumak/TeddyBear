#include "Monster.h"



Monster::Monster()
{
}


Monster::~Monster()
{
}

void Monster::setStartFeatures()
{
	m_Spell.resize(20);
	for (int i = 0; i < m_Spell.size(); i++)
	{
		m_Spell[i] = nullptr;
	}
}

void Monster::spawn(int levelSize, int levelNumber)
{
	m_LevelSize = levelSize;
	m_LevelNumber = levelNumber;
	m_Resolution.x = VideoMode::getDesktopMode().width;
	m_Resolution.y = VideoMode::getDesktopMode().height;
	setTexture();
	m_MonsterSprite.setTexture(m_MonsterTexture);
	setStartFeatures();
	m_MonsterSprite.setPosition(m_Position);
}

bool Monster::isMonsterAlive()
{
	return isAlive;
}


void Monster::fire(Vector2f target, int levelSize, float dtAsSeconds)
{
	float distance = m_Position.x - target.x;
	if (distance < 0)
	{
		distance *= -1;
	}
	if (distance < 1300)
	{
		m_ThisShootTime += dtAsSeconds;
		if (m_ThisShootTime >= m_TimeToShoot)
		{
			if (m_CurrentSpell == SPELL_NUM)
			{
				m_CurrentSpell = 0;
			}
			Vector2f startPosition = spellStartPosition();
			m_Spell[m_CurrentSpell]->shoot(startPosition.x, startPosition.y, target.x, target.y, levelSize);
			m_CurrentSpell++;
			m_ThisShootTime = 0;
		}
	}
	for (int i = 0; i < SPELL_NUM; i++)
	{
		m_Spell[i]->update(dtAsSeconds);
	}
}

void Monster::update(float dtAsSeconds, Vector2f target, int levelSize)
{
	m_LevelSize = levelSize;
	float targetX = m_Stay * target.x + individualCorrection;
	float distance;
	distance = m_Position.x - targetX;
	if (distance < 0)
	{
		distance *= -1;
	}
	if (distance < 1300)
	{
		if (targetX < m_Position.x)
		{
			m_Position.x -= SPEED*individualSpeed*dtAsSeconds;
		}
		if (targetX > m_Position.x)
		{
			if (m_Position.x + m_Shape.width <= BCG_SIZE*levelSize + m_StopCorrection)
				m_Position.x += SPEED*individualSpeed*dtAsSeconds;
		}
		m_MonsterSprite.setPosition(m_Position);
	}
	if (m_Spell[0] != nullptr)
	{
		fire(target, levelSize, dtAsSeconds);
	}
}

Sprite Monster::getSprite()
{
	return m_MonsterSprite;
}

float Monster::hit(float dtAsSeconds)
{
	lastHitTime += dtAsSeconds;
	if (lastHitTime >= timeToHit)
	{
		srand((int)time(0));
		float power = ((rand() % (m_MaxPower - m_MinPower)) + m_MaxPower);
		lastHitTime = 0;
		return power;
	}
	return 0;
}

Vector2f Monster::getPosition()
{
	return m_Position;
}

vector<Spell*> Monster::getSpell()
{
	return m_Spell;
}


bool Monster::canStopTeddy()
{
	return m_CanStopTeddy;
}

void Monster::damage(float power)
{
	m_Health -= power;
	if (m_Health <= 0)
	{
		isAlive = false;
	}
}