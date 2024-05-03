#include "stdafx.h"
#include "BossUSA.h"

namespace Raiden
{
	void BossUSA::Init(BossData boss_data)
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString({ "Resources/TestSprite/TestSpritePurple.bmp" });
		sprite.SetTopLeft(0, 0);
		health = 1000;
	}

	void BossUSA::Attack(const Player &player)
	{
		// TODO: write the logic of bosses.
	}
}
