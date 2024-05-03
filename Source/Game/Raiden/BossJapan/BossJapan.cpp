#include "stdafx.h"
#include "BossJapan.h"

namespace Raiden
{
	void BossJapan::Init(BossData boss_data)
	{
		// Extracting color mask values from the boss_data tuple
		int color_mask_red = std::get<0>(boss_data.color_mask); // Red component of color mask
		int color_mask_green = std::get<1>(boss_data.color_mask); // Green component of color mask
		int color_mask_blue = std::get<2>(boss_data.color_mask); // Blue component of color mask

		// Loading sprite image using extracted color mask values
		sprite.LoadBitmapByString(boss_data.sprite_paths, RGB(color_mask_red, color_mask_green, color_mask_blue));

		// Initializing collision box with sprite dimensions
		InitCollisionBox(sprite.GetWidth(), sprite.GetHeight());

		// Assigning boss positions from boss_data
		positions = boss_data.positions;

		// Setting initial health value
		health = 1000;
	}

	void BossJapan::Attack(const Player &player)
	{
		
	}
}
