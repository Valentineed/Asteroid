#pragma once

#include <vector>

namespace Asteroids
{
	template <typename V>
	using KeywordMappper = std::unordered_map<std::string, std::vector<V>>;

	template<typename T>
	void ConfigManager::AddKeyword(const std::string& keyword, std::vector<T>& values)
	{
		KeywordMappper<T>& keywordsMapper = GetConfigValues<T>();
		keywordsMapper.insert({ keyword, values });
	}

	template <typename T>
	const T& ConfigManager::GetValue(const std::string& keyword)
	{
		return GetAllValues<T>(keyword)[0];
	}

	template <typename T>
	const std::vector<T>& ConfigManager::GetAllValues(const std::string& keyword)
	{
		KeywordMappper<T>& strMap = GetConfigValues<T>();
		auto search = strMap.find(keyword);
		if (search != strMap.end())
		{
			// std::cout << "Found " << search->first << " \n"; DEBUG print
			return search->second;
		}
		else {
			// std::cout << "Not found\n"; DEBUG print
			assert(false);
			return strMap[""];
		}
	}
}
