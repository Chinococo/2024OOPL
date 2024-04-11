#include "stdafx.h"
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

	void Collidable::InitCollisionBox(int width, int height)
	{
		collision_box.Init({ { 0, 0, width, height } });
	}

	void Collidable::UpdateCollisionBox(int left, int top)
	{
		collision_box.SetTopLeft(left, top);
	}

	void Collidable::ShowCollisionBox()
	{
		collision_box.Show();
	}
}
