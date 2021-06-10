#include "pch.h"
#include "AsteroidEntity.h"
#include "GameManager.h"

namespace Asteroids
{
	AsteroidEntity::AsteroidEntity(sf::Sprite* sprite, AsteroidSize aSize)
	{
		m_movement.SetSprite(sprite);
		switch (aSize)
		{
		case Asteroids::AsteroidSize::SMALL:
			m_movement.SetScale((float)SMALL_ASTEROID);
			break;
		case Asteroids::AsteroidSize::MEDIUM:
			m_movement.SetScale((float)MEDIUM_ASTEROID);
			break;
		case Asteroids::AsteroidSize::LARGE:
			m_movement.SetScale((float)LARGE_ASTEROID);
			break;
		default:
			break;
		}

	}

	void AsteroidEntity::Update(float dTime)
	{
		m_movement.Update(dTime);
	}

	void AsteroidEntity::Draw(sf::RenderWindow& window)
	{
		m_movement.Draw(window);
	}

	void AsteroidEntity::SetMovement(sf::Vector2f dir)
	{
		m_movement.SetMovement(dir);
	}

	void AsteroidEntity::SetRotation(float angle)
	{
		m_movement.SetRotation(angle);
	}

	float AsteroidEntity::GetWidth() const
	{
		return m_movement.GetWidth();
	}

	float AsteroidEntity::GetTop() const
	{
		return m_movement.GetTop();
	}

	sf::Vector2f AsteroidEntity::GetPosition() const
	{
		return m_movement.GetPosition();
	}

	void AsteroidEntity::SetSideScrolling(float sideMove)
	{
		m_movement.SetSideMovement(sideMove);
	}

	void AsteroidEntity::SetPosition(sf::Vector2f pos)
	{
		m_movement.SetPosition(pos.x, pos.y);
	}

	void AsteroidEntity::SetHP(float hp)
	{
		m_health.SetHP(hp);
	}

	float AsteroidEntity::GetHP() const
	{
		return m_health.GetHP();
	}

	void AsteroidEntity::SetSize(AsteroidSize size)
	{
		m_size = size;
	}

	AsteroidSize AsteroidEntity::GetSize() const
	{
		return m_size;
	}

	bool AsteroidEntity::RemoveFromHp(float damage)
	{
		return m_health.RemoveHp(damage);
	}
}
