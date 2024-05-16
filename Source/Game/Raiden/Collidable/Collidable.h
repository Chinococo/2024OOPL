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
		void InitCollisionBox(int width, int height);
		void UpdateCollisionBox(int left, int top);
		void ShowCollisionBox();
	private:
		CollisionBox collision_box;
	};
}
