#include "stdafx.h"
#include "Fighter.h"
#include "../Player/Player.h"

namespace Raiden
{
	void Fighter::Init()
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString({ "Resources/TestSprite/TestSpriteRed.bmp" });
		alive = true;

		// === TODO: integrate these with XMLReader later. ===
		for (int i = 10; i <= 500; i += 50)
			positions.push_back({ i, i });

		move_interval_milli = 300;
		appear_distance = 0;
		// ===================================================
	}

	void Fighter::Update(const Player &player, int scrolled_distance)
	{
		if (scrolled_distance < appear_distance)
			return;

		move_clock = std::clock();
		std::clock_t elapsed_time = move_clock - start_move_time;
		double alpha = min(1, static_cast<double>(elapsed_time) / move_interval_milli);
		int left = static_cast<int>((1 - alpha) * positions[position_index].x + alpha * positions[position_index + 1].x);
		int top = static_cast<int>((1 - alpha) * positions[position_index].y + alpha * positions[position_index + 1].y);

		sprite.SetTopLeft(left, top);

		if (static_cast<double>(move_clock - start_move_time) / CLOCKS_PER_SEC < static_cast<double>(move_interval_milli) / 1000)
			return;

		start_move_time = std::clock();

		// Stay at the last position.
		position_index = position_index < positions.size() - 2 ? position_index + 1 : position_index;
	}

	void Fighter::Show()
	{
		sprite.ShowBitmap();
	}

	void Fighter::Destroy()
	{
		alive = false;
	}

	bool Fighter::IsAlive() const
	{
		return alive;
	}
}
