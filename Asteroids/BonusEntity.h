#pragma once

#include "GraphicComponent.h"
#include "MovementComponent.h"
#include "PlayerEntity.h"
#include "Entity.h"

namespace Asteroids
{

	enum class BonusType
	{
		HEALTH,
		LIFE,
		SCORE,
		SHIELD
	};

	class BonusEntity : public Entity
	{
	public:
		typedef void (BonusEntity::*callback)(PlayerEntity&);

		BonusEntity() = delete;
		BonusEntity(sf::Sprite* sprite, sf::Vector2f position, sf::Vector2f direction, callback effect);
		~BonusEntity() = default;

		float GetTop() const;
		float GetWidth() const;

		void SetPosition(float x, float y);
		void SetPosition(sf::Vector2f position);

		sf::Vector2f GetPosition() const;

		void SetMovement(float deltaX, float deltaY);

		void SetSideScrolling(float sideMove);

		void ApplyTo(PlayerEntity& player);

		void Update(float dTime);

		void Draw(sf::RenderWindow & window) const;

		void healthEffect(PlayerEntity& player);
		void lifeEffect(PlayerEntity& player);
		void scorehEffect(PlayerEntity& player);
		void shieldEffect(PlayerEntity& player);

	private:

		callback			 m_effect;
		MovementComponent	 m_movement;
	};
}
