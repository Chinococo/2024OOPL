#include "stdafx.h"
#include "StageUSA.h"
#include "../BossUSA/BossUSA.h"
#include "../../config.h"
namespace Raiden
{
	void StageUSA::InitDerived(StageData &&stage_data, shared_ptr<GameObjectPool<Fighter>>fighters, shared_ptr<GameObjectPool<Bullet>>bullets)
	{
		this->fighter_pool = fighters;
		this->bullet_pool = bullets;
		boss = std::make_shared<BossUSA>();
		boss->Init(stage_data.boss_data);
		
		for (auto &fighter_data : stage_data.fighters_data)
		{
			int index = fighter_pool->AddElement();
			fighter_pool->operator[](index)->Init(std::move(fighter_data), bullets);
		}
	}

	void StageUSA::UpdateDerived(const Player &player)
	{
		// TODO: perform stage logic here.
		fighter_pool->Update();
		//fighter_pool->operator[](0)->Update(player, background.GetScrolledDistance());
		for (std::size_t i = 0; i < fighter_pool->GetSize(); i++)
		{
			if (!fighter_pool->operator[](i)->IsAlive())
			{
				fighter_pool->operator[](i)->Destroy();
				continue;
			}

			if (fighter_pool->operator[](i)->GetLeft() < 0 || fighter_pool->operator[](i)->GetLeft() >= RESOLUTION_X) {
				fighter_pool->operator[](i)->Destroy();
				continue;
			}

			if (fighter_pool->operator[](i)->GetTop() < 0 || fighter_pool->operator[](i)->GetTop() >= RESOLUTION_Y) {
				fighter_pool->operator[](i)->Destroy();
				continue;
			}
		}
	}
}
