#include "stdafx.h"
#include "../StateManager/StateManager.h"
#include "../SelectControlState/SelectControlState.h"
#include "../RunningState/RunningState.h"

namespace Raiden
{
	void StateManager::Init()
	{
		states.push_back(std::make_unique<SelectControlState>());
		states.push_back(std::make_unique<RunningState>());
		ChangeState(0);
	}

	void StateManager::MouseMove(CPoint &&point)
	{
		control.point = std::move(point);
	}

	void StateManager::KeyUp(Key key)
	{
		control.keys = std::set<Key>{ key };
		states[state_index]->KeyUp(control);
	}

	void StateManager::Update(const std::set<Key> &keys)
	{
		if (states[state_index]->Over())
			ChangeState(state_index + 1);

		control.keys = keys;
		states[state_index]->Update(control);
	}

	void StateManager::Show()
	{
		if(state_index< states.size())
			states[state_index]->Show();
	}

	void StateManager::ChangeState(std::size_t state_index)
	{
		this->state_index = state_index;
		states[state_index]->Init();
	}
}
