#pragma once

#include "MovementComponent.h"
#include "GraphicComponent.h"
#include "ScoreComponent.h"
#include "HealthComponent.h"
#include "ShieldComponent.h"
#include "Entity.h"

namespace Asteroids
{
	class PlayerEntity : public Entity
	{
	public:
		PlayerEntity(sf::Sprite* sprite);
		~PlayerEntity() = default;

		void Draw(sf::RenderWindow& window, bool displayShield) const;

		void Move(float x, float y, float dTime);

		void SetPosition(float x, float y);
		sf::Vector2f GetPosition();
		float GetWidth();
		float GetHeight();

		void AddToHealth(float health);
		bool RemoveFromHealth(float damage);
		void AddOneLife();
		void AddToScoreMultiplier(float multiplier);
		void ResetScoreMultiplier();
		void ResetShiledCooldown();
		int GetLifeLeft() const;

		bool RemoveFromShield(float dTime);
		void RegenShield(float dTime);

		HealthComponent& GetHealth();
		ShieldComponent& GetShield();

		void DrawHPLeft(sf::RenderWindow& window) const;
		void DrawHPBar(sf::RenderWindow& window) const;
		void DrawShield(sf::RenderWindow& window) const;
		void DrawShieldBar(sf::RenderWindow& window) const;

	private:
		MovementComponent	 m_movement;
		ScoreComponent		 m_score;
		HealthComponent		 m_health;
		ShieldComponent		 m_shield;

		int					 m_lifeLeft = 3;
	};
}
