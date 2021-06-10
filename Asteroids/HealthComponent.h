#pragma once

#include "Component.h"

namespace Asteroids
{
	class HealthComponent : public Component
	{
	public:
		HealthComponent() = default;
		HealthComponent(float maxHp);
		~HealthComponent() = default;

		float GetHP() const;
		void AddHp(float hp);
		bool RemoveHp(float hp);
		void SetHP(float hp);
		void SetMaxHP(float hp);

	private:
		float m_maxHp;
		float m_hp;

	};
}
