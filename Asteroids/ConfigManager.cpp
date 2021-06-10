#include "pch.h"
#include "ConfigManager.h"
#include <fstream>//ifi
#include <sstream>//istringstream
#include <iostream>

namespace Asteroids
{
	ConfigManager::ConfigManager(GameManager* game) :
		Manager(game)
	{
	}

	bool ConfigManager::ReadConfigFile(const std::string& fileName)
	{
		std::string line;
		std::ifstream ifi(fileName);

		if (!ifi.is_open())
		{
			std::cout << "Error opening file" << std::endl;
			return false;
		}
		else
		{
			while (getline(ifi, line))
			{
				std::vector<std::string> m_string;
				std::vector<float> m_float;

				std::istringstream is(line);
				std::string keyword;
				is >> keyword;

				std::string paramLine;

				size_t commentPos = keyword.find('#');
				if (commentPos != std::string::npos)
				{
					keyword = keyword.erase(commentPos);
				}
				if (!keyword.empty())
				{
					//std::cout << "I read ----key---- " << keyword << "!\n"; DEBUG print
					while (getline(ifi,paramLine))
					{
						std::istringstream paramLineStream(paramLine);
						std::string param;
						
						paramLineStream >> param;
						if (param == "end")
						{
							if (!m_string.empty())
							{
								AddKeyword(keyword, m_string);
								m_string.clear();
							}
							else
							{
								AddKeyword(keyword, m_float );
								m_float.clear();
							}
							
							break;
						}
							
						//std::cout << "I read " << param << "\n"; DEBUG print

						float fparm = std::strtof(param.c_str(), nullptr);

						if (fparm == 0)
						{
							if ("0" == param)
							{
								m_float.push_back(fparm);
							}
							else
							{
								m_string.push_back(param);
							}
						}
						else
						{
							m_float.push_back(fparm);
						}
						//std::cout << fparm << "\n"; DEBUG print
					}
				}
			}
			return true;
		}
	}
}
