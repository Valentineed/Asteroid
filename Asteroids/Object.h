#pragma once

namespace Asteroids
{

	class Object
	{
	public:
		Object() = default;
		~Object() = default;

		size_t GetIndex() const { return m_index; }
		void SetIndex(size_t index) { m_index = index; }

	private:
		size_t m_index;

	};
}
