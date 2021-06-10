#pragma once

#include "SFML/Graphics.hpp"
#include "Manager.h"

#define SCREEN_PADDING 100

namespace Asteroids
{
	class SpawnerManager : public Manager
	{
	public:
		SpawnerManager(GameManager* game);
		~SpawnerManager() = default;

		sf::Vector2f GetNewPos();

	private:

	};
}