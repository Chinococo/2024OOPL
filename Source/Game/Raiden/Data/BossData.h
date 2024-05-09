#pragma once
#include "AttackPeriodData.h"
#include <vector>
#include <atltypes.h>

namespace Raiden {
	struct BossData {
		std::vector<std::string> sprite_paths;
		std::tuple<int, int, int> color_mask;
		std::vector<CPoint> positions;
		std::vector<AttackPeriodData> attack_periods;
	};
}
