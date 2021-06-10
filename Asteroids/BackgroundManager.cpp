#include "pch.h"
#include "BackgroundManager.h"
#include "GameManager.h"

namespace Asteroids
{
	BackgroundManager::BackgroundManager(GameManager* game) :
		Manager(game)
	{
	}

	void BackgroundManager::Init()
	{
		m_cooldown = ((float)(rand() % 1000)) / 200.0f; // TODO: magic number

		ParallaxEntity* background = &m_pool.GetNew(m_game->GetSprite().GetBackground());
		background->SetDepth(0.1f); // TODO: magic number
		background->SetScale(1);

		AddNewParallax(background);
	}

	void BackgroundManager::Update(float timeLaps, int sideMove)
	{
		//////  spawn new parallax
		m_cooldown -= timeLaps;
		if (m_cooldown < 0 && m_quantity < POOL_SIZE)
		{
			ParallaxEntity* parallax = &m_pool.GetNew(m_game->GetSprite().GetParallax());
			parallax->SetPosition((float)(rand() % (int)m_game->GetWindowWidth()), -(float)parallax->GetHeight());
			AddNewParallax(parallax);

			m_cooldown = ((float)(rand() % 1000)) / 200.0f; // TODO: magic number
		}


		//////   move all parallax
		for (size_t i = 0; i < m_quantity; i++)
		{
			ParallaxEntity* parallax = m_active[i];
			parallax->SetSideScrolling(sideMove * (m_game->GetConfig().GetValue<float>("player_speed") / 2) * parallax->GetDepth());
			parallax->Update(timeLaps);
			if (parallax->GetTop() > m_game->GetWindowHeight())
			{
				RemoveParallax(i);
				i--;
			}
		}


		ParallaxEntity* background = m_active[0];// TODO: magic number - background = m_active[0];
		sf::Vector2f position = background->GetPosition();
		///// replace background
		if (background->GetTop() > 0)
		{
			background->SetPosition(position.x, position.y - background->GetTextureHeight()); // TODO
		}

		if (background->GetLeft() > 0)
		{
			background->SetPosition(position.x - background->GetTextureWidth(), position.y);// TODO
		}

		else if (background->GetLeft() < background->GetTextureWidth() * -1)
		{
			background->SetPosition(position.x + background->GetTextureWidth(), position.y);// TODO
		}
	}

	void BackgroundManager::Display() const
	{
		for (size_t i = 0; i < m_quantity; i++)
		{
			m_active[i]->Draw(m_game->GetWindow());
		}
	}

	void BackgroundManager::AddNewParallax(ParallaxEntity* parallax)
	{
		m_active[m_quantity] = parallax;
		for (size_t i = m_quantity; i > 0; i--)
		{
			if (m_active[i]->GetDepth() < m_active[i - 1]->GetDepth())
			{
				m_active[i] = m_active[i - 1];
				m_active[i - 1] = parallax;
			}
			else
			{
				break;
			}
		}
		m_quantity++;
	}

	void BackgroundManager::RemoveParallax(size_t index)
	{
		m_pool.Recycle(*m_active[index]);

		for (size_t i = index; i < m_quantity - 1; i++)
		{
			m_active[i] = m_active[i + 1];
		}

		m_quantity--;
		m_active[m_quantity] = nullptr;
	}
}
