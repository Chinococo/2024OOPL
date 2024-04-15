#include "stdafx.h"
#include "StatusPanel.h"
#include "../Player/Player.h"
#include "../../config.h"
#include <string>

namespace Raiden
{
	void StatusPanel::Init(TextGraphics &text_graphics)
	{
		// TODO: fix the position of the counters and the sprite image.
		score_counter_id = text_graphics.Register({ 0, 0 }, "SCORE: 0    HIGH SCORE: 0 Life Count: 0");
		life_counter.LoadBitmapByString({ "Resources/TestSprite/TestSpriteBlue.bmp" });
		life_counter.SetTopLeft(0, 0);
		bomb_counter.LoadBitmapByString({ "Resources/TestSprite/TestSpriteBlue.bmp" });
		bomb_counter.SetTopLeft(0, 0);
	}

	void StatusPanel::Update(const Player &player, TextGraphics &text_graphics)
	{
		// TODO: fix the position of the counters and the sprite image.
		std::string text = "SCORE: " + std::to_string(player.GetScore()) + "    HIGH SCORE: " + std::to_string(player.GetHighScore()) + " Life Count: " + std::to_string(player.GetLifeCount());
		text_graphics.UpdateText(score_counter_id, text);
		// lifeCounter.SetFrameIndexOfBitmap(player.GetLifeCount());
		// bombCounter.SetFrameIndexOfBitmap(player.GetBombCount());
	}

	void StatusPanel::Show()
	{
		life_counter.ShowBitmap();
		bomb_counter.ShowBitmap();
	}
}
