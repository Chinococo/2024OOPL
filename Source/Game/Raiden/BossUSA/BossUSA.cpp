#include "stdafx.h"
#include "BossUSA.h"

namespace Raiden
{
	void BossUSA::Init()
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString({ "Resources/TestSprite/TestSpritePurple.bmp" });
		sprite.SetTopLeft(0, 0);
		health = 1000;
	}

	void BossUSA::Update(const Player &player, bool start_attack)
	{
		// TODO: write the logic of bosses.
	}
}
