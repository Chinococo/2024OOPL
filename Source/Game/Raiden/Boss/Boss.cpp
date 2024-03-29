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
}
