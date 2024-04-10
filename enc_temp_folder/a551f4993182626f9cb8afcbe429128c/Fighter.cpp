#include "stdafx.h"
#include "Fighter.h"
#include "../Player/Player.h"

namespace Raiden
{
	void Fighter::Init(FighterData &&fighter_data)
	{
		int color_mask_red = std::get<0>(fighter_data.color_mask);
		int color_mask_green = std::get<1>(fighter_data.color_mask);
		int color_mask_blue = std::get<2>(fighter_data.color_mask);

		sprite.LoadBitmapByString(fighter_data.sprites, RGB(color_mask_red, color_mask_green, color_mask_blue));
		positions = fighter_data.positions;
		attack_positions = std::vector<bool>(fighter_data.positions.size(), false);
		appear_distance = fighter_data.appear_distance;
		move_interval_milli = fighter_data.move_interval_milli;
		alive = true;
	}

	void Fighter::Update(const Player &player, int scrolled_distance)
	{
		if (scrolled_distance < appear_distance) {
			return;
		}
			

		move_clock = std::clock();

		std::clock_t elapsed_time = move_clock - start_move_time;
		double elapsed_time_sec = static_cast<double>(elapsed_time) / CLOCKS_PER_SEC;
		double move_interval_sec = static_cast<double>(move_interval_milli) / 1000;

		// The completeness of the current position index. The range is [0, 1].
		double completeness = min(1, elapsed_time_sec / move_interval_sec);
		// Stay at the last position.
		if (position_index == positions.size() - 2 && completeness == 1) {
			sprite.SetFrameIndexOfBitmap(12);
			sprite.SetTopLeft(sprite.GetLeft(), sprite.GetTop() + (scrolled_distance-last_distance)+3);
			last_distance = scrolled_distance;
			return;
		}
			

		int left = static_cast<int>((1 - completeness) * positions[position_index].x + completeness * positions[position_index + 1].x);
		int top = static_cast<int>((1 - completeness) * positions[position_index].y + completeness * positions[position_index + 1].y);
		double angle = atan2(-(positions[position_index + 1].y - positions[position_index].y),
			positions[position_index + 1].x - positions[position_index].x);
		
		sprite.SetTopLeft(left, top);
		last_distance = scrolled_distance;
		// Stay at the current position index.
		if (completeness < 1)
			return;
		
		double angleInDegrees = angle * (180.0 / M_PI);
		sprite.SetFrameIndexOfBitmap((static_cast<int>((angleInDegrees + 360) / 22.5) % 16));

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
