#pragma once
#include<SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "MySpell.h"

using namespace sf;

class Teddy
{
private:
	MySpell magicBall[20];
	const int magicNum = 20;
	int currentBall = 0;
	float m_Health;
	Vector2f m_HandsPosition;
	Vector2f resolution;
	Vector2i m_MousePosition;
	TextureHolder m_TextureHolder;
	const int SPEED = 350;
	const int GRAVITY = 700;
	const int BCG_SIZE = 1920;
	const int MAX_HEALTH = 500;
	const float STEP_TIME = 0.2f;
	const float JUMP_TIME = 2.3f;
	const float SHOOT_TIME = 0.5f;
	float m_ThisShootTime = 0;
	Texture m_TextureTeddy;
	Sprite m_SpriteTeddy;
	Vector2f m_Position;
	FloatRect m_Dimensions;
	Vector2f m_Size;
	bool m_Block = false;
	bool m_Left = false;
	bool m_Right = true;
	bool isJumping = false;
	bool isFalling = false;
	bool m_Stop = true;
	bool m_IsShooting = false;
	bool m_StopRight = false;
	bool m_Alive = true;
	float m_LastStep = 0;
	float thisJumpTime = 0;
	int m_Step = 1;
	RectangleShape m_HealthBar;
	int m_MaxPower = 35;
	int m_MinPower = 30;
	Sprite m_Shield;
	Texture m_TextureShield;
	void walk(float dtAsSeconds, int levelSize);
	void jump(float dtAsSeconds, int levelSize);
	void handsPosition();
public:
	void stopRL();
	void stopR(bool stop);
	void goLeft();
	void goRight();
	void jumpNow();
	void shootNow();
	void damage(float power);
	const int getMagicNum();
	MySpell* getMagicBalls();
	Sprite getSprite();
	Vector2f getSize();
	void spawn(Vector2f startPosition);
	Vector2f getPosition();
	void updateTeddy(float dtAsSeconds, int levelSize);
	void fire(Vector2f target, int levelSize);
	FloatRect getFeet();
	RectangleShape getHealthBar();
	bool isTeddyAlive();
	bool falling();
	void newLife();
	void setBlock(bool block);
	bool isShooting();
	float hit();
	void cure(float healthPoints);
	Sprite getShield();
	Teddy();
	~Teddy();
};
