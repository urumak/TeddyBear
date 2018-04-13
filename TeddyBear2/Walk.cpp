#include "Teddy.h"

void Teddy::walk(float dtAsSeconds, int levelSize)
{
	if (m_IsShooting)
	{
		m_ThisShootTime += dtAsSeconds;
	}
	if (!m_Stop)
	{
		if (m_Right)
		{
			if (m_Position.x <= levelSize*BCG_SIZE - getSize().x && !m_StopRight)
				m_Position.x += SPEED*dtAsSeconds;
			if (m_LastStep >= STEP_TIME)
			{
				switch (m_Step)
				{
				case 1:
					if (!m_IsShooting && !m_Block)
					{
						m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/walk1.png");
					}
					else if (m_ThisShootTime < SHOOT_TIME || m_Block)
					{
						m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/walk1_h.png");
					}
					else
					{
						m_IsShooting = false;
						m_ThisShootTime = 0;
					}
					m_Step = 2;
					m_LastStep = 0;
					break;
				case 2:
					if (!m_IsShooting && !m_Block)
					{
						m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/walk2.png");
					}
					else if (m_ThisShootTime < SHOOT_TIME || m_Block)
					{
						m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/walk2_h.png");
					}	
					else
					{
						m_IsShooting = false;
						m_ThisShootTime = 0;
					}
					m_Step = 1;
					m_LastStep = 0;
					break;
				}
			}
		}
		if (m_Left)
		{
			if (m_Position.x >= 0)
				m_Position.x -= SPEED*dtAsSeconds;
			if (m_LastStep >= STEP_TIME)
			{
				switch (m_Step)
				{
				case 1:
					if (!m_IsShooting && !m_Block)
					{
						m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/walk1.png");
					}
					else if (m_ThisShootTime < SHOOT_TIME || m_Block)
					{
						m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/walk1_h.png");
					}			
					else
					{
						m_IsShooting = false;
						m_ThisShootTime = 0;
					}
					m_Step = 2;
					m_LastStep = 0;
					break;
				case 2:
					if (!m_IsShooting && !m_Block)
					{
						m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/walk2.png");
					}
					else if (m_ThisShootTime < SHOOT_TIME || m_Block)
					{
						m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/walk2_h.png");
					}
					else
					{
						m_IsShooting = false;
						m_ThisShootTime = 0;
					}
					m_Step = 1;
					m_LastStep = 0;
					break;
				}
			}
		}
	}
	else
	{
		if (m_Right)
		{
			if (!m_IsShooting && !m_Block)
			{
				m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/teddy.png");
			}
			else if (m_ThisShootTime < SHOOT_TIME || m_Block)
			{
				m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/right/teddy_h.png");
			}
			else
			{
				m_IsShooting = false;
				m_ThisShootTime = 0;
			}
		}
		if (m_Left)
		{
			if (!m_IsShooting && !m_Block)
			{
				m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/teddy.png");
			}
			else if (m_ThisShootTime < SHOOT_TIME || m_Block)
			{
				m_TextureTeddy = TextureHolder::GetTexture("graphics/teddyBear/left/teddy_h.png");
			}
			else
			{
				m_IsShooting = false;
				m_ThisShootTime = 0;
			}
		}
	}
}