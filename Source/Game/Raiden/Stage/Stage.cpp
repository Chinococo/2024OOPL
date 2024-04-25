#include "stdafx.h"
#include "Stage.h"
#include "../Player/Player.h"

namespace Raiden
{
	void Stage::Init(StageData &&stage_data,shared_ptr<GameObjectPool<Fighter>>fighters, shared_ptr<GameObjectPool<Bullet>>bullets)
	{
		background.Init(stage_data.background_data);
		InitDerived(std::move(stage_data), fighters, bullets);
	}

	void Stage::Update(const Player &player)
	{
		background.Update();
		if (background.Over())
			boss->Update(player);
		UpdateDerived(player);
	}

	void Stage::Show()
	{
		background.Show();
		if (background.Over())
			boss->Show();
	}

	bool Stage::Over() const
	{
		return boss->Dead();
	}
}
