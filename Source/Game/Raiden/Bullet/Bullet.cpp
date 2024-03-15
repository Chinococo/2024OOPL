#include "stdafx.h"
#include "bullet.h"

namespace Raiden
{
	void Bullet::Init(int left, int top)
	{
		sprite.LoadBitmapByString({ "Resources/1.bmp" });
		collision_box.Init({ {0, 0, sprite.GetWidth(), sprite.GetWidth()} });
		collision_box.SetTopLeft(left, top);
		sprite.SetTopLeft(left, top);
		alive = true;
	}

	void Bullet::Update(int delta_x = 0, int delta_y = 0)
	{
		collision_box.SetTopLeft(sprite.GetLeft() + delta_x, sprite.GetTop() + delta_y);
		std::pair<int, int> top_left = collision_box.GetTopLeft();
		sprite.SetTopLeft(top_left.first, top_left.second);
	}

	void Bullet::Show()
	{
		sprite.ShowBitmap();
		collision_box.Show();
	}

	void Bullet::Destroy()
	{
		alive = false;
	}

	const CollisionBox &Bullet::GetCollisionBox()
	{
		return collision_box;
	}

	bool Bullet::IsCollisionBoxOverlap(const Bullet &other)
	{
		return collision_box.IsCollisionBoxOverlap(other.GetCollisionBox());
	}

	bool Bullet::IsAlive()
	{
		return alive;
	}
}
