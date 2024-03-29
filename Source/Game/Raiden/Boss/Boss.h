#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"

namespace Raiden
{
	class Boss
	{
	public:
		virtual ~Boss() = default;
		virtual void Init() = 0;
		virtual void Update(const Player &player, bool start_attack) = 0;
		Boss(int);
		void Show();
		bool Dead() const;
	protected:
		game_framework::CMovingBitmap sprite;
		int health = 1000;
	};
}
