#pragma once

#include "GraphicComponent.h"
#include "MovementComponent.h"
#include "HealthComponent.h"
#include "Entity.h"

namespace Asteroids
{
	enum class AsteroidSize
	{
		SMALL = 0,
		MEDIUM,
		LARGE
	};

	class AsteroidEntity : public Entity
	{
	public:
		AsteroidEntity(sf::Sprite* sprite, AsteroidSize aSize);
		~AsteroidEntity() = default;

		float GetWidth() const;

		float GetTop() const;

		sf::Vector2f GetPosition() const;

		void SetSideScrolling(float sideMove);

		void SetPosition(sf::Vector2f pos);

		void SetMovement(sf::Vector2f dir);

		void SetRotation(float angle);

		void Update(float dTime);

		void Draw(sf::RenderWindow& window);

		void SetHP(float hp);

		float GetHP() const;

		bool RemoveFromHp(float damage);

		void SetSize(AsteroidSize size);

		AsteroidSize GetSize() const;

	private:
		MovementComponent	 m_movement;
		HealthComponent		 m_health;
		AsteroidSize		 m_size;

	};

}
