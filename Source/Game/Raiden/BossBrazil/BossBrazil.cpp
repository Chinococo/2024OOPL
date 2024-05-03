#include "stdafx.h"
#include "BossBrazil.h"

namespace Raiden
{
	void BossBrazil::Init(BossData boss_data)
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString({ "Resources/TestSprite/TestSpritePurple.bmp" });
		this->InitCollisionBox(this->sprite.GetWidth(), this->sprite.GetHeight());
		sprite.SetTopLeft(0, 0);
		health = 1000;
	}

	void BossBrazil::Attack(const Player &player)
	{
		// TODO: write the logic of bosses.
	}
}
