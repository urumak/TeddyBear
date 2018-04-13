#include "Teddy.h"

void Teddy::jump(float dtAsSeconds, int levelSize)
{
	if (m_IsShooting)
	{
		m_ThisShootTime += dtAsSeconds;
	}
	thisJumpTime += 5 * dtAsSeconds;
	if (thisJumpTime < JUMP_TIME)
	{
		m_Position.y -= GRAVITY*dtAsSeconds;
		if (m_Right)
		{
			if (!m_IsShooting && !m_Block)
			{
				m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/jump.png");
			}
			else if (m_ThisShootTime < SHOOT_TIME || m_Block)
			{
				m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/jump_h.png");
			}
			else
			{
				m_IsShooting = false;
				m_ThisShootTime = 0;
			}
			if ((m_Position.x <= levelSize*BCG_SIZE - getSize().x && !m_Stop) && !m_StopRight)
				m_Position.x += SPEED*dtAsSeconds;
		}
		if (m_Left)
		{
			if (!m_IsShooting && !m_Block)
			{
				m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/jump.png");
			}
			else if (m_ThisShootTime < SHOOT_TIME || m_Block)
			{
				m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/jump_h.png");
			}
			else
			{
				m_IsShooting = false;
				m_ThisShootTime = 0;
			}			
			if (m_Position.x >= 0 && !m_Stop)
				m_Position.x -= SPEED*dtAsSeconds;
		}
	}
	else
	{
		isFalling = true;
	}
	if (isFalling)
	{
		if (m_Position.y < resolution.y - getSize().y)
		{
			m_Position.y += GRAVITY*dtAsSeconds;
			if (m_Right)
			{
				if (!m_IsShooting && !m_Block)
				{
					m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/jump.png");
				}
				else if (m_ThisShootTime < SHOOT_TIME  || m_Block)
				{
					m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/jump_h.png");
				}
				else
				{
					m_IsShooting = false;
					m_ThisShootTime = 0;
				}			
				if (m_Position.x <= levelSize*BCG_SIZE - getSize().x && !m_Stop)
					m_Position.x += SPEED*dtAsSeconds;
			}
			if (m_Left)
			{
				if (!m_IsShooting && !m_Block)
				{
					m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/jump.png");
				}
				else if (m_ThisShootTime < SHOOT_TIME || m_Block)
				{
					m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/jump_h.png");
				}
				else
				{
					m_IsShooting = false;
					m_ThisShootTime = 0;
				}				
				if (m_Position.x >= 0 && !m_Stop)
					m_Position.x -= SPEED*dtAsSeconds;
			}
		}
		else
		{
			if (m_Right)
			{
				m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/teddy.png");
			}
			if (m_Left)
			{
				m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/teddy.png");
			}
			isJumping = false;
			isFalling = false;
			thisJumpTime = 0;
		}
	}
}