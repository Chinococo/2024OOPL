#include "stdafx.h"
#include "Boss.h"
#include "../Player/Player.h"
#define M_PI 3.1415926
namespace Raiden
{
	void Boss::Init(BossData boss_data,std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullet)
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
		health = 200;
		bullets = bullet;
		this->LoadTurretGroup();
	}

	void Boss::Show()
	{
		is_appear = true;
		sprite.ShowBitmap();
		this->ShowCollisionBox();
	}

	void Boss::Damage(int damage)
	{
		health -= damage;
	}

	bool Boss::IsAlive() const
	{
		return health > 0;
	}

	bool Boss::IsAppear() const
	{
		return is_appear;
	}

	bool Boss::Dead() const
	{
		std::wstring health_str = std::to_wstring(health);
		health_str += L"\n";
		OutputDebugStringW(health_str.c_str());
		return health == 0;
	}


	CPoint Boss::GetTopLeft()
	{
		return CPoint(this->sprite.GetLeft(), this->sprite.GetTop());
	}

	void Boss::MoveTo(int left, int top)
	{
		sprite.SetTopLeft(left, top);
		UpdateCollisionBox(left, top);
	}

	void Boss::Move()
	{
		// Check if the boss has reached the last position
		if (position_index > positions.size() - 2)
		{
			if (clock() - move_time > 10) {
				if (std::rand() % 1000 < 1) {  // 1%的機率停下來10秒
					move_time += 10 * CLOCKS_PER_SEC;
					return;
				}
				angle += 1.0f;
				if (angle >= 360.0f) {
					angle -= 360.0f;
				}
				double radians = angle * (M_PI / 180.0f);
				int newX = static_cast<int>(last_position_X + 100 * std::cos(radians) - 100);
				int newY = static_cast<int>(last_position_Y + 100 * std::sin(radians));
				MoveTo(newX, newY);
				move_time = clock();
			}
			return;
		}

		// Calculate the elapsed time since the last movement in milliseconds
		double elapsed_time_milli = static_cast<double>(std::clock() - start_move_time) / CLOCKS_PER_SEC * 1000;

		// Calculate the completeness of the current movement, ranging from 0 to 1
		double completeness = min(1, elapsed_time_milli / move_interval_milli);

		// Compute the interpolated position based on the current and next positions
		int left = static_cast<int>((1 - completeness) * positions[position_index].x + completeness * positions[position_index + 1].x);
		int top = static_cast<int>((1 - completeness) * positions[position_index].y + completeness * positions[position_index + 1].y);

		// Move the boss and update its collision box to the computed position
		MoveTo(left, top);
		last_position_X = left, last_position_Y = top;
		// Check if the movement is not yet complete
		if (completeness < 1)
			return; // If not, wait for the next update cycle before proceeding

		// Update the start-move-time for the next movement
		start_move_time = std::clock();

		// Move to the next position index
		position_index++;
	}


	void Boss::Update(const Player &player)
	{
		Move();
		turretGroup->update({ this->sprite.GetLeft(), this->sprite.GetTop() });
		if (clock() - bullet_interval > 1000) {
			//Attack(player);
			
			//bullet_interval = clock();
		}
			
	}
}
