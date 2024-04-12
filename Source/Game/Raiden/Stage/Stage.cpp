#include "stdafx.h"
#include "Stage.h"
#include "../Player/Player.h"

namespace Raiden
{
	void Stage::Init(StageData &&stage_data,shared_ptr<GameObjectPool<Fighter>>fighters)
	{
		background.Init(stage_data.background_data);
		InitDerived(std::move(stage_data), fighters);
	}

	void Stage::Update(const Player &player)
	{
		background.Update();
		boss->Update(player, background.Over());
		UpdateDerived(player);
	}

	void Stage::Show()
	{
		background.Show();
		boss->Show();
		ShowDerived();
	}

	bool Stage::Over() const
	{
		return boss->Dead();
	}
}
