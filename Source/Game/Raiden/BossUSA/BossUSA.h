#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossUSA : public Boss
	{
	public:
		BossUSA(int health) : Boss(health) {};
		void Init(BossData boss_data) override;
		void Attack(const Player &player) override;
	};
}
