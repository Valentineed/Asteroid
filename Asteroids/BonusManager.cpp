#include "pch.h"
#include "BonusManager.h"
#include "GameManager.h"

Asteroids::BonusManager::BonusManager(GameManager* game) :
	Manager(game)
{
}

void Asteroids::BonusManager::Spawn(sf::Vector2f position)
{
	if (m_quantity < POOL_SIZE)
	{
		sf::Sprite* bonusSprite;
		BonusEntity::callback function;
		BonusType type = (BonusType)(rand() % 4);
		switch (type)
		{
		case BonusType::HEALTH:
			bonusSprite = m_game->GetSprite().GetPowerupHealth();
			function = &BonusEntity::healthEffect;
			break;
		case BonusType::LIFE:
			bonusSprite = m_game->GetSprite().GetPowerupLife();
			function = &BonusEntity::lifeEffect;
			break;
		case BonusType::SCORE:
			bonusSprite = m_game->GetSprite().GetPowerupScore();
			function = &BonusEntity::scorehEffect;
			break;
		case BonusType::SHIELD:
			bonusSprite = m_game->GetSprite().GetPowerupShield();
			function = &BonusEntity::shieldEffect;
			break;
		}

		sf::Vector2f bonusMovement = { 0, m_game->GetConfig().GetValue<float>("powerups_speed") };
		BonusEntity* bonus = &m_pool.GetNew(bonusSprite, position, bonusMovement, function);

		AddNewBonus(bonus);
	}
}

void Asteroids::BonusManager::Colide(PlayerEntity& player)
{
	for (size_t i = 0; i < m_quantity; i++)
	{
		BonusEntity& bonus = *m_active[i];
		sf::Vector2f other = player.GetPosition();
		float deltaX = bonus.GetPosition().x - player.GetPosition().x;
		float deltaY = bonus.GetPosition().y - player.GetPosition().y;
		float distance = sqrtf((deltaX * deltaX) + (deltaY * deltaY));
		float bonusRange = bonus.GetWidth() / 2;
		float otherRange = player.GetWidth() / 2;

		if (distance < bonusRange + otherRange)
		{
			bonus.ApplyTo(player);
			RemoveBonus(i);
			i--;
			m_game->GetSound().PlaySoundEffect(SoundEffect::POWERUP_HIT);
		}
	}
}

void Asteroids::BonusManager::Update(float timeLaps, int sideMove)
{
	for (size_t i = 0; i < m_quantity; i++)
	{
		BonusEntity* bonus = m_active[i];
		bonus->SetSideScrolling(sideMove * (m_game->GetConfig().GetValue<float>("player_speed") / 2));
		bonus->Update(timeLaps);
		if (bonus->GetTop() > m_game->GetWindowHeight())
		{
			RemoveBonus(i);
			i--;
		}
	}
}

void Asteroids::BonusManager::Display()
{
	for (size_t i = 0; i < m_quantity; i++)
	{
		m_active[i]->Draw(m_game->GetWindow());
	}
}

void Asteroids::BonusManager::AddNewBonus(BonusEntity* bonus)
{
	m_active[m_quantity] = bonus;
	m_quantity++;
}

void Asteroids::BonusManager::RemoveBonus(size_t index)
{
	m_pool.Recycle(*m_active[index]);

	for (size_t i = index; i < m_quantity - 1; i++)
	{
		m_active[i] = m_active[i + 1];
	}

	m_quantity--;
	m_active[m_quantity] = nullptr;
}
