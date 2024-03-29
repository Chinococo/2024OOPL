#include "stdafx.h"
#include "StageUSA.h"
#include "../BossUSA/BossUSA.h"

namespace Raiden
{
	void StageUSA::Init()
	{
		background.Init({ "Resources/Background/StageUSA.bmp", "Resources/Background/StageComplement.bmp" });
		boss = std::make_unique<BossUSA>(1000);
		boss->Init();
		fighter_pool.AddElement();
	}

	void StageUSA::UpdateDerived(const Player &player)
	{
		// TODO: perform stage logic here.
		fighter_pool.Update();
		fighter_pool[0]->Update(player, background.GetScrolledDistance());
	}

	void StageUSA::ShowDerived()
	{
		fighter_pool.Show();
	}
}
