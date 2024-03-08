#pragma once
#include "Stage.hpp"
#include <vector>
#include <memory>

namespace Raiden
{
	class StageManager
	{
	public:
		void Init(); // Init to the first stage.
		bool Update();
		void Show();

	private:
		std::vector<std::unique_ptr<Stage>> stages;
		std::size_t stage_index = 0;
		void Switch(std::size_t stage_index);
	};
}
