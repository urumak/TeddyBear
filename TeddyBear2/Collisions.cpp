#include "Engine.h"

void Engine::collisions(float dtAsSeconds)
{
	if (m_IsBlocking)
	{
		m_ThisBlockTime += dtAsSeconds;
		if (m_ThisBlockTime >= BLOCK_DURATION)
		{
			m_IsBlocking = false;
			m_Teddy.setBlock(m_IsBlocking);
			m_ThisBlockTime = 0;
		}
	}
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if (m_Monsters[i]->isMonsterAlive())
		{
			if (m_Monsters[i]->getSprite().getGlobalBounds().intersects(m_Teddy.getSprite().getGlobalBounds()) && !m_IsBlocking)
			{
				m_Teddy.damage(m_Monsters[i]->hit(dtAsSeconds));
			}
			for (int j = 0; j < m_Teddy.getMagicNum(); j++)
			{
				if (m_MagicBall[j].isInFlight() && m_MagicBall[j].getSprite().getGlobalBounds().intersects(m_Monsters[i]->getSprite().getGlobalBounds()))
				{
					m_Monsters[i]->damage(m_MagicBall[j].hit());
					m_MagicBall[j].stop();
				}
			}
			m_Spell = m_Monsters[i]->getSpell();
			for (int j = 0; j < m_Spell.size(); j++)
			{
				if (m_Spell[j] != nullptr && m_Spell[j]->isInFlight() && 
					m_Spell[j]->getPosition().intersects(m_Teddy.getSprite().getGlobalBounds()))
				{
					if (!m_IsBlocking)
						m_Teddy.damage(m_Spell[j]->hit());
					m_Spell[j]->stop();
				}
			}
		}
	}
	bool stop = false;
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if (m_Monsters[i]->isMonsterAlive() && m_Monsters[i]->canStopTeddy() && 
			m_Monsters[i]->getSprite().getGlobalBounds().intersects(m_Teddy.getSprite().getGlobalBounds()))
		{
			stop = true;
			m_Teddy.stopR(true);
		}
		else if (!stop)
		{
			m_Teddy.stopR(false);
		}
	}
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if (!(m_Monsters[i]->canStopTeddy()) && m_Teddy.falling() && m_LastJumpAttack >= JUMP_ATTACK && 
			m_Monsters[i]->getSprite().getGlobalBounds().intersects(m_Teddy.getSprite().getGlobalBounds()) && m_Monsters[i]->isMonsterAlive())
		{
			m_Monsters[i]->damage(m_Teddy.hit());
			m_LastJumpAttack = 0;
		}
	}
}