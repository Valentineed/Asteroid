#include "pch.h"
#include "ScoreComponent.h"

#include <iostream>

void Asteroids::ScoreComponent::setPosition(float x, float y)
{
	m_graphic.SetPosition(x, y);
}

void Asteroids::ScoreComponent::Draw(sf::RenderWindow& window) const
{
	//std::cout << "current Multiplier:\tX " << m_multiplier << "\t\tcurrent score: " << m_currentScore << std::endl;
	//m_graphic.Draw(window); // TODO: use grafic component
}

void Asteroids::ScoreComponent::Update(float timeLaps)
{
	m_cooldown -= timeLaps;
	if (m_cooldown < 0)
	{
		addMultiplier(0.1f);
		m_cooldown = 5.0f;
	}

	m_currentScore += m_baseIncrease * m_multiplier * timeLaps;
}

void Asteroids::ScoreComponent::SetBaseIncrease(float baseIncrease)
{
	m_baseIncrease = baseIncrease;
}

void Asteroids::ScoreComponent::resetMultiplier()
{
	m_multiplier = 0.0f;
	m_cooldown = 5.0f;
}

void Asteroids::ScoreComponent::addMultiplier(float multiplier)
{
	m_multiplier += multiplier;
	if (m_multiplier > 5.0f)
	{
		m_multiplier = 5.0f;
	}
}
