#pragma once

#include <SFML/Graphics/Text.hpp>
#include "Manager.h"


namespace Asteroids
{
	enum class GameMode
	{
		NONE = 0,
		INFINIT_RUNNER,
		TIME_ATTACK_2,
		TIME_ATTACK_5,
		TIME_ATTACK_10,
		QUIT
	};
	class MenuManager : public Manager
	{
	public:
		MenuManager(GameManager* game) :
			Manager(game)
		{
		}
		~MenuManager() = default;

		void Init();

		void Update(float timeLaps);

	private:
		sf::Font m_font;

		sf::Text m_exit;
		sf::Text m_infinitRunner;
		sf::Text m_timeAttack2;
		sf::Text m_timeAttack5;
		sf::Text m_timeAttack10;
		sf::Text m_soundSetings;
	};
}