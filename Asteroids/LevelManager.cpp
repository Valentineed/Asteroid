#include "pch.h"
#include "LevelManager.h"
#include "GameManager.h"

namespace Asteroids
{
	void LevelManager::Update(float timeLaps)
	{
		m_timeLeft -= timeLaps;

		if (m_timeLeft < 0)
		{
			m_level++;
			m_timeLeft = (m_level * 15.0f) + 30.0f;
			m_game->GetSound().PlayNextMusic();
		}
	}

	int LevelManager::GetLevel() const
	{
		return m_level;
	}
}