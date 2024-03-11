#include <StdAfx.h>
#include "BossBrazil.h"

namespace Raiden
{
	BossBrazil::BossBrazil(int health) : Boss(health) {}

	void BossBrazil::Init()
	{
		// TODO
		sprite.LoadBitmapByString({ "TODO" });
		sprite.SetTopLeft(0, 0);
	}
}
