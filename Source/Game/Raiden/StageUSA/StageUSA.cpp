#include "stdafx.h"
#include "StageUSA.h"
#include "../BossUSA/BossUSA.h"

namespace Raiden
{
	void StageUSA::InitDerived(StageData &&stage_data)
	{
		boss = std::make_unique<BossUSA>(1000);
		boss->Init();
		
		for (auto &fighter_data : stage_data.fighters_data)
		{
			int index = fighter_pool.AddElement();
			fighter_pool[index]->Init(std::move(fighter_data));
		}
	}

	void StageUSA::UpdateDerived(const Player &player)
	{
		// TODO: perform stage logic here.
		fighter_pool.Update();
		bullet_pool.Update();

		for (std::size_t i = 0; i < fighter_pool.GetSize(); i++)
		{
			if (!fighter_pool[i]->IsAlive())
			{
				fighter_pool[i]->Destroy();
				continue;
			}

			fighter_pool[i]->Update(player, background.GetScrolledDistance());

			if (fighter_pool[i]->IsAttacking())
			{
				int bullet_index = bullet_pool.AddElement();
				bullet_pool[bullet_index]->SetTopLeft({ fighter_pool[i]->GetLeft(), fighter_pool[i]->GetTop() });
				bullet_pool[bullet_index]->ApplyForce({ 0, 1 });
			}
		}

		for (std::size_t i = 0; i < bullet_pool.GetSize(); i++)
		{
			if (!bullet_pool[i]->IsAlive())
			{
				bullet_pool[i]->Destroy();
				continue;
			}

			bullet_pool[i]->Update();
		}
	}

	void StageUSA::ShowDerived()
	{
		fighter_pool.Show();
	}
}
