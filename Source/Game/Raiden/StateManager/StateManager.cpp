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

	void StateManager::Update(Control &&control)
	{
		if (states[state_index]->Over())
			ChangeState(state_index + 1);

		states[state_index]->Update(std::move(control));
	}

	void StateManager::Show()
	{
		states[state_index]->Show();
	}

	void StateManager::ChangeState(std::size_t state_index)
	{
		this->state_index = state_index;
		states[state_index]->Init();
	}
}
