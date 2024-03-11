#include <StdAfx.h>
#include "Stage.hpp"
#include "../Background/Background.hpp"
#include "../AnimatedBitmap/AnimatedBitmap.hpp"

namespace Raiden
{
	void Stage::Init()
	{
		background.Init({ "Resources/TestSprite/TestStage.bmp", "Resources/Background/StageComplement.bmp" });
	}
	
	void Stage::Update()
	{
		background.Update();
	}

	void Stage::Show()
	{
		background.Show();
	}

	bool Stage::Over()
	{
		return false;
	}
}
