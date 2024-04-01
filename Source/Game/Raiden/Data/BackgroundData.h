#pragma once
#include <vector>
#include <string>

namespace Raiden
{
	struct BackgroundData
	{
		int left_margin;
		int scroll_step;
		int scroll_interval_milli;
		std::vector<std::string> sprites;
	};
}
