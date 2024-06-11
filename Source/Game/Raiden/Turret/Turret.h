#pragma once
#include <vector>
#include "../Bullet/Bullet.h"
#include "../GameObjectPool/GameObjectPool.h"
// �������O
namespace Raiden{
	class Turret {
	public:
		CPoint position;
		float bulletSpeed; // �l�u���t��
		int angle; // �l�u����V
		time_t time = clock();
		time_t per_time = 200;
		std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>> bullets;
		Turret(CPoint position, int angle, float bulletSpeed, std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullet);
		void update(CPoint now);
	};
}
