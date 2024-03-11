#include <StdAfx.h>
#include "Boss.h"
#include "../Player/Player.h"

namespace Raiden
{
	Boss::Boss(int health) : Enemy(health) {}

	void Boss::Update(const Player &player)
	{
		// TODO
	}

	bool Boss::Dead() const
	{
		return health == 0;
	}
}
