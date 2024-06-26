#include "stdafx.h"
#include "Fighter.h"
#include "../Player/Player.h"

namespace Raiden
{
	void Fighter::Init(FighterData &&fighter_data, std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>> bullets)
	{
		this->bullets = bullets;
		int color_mask_red = std::get<0>(fighter_data.color_mask);
		int color_mask_green = std::get<1>(fighter_data.color_mask);
		int color_mask_blue = std::get<2>(fighter_data.color_mask);
		bullet_speed = fighter_data.bullet_speed;
		bullet_type= fighter_data.bullet_type;
		bullet_angle= fighter_data.bullet_angle;
		this->position_index = 0;
		auto temp = fighter_data.sprites;
		sprite.LoadBitmapByString(temp, RGB(color_mask_red, color_mask_green, color_mask_blue));
		InitCollisionBox(sprite.GetWidth(), sprite.GetHeight());
		positions = fighter_data.positions;
		attack_positions = std::vector<bool>(fighter_data.positions.size(), false);
		appear_distance = fighter_data.appear_distance;
		move_interval_milli = fighter_data.move_interval_milli;
		alive = true;
		IsAppear = false;
		sprite.SetTopLeft(50, 50);
		sprite.SetFrameIndexOfBitmap(12);
	}

	void Fighter::Update(const Player &player, int scrolled_distance)
	{
		if (scrolled_distance < appear_distance) {
			return;
		}
		IsAppear = true;
		move_clock = std::clock();
		std::clock_t elapsed_time = move_clock - start_move_time;
		double elapsed_time_sec = static_cast<double>(elapsed_time) / CLOCKS_PER_SEC;
		double move_interval_sec = static_cast<double>(move_interval_milli) / 1000;

		// The completeness of the current position index. The range is [0, 1].
		double completeness = min(1, elapsed_time_sec / move_interval_sec);


		int left = static_cast<int>((1 - completeness) * positions[position_index].x + completeness * positions[position_index + 1].x);
		int top = static_cast<int>((1 - completeness) * positions[position_index].y + completeness * positions[position_index + 1].y);
		double angle = atan2(-(positions[position_index + 1].y - positions[position_index].y),
			positions[position_index + 1].x - positions[position_index].x);
		double angleInDegrees = angle * (180.0 / M_PI);
		double bulletAngleInRadians = bullet_angle * (M_PI/180.0);
		if (std::clock() - shoot_clock > 700)
		{
			int index = bullets->AddElement();
			bullets->operator[](index)->Init(false, bullet_type);
			bullets->operator[](index)->SetTopLeft({ sprite.GetLeft(),sprite.GetTop()});
			double bulletSpeedX = cos(bulletAngleInRadians);
			double bulletSpeedY = sin(bulletAngleInRadians);
			bullets->operator[](index)->ApplyForce({ static_cast<int>(bullet_speed * cos(bulletAngleInRadians)),static_cast<int>(-bullet_speed * sin(bulletAngleInRadians)) });
			shoot_clock = std::clock();
		}
		// Stay at the last position.
		if (position_index == positions.size() - 2 && completeness == 1) {
			sprite.SetFrameIndexOfBitmap(12);
			Move(sprite.GetLeft()+ offset_x, sprite.GetTop() + (scrolled_distance-last_distance)+3);
			last_distance = scrolled_distance;
			return;
		}
		Move(left, top);
		last_distance = scrolled_distance;
		// Stay at the current position index.
		if (completeness < 1)
			return;
		sprite.SetFrameIndexOfBitmap((static_cast<int>((angle + 360) / 30) % 16));

		start_move_time = std::clock();

		// Stay at the last position index.
		position_index = position_index < positions.size() - 2 ? position_index + 1 : position_index;
	}

	void Fighter::Show(bool debug)
	{
		if (IsAppear) {
			sprite.ShowBitmap(2);

			if (debug) {
				ShowCollisionBox();
			}
		}
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

	void Fighter::Move(int left, int top)
	{
		sprite.SetTopLeft(left, top);
		UpdateCollisionBox(left, top);
	}
}
