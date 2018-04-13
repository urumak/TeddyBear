#pragma once
#include "SFML/Graphics.hpp"
#include "TextureHolder.h"

using namespace sf;

class Spell
{
protected:
	TextureHolder m_TextureHolder;
	Texture m_TextureSpell;
	Sprite m_SpriteSpell;
	Vector2f m_Position;
	bool m_InFlight;
	const float SPEED = 1000;
	float m_DistanceX;
	float m_DistanceY;
	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;
	int m_MaxPower = 0;
	int m_MinPower = 0;
	float m_Health = 0;
	virtual void individualFeatures() = 0;
public:
	bool isInFlight();
	void stop();
	void shoot(float startX, float startY, float targetX, float targetY, int levelSize);
	FloatRect getPosition();
	Sprite getSprite();
	void update(float dtAsSeconds);
	float hit();
	Spell();
	~Spell();
};

