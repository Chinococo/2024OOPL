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
		fighter_pool.AddElement();
	}

	void StageJapan::UpdateDerived(const Player &player, int scrolled_distance)
	{
		// TODO: perform stage logic here.
		fighter_pool.Update();
		fighter_pool[0]->Update(player, scrolled_distance);
	}

	void StageJapan::ShowDerived()
	{
		fighter_pool.Show();
	}
}
