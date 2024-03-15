#include <StdAfx.h>
#include "BossUSA.h"

namespace Raiden
{
	BossUSA::BossUSA(int health) : Boss(health) {}

	void BossUSA::Init()
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString({ "Resources/TestSprite/TestSpritePurple.bmp" });
		sprite.SetTopLeft(0, 0);
	}
}