#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossJapan : public Boss
	{
	public:
		BossJapan(int health) : Boss(health) {};
		void Attack(const Player &player) override;
	};
}
