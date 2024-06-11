#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"
#include "../Data/BossData.h"
#include "../Collidable/Collidable.h"
#include "../TurretGroup/TurretGroup.h"
#include <ctime>

namespace Raiden
{
	class Boss : public Collidable
	{
	public:
		virtual ~Boss() = default;
		void Init(BossData boss_data,std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullet);
		void Update(const Player &player);
		void Show();
		void Damage(int);
		bool IsAlive() const;
		bool IsAppear() const;
		bool Dead() const;
		CPoint GetTopLeft();
	protected:
		void MoveTo(int left, int top);
		void Move();
		virtual void Attack(const Player &player) = 0;
		game_framework::CMovingBitmap sprite;
		int health = 1000;
		std::vector<CPoint> positions;
		std::size_t position_index = 0;
		std::clock_t start_move_time;
		int move_interval_milli = 1000;
		time_t bullet_interval = clock();
		std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>> bullets;
		TurretGroup* turretGroup;
	};
}
