#pragma once
#include "AttackPeriodData.h"
#include <vector>
#include <atltypes.h>

namespace Raiden {
	struct BossData {
		std::vector<std::string> sprite_paths;
		std::vector<CPoint> positions;
		std::vector<AttackPeriodData> attack_periods;
	};
}
