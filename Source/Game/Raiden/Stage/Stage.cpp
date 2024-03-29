#include "stdafx.h"
#include "Stage.h"
#include "../Player/Player.h"

namespace Raiden
{
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
