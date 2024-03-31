#include "stdafx.h"
#include "StageJapan.h"
#include "../BossJapan/BossJapan.h"

namespace Raiden
{
	void StageJapan::Init()
	{
		background.Init({ "Resources/Background/StageJapan.bmp", "Resources/Background/StageComplement.bmp" });
		boss = std::make_unique<BossJapan>(1000);
		boss->Init();

		

		for (int i = 0; i < FIGHTER_COUNT; i++)
			fighter_pool.AddElement();
	}

	void StageJapan::UpdateDerived(const Player &player)
	{
		// TODO: perform stage logic here.
		fighter_pool.Update();
		bullet_pool.Update();

		for (int i = 0; i < FIGHTER_COUNT; i++)
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
				bullet_count++;
			}
		}

		for (int i = 0; i < bullet_count; i++)
		{
			if (!bullet_pool[i]->IsAlive())
			{
				bullet_pool[i]->Destroy();
				continue;
			}

			bullet_pool[i]->Update();
		}
	}

	void StageJapan::ShowDerived()
	{
		fighter_pool.Show();
		bullet_pool.Show();
	}
}
