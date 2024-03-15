#include <StdAfx.h>
#include "Fighter.h"
#include "../Player/Player.h"

namespace Raiden
{
	void Fighter::Init(int left, int top)
	{
		// TODO: write the position and the sprite image.
		sprite.LoadBitmapByString({ "Resources/TestSprite/TestSpriteRed.bmp" });
		sprite.SetTopLeft(left, top);
		alive = true;
	}

	void Fighter::Update(const Player &player)
	{
		// TODO: write the position and the sprite image.
	}

	void Fighter::Show()
	{
		sprite.ShowBitmap();
	}

	void Fighter::Destroy()
	{
		alive = false;
	}

	bool Fighter::IsAlive() const
	{
		return alive;
	}
}
