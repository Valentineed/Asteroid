#pragma once

#include "Manager.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <cassert>

namespace Asteroids
{
	class ConfigManager : public Manager
	{
	public:
		ConfigManager(GameManager* game);
		~ConfigManager() = default;

		bool ReadConfigFile(const std::string& fileName);

		template <typename T>
		void AddKeyword(const std::string& keyword, std::vector<T>& values);
		
		template <typename T>
		const T& GetValue(const std::string& keyword);

		template <typename T>
		const std::vector<T>& GetAllValues(const std::string& keyword);
		
	private:
		template <typename V>
		using KeywordMappper = std::unordered_map<std::string, std::vector<V>>;
		
		KeywordMappper<std::string> m_stringConfigValues;
		KeywordMappper<float> m_floatConfigValues;

		template <typename T>
		KeywordMappper<T>& GetConfigValues() = delete;

		template<>
		KeywordMappper<std::string>& GetConfigValues()
		{
			return m_stringConfigValues;
		}

		template<>
		KeywordMappper<float>& GetConfigValues()
		{
			return m_floatConfigValues;
		}
	};
}

#include "ConfigManager.hpp"
