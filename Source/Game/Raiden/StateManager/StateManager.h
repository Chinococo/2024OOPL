#pragma once
#include "../State/State.h"
#include "../Control/Control.h"
#include "../Key/Key.h"
#include <vector>
#include <memory>
#include <set>
#include <atltypes.h>

namespace Raiden
{
	class StateManager
	{
	public:
		void Init();
		void MouseMove(CPoint &&point);
		void KeyUp(Key key);
		void Update(const std::set<Key> &keys);
		void Show();

	private:
		void ChangeState(std::size_t state_index);
		std::vector<std::unique_ptr<State>> states;
		std::size_t state_index = 0;
		Control control;
	};
}
