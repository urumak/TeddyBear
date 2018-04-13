#include "LevelManager.h"

vector <Monster*> LevelManager::getMonsters(int levelNum)
{
	switch (levelNum)
	{
	case 1:
		m_MonstersNumber = 8;
		m_Monsters.resize(m_MonstersNumber);
		for (int i = 0; i < m_MonstersNumber; i++)
		{
			if (i < 6)
			{
				m_Monsters[i] = new Spider;
			}
			else
			{
				m_Monsters[i] = new Ghost;
			}
		}
		return m_Monsters;
	case 2:
		m_MonstersNumber = 10;
		m_Monsters.resize(m_MonstersNumber);
		for (int i = 0; i < m_MonstersNumber; i++)
		{
			if (i < 5)
			{
				m_Monsters[i] = new Spider;
			}
			else if (i >= 5 && i < 8)
			{
				m_Monsters[i] = new Ghost;
			}
			else
			{
				m_Monsters[i] = new PoisonSpider;
			}
		}
		return m_Monsters;
	case 3:
		m_MonstersNumber = 18;
		m_Monsters.resize(m_MonstersNumber);
		for (int i = 0; i < m_MonstersNumber; i++)
		{
			if (i < 6)
			{
				m_Monsters[i] = new Spider;
			}
			else if (i >= 6 && i < 12)
			{
				m_Monsters[i] = new Ghost;
			}
			else
			{
				m_Monsters[i] = new PoisonSpider;
			}
		}
		return m_Monsters;
	case 4:
		m_MonstersNumber = 12;
		m_Monsters.resize(m_MonstersNumber);
		for (int i = 0; i < m_MonstersNumber; i++)
		{
			if (i < 4)
			{
				m_Monsters[i] = new Spider;
			}
			else if (i >= 4 && i < 7)
			{
				m_Monsters[i] = new PoisonSpider;
			}
			else if (i >= 7 && i < 10)
			{
				m_Monsters[i] = new Ghost;
			}
			else
			{
				m_Monsters[i] = new RedGhost;
			}
		}
		return m_Monsters;
	case 5:
		m_MonstersNumber = 12;
		m_Monsters.resize(m_MonstersNumber);
		for (int i = 0; i < m_MonstersNumber; i++)
		{
			if (i < 3)
			{
				m_Monsters[i] = new Spider;
			}
			else if (i >= 3 && i < 6)
			{
				m_Monsters[i] = new PoisonSpider;
			}
			else if (i >= 6 && i < 9)
			{
				m_Monsters[i] = new Ghost;
			}
			else
			{
				m_Monsters[i] = new RedGhost;
			}
		}
		return m_Monsters;
	case 6:
		m_MonstersNumber = 12;
		m_Monsters.resize(m_MonstersNumber);
		for (int i = 0; i < m_MonstersNumber; i++)
		{
			if (i < 5)
			{
				m_Monsters[i] = new Spider;
			}
			else if (i >= 3 && i < 5)
			{
				m_Monsters[i] = new PoisonSpider;
			}
			else if (i >= 5 && i < 8)
			{
				m_Monsters[i] = new Ghost;
			}
			else if (i >= 8 && i < 10)
			{
				m_Monsters[i] = new RedGhost;
			}
			else
			{
				m_Monsters[i] = new GreenGhost;
			}
		}
		return m_Monsters;
	case 7:
		m_MonstersNumber = 15;
		m_Monsters.resize(m_MonstersNumber);
		for (int i = 0; i < m_MonstersNumber; i++)
		{
			if (i < 4)
			{
				m_Monsters[i] = new Spider;
			}
			else if (i >= 4 && i < 8)
			{
				m_Monsters[i] = new PoisonSpider;
			}
			else if (i >= 8 && i < 10)
			{
				m_Monsters[i] = new Ghost;
			}
			else if (i >= 10 && i < 12)
			{
				m_Monsters[i] = new RedGhost;
			}
			else
			{
				m_Monsters[i] = new GreenGhost;
			}
		}
		return m_Monsters;
	case 8:
		m_MonstersNumber = 31;
		m_Monsters.resize(m_MonstersNumber);
		for (int i = 0; i < m_MonstersNumber; i++)
		{
			if (i < 8)
			{
				m_Monsters[i] = new Spider;
			}
			else if (i >= 8 && i < 15)
			{
				m_Monsters[i] = new PoisonSpider;
			}
			else if (i >= 15 && i < 20)
			{
				m_Monsters[i] = new Ghost;
			}
			else if (i >= 20 && i < 25)
			{
				m_Monsters[i] = new RedGhost;
			}
			else if (i >= 25 && i < 30)
			{
				m_Monsters[i] = new GreenGhost;
			}
			else
			{
				m_Monsters[i] = new Witch;
			}
		}
		return m_Monsters;
	}
}