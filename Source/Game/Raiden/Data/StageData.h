#pragma once
#include "BackgroundData.h"
#include "FighterData.h"
#include "BossData.h"

namespace Raiden
{
	struct StageData
	{
		BackgroundData background_data;
		std::vector<FighterData> fighters_data;
		BossData boss_data;
	};
}
