#include "stdafx.h"
#include "Source/Game/Raiden/bullet/bullet.h"
namespace Raiden {
	Bullet::Bullet() {
		
	}
	void Bullet::Init(int _left, int _top) {
		LoadBitmapByString({ "Resources/1.bmp" });
		this->collisionBox.Init({ { 0,0,this->GetWidth(),this->GetWidth() } });
		this->collisionBox.SetTopLeft(_left, _top);
		this->SetTopLeft(_left, _top);
		
	}
	void Bullet::Update(int deltaX=0,int deltaY=0)
	{
		this->collisionBox.Update(this->GetLeft() + deltaX, this->GetTop() + deltaY);
		pair<int, int> top_left = this->collisionBox.GetTopLeft();
		this->SetTopLeft(top_left.first, top_left.second);
	}
	void Bullet::Show()
	{
		this->ShowBitmap();
		this->collisionBox.Show();
	}
	CollisionBox& Bullet::GetCollisionBox()
	{
		return collisionBox;
	}
	bool Bullet::IsCollisionBoxOverlap(Bullet& other) {
		return this->collisionBox.IsCollisionBoxOverlap(other.GetCollisionBox());
	}
}