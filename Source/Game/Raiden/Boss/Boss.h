#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"

namespace Raiden
{
	class Boss
	{
	public:
		Boss(int health);
		virtual ~Boss() = default;
		virtual void Init() = 0;
		virtual void Update(const Player &player, bool start_attack) = 0;
		void Show();
		bool Dead() const;

	protected:
		game_framework::CMovingBitmap sprite;
		int health = 1000;
	};
}
