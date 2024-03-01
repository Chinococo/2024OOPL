#pragma once
#include "Component.h"
#include "../../Library/gameutil.h"
#include <ctime>

namespace Raiden
{
	class Background : public Component
	{
	public:
		Background();
		void Init() override;
		void Update() override;
		void Show() override;

	private:
		const int LEFT_MARGIN;            // Specifies the margin of the background from the left side of the screen.
		const int SCROLL_STEP;            // Specifies the number of pixels scrolled per step.
		const int SCROLL_INTERVAL_SEC;    // Specifies the duration of the interval between each scrolling step.
		clock_t scroll_clock;             // The clock used for calculating the interval.
		game_framework::CMovingBitmap part1;
		game_framework::CMovingBitmap part2;
	};
}
