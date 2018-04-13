#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Spell.h"
#include <vector>

using namespace sf;

class Monster
{
protected:
	Vector2f m_Resolution;
	Sprite m_MonsterSprite;
	Texture m_MonsterTexture;
	const int SPEED = 100;
	TextureHolder m_TextureHolder;
	Vector2f m_Position;
	const int BCG_SIZE = 1920;
	FloatRect m_Shape;
	bool isAlive = true;
	float lastHitTime = 0;
	float timeToHit = 0;
	int m_MinPower = 0;
	int m_MaxPower = 0;
	float m_MaxHealth = 0;
	float m_Health = 0;
	int m_LevelSize;
	int m_LevelNumber;
	int m_Stay = 1;
	float individualSpeed = 0;
	float individualCorrection = 0;
	float m_StopCorrection = 0;
	vector<Spell*> m_Spell;
	float m_TimeToShoot;
	float m_ThisShootTime;
	const int SPELL_NUM = 20;
	int m_CurrentSpell = 0;
	bool m_CanStopTeddy = false;
	void fire(Vector2f target, int levelSize, float dtAsSecends);
	virtual void setTexture() = 0;
	virtual void setStartFeatures();
	virtual Vector2f spellStartPosition() = 0;
public:
	float hit(float dtAsSeconds);
	void spawn(int levelSize, int levelNumber);
	Sprite getSprite();
	Vector2f getPosition();
	void update(float dtAsSeconds, Vector2f target, int levelSize);
	bool isMonsterAlive();
	vector<Spell*> getSpell();
	bool canStopTeddy();
	void damage(float power);
	Monster();
	~Monster();
};

