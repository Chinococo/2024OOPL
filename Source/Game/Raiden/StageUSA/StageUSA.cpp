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
		boss->Init(stage_data.boss_data, bullets);
		
		for (auto &fighter_data : stage_data.fighters_data)
		{
			int index = fighter_pool->AddElement();
			fighter_pool->operator[](index)->Init(std::move(fighter_data), bullets);
		}
	}

	void StageUSA::UpdateDerived(const Player &player)
	{
		for (std::size_t i = 0; i < fighter_pool->GetSize(); i++)
		{
			fighter_pool->operator[](i)->Update(player, background.GetScrolledDistance());

			if (fighter_pool->operator[](i)->IsAttacking())
			{
				int bullet_index = bullet_pool->AddElement();
				bullet_pool->operator[](bullet_index)->SetTopLeft({ fighter_pool->operator[](i)->GetLeft(), fighter_pool->operator[](i)->GetTop() });
				bullet_pool->operator[](bullet_index)->ApplyForce({ 0, 10 });
			}
		}
	}
}
