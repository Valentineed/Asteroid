#include "pch.h"
#include "GameManager.h"
#include<iostream>

namespace Asteroids
{
	GameManager::GameManager() :
		m_config(this),
		m_texture(this),
		m_sprite(this),
		m_sound(this),
		m_inputService(this),
		m_level(this),
		m_spawner(this),
		m_asteroids(this),
		m_player(this), // need to be after m_input
		m_bonus(this),
		m_state(this),
		m_background(this),
		m_menu(this),
		m_mode(GameMode::NONE)
	{
		if (!m_config.ReadConfigFile("assets/config.txt"))
		{
			std::cout << "Game abort: could not load config" << std::endl;
			return;
		}

		if (!m_texture.Load())
		{
			std::cout << "Game abort: could not load all Texture" << std::endl;
			return;
		}
		m_sprite.Init();

		if (!m_sound.Load())
		{
			std::cout << "Game abort: could not load all Sounds" << std::endl;
			return;
		}

		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		m_window.create({	(unsigned int)m_config.GetValue<float>("window_width"),
							(unsigned int)m_config.GetValue<float>("window_height") },
						m_config.GetValue<std::string>("window_title"),
						sf::Style::Default,
						settings);
		m_window.setVerticalSyncEnabled(true);

		SetInput();

		m_background.Init();

		m_state.Init();

		m_player.Init();

		m_isReady = true;

	}

	void GameManager::Run()
	{
		sf::Clock clock;
		GetSound().PlayNextMusic();
		// Start the game loop
		while (m_window.isOpen())
		{
			float timeLaps = clock.restart().asSeconds();

			m_state.Update(timeLaps);
		}
	}


	void GameManager::SetInput()
	{

		sf::Event myEvent;

		
		auto playerFire = new CallbackCommand<PlayerManager, void, bool>(m_inputMap,&PlayerManager::PlayerFire, &m_player, true);
		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::Space;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, playerFire));

		auto stopFire = new CallbackCommand<PlayerManager, void, bool>(m_inputMap, &PlayerManager::PlayerFire, &m_player, false);
		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::Space;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopFire));

		auto moveRight = new CallbackCommand<PlayerManager, void, int>(m_inputMap,&PlayerManager::SetHorizontalMovement, &m_player, 1);
		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::D;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, moveRight));

		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::Right;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, moveRight));


		auto moveLeft = new CallbackCommand<PlayerManager, void, int>(m_inputMap,&PlayerManager::SetHorizontalMovement, &m_player, -1);
		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::A;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, moveLeft));

		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::Left;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, moveLeft));

		auto moveUP = new CallbackCommand<PlayerManager, void, int>(m_inputMap,&PlayerManager::SetVerticalMovement, &m_player, 1);
		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::W;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, moveUP));

		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::Up;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, moveUP));

		auto moveDOWN = new CallbackCommand<PlayerManager, void, int>(m_inputMap,&PlayerManager::SetVerticalMovement, &m_player, -1);
		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::S;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, moveDOWN));

		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::Down;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, moveDOWN));

		auto stopRight = new CallbackCommand<PlayerManager, void, int>(m_inputMap,&PlayerManager::SetHorizontalMovement, &m_player, 0);
		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::D;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopRight));

		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::Right;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopRight));

		auto stopLeft = new CallbackCommand<PlayerManager, void, int>(m_inputMap,&PlayerManager::SetHorizontalMovement, &m_player, 0);
		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::A;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopLeft));

		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::Left;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopLeft));


		auto stopUP = new CallbackCommand<PlayerManager, void, int>(m_inputMap,&PlayerManager::SetVerticalMovement, &m_player, 0);
		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::W;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopUP));

		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::Up;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopUP));


		auto stopDOWN = new CallbackCommand<PlayerManager, void, int>(m_inputMap,&PlayerManager::SetVerticalMovement, &m_player, 0);
		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::S;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopDOWN));

		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::Down;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopDOWN));


		auto morevolumeMusic = new CallbackCommand<SoundManager, void, float>(m_inputMap, &SoundManager::VolumeMusic, &m_sound, 10.0f);
		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::Num6;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, morevolumeMusic));
		
		auto minusvolumeMusic = new CallbackCommand<SoundManager, void, float>(m_inputMap,&SoundManager::VolumeMusic, &m_sound, -10.0f);
		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::Num4;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, minusvolumeMusic));

		auto stopMusic = new CallbackCommand<SoundManager, void, float>(m_inputMap, &SoundManager::VolumeMusic, &m_sound, 0.0f);
		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::Num6;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopMusic));

		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::Num4;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, stopMusic));

		auto flipShieldEnable = new CallbackCommand<PlayerManager, void>(m_inputMap, &PlayerManager::FlipShieldEnabled, &m_player);
		myEvent.type = sf::Event::KeyPressed;
		myEvent.key.code = sf::Keyboard::X;
		m_inputMap.AddCommandDescriptor(InputCommandDesc(myEvent, flipShieldEnable));


		//---------------------------------------// need after

		auto startInfinityRunner = new CallbackCommand<GameManager, void, GameMode>(m_inputMenuMap, &GameManager::SetMode,this , GameMode::INFINIT_RUNNER);
		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::Q;
		m_inputMenuMap.AddCommandDescriptor(InputCommandDesc(myEvent, startInfinityRunner));

		auto startTimeAttack2 = new CallbackCommand<GameManager, void, GameMode>(m_inputMenuMap, &GameManager::SetMode, this, GameMode::TIME_ATTACK_2);
		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::W;
		m_inputMenuMap.AddCommandDescriptor(InputCommandDesc(myEvent, startTimeAttack2));

		auto startTimeAttack5 = new CallbackCommand<GameManager, void, GameMode>(m_inputMenuMap, &GameManager::SetMode, this, GameMode::TIME_ATTACK_5);
		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::E;
		m_inputMenuMap.AddCommandDescriptor(InputCommandDesc(myEvent, startTimeAttack5));

		auto startTimeAttack10 = new CallbackCommand<GameManager, void, GameMode>(m_inputMenuMap, &GameManager::SetMode, this, GameMode::TIME_ATTACK_10);
		myEvent.type = sf::Event::KeyReleased;
		myEvent.key.code = sf::Keyboard::R;
		m_inputMenuMap.AddCommandDescriptor(InputCommandDesc(myEvent, startTimeAttack10));


	}



}
