#pragma once

#include "Manager.h"

namespace Asteroids
{
	class State : public Manager
	{
	public:
		State() = delete;
		State(GameManager* game);
		~State() = default;

		virtual void OnBegin() = 0;
		virtual State* OnUpdate(float timeLaps) = 0;
		virtual void OnEnd() = 0;

	private:

	};
}