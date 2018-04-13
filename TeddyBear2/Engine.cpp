#include "Engine.h"



Engine::Engine()
{
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Teddy Bear", Style::Fullscreen);
	m_MenuTexture = TextureHolder::GetTexture("graphics/menu/home.png");
	m_MenuSprite.setTexture(m_MenuTexture);
	Vector2f center;
	center.x = (resolution.x / 2) - MOD_WIDTH / 2;
	center.y = (resolution.y / 2) - MOD_HEIGHT / 2;
	m_PlaySprite.setPosition(center.x, center.y - 2 * MOD_HEIGHT);
	m_HelpSprite.setPosition(center.x, center.y);
	m_QuitSprite.setPosition(center.x, center.y + 2 * MOD_HEIGHT);
	m_MainView.setSize(resolution);
	viewCenterX = resolution.x / 2;
	viewCenterY = resolution.y / 2;
	m_MainView.setCenter(viewCenterX, viewCenterY);
	m_CrosshairTexture = TextureHolder::GetTexture("graphics/teddyBear/crosshair.png");
	m_CrosshairSprite.setTexture(m_CrosshairTexture);
	m_CrosshairSprite.setOrigin(25, 25);
	m_ShieldTexture = TextureHolder::GetTexture("graphics/teddyBear/n_active.png");
	m_ShieldSprite.setTexture(m_ShieldTexture);
	m_ShieldSprite.setPosition(50, 180);
}


Engine::~Engine()
{
}


void Engine::run()
{
	Clock clock;
	setHUD();
	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		float dtAsSeconds = dt.asSeconds();
		if (playing)
		{
			m_Window.setMouseCursorVisible(false);
			input(dtAsSeconds);
			if (m_Teddy.isTeddyAlive() && !m_Win && !m_Paused)
			{
				update(dtAsSeconds);
			}
			draw();
		}
		else
		{
			m_Window.setMouseCursorVisible(true);
			inputMenu();
			drawMenu();
		}
	}
}

void Engine::drawMenu()
{
	m_Window.setView(m_Window.getDefaultView());
	m_Window.clear();
	m_Window.draw(m_MenuSprite);
	m_Window.draw(m_HelpSprite);
	m_Window.draw(m_PlaySprite);
	m_Window.draw(m_QuitSprite);
	if (isHelpActive)
		m_Window.draw(m_SpriteShowHelp);
	m_Window.display();
}



void Engine::draw()
{
	m_Window.clear();
	m_Window.setView(m_MainView);
	m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_Teddy.getSprite());
	int size = m_Teddy.getMagicNum();
	if (m_IsBlocking)
	{
		m_Window.draw(m_Teddy.getShield());
	}
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if (m_Monsters[i]->isMonsterAlive())
		{
			m_Window.draw(m_Monsters[i]->getSprite());
		}
	}
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		m_Spell = m_Monsters[i]->getSpell();
		if (m_Monsters[i]->isMonsterAlive())
		{
			for (int j = 0; j < size; j++)
			{
				if (m_Spell[j] != nullptr && m_Spell[j]->isInFlight())
				{
					m_Window.draw(m_Spell[j]->getSprite());
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (m_MagicBall[i].isInFlight())
			m_Window.draw(m_MagicBall[i].getSprite());
	}
	m_Window.setView(m_HUDView);
	m_Window.draw(m_Frame);
	m_Window.draw(m_MaxHealth);
	if (m_Teddy.getHealthBar().getSize().x > 0)
	{
		m_Window.draw(m_Teddy.getHealthBar());
	}
	else
	{
		m_Window.draw(m_GameOverText);
	}
	m_Window.draw(m_HealthText);
	m_Window.draw(m_MonstersLeft);
	m_Window.draw(m_LevelText);
	m_Window.draw(m_ShieldSprite);
	if (m_Win)
	{
		m_Window.draw(m_WinText);
	}
	if (m_Paused)
	{
		m_Window.draw(m_Pause);
	}
	m_Window.setView(m_MainView);
	m_Window.draw(m_CrosshairSprite);
	m_Window.display();
}

void Engine::setHUD()
{
	Vector2f position;
	position.x = resolution.x / 2;
	position.y = resolution.y / 2;
	m_HUDView.setCenter(position);
	m_HUDView.setSize(resolution);
	m_Font.loadFromFile("fonts/KOMIKAP_.ttf");
	m_HealthText.setFont(m_Font);
	m_HealthText.setString("HEALTH");
	m_HealthText.setCharacterSize(50);
	position.x = 50;
	position.y = 110;
	m_HealthText.setPosition(position);
	position.x = 50;
	position.y = 50;
	m_MaxHealth.setPosition(position);
	Vector2f size;
	size.x = 500;
	size.y = 50;
	m_MaxHealth.setSize(size);
	m_MaxHealth.setFillColor(Color::Black);
	position.x = 45;
	position.y = 45;
	size.x = 510;
	size.y = 60;
	m_Frame.setPosition(position);
	m_Frame.setSize(size);
	m_Frame.setFillColor(Color::Color(70, 70, 70));
	m_MonstersLeft.setFont(m_Font);
	m_MonstersLeft.setCharacterSize(50);
	position.x = 1400;
	position.y = 50;
	m_MonstersLeft.setPosition(position);
	m_GameOverText.setFont(m_Font);
	m_GameOverText.setString("GAME OVER, PRESS ESC TO BACK TO MENU");
	m_GameOverText.setCharacterSize(70);
	position.x = resolution.x / 2 - m_GameOverText.getGlobalBounds().width / 2;
	position.y = resolution.y / 2;
	m_GameOverText.setPosition(position);
	m_GameOverText.setFillColor(Color::Blue);
	m_LevelText.setFont(m_Font);
	m_LevelText.setCharacterSize(50);
	m_LevelText.setString("LEVEL 1");
	position.x = resolution.x / 2 - m_LevelText.getGlobalBounds().width / 2;
	position.y = 50;
	m_LevelText.setPosition(position);
	m_WinText.setFont(m_Font);
	m_WinText.setString("YOU WON!!! PRESS ESC TO BACK TO MENU");
	m_WinText.setCharacterSize(70);
	position.x = resolution.x / 2 - m_WinText.getGlobalBounds().width / 2;
	position.y = resolution.y / 2;
	m_WinText.setPosition(position);
	m_WinText.setFillColor(Color::Blue);
	m_Pause.setFont(m_Font);
	m_Pause.setCharacterSize(70);
	m_Pause.setString("PAUSED");
	position.x = resolution.x / 2 - m_Pause.getGlobalBounds().width / 2;
	m_Pause.setPosition(position);
	m_Pause.setFillColor(Color::Blue);
}