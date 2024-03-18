#include <StdAfx.h>
#include "StageUSA.h"
#include "../BossUSA/BossUSA.h"

namespace Raiden
{
	void StageUSA::Init()
	{
		background.Init({ "Resources/Background/StageUSA.bmp", "Resources/Background/StageComplement.bmp" });
		boss = std::make_unique<BossUSA>(1000);
		boss->Init();
		fighterPool.AddElement({ 50, 50 });
	}

	void StageUSA::UpdateDerived(const Player &player)
	{
		// TODO: perform stage logic here.
	}

	void StageUSA::ShowDerived()
	{
		fighterPool.Show();
	}
}
