#pragma once

#include "ParallaxEntity.h"
#include "ObjectPool.h"
#include "Manager.h"

namespace Asteroids
{
	class BackgroundManager : public Manager
	{
	public:
		BackgroundManager() = delete;
		BackgroundManager(GameManager* game);
		~BackgroundManager() = default;

		void Init();

		void Update(float timeLaps, int sideMove);
		void Display() const;

	private:
		static const int POOL_SIZE = 10; // TODO: magic number
		static const int PARALLAX_COOLDOWN = 2; // TODO: magic number replace with random float

		void AddNewParallax(ParallaxEntity* parallax);
		void RemoveParallax(size_t index);

		size_t m_quantity = 0;
		ParallaxEntity* m_active[POOL_SIZE] = {};
		ObjectPool<ParallaxEntity, POOL_SIZE> m_pool;
		float m_cooldown = 0;
	};
}