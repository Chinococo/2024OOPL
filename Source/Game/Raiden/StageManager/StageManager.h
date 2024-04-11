#pragma once
#include "../Stage/Stage.h"
#include "../Player/Player.h"
#include "../Data/StageData.h"
#include <vector>
#include <memory>

namespace Raiden
{
	class StageManager
	{
	public:
		void Init(std::vector<StageData> &&stages_data);
		void Update(const Player &player);
		void Show();
		bool Over() const;

	private:
		void ChangeStage(std::size_t stage_index);
		std::vector<std::unique_ptr<Stage>> stages;
		std::size_t stage_index = 0;
		std::vector<StageData> stages_data;
	};
}
