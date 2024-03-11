#include "stdafx.h"
#include "Source/Game/Raiden/bullet/bullet.h"
namespace Raiden {
	Bullet::Bullet() {
		
	}
	void Bullet::Init(int _left, int _top) {
		this->left = _left;
		this->top = _top;
		LoadBitmapByString({ "Resources/1.bmp" });
		this->SetTopLeft(left, top);
		this->collisionBox.Init({ { 0,0,this->GetWidth(),this->GetWidth() } });
	}
	void Bullet::Update(int deltaX=0,int deltaY=0)
	{
		this->SetTopLeft(this->GetLeft()+ deltaX, this->GetTop()+ deltaY);
		this->collisionBox.Update(this->GetLeft(),this->GetTop());
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