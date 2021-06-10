#pragma once

#include <SFML/Graphics.hpp>

#include "InputService.h"

#include "SpriteManager.h"

#include "ConfigManager.h"

#include "AsteroidsManager.h"

#include "PlayerManager.h"

#include "TextureManager.h"

#include "SoundManager.h"

#include "BackgroundManager.h"

#include "SpawnerManager.h"

#include "BonusManager.h"

#include "LevelManager.h"

#include "StateManager.h"

#include "MenuManager.h"


namespace Asteroids
{
#define IMPLEMENT_SERVICE(ServiceType) \
public:\
	template <>\
	ServiceType::ComponentType* CreateComponent()\
	{\
		return m_##ServiceType.CreateComponent();\
	}\
private:\
	template <>\
	void DestroyComponent_Impl(ServiceType::ComponentType* cpnt)\
	{\
		return m_##ServiceType.RecycleComponent(cpnt);\
	}\
	ServiceType m_##ServiceType;

	class GameManager
	{
	public:
		GameManager();
		virtual ~GameManager() = default;

		ConfigManager& GetConfig() { return m_config; }
		TextureManager& GetTexture() { return m_texture; }
		SpriteManager& GetSprite() { return m_sprite; }
		BackgroundManager& GetBackground() { return m_background; }
		SoundManager& GetSound() { return m_sound; }
		AsteroidsManager& GetAsteroids() { return m_asteroids; }
		PlayerManager& GetPlayer() { return m_player; }
		InputService& GetInput() { return m_inputService; }
		SpawnerManager& GetSpawner() { return m_spawner; }
		BonusManager& GetBonus() { return m_bonus; }
		LevelManager& GetLevel() { return m_level; }
		StateManager& GetState() { return m_state; }
		InputCommandMap* GetLevelMap() { return &m_inputMap; }
		InputCommandMap* GetMenuMap() { return &m_inputMenuMap; }
		MenuManager& GetMenu() { return m_menu; }

		sf::RenderWindow& GetWindow() { return m_window; }
		float GetWindowHeight() { return m_config.GetValue<float>("window_height"); }
		float GetWindowWidth() { return m_config.GetValue<float>("window_width"); }
		bool IsReady() { return m_isReady; }


		void SetMode(GameMode mode) { m_mode = mode; }
		GameMode GetMode() { return m_mode; }

		void	Run();

		template<typename T>
		T* CreateComponent()
		{
			return CreateComponent<T>();
		}


		template<typename T>
		void DestroyComponent(T* cpnt)
		{
			if (cpnt == nullptr)
			{
				return;
			}

			DestroyComponent_Impl<T>(cpnt);
		}

		void SetInput();

	private:
		sf::RenderWindow	m_window;
		bool m_isReady = false;
		GameMode m_mode;

		ConfigManager m_config;

		TextureManager m_texture;

		SpriteManager m_sprite;

		AsteroidsManager m_asteroids;

		PlayerManager m_player;

		BackgroundManager m_background;

		SoundManager m_sound;

		InputService m_inputService;

		InputCommandMap m_inputMap;

		InputCommandMap m_inputMenuMap;

		SpawnerManager m_spawner;

		BonusManager m_bonus;

		LevelManager m_level;

		StateManager m_state;

		MenuManager m_menu;

		template<typename T>
		void DestroyComponent_Impl(T* cpnt) = delete;
	};


}
