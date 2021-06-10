#pragma once

#include "ObjectPool.h"
#include "AsteroidEntity.h"
#include "Manager.h"

#define ASTEROIDS_NUM 128

#define SMALL_ASTEROID 0.1f
#define MEDIUM_ASTEROID 0.3f
#define LARGE_ASTEROID 0.6f

#define MIN_SPEED 100
#define MAX_SPEED 200

#define MIN_SIDE -100
#define MAX_SIDE 100

#define MIN_SPIN -45
#define MAX_SPIN 45

#define BONUS_CHANCE 2

namespace Asteroids
{

	class AsteroidsManager : public Manager
	{
	public:
		AsteroidsManager(GameManager* game);
		~AsteroidsManager() = default;

		void Display();
		void Update(float timeLaps, int sideMove);

		bool Colide(sf::Vector2f position, float range, float damage);

	private:
		void AddNewAsteroid(AsteroidEntity* asteroid);
		void RemoveAsteroid(size_t index);

		size_t												 m_quantity = 0;
		AsteroidEntity*										 m_active[ASTEROIDS_NUM] = {};
		ObjectPool<AsteroidEntity, (size_t)ASTEROIDS_NUM> 	 m_pool;
		float												 m_cooldown = 0;

	};
}
