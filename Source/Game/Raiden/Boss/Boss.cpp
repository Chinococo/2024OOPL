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
		std::vector<std::string> bitmapPaths;
		for (int i = 0; i <= 7; ++i) {
			bitmapPaths.push_back("Resources/fx/" + std::to_string(i) + ".bmp");
		}
		fx.LoadBitmapByString(bitmapPaths, RGB(255, 255, 255));
	}

	void Boss::Show(bool debug)
	{
		is_appear = true;
		sprite.ShowBitmap();

		if (debug) {
			this->ShowCollisionBox();
		}
		
		if (fx_toggle) {
			this->fx.ShowBitmap();
		}
		
	}

	void Boss::Damage(int damage)
	{
		if (health / 30 != (health - damage) / 30) {
			fx.SetAnimation(10, true);
			fx.ToggleAnimation();
			fx_toggle = true;
		} 
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
		if(!this->fx_toggle)
			fx.SetTopLeft(left+std::rand()%(sprite.GetWidth()-50), top + std::rand() % (sprite.GetHeight()-50));
		UpdateCollisionBox(left, top);
	}

	void Boss::Move()
	{
		// Check if the boss has reached the last position
		if (position_index > positions.size() - 2)
		{
			position_index = 0;
			turret_groups_index = (turret_groups_index + 1) % turretGroups.size();
			start_move_time = clock();
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
		if (this->fx.IsAnimationDone()) {
			this->fx_toggle = false;
		}
		Move();
		turretGroups[turret_groups_index]->update({ this->sprite.GetLeft(), this->sprite.GetTop() });
		if (clock() - bullet_interval > 1000) {
			//Attack(player);
			
			//bullet_interval = clock();
		}
			
	}
}
