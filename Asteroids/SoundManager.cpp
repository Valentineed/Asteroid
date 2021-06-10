#include "pch.h"
#include "SoundManager.h"
#include "GameManager.h"
#include <iostream>
namespace Asteroids
{
	SoundManager::SoundManager(GameManager* game) :
		Manager(game)
	{
	}

	bool SoundManager::Load()
	{
		m_loadSuccess = true;

		m_vBuffers.resize((int)SoundEffect::NO_MORE); 

		LoadSound(SoundEffect::PLAYER_FIRE, "player_fire_sfx");
		LoadSound(SoundEffect::PLAYER_SHIELD_UP, "player_shield_up_sfx");
		LoadSound(SoundEffect::PLAYER_SHIELD_DOWN, "player_shield_down_sfx");
		LoadSound(SoundEffect::PLAYER_SHIELD_HIT, "player_shield_hit_sfx");
		LoadSound(SoundEffect::PLAYER_HIT, "player_hit_sfx");
		LoadSound(SoundEffect::PLAYER_DEAD, "player_dead_sfx");
		LoadSound(SoundEffect::PLAYER_SWITCH, "player_switch_sfx");
		LoadSound(SoundEffect::ASTEROID_BROKEN, "asteroid_broken_sfx");
		LoadSound(SoundEffect::ASTEROID_TOUCHED, "asteroid_touched_sfx");
		LoadSound(SoundEffect::POWERUP_HIT, "powerup_hit_sfx");
		LoadSound(SoundEffect::JINGLE_NEW_GAME, "jingle_new_game_sfx");
		LoadSound(SoundEffect::JINGLE_GAME_OVER, "jingle_game_over_sfx");
		LoadSound(SoundEffect::JINGLE_NEW_HI_SCORE, "jingle_new_hi_score_sfx");
		LoadSound(SoundEffect::JINGLE_MULTIPLIER_RESET, "jingle_multiplier_reset_sfx");


		m_musics = m_game->GetConfig().GetAllValues<std::string>("music");

		return m_loadSuccess;
	}

	void SoundManager::PlaySoundEffect(SoundEffect enumValue)
	{
		m_mSound[enumValue].play();
	}

	void SoundManager::LoadSound(SoundEffect enumValue, std::string configName)
	{
		if (!m_vBuffers[(int)enumValue].loadFromFile(m_game->GetConfig().GetValue<std::string>(configName)))
		{
			std::cout << "unable to open sound effect: "
				<< m_game->GetConfig().GetValue<std::string>(configName) << std::endl;

			m_loadSuccess = false;
		}

		m_mSound[enumValue].setBuffer(m_vBuffers[(int)enumValue]);
	}

	void SoundManager::PlayNextMusic()
	{
		++m_track;
		if (m_track == m_musics.size())
		{
			m_track = 0;
		}
		LoadMusic();
	}

	void SoundManager::VolumeMusic(float value)
	{
		m_volumeMusic += value;
		if (m_volumeMusic < 10.0f)
		{
			m_volumeMusic = (0.0f);
		}
		else if (m_volumeMusic > 90.0f)
		{
			m_volumeMusic = 100.0f;
		}
		m_music.setVolume(m_volumeMusic);
	}

	void Asteroids::SoundManager::LoadMusic()
	{
		if (!m_music.openFromFile(m_musics[m_track]))
		{
			std::cout << "Music fail " << std::endl;
			m_loadSuccess = false;
		}
		m_music.play();
		m_music.setLoop(true);
	}
}