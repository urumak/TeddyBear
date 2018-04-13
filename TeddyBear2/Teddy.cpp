#include "Teddy.h"



Teddy::Teddy()
{
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/teddy.png");
	m_SpriteTeddy.setTexture(m_TextureTeddy);
	m_TextureShield = TextureHolder::GetTexture("graphics/teddyBear/shield.png");
	m_Shield.setTexture(m_TextureShield);
	m_Shield.setOrigin(54, 20);
	m_Health = MAX_HEALTH;
}


Teddy::~Teddy()
{
}

void Teddy::spawn(Vector2f startPosition)
{
	Vector2f size;
	size.x = MAX_HEALTH;
	size.y = 50;
	m_HealthBar.setSize(size);
	Vector2f position;
	position.x = 50;
	position.y = 50;
	m_HealthBar.setPosition(position);
	m_HealthBar.setFillColor(Color::Red);
	m_Left = false;
	m_Right = true;
	isJumping = false;
	isFalling = false;
	m_Stop = true;
	m_LastStep = 0;
	thisJumpTime = 0;
	m_Step = 1;
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;
	m_SpriteTeddy.setPosition(m_Position);
}

Sprite Teddy::getSprite()
{
	return m_SpriteTeddy;
}

Vector2f Teddy::getSize()
{
	m_Dimensions = m_SpriteTeddy.getGlobalBounds();
	m_Size.x = m_Dimensions.width;
	m_Size.y = m_Dimensions.height;
	return m_Size;
}

Vector2f Teddy::getPosition()
{
	return m_SpriteTeddy.getPosition();
}

MySpell* Teddy::getMagicBalls()
{
	return magicBall;
}

const int Teddy::getMagicNum()
{
	return magicNum;
}



void Teddy::fire(Vector2f target, int levelSize)
{
	if (currentBall == magicNum) 
	{
		currentBall = 0;
	}
	handsPosition();
	magicBall[currentBall].shoot(m_HandsPosition.x, m_HandsPosition.y, target.x, target.y, levelSize);
	currentBall++;
}


void Teddy::goRight()
{
	m_Stop = false;
	m_Left = false;
	m_Right = true;
}

void Teddy::goLeft()
{
	m_Stop = false;
	m_Right = false;
	m_Left = true;
}

void Teddy::stopRL()
{
	m_Stop = true;
}

void Teddy::jumpNow()
{
	isJumping = true;
}

void Teddy::handsPosition()
{
	m_HandsPosition.y = m_Position.y + 100;
	if (m_Right)
	{
		m_HandsPosition.x = m_Position.x + 130;
	}
	if (m_Left)
	{
		m_HandsPosition.x = m_Position.x;
	}
}

void Teddy::shootNow()
{
	m_IsShooting = true;
}

FloatRect Teddy::getFeet()
{
	FloatRect feetPosition;
	feetPosition.left = m_Position.x + 40;
	feetPosition.width = 50;
	feetPosition.top = m_Position.y + 275;
	feetPosition.height = 20;
	return feetPosition;
}


void Teddy::stopR(bool stop)
{
	m_StopRight = stop;
}

RectangleShape Teddy::getHealthBar()
{
	return m_HealthBar;
}

void Teddy::damage(float power)
{
	Vector2f newSize;
	newSize.x = m_HealthBar.getSize().x - power;
	newSize.y = m_HealthBar.getSize().y;
	m_HealthBar.setSize(newSize);
	m_Health = newSize.x;
	if (newSize.x <= 0)
	{
		m_Alive = false;
	}
}

bool Teddy::isTeddyAlive()
{
	return m_Alive;
}

void Teddy::newLife()
{
	m_Alive = true;
}

bool Teddy::falling()
{
	return isFalling;
}

float Teddy::hit()
{
	srand((int)time(0));
	float power = ((rand() % (m_MaxPower - m_MinPower)) + m_MaxPower);
	return power;
}

void Teddy::setBlock(bool block)
{
	m_Block = block;
}

bool Teddy::isShooting()
{
	return m_IsShooting;
}

Sprite Teddy::getShield()
{
	handsPosition();
	m_Shield.setPosition(m_HandsPosition);
	return m_Shield;
}

void Teddy::cure(float healthPoints)
{
	if (m_Health < MAX_HEALTH)
	{
		Vector2f newSize;
		newSize.x = m_HealthBar.getSize().x + healthPoints;
		if (newSize.x > MAX_HEALTH)
		{
			newSize.x = MAX_HEALTH;
		}
		newSize.y = m_HealthBar.getSize().y;
		m_HealthBar.setSize(newSize);
		m_Health = newSize.x;
	}
}