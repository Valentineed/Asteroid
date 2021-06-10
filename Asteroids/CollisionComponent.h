#pragma once

#include "Component.h"

namespace Asteroids
{
	class CollisionComponent : public Component
	{
		enum class CollisionType
		{
			//Collision aab,
			//Collision obb,
			//Collision cercle;
		};

		union ColissionData
		{
			//TODO
		};
	public:
		CollisionComponent() = default;
		~CollisionComponent() = default;

	private:

	};
}
