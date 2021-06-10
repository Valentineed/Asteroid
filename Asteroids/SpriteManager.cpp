#include "pch.h"
#include "SpriteManager.h"
#include "GameManager.h"

namespace Asteroids
{
	void SpriteManager::Init()
	{
		const sf::Texture& background = m_game->GetTexture().GetBackground();
		m_background.setTexture(background);
		m_background.setTextureRect({ 0, 0, (int)background.getSize().x * 5, (int)background.getSize().y * 5 });

		const sf::Texture& player = m_game->GetTexture().GetPlayer();
		m_player.setTexture(player);

		const sf::Texture& bullet = m_game->GetTexture().GetBullet();
		m_bullet.setTexture(bullet);

		const sf::Texture& asteroids = m_game->GetTexture().GetAsteroid();
		m_asteroids.setTexture(asteroids);

		const std::vector<sf::Texture>& parallax = m_game->GetTexture().GetParallax();
		m_vParallax.reserve(parallax.size());

		for (const sf::Texture& texture : parallax)
		{
			m_vParallax.emplace_back(texture);
		}

		m_powerupHealth.setTexture(m_game->GetTexture().GetPowerupHealth());
		m_powerupLife.setTexture(m_game->GetTexture().GetPowerupLife());
		m_powerupScore.setTexture(m_game->GetTexture().GetPowerupScore());
		m_powerupShield.setTexture(m_game->GetTexture().GetPowerupShield());
	}

	sf::Sprite* SpriteManager::GetBackground()
	{
		return &m_background;
	}

	sf::Sprite* SpriteManager::GetPlayer()
	{
		return &m_player;
	}

	sf::Sprite* SpriteManager::GetBullet()
	{
		return &m_bullet;
	}

	sf::Sprite* SpriteManager::GetAsteroid()
	{
		return &m_asteroids;
	}

	sf::Sprite* SpriteManager::GetParallax(size_t index)
	{
		return &m_vParallax[index];
	}

	sf::Sprite* SpriteManager::GetParallax()
	{
		return &m_vParallax[rand() % m_vParallax.size()];
	}

	sf::Sprite* SpriteManager::GetPowerupHealth()
	{
		return &m_powerupHealth;
	}

	sf::Sprite* SpriteManager::GetPowerupLife()
	{
		return &m_powerupLife;
	}

	sf::Sprite* SpriteManager::GetPowerupScore()
	{
		return &m_powerupScore;
	}

	sf::Sprite* SpriteManager::GetPowerupShield()
	{
		return &m_powerupShield;
	}

}