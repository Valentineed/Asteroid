#include "pch.h"
#include "HealthComponent.h"

namespace Asteroids
{
	HealthComponent::HealthComponent(float hp)
	{
		m_maxHp = hp;
		m_hp = hp;
	}

	float HealthComponent::GetHP() const
	{
		return m_hp;
	}

	void HealthComponent::AddHp(float hp)
	{
		m_hp += hp;
		if (m_hp > m_maxHp)
		{
			m_hp = m_maxHp;
		}
	}

	bool HealthComponent::RemoveHp(float hp)
	{
		m_hp -= hp;
		return m_hp > 0;
	}

	void HealthComponent::SetHP(float hp)
	{
		m_hp = hp;
	}

	void HealthComponent::SetMaxHP(float hp)
	{
		m_maxHp = hp;
	}
}
