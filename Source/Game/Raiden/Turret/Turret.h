#pragma once
#include <vector>
#include "../Bullet/Bullet.h"
#include "../GameObjectPool/GameObjectPool.h"
// �������O
namespace Raiden{
	class Turret {
	public:
		float x, y; // ���𪺦�m
		float bulletSpeed; // �l�u���t��
		CPoint bulletDirection; // �l�u����V
		GameObjectPool<Bullet> bullets; // ����o�g���l�u
		time_t time = clock();
		time_t per_time = 200;
		Turret(float x, float y, CPoint bulletDirection, float bulletSpeed)
			: x(x), y(y), bulletDirection(bulletDirection), bulletSpeed(bulletSpeed) {
			time = clock();
		}
	};
}
