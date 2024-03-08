#pragma once
#include <vector>
#include <memory>
#include "Stage.hpp"

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
