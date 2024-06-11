#pragma once
#include <vector>
#include "../Bullet/Bullet.h"
#include "../GameObjectPool/GameObjectPool.h"
// 砲塔類別
namespace Raiden{
	class Turret {
	public:
		CPoint position;
		float bulletSpeed; // 子彈的速度
		int angle; // 子彈的方向
		time_t time = clock();
		time_t per_time = 200;
		std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>> bullets;
		Turret(CPoint position, int angle, float bulletSpeed, std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullet);
		void update(CPoint now);
	};
}
