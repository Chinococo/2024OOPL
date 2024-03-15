#include <StdAfx.h>
#include "Fighter.h"
#include "../Player/Player.h"

namespace Raiden
{
	Fighter::Fighter(int health) : Enemy(health) {}

	void Fighter::Init()
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString({ "Resources/TestSprite/TestSpriteRed.bmp" });
	}

	void Fighter::Update(const Player &player)
	{
		// TODO: write the position and the sprite image.
	}
}
