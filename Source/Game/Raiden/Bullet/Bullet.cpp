#include "stdafx.h"
#include "Bullet.h"

namespace Raiden
{
	void Bullet::Init()
	{
		sprite.LoadBitmapByString({ "Resources/1.bmp" });
		collisionBox.Init({ { 0, 0, sprite.GetWidth(), sprite.GetWidth() } });
		alive = true;
	}

	void Bullet::SetTopLeft(int left, int top)
	{
		sprite.SetTopLeft(left, top);
	}

	void Bullet::ApplyForce(int left, int top)
	{
		delta_left = left;
		delta_top = top;
	}

	void Bullet::Update()
	{
		collisionBox.SetTopLeft(sprite.GetLeft() + delta_left, sprite.GetTop() + delta_top);
		std::pair<int, int> top_left = collisionBox.GetTopLeft();
		sprite.SetTopLeft(top_left.first, top_left.second);
	}

	void Bullet::Show()
	{
		sprite.ShowBitmap();
		collisionBox.Show();
	}

	CollisionBox &Bullet::GetCollisionBox()
	{
		return collisionBox;
	}

	bool Bullet::IsCollisionBoxOverlap(Bullet &other)
	{
		return collisionBox.IsCollisionBoxOverlap(other.GetCollisionBox());
	}

	void Bullet::Destroy()
	{
		alive = false;
	}

	bool Bullet::IsAlive()
	{
		return alive;
	}
}
