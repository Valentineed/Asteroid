#pragma once

#include "Manager.h"
#include <SFML/Graphics/Texture.hpp>

namespace Asteroids
{
	class TextureManager : public Manager
	{
	public:

		TextureManager() = delete;
		TextureManager(GameManager* game);
		~TextureManager();

		const sf::Texture& GetBackground() const;
		const sf::Texture& GetPlayer() const;
		const sf::Texture& GetBullet() const;
		const sf::Texture& GetAsteroid() const;
		const sf::Texture& GetPowerupLife() const;
		const sf::Texture& GetPowerupScore() const;
		const sf::Texture& GetPowerupShield() const;
		const sf::Texture& GetPowerupHealth() const;
		const std::vector<sf::Texture>& GetParallax() const;

		bool Load();

	private://TODO change  Name
		bool loadBackground();
		bool loadPowerup();
		bool loadPlayer();
		bool loadBullet();
		bool loadAsteroid();
		bool loadParallax();

		sf::Texture m_background;
		sf::Texture m_player;
		sf::Texture m_bullet;
		sf::Texture m_asteroid;
		sf::Texture m_powerupLife;
		sf::Texture m_powerupScore;
		sf::Texture m_powerupShield;
		sf::Texture m_powerupHealth;
		std::vector<sf::Texture> m_vParallax;

	};
}