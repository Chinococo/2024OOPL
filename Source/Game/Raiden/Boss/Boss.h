#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"
#include "../Data/BossData.h"

namespace Raiden
{
	class Boss
	{
	public:
		virtual ~Boss() = default;
		virtual void Init(BossData boss_data) = 0;
		virtual void Update(const Player &player) = 0;
		Boss(int);
		void Show();
		bool Dead() const;
	protected:
		game_framework::CMovingBitmap sprite;
		int health = 1000;
	};
}
