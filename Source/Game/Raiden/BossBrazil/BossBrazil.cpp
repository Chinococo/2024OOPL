#include "stdafx.h"
#include "BossBrazil.h"

namespace Raiden
{
	BossBrazil::BossBrazil(int health) : Boss(health) {}

	void BossBrazil::Init()
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString({ "Resources/TestSprite/TestSpritePurple.bmp" });
		sprite.SetTopLeft(0, 0);
	}

	void BossBrazil::Update(const Player &player, bool start_attack)
	{
		// TODO: write the logic of bosses.
	}
}
