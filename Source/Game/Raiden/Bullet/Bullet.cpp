#include "stdafx.h"
#include "Bullet.h"
#include "../../config.h"
namespace Raiden
{
	void Bullet::Init(bool friendly)
	{
		this->friendly = friendly;
		sprite.LoadBitmapByString({ "Resources/1.bmp" });
		collisionBox.Init({ { 0, 0, sprite.GetWidth(), sprite.GetWidth() } });
		alive = true;
	}

	void Bullet::SetTopLeft(CPoint &&point)
	{
		sprite.SetTopLeft(std::move(point.x), std::move(point.y));
	}

	void Bullet::ApplyForce(CPoint &&force)
	{
		delta_left = std::move(force.x);
		delta_top = std::move(force.y);
	}

	void Bullet::Update()
	{
		collisionBox.SetTopLeft(sprite.GetLeft() + delta_left, sprite.GetTop() + delta_top);
		std::pair<int, int> top_left = collisionBox.GetTopLeft();
		sprite.SetTopLeft(top_left.first, top_left.second);
		if (top_left.first < 0 || top_left.first >= RESOLUTION_X) {
			alive = false;
			return;
		}
		if (top_left.second < 0 || top_left.second >= RESOLUTION_Y) {
			alive = false;
			return;
		}
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
