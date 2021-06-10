#pragma once

#include "PlayerEntity.h"
#include "Manager.h"
#include "BulletEntity.h"
#include "ObjectPool.h"

namespace Asteroids
{
	class PlayerManager : public Manager
	{
	public:
		PlayerManager(GameManager* game);
		~PlayerManager() = default;

		void Init();

		void Display();
		int Update(float dTime);

		void SetVerticalMovement(int value);
		void SetHorizontalMovement(int value);
		void PlayerFire(bool fire);
		void FlipShieldEnabled();

		void CheckCollision(float dTime);
		void checkPlayerAsteroids(float dTime);
		void checkBulletAsteroids();
		void checkPlayerBonus();
		int GetLifeLeft() const;


	private:
		PlayerEntity m_player;

		int m_verticalMovement;
		int m_horizontalMovement;

					/*BULLET*/
		//-----------------------------//

		void AddNewBullet(BulletEntity* bullet);
		void RemoveBullet(int index);
		bool m_playerFire;
		bool m_shieldEnabled;

		static const int POOL_SIZE = 20; // TODO: magic number

		int m_quantity = 0;
		BulletEntity* m_active[POOL_SIZE] = {};
		ObjectPool<BulletEntity, POOL_SIZE> m_pool;
		float m_cooldown = 0;
	};
}