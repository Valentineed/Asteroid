#include "pch.h"
#include "GraphicComponent.h"

namespace Asteroids
{
	GraphicComponent::GraphicComponent(sf::Sprite* sprite) :
		m_sprite(sprite)
	{
	}
	
	GraphicComponent::GraphicComponent(sf::Sprite* sprite, sf::Vector2f position, float angle, float scale) :
		m_sprite(sprite),
		m_position(position),
		m_angle(angle),
		m_scale(scale)
	{
	}

	const sf::Sprite& GraphicComponent::GetSprite() const
	{
		return *m_sprite;
	}

	sf::Vector2f GraphicComponent::GetPosition() const
	{
		return m_position;
	}

	float GraphicComponent::GetTop() const
	{
		SetValue();
		return m_sprite->getGlobalBounds().top;
	}

	float GraphicComponent::GetLeft() const
	{
		SetValue();
		return m_sprite->getGlobalBounds().left;
	}

	float GraphicComponent::GetRight() const
	{
		SetValue();
		return m_sprite->getGlobalBounds().left + m_sprite->getGlobalBounds().width;
	}

	float GraphicComponent::GetBottom() const
	{
		SetValue();
		return m_sprite->getGlobalBounds().top + m_sprite->getGlobalBounds().height;
	}

	float GraphicComponent::GetHeight() const
	{
		SetValue();
		return m_sprite->getGlobalBounds().height;
	}

	float GraphicComponent::GetWidth() const
	{
		SetValue();
		return m_sprite->getGlobalBounds().width;
	}

	float GraphicComponent::GetTextureWidth() const
	{
		return m_sprite->getTexture()->getSize().x;
	}

	float GraphicComponent::GetTextureHeight() const
	{
		return m_sprite->getTexture()->getSize().y;
	}

	void GraphicComponent::SetSprite(sf::Sprite* sprite)
	{
		m_sprite = sprite;
	}

	void GraphicComponent::Move(float x, float y)
	{
		m_position.x += x;
		m_position.y += y;
	}

	void GraphicComponent::Move(sf::Vector2f move)
	{
		m_position += move;
	}

	void GraphicComponent::Rotate(float angle)
	{
		m_angle += angle;
	}

	void GraphicComponent::SetScale(float scale)
	{
		m_scale = scale;
	}

	void GraphicComponent::SetPosition(float x, float y)
	{
		m_position = { x, y };
	}

	void GraphicComponent::SetPosition(sf::Vector2f position)
	{
		m_position = position;
	}

	void GraphicComponent::Draw(sf::RenderWindow& window) const
	{
		if (m_sprite == nullptr)
		{
			return;
		}

		SetValue();

		window.draw(*m_sprite);
	}

	void GraphicComponent::SetValue() const
	{
		m_sprite->setScale(m_scale, m_scale);

		sf::FloatRect bound = m_sprite->getLocalBounds();
		m_sprite->setOrigin(bound.width / 2, bound.height / 2);

		m_sprite->setPosition(m_position);
		m_sprite->setRotation(m_angle);
	}
}
