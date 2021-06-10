#include "pch.h"
#include "MovementComponent.h"

namespace Asteroids
{
	MovementComponent::MovementComponent(sf::Sprite* sprite, sf::Vector2f direction, float rotationSpeed) :
		m_direction(direction),
		m_rotationSpeed(rotationSpeed),
		m_graphic(sprite)
	{
	}

	sf::Vector2f MovementComponent::GetPosition() const
	{
		return m_graphic.GetPosition();
	}

	float MovementComponent::GetTop() const
	{
		return m_graphic.GetTop();
	}

	float MovementComponent::GetLeft() const
	{
		return m_graphic.GetLeft();
	}

	float MovementComponent::GetRight() const
	{
		return m_graphic.GetRight();
	}

	float MovementComponent::GetBottom() const
	{
		return m_graphic.GetBottom();
	}

	float MovementComponent::GetHeight() const
	{
		return m_graphic.GetHeight();
	}

	float MovementComponent::GetWidth() const
	{
		return m_graphic.GetWidth();
	}

	float MovementComponent::GetTextureWidth() const
	{
		return m_graphic.GetTextureWidth();
	}

	float MovementComponent::GetTextureHeight() const
	{
		return m_graphic.GetTextureHeight();
	}

	void MovementComponent::SetSprite(sf::Sprite* sprite)
	{
		m_graphic.SetSprite(sprite);
	}

	void MovementComponent::SetPosition(float x, float y)
	{
		m_graphic.SetPosition(x, y);
	}

	void MovementComponent::SetPosition(sf::Vector2f direction)
	{
		m_graphic.SetPosition(direction);
	}

	void MovementComponent::SetMovement(float deltaX, float deltaY)
	{
		m_direction.x = deltaX;
		m_direction.y = deltaY;
	}

	void MovementComponent::SetMovement(sf::Vector2f direction)
	{
		m_direction = direction;
	}

	void MovementComponent::SetRotation(float rotationSpeed)
	{
		m_rotationSpeed = rotationSpeed;
	}

	void MovementComponent::SetScale(float scale)
	{
		m_graphic.SetScale(scale);
	}

	void MovementComponent::SetSideMovement(float sideMove)
	{
		m_sideMovement = sideMove;
	}

	void MovementComponent::Update(float timeLaps)
	{
		m_graphic.Move((m_direction.x + m_sideMovement) * timeLaps, m_direction.y * timeLaps);
		m_graphic.Rotate(m_rotationSpeed * timeLaps);
	}

	void MovementComponent::Draw(sf::RenderWindow& window) const
	{
		m_graphic.Draw(window);
	}
}