#pragma once

#include "GraphicComponent.h"

namespace Asteroids
{
	class 
		ScoreComponent : public Component
	{
	public:
		ScoreComponent() = default;
		~ScoreComponent() = default;

		void setPosition(float x, float y);

		void Draw(sf::RenderWindow& window) const;
		void Update(float timeLaps);

		void SetBaseIncrease(float baseIncrease);
		void resetMultiplier();
		void addMultiplier(float multiplier);

	private:
		GraphicComponent m_graphic;

		float m_currentScore = 0.0f;

		float m_baseIncrease = 100.0f;
		float m_multiplier = 0.0f;
		float m_cooldown = 5.0f;
	};
}