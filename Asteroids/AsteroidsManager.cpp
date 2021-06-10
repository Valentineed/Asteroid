#include "pch.h"
#include "AsteroidsManager.h"

#include "GameManager.h"

namespace Asteroids
{
	AsteroidsManager::AsteroidsManager(GameManager* game) :
		Manager(game)
	{
	}

	void AsteroidsManager::Display()
	{
		for (size_t i = 0; i < m_quantity; i++)
		{
			m_active[i]->Draw(m_game->GetWindow());
		}
	}

	void AsteroidsManager::Update(float timeLaps, int sideMove)
	{
		m_cooldown -= timeLaps;

		if (m_cooldown < 0)
		{
			int maxAsteroids = 5 + m_game->GetLevel().GetLevel();
			float cooldownTime = (float)(m_game->GetLevel().GetLevel() * 50 + 300);

			int nbAste = rand() % maxAsteroids + 1;
			m_cooldown = ((float)(rand() % 1000)) / cooldownTime;

			for (int i = 0; i < nbAste; i++)
			{
				if (m_quantity < ASTEROIDS_NUM)
				{
					//srand(time(0));		//Makes asteroids spawn on each other when the rand nbAste decides to spawn more than 1 asteroid
					AsteroidSize randSize;
					randSize = AsteroidSize(rand() % ((int)AsteroidSize::LARGE + 1));

					AsteroidEntity* newAsteroid = (&m_pool.GetNew(m_game->GetSprite().GetAsteroid(), randSize));
					newAsteroid->SetPosition(m_game->GetSpawner().GetNewPos());


					switch (randSize)
					{
					case Asteroids::AsteroidSize::SMALL:
						newAsteroid->SetSize(AsteroidSize::SMALL);
						newAsteroid->SetHP(m_game->GetConfig().GetValue<float>("asteroid_life"));
						//printf("Small HP: %f\n", newAsteroid->GetHP());
						break;

					case Asteroids::AsteroidSize::MEDIUM:
						newAsteroid->SetSize(AsteroidSize::MEDIUM);
						newAsteroid->SetHP(m_game->GetConfig().GetValue<float>("asteroid_life") * 2);
						//printf("Medium HP: %f\n", newAsteroid->GetHP());
						break;

					case Asteroids::AsteroidSize::LARGE:
						newAsteroid->SetSize(AsteroidSize::LARGE);
						newAsteroid->SetHP(m_game->GetConfig().GetValue<float>("asteroid_life") * 4);
						//printf("Large HP: %f\n", newAsteroid->GetHP());
						break;

					default:
						break;
					}

					float x = (float)(rand() % (MAX_SPEED - MIN_SPEED) + MIN_SPEED);
					float y = (float)(rand() % (MAX_SIDE - MIN_SIDE) + MIN_SIDE);
					newAsteroid->SetMovement({ y, x });

					float rotSpeed = (float)(rand() % (MAX_SPIN - MIN_SPIN) + MIN_SPIN);
					newAsteroid->SetRotation(rotSpeed);

					AddNewAsteroid(newAsteroid);

					
				}
			}
		}

		for (size_t i = 0; i < m_quantity; i++)
		{
			AsteroidEntity* asteroids = m_active[i];
			asteroids->SetSideScrolling(sideMove * (m_game->GetConfig().GetValue<float>("player_speed") / 2));
			asteroids->Update(timeLaps);// TODO: magic number - max speed = 100;
			if (asteroids->GetTop() > m_game->GetWindowHeight())
			{
				RemoveAsteroid(i);
				i--;
			}
		}
	}

	bool AsteroidsManager::Colide(sf::Vector2f otherPosition, float otherRange, float otherDamage)
	{
		for (size_t i = 0; i < m_quantity; i++)
		{
			sf::Vector2f asteroid = m_active[i]->GetPosition();
			float deltaX = asteroid.x - otherPosition.x;
			float deltaY = asteroid.y - otherPosition.y;
			float distance = sqrtf((deltaX * deltaX) + (deltaY * deltaY));
			float asteroidRange = m_active[i]->GetWidth() / 2;

			if (distance < asteroidRange + otherRange)
			{
				if (!m_active[i]->RemoveFromHp(otherDamage))
				{
					RemoveAsteroid(i);
					i--;
					m_game->GetSound().PlaySoundEffect(SoundEffect::ASTEROID_BROKEN);
				}
				return true;
			}
		}
		return false;
	}

	void AsteroidsManager::AddNewAsteroid(AsteroidEntity* asteroid)
	{
		m_active[m_quantity] = asteroid;
		m_quantity++;
	}

	void AsteroidsManager::RemoveAsteroid(size_t index)
	{
		if (m_active[index]->GetSize() == AsteroidSize::LARGE)
		{
			int randBonus = rand() % BONUS_CHANCE;
			printf("randBonus = %i\n", randBonus);

			if (randBonus > BONUS_CHANCE - 2)
			{
				
				m_game->GetBonus().Spawn(m_active[index]->GetPosition());
			}
		}

		m_pool.Recycle(*m_active[index]);

		for (size_t i = index; i < m_quantity - 1; i++)
		{
			m_active[i] = m_active[i + 1];
		}

		m_quantity--;
		m_active[m_quantity] = nullptr;
	}
}
