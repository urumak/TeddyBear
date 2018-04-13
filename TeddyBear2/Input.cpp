#include "Engine.h"

void Engine::input(float dtAsSeconds)
{
	m_LastShoot += dtAsSeconds;
	m_LastJumpAttack += dtAsSeconds;
	m_LastBlock += dtAsSeconds;
	mouseWorldPosition = m_Window.mapPixelToCoords(Mouse::getPosition(), m_MainView);	
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left && m_LastShoot >= SOOT_TIME)
			{
				m_Teddy.shootNow();
				m_Teddy.fire(mouseWorldPosition, m_LevelManager.getLevelSize());
				m_LastShoot = 0;
			}
			if (event.mouseButton.button == Mouse::Right && m_LastBlock >= m_BlockTime && !m_IsBlocking && !m_Teddy.isShooting())
			{
				m_IsBlocking = true;
				m_Teddy.setBlock(m_IsBlocking);
				m_LastBlock = 0;
			}
		}
		if (event.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				playing = false;
				reset();
			}
			if (Keyboard::isKeyPressed(Keyboard::N))
			{
				newLevel = true;
				reset();
			}
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				m_Paused = !m_Paused;
			}
		}

	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_Teddy.goRight();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_Teddy.goLeft();
	}
	else
	{
		m_Teddy.stopRL();
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		m_Teddy.jumpNow();
	}
}