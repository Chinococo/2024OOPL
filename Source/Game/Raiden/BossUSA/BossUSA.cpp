#include <StdAfx.h>
#include "BossUSA.h"

namespace Raiden
{
	BossUSA::BossUSA(int health) : Boss(health) {}

	void BossUSA::Init()
	{
		// TODO
		sprite.LoadBitmapByString({ "TODO" });
		sprite.SetTopLeft(0, 0);
	}
}
