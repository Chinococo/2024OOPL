#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossUSA : public Boss
	{
	public:
		void Attack(const Player &player) override;
		void LoadTurretGroup() override;
	};
}
