#pragma once

#include <vector>
#include <stack> 
#include <iostream>

template<typename TObject, size_t size>
class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool() = default;

	template<typename... Args>
	TObject& GetNew(Args&&... args);

	const std::vector<TObject>& GetPool();

	void Recycle(TObject& object);

private:
	std::vector<TObject>	 m_pool;
	std::stack<size_t>			 m_freeList;

};

#include "ObjectPool.hpp"
