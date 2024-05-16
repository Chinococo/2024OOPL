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

	void Bullet::Init(bool friendly, int type)
	{
		this->friendly = friendly;
		this->type = type;
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
	}

	
	
	/*
	void Bullet::Update(Player& player, std::vector<std::shared_ptr<Fighter>>& fighters)
	{
		collisionBox.SetTopLeft(sprite.GetLeft() + delta_left, sprite.GetTop() + delta_top);
		std::pair<int, int> top_left = collisionBox.GetTopLeft();
		sprite.SetTopLeft(top_left.first, top_left.second);
	}*/

	void Bullet::Show()
	{
		sprite.ShowBitmap();
		collisionBox.Show();
	}

	CollisionBox &Bullet::GetCollisionBox()
	{
		return collisionBox;
	}

	bool Bullet::IsCollisionBoxOverlap(CollisionBox& other)
	{
		return collisionBox.IsCollisionBoxOverlap(other);
	}

	void Bullet::Destroy()
	{
		alive = false;
	}

	bool Bullet::IsAlive()
	{
		return alive;
	}
	bool Bullet::IsFriendly()
	{
		return friendly;
	}
}
