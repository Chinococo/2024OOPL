#include <StdAfx.h>
#include "Fighter.h"
#include "../Player/Player.h"

namespace Raiden
{
	Fighter::Fighter(int health) : Enemy(health) {}

	void Fighter::Init()
	{
		// TODO
		sprite.LoadBitmapByString({ "TODO" });
		sprite.SetTopLeft(0, 0);
	}

	void Fighter::Update(const Player &player)
	{
		// TODO
	}
}
