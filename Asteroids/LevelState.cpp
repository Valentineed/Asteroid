#include "pch.h"
#include "LevelState.h"
#include "GameManager.h"

namespace Asteroids
{
	LevelState::LevelState(GameManager * game) :
		State(game)
	{
	}
	void LevelState::OnBegin()
	{
		// TODO: init game
		switch (m_game->GetMode())
		{
		case GameMode::INFINIT_RUNNER:
			m_endCondition = &LevelState::lifeEnd;
			break;
		case GameMode::TIME_ATTACK_2:
			m_timeAttack = 2;
			m_endCondition = &LevelState::timeEnd;
			break;
		case GameMode::TIME_ATTACK_5:
			m_timeAttack = 5;
			m_endCondition = &LevelState::timeEnd;
			break;
		case GameMode::TIME_ATTACK_10:
			m_timeAttack = 10;
			m_endCondition = &LevelState::timeEnd;
			break;
		default:
			printf("unknown mode %d", (int)m_game->GetMode());
			break;
		}

		m_game->GetInput().SetInputMap(m_game->GetLevelMap());

		m_totalTimeElapse = 0;
	}

	State* LevelState::OnUpdate(float timeLaps)
	{
		m_totalTimeElapse += timeLaps;
		if (m_game->GetInput().UpdateInputs())
		{
			m_game->GetWindow().close();
		}
		else
		{
			m_game->GetInput().UpdateInputs();
		}

		int reframe = m_game->GetPlayer().Update(timeLaps);

		m_game->GetBackground().Update(timeLaps, reframe);
		m_game->GetAsteroids().Update(timeLaps, reframe);
		m_game->GetBonus().Update(timeLaps, reframe);


		m_game->GetBackground().Display();
		m_game->GetBonus().Display();
		m_game->GetAsteroids().Display();
		m_game->GetPlayer().Display();
		//TODO: display m_timeAttack - m_totalTimeElapse if timeAttack
		//TODO: dipolay life left in infinite;

		m_game->GetWindow().display();


		if (!(this->*m_endCondition)())
		{
			return m_game->GetState().getMenuState(); // todo: switch to gameover state
		}
		return this;
		//TODO: return Menu if Game and
		//return game->GetState().getMenuState();
	}

	void LevelState::OnEnd()
	{
		m_game->SetMode(GameMode::NONE);
	}

	bool LevelState::lifeEnd()
	{
		return m_game->GetPlayer().GetLifeLeft() > 0;
	}

	bool LevelState::timeEnd()
	{
		return m_totalTimeElapse < m_timeAttack;
	}
}
