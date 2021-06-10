#pragma once

#include "Component.h"

namespace Asteroids
{
	class ShieldComponent : public Component
	{
	public:
		ShieldComponent() = default;
		~ShieldComponent() = default;

		float GetShieldTime() const;
		float GetShieldRegen() const;
		float GetMaxShield() const;

		void SetShieldTime(float shieldTime);
		void SetShieldMaxTime(float shieldTime);
		void SetShieldCD(float shieldCD);

		bool RemoveShield(float dTime);

		void RegenShield(float dTime);

		void ResetShield();

	private:
		float m_shieldTime;
		float m_shieldMaxTime;
		float m_shieldRegen;

	};
}
