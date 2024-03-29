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
		{
			positions.push_back({ i, i });
			attack_positions.push_back(i % 2 == 0);
		}

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
		double elapsed_time_sec = static_cast<double>(elapsed_time) / CLOCKS_PER_SEC;
		double move_interval_sec = static_cast<double>(move_interval_milli) / 1000;

		// The completeness of the current position index. The range is [0, 1].
		double completeness = min(1, elapsed_time_sec / move_interval_sec);

		// Stay at the last position.
		if (position_index == positions.size() - 2 && completeness == 1)
			return;

		int left = static_cast<int>((1 - completeness) * positions[position_index].x + completeness * positions[position_index + 1].x);
		int top = static_cast<int>((1 - completeness) * positions[position_index].y + completeness * positions[position_index + 1].y);

		sprite.SetTopLeft(left, top);

		// Stay at the current position index.
		if (completeness < 1)
			return;

		start_move_time = std::clock();

		// Stay at the last position index.
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

	bool Fighter::IsAttacking() const
	{
		return attack_positions[position_index];
	}

	int Fighter::GetLeft()
	{
		return sprite.GetLeft();
	}

	int Fighter::GetTop()
	{
		return sprite.GetTop();
	}
}
