#include "pch.h"
#include "PlayerManager.h"
#include "GameManager.h"

namespace Asteroids
{
	PlayerManager::PlayerManager(GameManager * game) : 
		Manager(game),
		m_player(game->GetSprite().GetPlayer())
	{
		m_cooldown = 0;
	}

	void PlayerManager::Init()
	{
		m_player.GetHealth().SetHP(m_game->GetConfig().GetValue<float>("player_life"));
		m_player.GetHealth().SetMaxHP(m_game->GetConfig().GetValue<float>("player_life"));
		m_player.GetShield().SetShieldTime(m_game->GetConfig().GetValue<float>("player_shield_duration"));
		m_player.GetShield().SetShieldMaxTime(m_game->GetConfig().GetValue<float>("player_shield_duration"));
		m_player.GetShield().SetShieldCD(m_game->GetConfig().GetValue<float>("player_shield_cooldown"));
	}

	void PlayerManager::Display()
	{
		m_player.Draw(m_game->GetWindow(), m_shieldEnabled);

		for (int i = 0; i < m_quantity; i++)
		{
			m_active[i]->Draw(m_game->GetWindow());
		}

		printf("Player HP: %f\n", m_player.GetHealth().GetHP());
		printf("Shield time left: %f", m_player.GetShield().GetShieldTime());
	}

	int  PlayerManager::Update(float dTime)
	{
		float speed = m_game->GetConfig().GetValue<float>("player_speed");
		float x = 0.0f;
		float y = 0.0f;

		if (m_verticalMovement == 1)
		{
			y = -speed;
		}
		else if (m_verticalMovement == -1)
		{
			y = speed;
		}

		if (m_horizontalMovement == 1)
		{
			x = speed;
		}
		else if (m_horizontalMovement == -1)
		{
			x = -speed;
		}

		int sideMove = 0;
		float windowWidth = m_game->GetConfig().GetValue<float>("window_width");
		switch ((int)(m_player.GetPosition().x / (windowWidth / 4)))
		{
		case 0:
			sideMove = 1;
			break;
		case 3:
			sideMove = -1;
			break;
		case 1:
		case 2:
		default:
			sideMove = 0;
			break;
		}

		x += (speed / 2) * sideMove;

		m_player.Move(x, y, dTime);

		sf::Vector2f position = m_player.GetPosition();
		if (m_player.GetPosition().x - m_player.GetWidth() < 0)
		{
			m_player.SetPosition(m_player.GetWidth(), m_player.GetPosition().y);
		}
		else if (m_player.GetPosition().x + m_player.GetWidth() > windowWidth)
		{
			m_player.SetPosition(windowWidth - m_player.GetWidth(), m_player.GetPosition().y);
		}

		float windowHeight = m_game->GetConfig().GetValue<float>("window_height");
		if (m_player.GetPosition().y - m_player.GetHeight() < 0)
		{
			m_player.SetPosition(m_player.GetPosition().x, m_player.GetHeight());
		}
		else if (m_player.GetPosition().y + m_player.GetHeight() > windowHeight)
		{
			m_player.SetPosition(m_player.GetPosition().x, windowHeight - m_player.GetHeight());
		}

				/*SHIELD*/
		//----------------------------//

		if (m_shieldEnabled)
		{
			if (!m_player.RemoveFromShield(dTime))
			{
				FlipShieldEnabled();
			}
		}

		else
		{
			m_player.RegenShield(dTime);
		}
		

				/*BULLET*/
		//----------------------------//

		m_cooldown -= dTime;
		if (m_playerFire && m_cooldown < 0 && m_quantity < POOL_SIZE)
		{
			BulletEntity* bullet = &m_pool.GetNew(m_game->GetSprite().GetBullet(), m_game->GetConfig().GetValue<float>("bullet_speed"));
			AddNewBullet(bullet);
			bullet->SetPosition(m_player.GetPosition().x, m_player.GetPosition().y);
			m_game->GetSound().PlaySoundEffect(SoundEffect::PLAYER_FIRE);

			m_cooldown = 1.0f/m_game->GetConfig().GetValue<float>("player_firing_rate");
		}

		for (int i = 0; i < m_quantity; i++)
		{
			BulletEntity* bullet = m_active[i];
			bullet->SetSideScrolling(sideMove * (m_game->GetConfig().GetValue<float>("player_speed") / 2));
			bullet->Update(dTime);
			if (bullet->GetBottom() < 0)
			{
				RemoveBullet(i);
				i--;
			}
		}

		CheckCollision(dTime);

		return sideMove;
	}

	void PlayerManager::SetVerticalMovement(int value)
	{
		m_verticalMovement = value;
	}

	void PlayerManager::SetHorizontalMovement(int value)
	{
		m_horizontalMovement = value;
	}

	void PlayerManager::PlayerFire(bool fire)
	{
		m_playerFire = fire;
	}

	void PlayerManager::FlipShieldEnabled()
	{
		m_shieldEnabled = !m_shieldEnabled;
	}

	void PlayerManager::CheckCollision(float dTime)
	{
		checkPlayerAsteroids(dTime);
		checkBulletAsteroids();
		checkPlayerBonus();
	}

	void PlayerManager::checkPlayerAsteroids(float dTime)
	{
		if (m_shieldEnabled)
		{
			return;
		}

		if (m_game->GetAsteroids().Colide(m_player.GetPosition(), m_player.GetWidth() / 2, 0.0f))
		{
			printf("player damage\n"); //TODO Debug pritnf
			m_player.RemoveFromHealth(dTime * m_game->GetConfig().GetValue<float>("player_hit_damage"));
			m_player.ResetScoreMultiplier();
			m_game->GetSound().PlaySoundEffect(SoundEffect::PLAYER_HIT);
		}
	}

	void PlayerManager::checkBulletAsteroids()
	{
		float bulletWidth = (m_quantity > 0 ? m_active[0]->GetWidth() : 0.0f);
		float bulletDamage = m_game->GetConfig().GetValue<float>("player_firing_damage");

		for (int i = 0; i < m_quantity; i++)
		{
			if (m_game->GetAsteroids().Colide(m_active[i]->GetPosition(), bulletWidth / 2, bulletDamage))
			{
				RemoveBullet(i);
				i--;
			}
		}
	}

	void PlayerManager::checkPlayerBonus()
	{
		m_game->GetBonus().Colide(m_player);
	}

	int PlayerManager::GetLifeLeft()const 
	{
		return m_player.GetLifeLeft();
	}

	void PlayerManager::AddNewBullet(BulletEntity* bullet)
	{
		m_active[m_quantity] = bullet;
		m_quantity++;
	}

	void PlayerManager::RemoveBullet(int index)
	{
		m_pool.Recycle(*m_active[index]);

		for (int i = index; i < m_quantity - 1; i++)
		{
			m_active[i] = m_active[i + 1];
		}

		m_quantity--;
		m_active[m_quantity] = nullptr;
	}
}