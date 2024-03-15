#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"
#include "../TextGraphics/TextGraphics.h"

namespace Raiden
{
	class StatusPanel
	{
	public:
		void Init();
		void Update(const Player &player);
		void Show();

	private:
		TextGraphics scoreCounter;
		game_framework::CMovingBitmap lifeCounter;
		game_framework::CMovingBitmap bombCounter;
	};
}
