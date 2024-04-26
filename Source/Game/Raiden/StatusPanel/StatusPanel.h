#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"
#include "../TextGraphics/TextGraphics.h"

namespace Raiden
{
	class StatusPanel
	{
	public:
		void Init(TextGraphics &text_graphics);
		void Update(const Player &player, TextGraphics &text_graphics);
		void Show();

	private:
		int score_counter_id;
		int life_score_id; // temporary
		game_framework::CMovingBitmap life_counter;
		game_framework::CMovingBitmap bomb_counter;
	};
}
