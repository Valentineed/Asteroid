#pragma once

#include "Entity.h"

namespace Asteroids
{
	class SpawnerEntity : public Entity
	{
	public:
		SpawnerEntity() = default;
		SpawnerEntity(GameManager* mgr) :
			Entity(mgr)
		{
		}
		~SpawnerEntity() = default;

	private:

	};
}
