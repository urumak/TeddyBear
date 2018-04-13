#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "TextureHolder.h"
#include "LevelManager.h"
#include "Teddy.h"
#include "MySpell.h"


using namespace sf;

class Engine
{
private:
	const int BCG_SIZE = 1920;
	const float SOOT_TIME = 0.5f;
	float m_LastShoot = 0;
	float m_LastJumpAttack = 0;
	const float JUMP_ATTACK = 0.5f;
	float m_LastBlock = 0;
	float m_ThisBlockTime = 0;
	float m_BlockTime = 10;
	const float BLOCK_DURATION = 2;
	bool m_IsBlocking = false;
	Sprite m_ShieldSprite;
	Texture m_ShieldTexture;
	Teddy m_Teddy;
	RenderWindow m_Window;
	Texture m_MenuTexture;
	Sprite m_MenuSprite;
	Texture m_BackgroundTexture;
	Sprite m_BackgroundSprite;
	RectangleShape m_MaxHealth;
	RectangleShape m_Frame;
	const int LVL_NUM = 8;
	const int CORRECTION = 500;
	const int MOD_WIDTH = 250;
	const int MOD_HEIGHT = 100;
	Texture m_PlayTexture;
	Sprite m_PlaySprite;
	Texture m_HelpTexture;
	Sprite m_HelpSprite;
	Texture m_QuitTexture;
	Sprite m_QuitSprite;
	Texture m_TextureShowHelp;
	Sprite m_SpriteShowHelp;
	Texture m_CrosshairTexture;
	Sprite m_CrosshairSprite;
	Vector2f resolution;
	Vector2i mousePosition;
	Vector2f mouseWorldPosition;
	View m_MainView;
	View m_HUDView;
	Font m_Font;
	Text m_HealthText;
	Text m_MonstersLeft;
	Text m_GameOverText;
	Text m_LevelText;
	Text m_WinText;
	Text m_Pause;
	int m_MonstersToKill;
	float viewCenterX;
	float viewCenterY;
	bool playing = false;
	bool isHelpActive = false;
	bool newLevel = false;
	bool m_Win = false;
	bool m_Paused = false;
	int m_LevelNum = 0;
	int m_MonstersNum;
	void drawMenu();
	void draw();
	void inputMenu();
	void input(float dtAsSeconds);
	void update(float dtAsSeconds);
	void reset();
	void collisions(float dtAsSeconds);
	void setHUD();
	TextureHolder m_TextureHolder;
	LevelManager m_LevelManager;
	vector<Monster*> m_Monsters;
	vector<Spell*> m_Spell;
	MySpell* m_MagicBall;
public:
	void run();
	Engine();
	~Engine();
};

