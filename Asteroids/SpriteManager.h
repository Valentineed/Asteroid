#pragma once

#include "TextureManager.h"
#include "Manager.h"
#include <SFML/Graphics/Sprite.hpp>

namespace Asteroids
{
	class SpriteManager : public Manager
	{
	public:
		SpriteManager(GameManager* game) :
			Manager(game)
		{
		}
		~SpriteManager() = default;

		void Init();

		sf::Sprite* GetBackground();
		sf::Sprite* GetPlayer();
		sf::Sprite* GetBullet();
		sf::Sprite* GetAsteroid();
		sf::Sprite* GetParallax(size_t index);
		sf::Sprite* GetParallax();
		sf::Sprite* GetPowerupHealth();
		sf::Sprite* GetPowerupLife();
		sf::Sprite* GetPowerupScore();
		sf::Sprite* GetPowerupShield();

	private:
		sf::Sprite					m_background;
		sf::Sprite					m_player;
		sf::Sprite					m_bullet;
		sf::Sprite					m_asteroids;
		sf::Sprite					m_powerupHealth;
		sf::Sprite					m_powerupLife;
		sf::Sprite					m_powerupScore;
		sf::Sprite					m_powerupShield;
		std::vector<sf::Sprite>		m_vParallax;

	};
}

