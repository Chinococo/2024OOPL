#pragma once
#include "../Stage/Stage.h"
#include "../Player/Player.h"
#include "../Fighter/Fighter.h"
#include "../Data/StageData.h"
#include <vector>
#include <memory>

namespace Raiden
{
	class StageManager
	{
	public:
		void Init(std::vector<StageData>&& stages_data, std::shared_ptr<GameObjectPool<Fighter>> fighters, std::shared_ptr<GameObjectPool<Bullet>> bullets, std::shared_ptr<Boss> boss);
		void Update(const Player &player);
		void Show(bool debug);
		bool Over() const;
		std::shared_ptr<Boss> GetBoss();
	private:
		void ChangeStage(std::size_t stage_index);
		std::vector<std::unique_ptr<Stage>> stages;
		std::size_t stage_index = 0;
		std::vector<StageData> stages_data;
		std::shared_ptr<GameObjectPool<Fighter>> fighters;
		std::shared_ptr<GameObjectPool<Bullet>> bullets;
		std::shared_ptr<Boss> boss;
	};
}
