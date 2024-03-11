#include <StdAfx.h>
#include "Stage.h"
#include "../Player/Player.h"

namespace Raiden
{
	void Stage::Update(const Player &player)
	{
		background.Update();
		boss->Update();

		for (Enemy &enemy : enemies)
			enemy.Update();
	}

	void Stage::Show()
	{
		background.Show();
		boss->Show();
		
		for (Enemy &enemy : enemies)
			enemy.Show();
	}

	bool Stage::Over() const
	{
		return boss->Dead();
	}
}
