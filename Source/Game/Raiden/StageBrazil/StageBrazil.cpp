#include "stdafx.h"
#include "StageBrazil.h"
#include "../BossBrazil/BossBrazil.h"

namespace Raiden
{
	void StageBrazil::Init()
	{
		background.Init({ "Resources/Background/StageBrazil.bmp", "Resources/Background/StageComplement.bmp" });
		boss = std::make_unique<BossBrazil>(1000);
		boss->Init();
		fighter_pool.AddElement();
	}

	void StageBrazil::UpdateDerived(const Player &player)
	{
		// TODO: perform stage logic here.
		fighter_pool.Update();
		fighter_pool[0]->Update(player, background.GetScrolledDistance());
	}

	void StageBrazil::ShowDerived()
	{
		fighter_pool.Show();
	}
}
