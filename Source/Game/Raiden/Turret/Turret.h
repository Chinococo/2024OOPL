#pragma once
#include <vector>
#include "../Bullet/Bullet.h"
#include "../GameObjectPool/GameObjectPool.h"
// 砲塔類別
namespace Raiden{
	class Turret {
	public:
		float x, y; // 砲塔的位置
		float bulletSpeed; // 子彈的速度
		CPoint bulletDirection; // 子彈的方向
		GameObjectPool<Bullet> bullets; // 砲塔發射的子彈
		time_t time = clock();
		time_t per_time = 200;
		Turret(float x, float y, CPoint bulletDirection, float bulletSpeed)
			: x(x), y(y), bulletDirection(bulletDirection), bulletSpeed(bulletSpeed) {
			time = clock();
		}
	};
}
