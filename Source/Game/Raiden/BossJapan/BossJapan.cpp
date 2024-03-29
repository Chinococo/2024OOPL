#include "stdafx.h"
#include "BossJapan.h"

namespace Raiden
{
	void BossJapan::Init()
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString({ "Resources/TestSprite/TestSpritePurple.bmp" });
		sprite.SetTopLeft(0, 0);
		health = 1000;
	}

	void BossJapan::Update(const Player &player, bool start_attack)
	{
		// TODO: write the logic of bosses.
	}
}
