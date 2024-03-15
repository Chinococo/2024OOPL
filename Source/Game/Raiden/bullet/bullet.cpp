#include "stdafx.h"
#include "bullet.h"
namespace Raiden {
	Bullet::Bullet() {
		
	}
	void Bullet::Init(int _left, int _top) {
		this->sprite.LoadBitmapByString({ "Resources/1.bmp" });
		this->collisionBox.Init({{ 0,0,this->sprite.GetWidth(),this->sprite.GetWidth()}});
		this->collisionBox.SetTopLeft(_left, _top);
		this->sprite.SetTopLeft(_left, _top);
		alive = true;
		
	}
	void Bullet::Update(int deltaX=0,int deltaY=0)
	{
		this->collisionBox.SetTopLeft(this->sprite.GetLeft() + deltaX, this->sprite.GetTop() + deltaY);
		pair<int, int> top_left = this->collisionBox.GetTopLeft();
		this->sprite.SetTopLeft(top_left.first, top_left.second);
	}
	void Bullet::Show()
	{
		this->sprite.ShowBitmap();
		this->collisionBox.Show();
	}
	CollisionBox& Bullet::GetCollisionBox()
	{
		return collisionBox;
	}
	bool Bullet::IsCollisionBoxOverlap(Bullet& other) {
		return this->collisionBox.IsCollisionBoxOverlap(other.GetCollisionBox());
	}
	bool Bullet::IsAlive() {
		return alive;
	}
	//void Bullet::Destroy() {
	//	this->alive = false;
	//}
}