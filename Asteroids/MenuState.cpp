#include "pch.h"
#include "MenuState.h"
#include "GameManager.h"

namespace Asteroids
{
	MenuState::MenuState(GameManager * game) :
		State(game)
	{
	}
	void MenuState::OnBegin()
	{
		m_game->GetInput().SetInputMap(m_game->GetMenuMap());
		/*
		afficher le menu
		setMenu selectOption in NONE
		*/
		m_game->GetMenu().Init();

	}

	State * MenuState::OnUpdate(float timeLaps)
	{

		if (m_game->GetInput().UpdateInputs())
		{
			m_game->GetWindow().close();
		}
		else
		{
			m_game->GetInput().UpdateInputs();
		}
		m_game->GetMenu().Update(timeLaps);

		if (m_game->GetMode() == GameMode::NONE)
		{
			return this;
		}
		else
		{
			return m_game->GetState().getLevelState();
		}
	}

	void MenuState::OnEnd()
	{

	}
}
