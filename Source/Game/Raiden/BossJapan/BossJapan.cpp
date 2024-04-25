#include "stdafx.h"
#include "BossJapan.h"

namespace Raiden
{
	void BossJapan::Init(BossData boss_data)
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString(boss_data.sprite_paths);

		CPoint position = boss_data.positions[0];
		sprite.SetTopLeft(position.x, position.y);

		health = 1000;
	}

	void BossJapan::Update(const Player &player)
	{
		// TODO: write the logic of bosses.
	}
}
