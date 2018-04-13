#include "Teddy.h"

void Teddy::updateTeddy(float dtAsSeconds, int levelSize)
{
	m_LastStep += dtAsSeconds;
	if (!isJumping)
	{
		walk(dtAsSeconds, levelSize);
	}
	else
	{
		jump(dtAsSeconds, levelSize);
	}
	if (m_Health < MAX_HEALTH && m_Alive)
	{
		Vector2f newSize;
		newSize.x = m_HealthBar.getSize().x + dtAsSeconds;
		newSize.y = m_HealthBar.getSize().y;
		m_HealthBar.setSize(newSize);
		m_Health = newSize.x;
	}
	m_SpriteTeddy.setTexture(m_TextureTeddy);
	m_SpriteTeddy.setPosition(m_Position);
	for (int i = 0; i < magicNum; i++)
	{
		magicBall[i].update(dtAsSeconds);
	}
}