#pragma once
#include "../../../Library/gameutil.h"
#include <ctime>
#include <vector>
#include <string>

namespace Raiden
{
	class Background
	{
	public:
		Background();
		void Init(std::vector<std::string> &&paths);
		void Update();
		void Show();
		bool Over();

	private:
		const int SCROLL_STEP; // Specifies the number of pixels scrolled per step.
		const int SCROLL_INTERVAL_MILLI; // Specifies the duration of the interval between each scrolling step.
		clock_t scroll_clock; // The clock used for calculating the interval.
		game_framework::CMovingBitmap part1;
		game_framework::CMovingBitmap part2;
		std::vector<std::string> paths;
	};
}
