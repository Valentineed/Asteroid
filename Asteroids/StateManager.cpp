#include "pch.h"
#include "StateManager.h"
namespace Asteroids
{
	StateManager::StateManager(GameManager* game) :
		Manager(game),
		m_levelState(game),
		m_menuState(game)
	{
		
	}

	void StateManager::Init()
	{
		SetState(&m_menuState);
	}

	void StateManager::Update(float timeLaps)
	{
		SetState(m_current->OnUpdate(timeLaps));
	}

	MenuState* StateManager::getMenuState()
	{
		return &m_menuState;
	}

	LevelState* StateManager::getLevelState()
	{
		return &m_levelState;
	}

	void StateManager::SetState(State* state)
	{
		if (state == m_current)
		{
			return;
		}

		if (m_current != nullptr)
		{
			m_current->OnEnd();
		}

		state->OnBegin();
		m_current = state;
	}
}
