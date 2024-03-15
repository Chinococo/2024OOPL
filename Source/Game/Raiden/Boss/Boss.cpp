#include <StdAfx.h>
#include "Boss.h"
#include "../Player/Player.h"

namespace Raiden
{
	Boss::Boss(int health) : health(health) {}

	void Boss::Show()
	{
		sprite.ShowBitmap();
	}

	bool Boss::Dead() const
	{
		return health == 0;
	}
}
