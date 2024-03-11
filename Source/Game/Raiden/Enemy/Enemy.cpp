#include <StdAfx.h>
#include "Enemy.h"

namespace Raiden
{
	Enemy::Enemy(int health) : health(health) {}

	void Enemy::Show()
	{
		sprite.ShowBitmap();
	}
}
