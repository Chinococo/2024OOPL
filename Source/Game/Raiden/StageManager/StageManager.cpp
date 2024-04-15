#include "stdafx.h"
#include "StageManager.h"
#include "../StageJapan/StageJapan.h"
#include "../StageBrazil/StageBrazil.h"
#include "../StageUSA/StageUSA.h"
#include "../Player/Player.h"
#include <memory>

namespace Raiden
{
	void StageManager::Init(std::vector<StageData>&& stages_data, std::shared_ptr<GameObjectPool<Fighter>> fighters, std::shared_ptr<GameObjectPool<Bullet>> bullets)
	{
		this->fighters = fighters;
		this->bullets = bullets;
		stages.clear();
		stages.push_back(std::make_unique<StageJapan>());
		stages.push_back(std::make_unique<StageBrazil>());
		stages.push_back(std::make_unique<StageUSA>());
		this->stages_data = stages_data;
		ChangeStage(0);
	}

	void StageManager::Update(const Player &player)
	{
		if (stages[stage_index]->Over())
			ChangeStage(stage_index + 1);
		
		stages[stage_index]->Update(player);
	}

	void StageManager::Show()
	{
		stages[stage_index]->Show();
	}

	bool StageManager::Over() const
	{
		return stage_index == stages.size() - 1 && stages[stage_index]->Over();
	}

	void StageManager::ChangeStage(std::size_t stage_index)
	{
		if (stage_index >= stages.size())
			return;
		
		this->stage_index = stage_index;
		stages[stage_index]->Init(std::move(stages_data[stage_index]), fighters, bullets);
	}
}
