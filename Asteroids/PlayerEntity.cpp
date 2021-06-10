#include "pch.h"
#include "PlayerEntity.h"

namespace Asteroids
{
	PlayerEntity::PlayerEntity(sf::Sprite* sprite)
	{
		m_movement.SetSprite(sprite);
		m_movement.SetScale(1);
		m_movement.SetPosition(500, 300);//TODO
	}

	void PlayerEntity::Draw(sf::RenderWindow& window, bool displayShield) const
	{
		m_score.Draw(window);
		m_movement.Draw(window);

		if (displayShield)
		{
			DrawShield(window);
		}

		DrawHPBar(window);
		DrawHPLeft(window);
		DrawShieldBar(window);
	}

	void PlayerEntity::Move(float x, float y, float dTime)
	{
		m_movement.SetMovement(x, y);
		m_movement.Update(dTime);
		m_score.Update(dTime);
	}

	void PlayerEntity::SetPosition(float x, float y)
	{
		m_movement.SetPosition(x, y);
	}

	sf::Vector2f PlayerEntity::GetPosition()
	{
		return m_movement.GetPosition();
	}

	float PlayerEntity::GetWidth()
	{
		return m_movement.GetWidth();
	}

	float PlayerEntity::GetHeight()
	{
		return m_movement.GetHeight();
	}

	void PlayerEntity::AddToHealth(float health)
	{
		m_health.AddHp(health);
	}

	bool PlayerEntity::RemoveFromHealth(float damage)
	{
		return m_health.RemoveHp(damage);
	}

	void PlayerEntity::AddOneLife()
	{
		m_lifeLeft++;
	}

	void PlayerEntity::AddToScoreMultiplier(float multiplier)
	{
		m_score.addMultiplier(multiplier);
	}

	void PlayerEntity::ResetScoreMultiplier()
	{
		m_score.resetMultiplier();
	}

	void PlayerEntity::ResetShiledCooldown()
	{
		m_shield.ResetShield();
	}

	bool PlayerEntity::RemoveFromShield(float dTime)
	{
		return m_shield.RemoveShield(dTime);
	}

	void PlayerEntity::RegenShield(float dTime)
	{
		m_shield.RegenShield(dTime);
	}

	HealthComponent& PlayerEntity::GetHealth()
	{
		return m_health;
	}

	ShieldComponent& PlayerEntity::GetShield()
	{
		return m_shield;
	}

	void PlayerEntity::DrawHPLeft(sf::RenderWindow& window) const
	{
		sf::RectangleShape hpLeft(sf::Vector2f(m_health.GetHP() * 10, 30));
		hpLeft.setPosition(sf::Vector2f(20, 20));
		hpLeft.setFillColor(sf::Color::Red);

		window.draw(hpLeft);
	}

	void PlayerEntity::DrawHPBar(sf::RenderWindow& window) const
	{
		sf::RectangleShape hpBar(sf::Vector2f(300, 30));
		hpBar.setPosition(sf::Vector2f(20, 20));
		hpBar.setOutlineColor(sf::Color::Red);
		hpBar.setFillColor(sf::Color::Transparent);
		hpBar.setOutlineThickness(3);

		window.draw(hpBar);
	}

	void PlayerEntity::DrawShield(sf::RenderWindow& window) const
	{
		sf::CircleShape shield(30);
		shield.setPosition(m_movement.GetPosition().x - 30, m_movement.GetPosition().y - 27);
		float Alpha = (m_shield.GetShieldTime() / m_shield.GetMaxShield());
		shield.setOutlineColor(sf::Color(0, 255, 255, (sf::Uint8)(Alpha * 255)));
		shield.setFillColor(sf::Color(0, 255, 255, (sf::Uint8)(Alpha * 128)));
		shield.setOutlineThickness(2);

		window.draw(shield);
	}

	void PlayerEntity::DrawShieldBar(sf::RenderWindow& window) const
	{
		sf::RectangleShape shieldLeft(sf::Vector2f(m_shield.GetShieldTime() * 30, 30));
		shieldLeft.setPosition(sf::Vector2f(650, 20));
		shieldLeft.setFillColor(sf::Color::Cyan);

		sf::RectangleShape shieldBar(sf::Vector2f(300, 30));
		shieldBar.setPosition(sf::Vector2f(650, 20));
		shieldBar.setOutlineColor(sf::Color::Cyan);
		shieldBar.setFillColor(sf::Color::Transparent);
		shieldBar.setOutlineThickness(3);

		window.draw(shieldLeft);
		window.draw(shieldBar);
	}
	int PlayerEntity::GetLifeLeft() const
	{
		return m_lifeLeft;
	}
}