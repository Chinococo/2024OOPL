#include "stdafx.h"
#include "Turret.h"
namespace Raiden {
	Turret::Turret(CPoint position, int angle, float bulletSpeed,std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullet)
		:position(position), angle(angle), bulletSpeed(bulletSpeed), time(clock()), bullets(bullet), per_time(200) {
	}
	void Turret::update() {
		if ((clock() - time) / per_time > 0) {
				for (int i = 0; i < (clock() - time) / per_time; i++) {
					int index = bullets->AddElement();
					bullets->operator[](index)->Init(false, straight_bullet);
					bullets->operator[](index)->SetTopLeft(std::move(position));
					// ­pºâ¤O
					CPoint force = { static_cast<int>(std::cos(angle) * bulletSpeed), static_cast<int>(std::sin(angle) * bulletSpeed) };
					bullets->operator[](index)->ApplyForce(std::move(force));
				}
				time = clock();
		}
		
	}
}