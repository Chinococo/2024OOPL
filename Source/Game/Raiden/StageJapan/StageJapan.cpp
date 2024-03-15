#include <StdAfx.h>
#include "StageJapan.h"
#include "../BossJapan/BossJapan.h"

namespace Raiden
{
	void StageJapan::Init()
	{
		background.Init({ "Resources/Background/StageJapan.bmp", "Resources/Background/StageComplement.bmp" });
		boss = std::make_unique<BossJapan>(1000);
		boss->Init();
	}
}
