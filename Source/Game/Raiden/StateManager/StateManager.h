#pragma once
#include "../State/State.h"
#include "../Control/Control.h"
#include <vector>
#include <memory>

namespace Raiden
{
	class StateManager
	{
	public:
		void Init();
		void Update(Control &&control);
		void Show();

	private:
		void ChangeState(std::size_t state_index);
		std::vector<std::unique_ptr<State>> states;
		std::size_t state_index = 0;
	};
}
