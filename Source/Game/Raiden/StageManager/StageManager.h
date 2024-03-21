#pragma once
#include "../Stage/Stage.h"
#include "../Player/Player.h"
#include <vector>
#include <memory>

namespace Raiden
{
	class StageManager
	{
	public:
		void Init();
		void Update(const Player &player);
		void Show();
		bool Over() const;

	private:
		std::vector<std::unique_ptr<Stage>> stages;
		std::size_t stage_index = 0;
		void ChangeStage(std::size_t stage_index);
	};
}
