#include "stdafx.h"
#include "Boss.h"
#include "../Player/Player.h"

namespace Raiden
{
	void Boss::Show()
	{
		sprite.ShowBitmap();
	}

	bool Boss::Dead() const
	{
		return health == 0;
	}
	Boss::Boss(int health) {
		this->health = health;
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
		Attack(player);
	}
}
