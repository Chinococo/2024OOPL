#pragma once
#include "../CollisionBox/CollisionBox.h"

namespace Raiden
{
	class Collidable
	{
	public:
		virtual ~Collidable() = default;
		CollisionBox &GetCollisionBox();
		bool IsCollisionBoxOverlap(Collidable &other);

	private:
		CollisionBox collision_box;
	};
}
