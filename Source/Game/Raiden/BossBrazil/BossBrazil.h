#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossBrazil : public Boss
	{
	public:
		BossBrazil(int health) : Boss(health) {};
		void Init(BossData boss_data) override;
		void Attack(const Player &player) override;
	};
}
