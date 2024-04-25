#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossJapan : public Boss
	{
	public:
		BossJapan(int health) : Boss(health) {};
		void Init(BossData boss_data) override;
		void Update(const Player &player) override;
	};
}
