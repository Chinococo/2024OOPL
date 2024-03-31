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
		void UpdateDerived(const Player &player) override;
		void ShowDerived() override;

	private:
		GameObjectPool<Fighter> fighter_pool;
		GameObjectPool<Bullet> bullet_pool;
		int bullet_count = 0;
	};
}
