#pragma once

#include "PlayerEntity.h"
#include "BonusEntity.h"
#include "ObjectPool.h"
#include "Manager.h"

namespace Asteroids
{

	class BonusManager : public Manager
	{
	public:
		BonusManager() = delete;
		BonusManager(GameManager* game);
		~BonusManager() = default;

		void Spawn(sf::Vector2f);

		void Colide(PlayerEntity& player);

		void Update(float timeLaps, int sideMove);
		void Display();

	private:
		static const int POOL_SIZE = 5; // TODO: magic number

		void AddNewBonus(BonusEntity* bonus);
		void RemoveBonus(size_t index);

		size_t m_quantity = 0;
		BonusEntity* m_active[POOL_SIZE] = {};
		ObjectPool<BonusEntity, POOL_SIZE> m_pool;
	};
}