#pragma once
#include "../../../Library/gameutil.h"
#include "../Data/BackgroundData.h"
#include <ctime>
#include <vector>
#include <string>

namespace Raiden
{
	class Background
	{
	public:
		void Init(BackgroundData background_data);
		void Update();
		void Show();
		bool Over();
		int GetScrolledDistance();

	private:
		int scroll_step; // Specifies the number of pixels scrolled per step.
		std::clock_t scroll_interval_milli; // Specifies the duration of the interval between each scrolling step.
		std::clock_t scroll_clock; // The clock used for calculating the interval.
		game_framework::CMovingBitmap part1;
		game_framework::CMovingBitmap part2;
	};
}
