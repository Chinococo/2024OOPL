#include "stdafx.h"
#include "Turret.h"
#define M_PI 3.141596
namespace Raiden {
	Turret::Turret(CPoint position, int angle, float bulletSpeed,std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullet)
		:position(position), angle(angle), bulletSpeed(bulletSpeed), time(clock()), bullets(bullet), per_time(400) {
	}
	void Turret::update(CPoint now) {
		if ((clock() - time)-per_time>0) {
			int index = bullets->AddElement();
			bullets->operator[](index)->Init(false, straight_bullet);
			bullets->operator[](index)->SetTopLeft(std::move(now+position));
			// ­pºâ¤O
			float radis = static_cast<float>((angle / 180.0f) * M_PI);
			CPoint force = { static_cast<int>(std::cos(radis) * bulletSpeed), -static_cast<int>(std::sin(radis) * bulletSpeed) };
			bullets->operator[](index)->ApplyForce(std::move(force));
			time = clock();
		}
			
		
	}
}