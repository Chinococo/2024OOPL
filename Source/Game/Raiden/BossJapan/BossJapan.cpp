#include <StdAfx.h>
#include "BossJapan.h"

namespace Raiden
{
	BossJapan::BossJapan(int health) : Boss(health) {}
	
	void BossJapan::Init()
	{
		// TODO
		sprite.LoadBitmapByString({ "TODO" });
		sprite.SetTopLeft(0, 0);
	}
}
