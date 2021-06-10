#include "pch.h"
#include "SpawnerManager.h"
#include "GameManager.h"

namespace Asteroids
{
	SpawnerManager::SpawnerManager(GameManager* game) :
		Manager(game)
	{
	}

	sf::Vector2f SpawnerManager::GetNewPos()
	{
		float width = m_game->GetWindowWidth();
		float height = m_game->GetWindowHeight();

		float xpos = 0;
		float ypos = 0;

		float maxRange = height + width;

		float randRange = (float)(rand() % ((int)maxRange));

		if (randRange < height / 2)
		{
			xpos = -SCREEN_PADDING;
			ypos = randRange;
		}

		else if (randRange > (height / 2) && randRange < ((height / 2) + width))
		{
			xpos = randRange - (height / 2);
			ypos = -SCREEN_PADDING;
		}

		else if (randRange > ((height / 2) + width))
		{
			xpos = (m_game->GetWindowWidth() + SCREEN_PADDING);
			ypos = randRange - ((height / 2) + width);
		}

		return { xpos , ypos };
	}
}