#pragma once

#include "Entity.h"
#include "MovementComponent.h"

namespace Asteroids
{
	class ParallaxEntity : public Entity
	{
	public:
		ParallaxEntity() = delete;
		ParallaxEntity(sf::Sprite* sprite);
		~ParallaxEntity() = default;

		void SetDepth(float depth);
		float GetDepth() const;

		float GetTop() const;

		float GetLeft() const;

		float GetHeight() const;

		float GetWidth() const;

		float GetTextureWidth() const;

		float GetTextureHeight() const;

		sf::Vector2f GetPosition() const;

		void SetSideScrolling(float sideMove);

		void SetPosition(float x, float y);

		void SetScale(float scale);

		void Update(float timeLaps);

		void Draw(sf::RenderWindow& window) const;

	private:
		MovementComponent m_movement;

		float m_depth = 0.0f;
	};
}