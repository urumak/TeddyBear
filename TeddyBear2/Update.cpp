#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	m_CrosshairSprite.setPosition(mouseWorldPosition);
	if (newLevel)
	{
		if (m_LevelNum < LVL_NUM)
			m_LevelNum ++;
		if (m_LevelNum <= LVL_NUM)
		{
			m_MonstersNum = m_LevelManager.getMonstersNumber(m_LevelNum);
			m_MagicBall = m_Teddy.getMagicBalls();
			int size = m_Teddy.getMagicNum();
			for (int i = 0; i < size; i++)
			{
				m_MagicBall[i].stop();
			}
			m_BackgroundSprite = m_LevelManager.nextLevel(m_LevelNum);
			m_BlockTime = m_LevelManager.getBlockTime(m_LevelNum);
			m_Monsters.resize(m_MonstersNum);
			m_Monsters = m_LevelManager.getMonsters(m_LevelNum);
			Vector2f startPosition;
			startPosition.x = resolution.x / 2 - CORRECTION;
			startPosition.y = resolution.y - m_Teddy.getSize().y;
			m_Teddy.spawn(startPosition);
			for (int i = 0; i < m_Monsters.size(); i++)
			{
				m_Monsters[i]->spawn(m_LevelManager.getLevelSize(), m_LevelNum);
			}
			reset();
			newLevel = false;
		}
	}
	collisions(dtAsSeconds);
	if (m_LastBlock >= m_BlockTime)
	{
		m_ShieldTexture = TextureHolder::GetTexture("graphics/teddyBear/active.png");
	}
	else
	{
		m_ShieldTexture = TextureHolder::GetTexture("graphics/teddyBear/n_active.png");
	}
	m_ShieldSprite.setTexture(m_ShieldTexture);
	m_Teddy.updateTeddy(dtAsSeconds, m_LevelManager.getLevelSize());
	Vector2f target;
	target.x = m_Teddy.getPosition().x;
	target.y = m_Teddy.getPosition().y + m_Teddy.getSprite().getGlobalBounds().height / 2;
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if (m_Monsters[i]->isMonsterAlive())
			m_Monsters[i]->update(dtAsSeconds, target, m_LevelManager.getLevelSize());
	}
	if (m_Teddy.getPosition().x >= BCG_SIZE / 2 - CORRECTION
		&& m_Teddy.getPosition().x <= (m_LevelManager.getLevelSize() - 1) * BCG_SIZE + resolution.x / 2 - CORRECTION)
	{
		m_MainView.setCenter(m_Teddy.getPosition().x + CORRECTION, resolution.y / 2);
	}
	int monstersLeft = m_MonstersToKill;
	m_MonstersToKill = 0;
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if (m_Monsters[i]->isMonsterAlive())
		{
			m_MonstersToKill++;
		}
	}
	int killedThisTime = monstersLeft - m_MonstersToKill;
	if (killedThisTime > 0)
	{
		m_Teddy.cure(20);
	}
	if (m_MonstersToKill == 0)
	{
		newLevel = true;
		if (m_LevelNum == 8)
		{
			m_Win = true;
		}
	}
	std::stringstream stream;
	stream << "LEVEL " << m_LevelNum;
	m_LevelText.setString(stream.str());
	std::stringstream stream2;
	stream2 << "MONSTERS LEFT: " << m_MonstersToKill;
	m_MonstersLeft.setString(stream2.str());
}

void Engine::reset()
{
	Spider::spiderNumber = 0;
	PoisonSpider::spiderNumber = 0;
	Ghost::ghostNumber = 0;
	RedGhost::ghostNumber = 0;
	GreenGhost::ghostNumber = 0;
}