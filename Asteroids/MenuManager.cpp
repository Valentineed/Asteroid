#include "pch.h"
#include "MenuManager.h"
#include "GameManager.h"

namespace Asteroids
{
	void MenuManager::Init()
	{
		
		m_game->GetBackground().Display();
		if (!m_font.loadFromFile(m_game->GetConfig().GetValue<std::string>("font")))
		{
			// erreur...
		}
		//TODO clean 
		m_infinitRunner.setFont(m_font);
		m_infinitRunner.setString("Press <-Q-> to Infinit Runner");
		m_infinitRunner.setCharacterSize(24);
		m_infinitRunner.setFillColor(sf::Color::Red);
		m_infinitRunner.setPosition(260, 250);

		m_timeAttack2.setFont(m_font);
		m_timeAttack2.setString("Press <-W-> to Time Attack 2 min");
		m_timeAttack2.setCharacterSize(24);
		m_timeAttack2.setFillColor(sf::Color::Red);
		m_timeAttack2.setPosition(260, 300);

		m_timeAttack5.setFont(m_font);
		m_timeAttack5.setString("Press <-E-> to Time Attack 5 min");
		m_timeAttack5.setCharacterSize(24);
		m_timeAttack5.setFillColor(sf::Color::Red);
		m_timeAttack5.setPosition(260, 350);

		m_timeAttack10.setFont(m_font);
		m_timeAttack10.setString("Press <-R-> to Time Attack 10 min");
		m_timeAttack10.setCharacterSize(24);
		m_timeAttack10.setFillColor(sf::Color::Red);
		m_timeAttack10.setPosition(260, 400);

		m_soundSetings.setFont(m_font);
		m_soundSetings.setString("4 <- Sound Volume -> 6");
		m_soundSetings.setCharacterSize(24);
		m_soundSetings.setFillColor(sf::Color::Red);
		m_soundSetings.setPosition(260, 450);

		m_exit.setFont(m_font);
		m_exit.setString("Press <-ESC-> To Quit");
		m_exit.setCharacterSize(24);
		m_exit.setFillColor(sf::Color::Red);
		m_exit.setPosition(300, 600);

		m_game->GetWindow().draw(m_infinitRunner);
		m_game->GetWindow().draw(m_timeAttack2);
		m_game->GetWindow().draw(m_timeAttack5);
		m_game->GetWindow().draw(m_timeAttack10);

		m_game->GetWindow().draw(m_soundSetings);
		m_game->GetWindow().draw(m_exit);



		m_game->GetWindow().display();
	}
	void MenuManager::Update(float timeLaps)
	{
		//TODO animation
	}
}
