#pragma once
#include <vector>
#include <tuple>
#include <atltypes.h>

namespace Raiden
{
	struct FighterData
	{
		int appear_distance;
		int move_interval_milli;
		std::tuple<int, int, int> color_mask;
		std::vector<std::string> sprites;
		std::vector<CPoint> positions;
	};
}
