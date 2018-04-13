#include "Spell.h"



Spell::Spell()
{
}


Spell::~Spell()
{
}

void Spell::shoot(float startX, float startY, float targetX, float targetY, int levelSize)
{
	individualFeatures();
	m_InFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;
	float gradient = (startX - targetX) / (startY - targetY);
	if (gradient < 0)
	{
		gradient *= -1;
	}
	float ratioXY = SPEED / (1 + gradient);
	m_DistanceY = ratioXY;
	m_DistanceX = ratioXY * gradient;
	if (targetX < startX)
	{
		m_DistanceX *= -1;
	}
	if (targetY < startY)
	{
		m_DistanceY *= -1;
	}
	m_MinX = 0;
	m_MaxX = levelSize * 1920;
	m_MinY = 0;
	m_MaxY = 1080;
	m_SpriteSpell.setPosition(m_Position);
}

void Spell::stop()
{
	m_InFlight = false;
}

bool Spell::isInFlight()
{
	return m_InFlight;
}

FloatRect Spell::getPosition()
{
	return m_SpriteSpell.getGlobalBounds();
}

void Spell::update(float dtAsSeconds)
{
	m_Position.x += m_DistanceX * dtAsSeconds;
	m_Position.y += m_DistanceY * dtAsSeconds;
	m_SpriteSpell.setPosition(m_Position);
	if (m_Position.x < m_MinX || m_Position.x > m_MaxX || m_Position.y < m_MinY || m_Position.y > m_MaxY)
	{
		stop();
	}
}

Sprite Spell::getSprite()
{
	return m_SpriteSpell;
}

float Spell::hit()
{
	srand((int)time(0));
	float power = ((rand() % (m_MaxPower - m_MinPower)) + m_MaxPower);
	return power;
}