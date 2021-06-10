#include "pch.h"
#include "BulletEntity.h"

namespace Asteroids
{
	BulletEntity::BulletEntity(sf::Sprite * sprite, float speed)
	{
		m_movement.SetSprite(sprite);
		m_movement.SetScale(1);//TODO
		m_movement.SetMovement(0, -speed);
	}

	void BulletEntity::SetSideScrolling(float sideMove)
	{
		m_movement.SetSideMovement(sideMove);
	}

	void BulletEntity::SetPosition(float x, float y)
	{
		m_movement.SetPosition(x, y);
	}

	void BulletEntity::Update(float dTime)
	{
		m_movement.Update(dTime);
	}

	void BulletEntity::Draw(sf::RenderWindow & window) const
	{
		m_movement.Draw(window);
	}
	float BulletEntity::GetBottom() const
	{
		return m_movement.GetBottom();
	}
	float BulletEntity::GetWidth() const
	{
		return m_movement.GetWidth();
	}
	sf::Vector2f BulletEntity::GetPosition() const
	{
		return m_movement.GetPosition();
	}
}