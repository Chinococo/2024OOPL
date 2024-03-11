#include "stdafx.h"
#include "Source/Game/Raiden/bullet/bullet.h"
namespace Raiden {
	Bullet::Bullet() {
		
	}
	Bullet::~Bullet()
	{
		free(this->collisionBox);
	}
	void Bullet::Init() {
		LoadBitmapByString({ "Resources/1.bmp" });
		this->SetTopLeft(10, 50);
		this->collisionBox = new CollisionBox({ { 0,0,this->GetWidth(),this->GetWidth() } });
	}
	void Bullet::Update()
	{
		this->SetTopLeft(this->GetLeft(), this->GetTop() + 3);
		this->collisionBox->Update(this->GetLeft(),this->GetTop());
	}
	void Bullet::Show()
	{
		this->ShowBitmap();
		this->collisionBox->Show();
	}
}