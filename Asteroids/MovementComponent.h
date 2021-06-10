#pragma once

#include <SFML/Graphics.hpp>
#include "Component.h"
#include "GraphicComponent.h"

namespace Asteroids
{
	class MovementComponent : public Component
	{
	public:
		MovementComponent() = default;
		MovementComponent(sf::Sprite* sprite, sf::Vector2f direction, float rotationSpeed);
		~MovementComponent() = default;


		sf::Vector2f GetPosition() const;

		float GetTop() const;

		float GetLeft() const;

		float GetRight() const;

		float GetBottom() const;

		float GetHeight() const;

		float GetWidth() const;

		float GetTextureWidth() const;

		float GetTextureHeight() const;


		void SetSprite(sf::Sprite* sprite);

		void SetPosition(float x, float y);
		void SetPosition(sf::Vector2f direction);

		void SetMovement(float deltaX, float deltaY);
		void SetMovement(sf::Vector2f direction);

		void SetRotation(float rotationSpeed);

		void SetScale(float scale);

		void SetSideMovement(float speed);


		void Update(float timeLaps);

		void Draw(sf::RenderWindow& window) const;

	private:
		GraphicComponent	 m_graphic;

		sf::Vector2f	 m_direction;
		float			 m_rotationSpeed;
		float			 m_sideMovement = 0;
	};
}