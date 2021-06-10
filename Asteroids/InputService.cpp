#include "pch.h"
#include "InputService.h"
#include "GameManager.h"

namespace Asteroids
{
	InputService::InputService(GameManager* game) :
		Manager(game)
	{}

	bool InputService::UpdateInputs()
	{
		sf::Event event;

		while (m_game->GetWindow().pollEvent(event))
		{
		
			if (event.type == sf::Event::Closed ||
				event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				return true;
			}
			if (m_map != nullptr)
			{
				InputCommand* eventCommand = m_map->GetInputCommand(event);
				if (eventCommand != nullptr)
				{
					(*eventCommand)();
				}
			}
			return false;
		}

		return false;
	}

	void InputCommandMap::AddCommandDescriptor(const InputCommandDesc& desc)
	{
		m_inputMap[desc.myEvent.type].push_back(desc);
	}

	InputCommand* InputCommandMap::GetInputCommand(const sf::Event& event)
	{
		const auto iterator = m_inputMap.find(event.type);
		if (iterator != m_inputMap.end())
		{
			if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased )
			{
				for (size_t i = 0; i < iterator->second.size(); i++)
				{
					const InputCommandDesc& desc = iterator->second[i];
					if (desc.myEvent.key.code == event.key.code)
					{
						return desc.m_command;
					}
				}
			}	
		}
		return nullptr;
	}


	
}