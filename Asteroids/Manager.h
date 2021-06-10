#pragma once

namespace Asteroids
{
	class GameManager;

	class Manager
	{
	public:
		Manager() = delete;
		Manager(GameManager* game) :
			m_game(game)
		{
		}
		~Manager() = default;

		GameManager* const m_game;

	private:
		
	};
}
