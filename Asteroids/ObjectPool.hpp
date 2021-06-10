#pragma once

#include <cassert>

template<typename T, size_t size>
ObjectPool<T, size>::ObjectPool()
{
	m_pool.reserve(size);

	for (int i = 0; i < size; i++)
	{
		m_freeList.push(size - 1 - i);
	}
}

template<typename T, size_t size>
const std::vector<T>& ObjectPool<T, size>::GetPool()
{
	return m_pool;
}

template<typename T, size_t size>
template<typename... Args>
T& ObjectPool<T, size>::GetNew(Args&&... args)
{
	assert(m_freeList.size() > 0);

	size_t firstAvailableIdx = m_freeList.top();
	m_freeList.pop();

	T* elem = m_pool.data() + firstAvailableIdx;
	new(elem) T(std::forward<Args>(args)...);

	elem->SetIndex(firstAvailableIdx);

	return *elem;
}

template<typename T, size_t size>
void ObjectPool<T, size>::Recycle(T& object)
{
	m_freeList.push(object.GetIndex());

	object.~T();
}