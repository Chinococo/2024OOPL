#pragma once
#include <ctime>
#include <vector>
#include <string>
#include "../../../Library/gameutil.h"

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
		const int LEFT_MARGIN; // Specifies the margin of the background from the left side of the screen.
		game_framework::CMovingBitmap part1;
		game_framework::CMovingBitmap part2;
	};
}
