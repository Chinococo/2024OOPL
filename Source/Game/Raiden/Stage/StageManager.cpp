#include <StdAfx.h>
#include "StageManager.hpp"
#include "../../../Library/gamecore.h"

namespace Raiden
{
	void StageManager::Init()
	{
		Switch(0);
	}

	bool StageManager::Update()
	{
		if (stages[stage_index]->Update()) // If the current stage is completed.
		{
			if (stage_index == stages.size() - 1)  // If it is the last stage.
				return true;

			Switch(stage_index + 1); // Proceed to the next stage.
		}

		return false; // The current stage is in progress.
	}

	void StageManager::Show()
	{
		stages[stage_index]->Show();
	}

	void StageManager::Switch(std::size_t stage_index)
	{
		this->stage_index = stage_index;
		stages[stage_index]->Init();
	}
}
