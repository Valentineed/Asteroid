#pragma once

#include "Manager.h"

namespace Asteroids
{
	class LevelManager : public Manager
	{
	public:
		LevelManager(GameManager* game) :
			Manager(game)
		{
		}
		~LevelManager() = default;

		void Update(float timeLaps);

		int GetLevel() const;

	private:
		int			 m_level = 0;
		float		 m_timeLeft = 0;

	};
}