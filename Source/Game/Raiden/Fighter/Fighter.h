#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"
#include "../Collidable/Collidable.h"
#include "../Data/FighterData.h"
#include <vector>
#include <ctime>

namespace Raiden
{
	class Fighter : public Collidable
	{
	public:
		void Init(FighterData &&fighter_data);
		void Update(const Player &player, int scrolled_distance);
		void Show();
		void Destroy();
		bool IsAlive() const;
		bool IsAttacking() const;
		int GetLeft();
		int GetTop();

	private:
		game_framework::CMovingBitmap sprite;
		int health = 10;
		bool alive = true;
		std::vector<CPoint> positions;
		std::size_t position_index = 0;
		std::clock_t start_move_time;
		std::clock_t move_clock;
		std::clock_t move_interval_milli = 1000;
		int appear_distance = 0;
		std::vector<bool> attack_positions;
		const float M_PI = 3.1415926f;
		int last_distance = 0;
	};
}
