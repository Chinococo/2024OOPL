#include "stdafx.h"
#include "Turret.h"
namespace Raiden {
	Turret::Turret(CPoint position, CPoint bulletDirection, float bulletSpeed,std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullet)
		:position(position), bulletDirection(bulletDirection), bulletSpeed(bulletSpeed), time(clock()), bullets(bullet), per_time(200) {
	}
	void Turret::update() {
		for (int i = 0; i < (clock() - time) / per_time; i++) {
			int index = bullets->AddElement();
			bullets->operator[](index)->Init(false, straight_bullet);
			bullets->operator[](index)->SetTopLeft(std::move(position));
			bullets->operator[](index)->ApplyForce(std::move(bulletDirection));
		}
		time = clock();
	}
}