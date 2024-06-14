#include "stdafx.h"
#include "StageJapan.h"
#include "../BossJapan/BossJapan.h"

namespace Raiden
{
	void StageJapan::InitDerived(StageData &&stage_data, shared_ptr<GameObjectPool<Fighter>> fighter, shared_ptr<GameObjectPool<Bullet>>bullets)
	{
		this->fighter_pool = fighter;
		this->bullet_pool = bullets;
		boss = std::make_shared<BossJapan>();
		boss->Init(stage_data.boss_data, bullets);

		for (auto &fighter_data : stage_data.fighters_data)
		{
			int index = fighter_pool->AddElement();
			fighter_pool->operator[](index)->Init(std::move(fighter_data), bullets);
		}
	}

	void StageJapan::UpdateDerived(const Player &player)
	{
		// TODO: perform stage logic here.
		//fighter_pool->Update();
		//fighter_pool->operator[](0)->Update(player, background.GetScrolledDistance());
		for (std::size_t i = 0; i < fighter_pool->GetSize(); i++)
		{
			fighter_pool->operator[](i)->Update(player, background.GetScrolledDistance());

			if (fighter_pool->operator[](i)->IsAttacking())
			{
				int bullet_index = bullet_pool->AddElement();
				bullet_pool->operator[](bullet_index)->SetTopLeft({ fighter_pool->operator[](i)->GetLeft(), fighter_pool->operator[](i)->GetTop() });
				bullet_pool->operator[](bullet_index)->ApplyForce({ 0, 1 });
			}
		}
	}
}
