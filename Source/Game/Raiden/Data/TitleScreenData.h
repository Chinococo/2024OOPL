#pragma once
#include <vector>
#include <atltypes.h>

namespace Raiden
{
	struct SelectionLineData
	{
		std::vector<CPoint> positions;
		std::vector<std::string> sprites;
	};

	struct TitleScreenData
	{
		int animation_delay_milli;
		int left_margin;
		std::vector<std::string> sprites;
		SelectionLineData selection_line_data;
	};
}
