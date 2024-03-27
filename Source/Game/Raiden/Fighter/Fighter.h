#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"
#include "../Collidable/Collidable.h"
#include <vector>
#include <ctime>

namespace Raiden
{
	class Fighter : public Collidable
	{
	public:
		void Init();
		void Update(const Player &player, int scrolled_distance);
		void Show();
		void Destroy();
		bool IsAlive() const;

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
	};
}
