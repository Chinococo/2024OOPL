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
		void Init(std::vector<std::string> paths);
		void Update(int scroll_step = 10);
		void Show();

	private:
		const int LEFT_MARGIN;            // Specifies the margin of the background from the left side of the screen.
		const int SCROLL_INTERVAL_MILLI;    // Specifies the duration of the interval between each scrolling step.
		clock_t scroll_clock;             // The clock used for calculating the interval.
		game_framework::CMovingBitmap part1;
		game_framework::CMovingBitmap part2;
	};
}
