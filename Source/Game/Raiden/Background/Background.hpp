#pragma once
#include "../Component.hpp"
#include "../../../Library/gameutil.h"
#include <ctime>
#include <vector>
#include <string>

namespace Raiden
{
	class Background : public Component
	{
	public:
		Background();
		void Init() override;
		void Update() override;
		void Show() override;
		void Switch(std::size_t id);

	private:
		const int LEFT_MARGIN;            // Specifies the margin of the background from the left side of the screen.
		const int SCROLL_STEP;            // Specifies the number of pixels scrolled per step.
		const int SCROLL_INTERVAL_MILLI;    // Specifies the duration of the interval between each scrolling step.
		clock_t scroll_clock;             // The clock used for calculating the interval.
		game_framework::CMovingBitmap part1;
		game_framework::CMovingBitmap part2;
		std::vector<std::vector<std::string>> paths;
	};
}
