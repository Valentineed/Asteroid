#pragma once

#include "Entity.h"
#include "MovementComponent.h"

namespace Asteroids
{
	class BulletEntity : public Entity
	{
	public:
		BulletEntity() = delete;
		BulletEntity(sf::Sprite* sprite, float speed);
		~BulletEntity() = default;

		void SetSideScrolling(float sideMove);
		void SetPosition(float x, float y);
		void Update(float dTime);

		void Draw(sf::RenderWindow& window)const;

		float GetBottom() const;
		float GetWidth() const;
		sf::Vector2f GetPosition() const;

	private:
		MovementComponent	 m_movement;

	};
}