#include "Engine.h"

void Engine::inputMenu()
{
	FloatRect rectPlay = m_PlaySprite.getGlobalBounds();
	FloatRect rectHelp = m_HelpSprite.getGlobalBounds();
	FloatRect rectQuit = m_QuitSprite.getGlobalBounds();
	mousePosition = Mouse::getPosition();
	if (rectPlay.contains(mousePosition.x, mousePosition.y) && !isHelpActive)
	{
		m_PlayTexture = TextureHolder::GetTexture("graphics/menu/play2.png");
	}
	else
	{
		m_PlayTexture = TextureHolder::GetTexture("graphics/menu/play.png");
	}
	mousePosition = Mouse::getPosition();
	if (rectHelp.contains(mousePosition.x, mousePosition.y) && !isHelpActive)
	{
		m_HelpTexture = TextureHolder::GetTexture("graphics/menu/help2.png");
	}
	else
	{
		m_HelpTexture = TextureHolder::GetTexture("graphics/menu/help.png");
	}
	mousePosition = Mouse::getPosition();
	if (rectQuit.contains(mousePosition.x, mousePosition.y) && !isHelpActive)
	{
		m_QuitTexture = TextureHolder::GetTexture("graphics/menu/quit2.png");
	}
	else
	{
		m_QuitTexture = TextureHolder::GetTexture("graphics/menu/quit.png");
	}
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				if (rectQuit.contains(mousePosition.x, mousePosition.y) && !isHelpActive)
				{
					m_Window.close();
				}
				if (rectPlay.contains(mousePosition.x, mousePosition.y) && !isHelpActive)
				{
					playing = true;
					m_Win = false;
					m_Teddy.newLife();
					m_LevelNum = 0;
					newLevel = true;
				}
				if (rectHelp.contains(mousePosition.x, mousePosition.y) && !isHelpActive)
				{
					isHelpActive = true;
					m_TextureShowHelp = TextureHolder::GetTexture("graphics/menu/general_hints.png");
					m_SpriteShowHelp.setTexture(m_TextureShowHelp);
					Vector2f center;
					FloatRect helpSize = m_SpriteShowHelp.getLocalBounds();
					center.x = resolution.x / 2 - helpSize.width / 2;
					center.y = (resolution.y / 2 - helpSize.height / 2) + 40;
					m_SpriteShowHelp.setPosition(center);
				}
			}
		}
		if (event.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				if (isHelpActive)
				{
					isHelpActive = false;
				}
				else
				{
					m_Window.close();
				}
			}
		}
	}
	m_PlaySprite.setTexture(m_PlayTexture);
	m_HelpSprite.setTexture(m_HelpTexture);
	m_QuitSprite.setTexture(m_QuitTexture);
}