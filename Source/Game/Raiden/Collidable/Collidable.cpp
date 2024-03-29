#include <StdAfx.h>
#include "Collidable.h"

namespace Raiden
{
	CollisionBox &Collidable::GetCollisionBox()
	{
		return collision_box;
	}

	bool Collidable::IsCollisionBoxOverlap(Collidable &other)
	{
		return collision_box.IsCollisionBoxOverlap(other.GetCollisionBox());
	}
}
