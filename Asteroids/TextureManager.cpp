#include "pch.h"
#include "ConfigManager.h"
#include "TextureManager.h"
#include "GameManager.h"
#include <string>
#include <iostream>

namespace Asteroids
{
	TextureManager::TextureManager(GameManager* game) :
		Manager(game)
	{
	}

	TextureManager::~TextureManager()
	{
	}

	bool TextureManager::Load()
	{
		bool success = true;

		if (!loadBackground())
			success = false;

		if (!loadPlayer())
			success = false;

		if (!loadBullet())
			success = false;

		if (!loadAsteroid())
			success = false;

		if (!loadParallax())
			success = false;

		if (!loadPowerup())
			success = false;

		return success;
	}

	bool TextureManager::loadBackground()
	{
		const std::string& result = m_game->GetConfig().GetValue<std::string>("background_image");

		if (!m_background.loadFromFile(result))
		{
			std::cout << "unable to open background file" << std::endl;
			return false;
		}
		m_background.setRepeated(true);
		return true;
	}

	bool TextureManager::loadPowerup()
	{
		if (!m_powerupHealth.loadFromFile(m_game->GetConfig().GetValue<std::string>("powerup_hp")))
		{
			std::cout << "unable to open life powerup file" << std::endl;
			return false;
		}

		if (!m_powerupLife.loadFromFile(m_game->GetConfig().GetValue<std::string>("powerup_1Up")))
		{
			std::cout << "unable to open life powerup file" << std::endl;
			return false;
		}

		if (!m_powerupScore.loadFromFile(m_game->GetConfig().GetValue<std::string>("powerup_points")))
		{
			std::cout << "unable to open life powerup file" << std::endl;
			return false;
		}

		if (!m_powerupShield.loadFromFile(m_game->GetConfig().GetValue<std::string>("powerup_shield")))
		{
			std::cout << "unable to open life powerup file" << std::endl;
			return false;
		}

		return true;
	}

	bool TextureManager::loadPlayer()
	{
		const std::string& result = m_game->GetConfig().GetValue<std::string>("player_tex");

		if (!m_player.loadFromFile(result))
		{
			std::cout << "unable to open Player file" << std::endl;
			return false;
		}
		return true;
	}

	bool TextureManager::loadBullet()
	{
		const std::string& result = m_game->GetConfig().GetValue<std::string>("player_bullet");

		if (!m_bullet.loadFromFile(result))
		{
			std::cout << "unable to open Player file" << std::endl;
			return false;
		}
		return true;
	}

	bool TextureManager::loadAsteroid()
	{
		const std::string& result = m_game->GetConfig().GetValue<std::string>("asteroid");

		if (!m_asteroid.loadFromFile(result))
		{
			std::cout << "unable to open Asteroid file" << std::endl;
			return false;
		}
		return true;
	}

	bool TextureManager::loadParallax()
	{
		bool success = true;

		const std::vector<std::string>& result =
			m_game->GetConfig().GetAllValues<std::string>("background_parallax_objects");

		m_vParallax.resize(result.size());

		for (size_t i = 0; i < result.size(); i++)
		{
			if (!m_vParallax[i].loadFromFile(result[i]))
			{
				std::cout << "unable to open Parallar file: " << result[i] << std::endl;
				success = false;
			}
		}
		return success;
	}

	const sf::Texture& TextureManager::GetBackground() const
	{
		return m_background;
	}

	const sf::Texture& TextureManager::GetPlayer() const
	{
		return m_player;
	}

	const sf::Texture& TextureManager::GetBullet() const
	{
		return m_bullet;
	}

	const sf::Texture& TextureManager::GetAsteroid() const
	{
		return m_asteroid;
	}
	const sf::Texture& TextureManager::GetPowerupLife() const
	{
		return m_powerupLife;
	}
	const sf::Texture& TextureManager::GetPowerupScore() const
	{
		return m_powerupScore;
	}
	const sf::Texture& TextureManager::GetPowerupShield() const
	{
		return m_powerupShield;
	}
	const sf::Texture& TextureManager::GetPowerupHealth() const
	{
		return m_powerupHealth;
	}
	const std::vector<sf::Texture>& TextureManager::GetParallax() const
	{
		return m_vParallax;
	}
}