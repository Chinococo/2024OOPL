#pragma once
#include "../Stage/Stage.h"
#include "../Player/Player.h"
#include "../GameObjectPool/GameObjectPool.h"
#include "../Fighter/Fighter.h"
#include "../Bullet/Bullet.h"

namespace Raiden
{
	class StageJapan : public Stage
	{
	public:
		void Init() override;
		void UpdateDerived(const Player &player, int scrolled_distance) override;
		void ShowDerived() override;

	private:
		const int FIGHTER_COUNT = 1;
		GameObjectPool<Fighter> fighter_pool;
		GameObjectPool<Bullet> bullet_pool;
		int bullet_count = 0;
	};
}
