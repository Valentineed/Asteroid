#pragma once

#include "Manager.h"
#include "State.h"
#include "MenuState.h"
#include "LevelState.h"

namespace Asteroids
{
	class GameManager;
	class StateManager : public Manager
	{
	public:
		StateManager() = delete;
		StateManager(GameManager* game);
		~StateManager() = default;

		void Init();
		void Update(float timeLaps);

		MenuState* getMenuState();
		LevelState* getLevelState();

		void SetState(State* state);
	private:

		MenuState m_menuState;
		LevelState m_levelState;

		State* m_current = nullptr;
	};
}