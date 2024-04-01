#include "stdafx.h"
#include "Stage.h"
#include "../Player/Player.h"

namespace Raiden
{
	void Stage::Init(StageData &&stage_data)
	{
		background.Init(stage_data.background_data);
		InitDerived(std::move(stage_data));
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
