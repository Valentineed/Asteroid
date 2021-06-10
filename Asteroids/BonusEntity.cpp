#include "pch.h"
#include "BonusEntity.h"

namespace Asteroids
{
	BonusEntity::BonusEntity(sf::Sprite* sprite, sf::Vector2f position, sf::Vector2f direction, callback effect) :
		m_movement(sprite, direction, 0),	//TODO Remove 50
		m_effect(effect)
	{
		m_movement.SetPosition(position);
	}

	void BonusEntity::Update(float timeLaps)
	{
		m_movement.Update(timeLaps);
	}

	void BonusEntity::Draw(sf::RenderWindow& window) const
	{
		m_movement.Draw(window);
	}

	float BonusEntity::GetTop() const
	{
		return m_movement.GetTop();
	}

	float BonusEntity::GetWidth() const
	{
		return m_movement.GetWidth();
	}

	void BonusEntity::SetPosition(float x, float y)
	{
		m_movement.SetPosition(x, y);
	}

	void BonusEntity::SetPosition(sf::Vector2f position)
	{
		m_movement.SetPosition(position);
	}

	sf::Vector2f BonusEntity::GetPosition() const
	{
		return m_movement.GetPosition();
	}

	void BonusEntity::SetMovement(float deltaX, float deltaY)
	{
		m_movement.SetMovement(deltaX, deltaY);
	}

	void BonusEntity::SetSideScrolling(float sideMove)
	{
		m_movement.SetSideMovement(sideMove);
	}

	void BonusEntity::ApplyTo(PlayerEntity& player)
	{
		(this->*m_effect)(player);
	}

	void BonusEntity::healthEffect(PlayerEntity& player)
	{
		player.AddToHealth(15.0f);
	}
	void BonusEntity::lifeEffect(PlayerEntity& player)
	{
		player.AddOneLife();
	}
	void BonusEntity::scorehEffect(PlayerEntity& player)
	{
		player.AddToScoreMultiplier(0.5f);
	}
	void BonusEntity::shieldEffect(PlayerEntity& player)
	{
		player.ResetShiledCooldown();
	}
}
