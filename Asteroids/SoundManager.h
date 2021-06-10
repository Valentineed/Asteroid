#pragma once

#include "Manager.h"
#include <SFML/Audio.hpp>
#include <map>

namespace Asteroids
{
	enum class SoundEffect
	{
		PLAYER_FIRE = 0,
		PLAYER_SHIELD_UP,
		PLAYER_SHIELD_DOWN,
		PLAYER_SHIELD_HIT,
		PLAYER_HIT,
		PLAYER_DEAD,
		PLAYER_SWITCH,
		ASTEROID_BROKEN,
		ASTEROID_TOUCHED,
		POWERUP_HIT,
		JINGLE_NEW_GAME,
		JINGLE_GAME_OVER,
		JINGLE_NEW_HI_SCORE,
		JINGLE_MULTIPLIER_RESET,

		NO_MORE // Keep last
	};

	class SoundManager : public Manager
	{
	public:
		SoundManager(GameManager* game);
		SoundManager() = delete;
		~SoundManager() = default;

		bool Load();

		void PlaySoundEffect(SoundEffect enumValue);
		void PlayNextMusic();
		void VolumeMusic(float value);

	private:
		void LoadSound(SoundEffect enumValue, std::string configName);
		void LoadMusic();

		std::map<SoundEffect, sf::Sound> m_mSound;
		std::vector<sf::SoundBuffer> m_vBuffers;

		std::vector<std::string> m_musics;
		sf::Music m_music;

		bool m_loadSuccess = false;
		int m_track = 0;
		float m_volumeMusic = 80.0f;
	};

	
}