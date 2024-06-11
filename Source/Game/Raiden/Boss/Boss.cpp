#include "stdafx.h"
#include "Boss.h"
#include "../Player/Player.h"

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
		turretGroup = new TurretGroup(bullets);
		turretGroup->LoadFromXML("Resources/turret/boss.xml");
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
			return; // If so, stop moving

		// Calculate the elapsed time since the last movement in milliseconds
		double elapsed_time_milli = static_cast<double>(std::clock() - start_move_time) / CLOCKS_PER_SEC * 1000;

		// Calculate the completeness of the current movement, ranging from 0 to 1
		double completeness = min(1, elapsed_time_milli / move_interval_milli);

		// Compute the interpolated position based on the current and next positions
		int left = static_cast<int>((1 - completeness) * positions[position_index].x + completeness * positions[position_index + 1].x);
		int top = static_cast<int>((1 - completeness) * positions[position_index].y + completeness * positions[position_index + 1].y);

		// Move the boss and update its collision box to the computed position
		MoveTo(left, top);

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
