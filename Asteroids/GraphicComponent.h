#pragma once

#include <SFML/Graphics.hpp>
#include "Component.h"

namespace Asteroids
{
	class GraphicComponent : public Component
	{
	public:
		GraphicComponent() = default;
		GraphicComponent(sf::Sprite* sprite);
		GraphicComponent(sf::Sprite* sprite, sf::Vector2f position, float angle, float scale);
		~GraphicComponent() = default;

		const sf::Sprite& GetSprite() const;

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
		void SetPosition(sf::Vector2f position);

		void Move(float x, float y);
		void Move(sf::Vector2f move);

		void Rotate(float angle);

		void SetScale(float scale);

		void Draw(sf::RenderWindow& window) const;

	private:
		void SetValue() const;

		sf::Sprite* m_sprite = nullptr;
		sf::Vector2f	m_position = {0, 0};
		float			m_angle = 0;
		float			m_scale = 1;

	};
}
