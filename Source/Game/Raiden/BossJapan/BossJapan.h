#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossJapan : public Boss
	{
	public:
		void Attack(const Player &player) override;
	};
}
