#include "pch.h"
#include "ShieldComponent.h"

namespace Asteroids
{
	float ShieldComponent::GetShieldTime() const
	{
		return m_shieldTime;
	}


	float ShieldComponent::GetMaxShield() const
	{
		return m_shieldMaxTime;
	}

	float ShieldComponent::GetShieldRegen() const
	{
		return m_shieldRegen;
	}

	void ShieldComponent::SetShieldTime(float shieldTime)
	{
		m_shieldTime = shieldTime;
	}

	void ShieldComponent::SetShieldMaxTime(float shieldTime)
	{
		m_shieldMaxTime = shieldTime;
	}

	void ShieldComponent::SetShieldCD(float shieldCD)
	{
		m_shieldRegen = m_shieldMaxTime / shieldCD;
	}

	bool ShieldComponent::RemoveShield(float dTime)
	{
		m_shieldTime -= dTime;

		return m_shieldTime > 0;
	}

	void ShieldComponent::RegenShield(float dTime)
	{
		m_shieldTime += dTime * m_shieldRegen;

		if (m_shieldTime > m_shieldMaxTime)
		{
			ResetShield();
		}
	}

	void ShieldComponent::ResetShield()
	{
		m_shieldTime = m_shieldMaxTime;
	}
}