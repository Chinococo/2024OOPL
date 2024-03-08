#include <StdAfx.h>
#include "Stage.hpp"

namespace Raiden
{
	bool Stage::Update()
	{
		background.Update();
	}

	void Stage::Show()
	{
		background.Show();
	}
}
