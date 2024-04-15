#pragma once
#include "../Stage/Stage.h"
#include "../Player/Player.h"
#include "../GameObjectPool/GameObjectPool.h"
#include "../Fighter/Fighter.h"
#include "../Bullet/Bullet.h"

namespace Raiden
{
	class StageUSA : public Stage
	{
	public:
		void InitDerived(StageData &&stage_data, shared_ptr<GameObjectPool<Fighter>>fighters) override;
		void UpdateDerived(const Player &player) override;

	private:
		std::shared_ptr<GameObjectPool<Fighter>> fighter_pool;
		GameObjectPool<Bullet> bullet_pool;
	};
}
