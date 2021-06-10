#pragma once

#include "State.h"

namespace Asteroids
{

	class MenuState : public State
	{
	public:
		MenuState() = delete;
		MenuState(GameManager* game);
		~MenuState() = default;

		void OnBegin() override;
		State* OnUpdate(float timeLaps) override;
		void OnEnd() override;

	private:

	};
}