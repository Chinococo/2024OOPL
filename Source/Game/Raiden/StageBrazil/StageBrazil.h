#pragma once
#include "../Stage/Stage.h"
#include "../Player/Player.h"
#include "../GameObjectPool/GameObjectPool.h"
#include "../Fighter/Fighter.h"

namespace Raiden
{
	class StageBrazil : public Stage
	{
	public:
		void Init() override;
		void UpdateDerived(const Player &player, int scrolled_distance) override;
		void ShowDerived() override;

	private:
		GameObjectPool<Fighter> fighter_pool;

	};
}
