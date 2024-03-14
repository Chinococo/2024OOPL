#include <StdAfx.h>
#include "StatusPanel.h"
#include "../Player/Player.h"
#include <string>

namespace Raiden
{
	void StatusPanel::Init()
	{
		// TODO: fix the position of the counters and the sprite image.
		lifeCounter.LoadBitmapByString({ "Resources/TestSprite/TestSpriteBlue.bmp" });
		lifeCounter.SetTopLeft(0, 0);
		bombCounter.LoadBitmapByString({ "Resources/TestSprite/TestSpriteBlue.bmp" });
		bombCounter.SetTopLeft(0, 0);
	}

	void StatusPanel::Update(const Player &player)
	{
		// TODO: fix the position of the counters and the sprite image.
		scoreCounter.Write(0, 0, "SCORE: " + std::to_string(player.GetScore()) + " HIGH SCORE: " + std::to_string(player.GetHighScore()));
		// lifeCounter.SetFrameIndexOfBitmap(player.GetLifeCount());
		// bombCounter.SetFrameIndexOfBitmap(player.GetBombCount());
	}

	void StatusPanel::Show()
	{
		lifeCounter.ShowBitmap();
		bombCounter.ShowBitmap();
	}
}
