#include "pch.h"
#include "ParallaxEntity.h"

#include <iostream>

Asteroids::ParallaxEntity::ParallaxEntity(sf::Sprite* sprite) :
	m_movement(sprite, {0, 0}, 0)
{
	SetDepth((float)(rand() % 75 + 25) / 100); // TODO: magic number - between 0.25 and 1.00
}

void Asteroids::ParallaxEntity::SetDepth(float depth)
{
	m_depth = depth;
	m_movement.SetMovement(0, 100 * m_depth);// TODO: magic number - max speed = 100
	m_movement.SetScale(m_depth);
}

float Asteroids::ParallaxEntity::GetDepth() const
{
	return m_depth;
}

float Asteroids::ParallaxEntity::GetTop() const
{
	return m_movement.GetTop();
}

float Asteroids::ParallaxEntity::GetLeft() const
{
	return m_movement.GetLeft();
}

float Asteroids::ParallaxEntity::GetHeight() const
{
	return m_movement.GetHeight();
}

float Asteroids::ParallaxEntity::GetWidth() const
{
	return m_movement.GetWidth();
}

float Asteroids::ParallaxEntity::GetTextureWidth() const
{
	return m_movement.GetTextureWidth();
}

float Asteroids::ParallaxEntity::GetTextureHeight() const
{
	return m_movement.GetTextureHeight();
}

sf::Vector2f Asteroids::ParallaxEntity::GetPosition() const
{
	return m_movement.GetPosition();
}

void Asteroids::ParallaxEntity::SetSideScrolling(float sideMove)
{
	m_movement.SetSideMovement(sideMove);
}

void Asteroids::ParallaxEntity::SetPosition(float x, float y)
{
	m_movement.SetPosition(x, y);
}

void Asteroids::ParallaxEntity::SetScale(float scale)
{
	m_movement.SetScale(scale);
}

void Asteroids::ParallaxEntity::Update(float timeLaps)
{
	m_movement.Update(timeLaps);
}

void Asteroids::ParallaxEntity::Draw(sf::RenderWindow& window) const
{
	m_movement.Draw(window);
}
