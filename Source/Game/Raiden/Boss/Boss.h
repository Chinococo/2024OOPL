#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"
#include "../Data/BossData.h"
#include "../Collidable/Collidable.h"
#include <ctime>

namespace Raiden
{
	class Boss : public Collidable
	{
	public:
		virtual ~Boss() = default;
		virtual void Init(BossData boss_data) = 0;
		void Update(const Player &player);
		Boss(int);
		void Show();
		void Damage(int);
		bool IsAlive() const;
		bool Dead() const;
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
	};
}
