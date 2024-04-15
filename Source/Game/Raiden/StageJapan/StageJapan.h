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
		void InitDerived(StageData &&stage_data,shared_ptr<GameObjectPool<Fighter>>fighters, shared_ptr<GameObjectPool<Bullet>>bullets) override;
		void UpdateDerived(const Player &player) override;

	private:
		shared_ptr<GameObjectPool<Fighter>> fighter_pool;
		std::shared_ptr<GameObjectPool<Bullet>> bullet_pool;
	};
}
