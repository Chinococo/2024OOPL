#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"

namespace Raiden
{
	class Enemy
	{
	public:
		Enemy(int health);
		virtual ~Enemy() = default;
		virtual void Init() = 0;
		virtual void Update(const Player &player) = 0;
		void Show();

	protected:
		game_framework::CMovingBitmap sprite;
		int health = 10;
	};
}
