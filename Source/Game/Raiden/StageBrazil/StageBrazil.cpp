#include "stdafx.h"
#include "StageBrazil.h"
#include "../BossBrazil/BossBrazil.h"

namespace Raiden
{
	void StageBrazil::InitDerived(StageData &&stage_data, shared_ptr<GameObjectPool<Fighter>>fighters)
	{
		this->fighter_pool = fighters;
		boss = std::make_unique<BossBrazil>(1000);
		boss->Init();
		
		for (auto &fighter_data : stage_data.fighters_data)
		{
			int index = fighter_pool->AddElement();
			fighter_pool->operator[](index)->Init(std::move(fighter_data));
		}
	}

	void StageBrazil::UpdateDerived(const Player &player)
	{
		// TODO: perform stage logic here.
		fighter_pool->Update();
		fighter_pool->operator[](0)->Update(player, background.GetScrolledDistance());
	}

	void StageBrazil::ShowDerived()
	{
		fighter_pool->Show();
	}
}
