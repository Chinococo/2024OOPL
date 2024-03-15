#include <StdAfx.h>
#include "BossJapan.h"

namespace Raiden
{
	BossJapan::BossJapan(int health) : Boss(health) {}
	
	void BossJapan::Init()
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString({ "Resources/TestSprite/TestSpritePurple.bmp" });
		sprite.SetTopLeft(0, 0);
	}

	void BossJapan::Update(const Player &player)
	{
		// TODO: write the logic of bosses.
	}
}
