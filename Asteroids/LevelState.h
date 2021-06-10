#pragma once

#include "State.h"

namespace Asteroids
{

	class LevelState : public State
	{
	public:
		LevelState() = delete;
		LevelState(GameManager* game);
		~LevelState() = default;

		void OnBegin() override;
		State* OnUpdate(float timeLaps) override;
		void OnEnd() override;

		bool lifeEnd();
		bool timeEnd();

	private:
		typedef bool (LevelState::*condition)();
		condition m_endCondition;

		float m_timeAttack;
		float m_totalTimeElapse;
	};
}