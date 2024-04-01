#pragma once
#include <vector>
#include <string>
#include <atltypes.h>
#include <tuple>

namespace Raiden
{
	struct PlayerData
	{
		std::tuple<int, int, int> color_mask;
		std::vector<std::string> sprites;
		CPoint init_position;
	};
}
