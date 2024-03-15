#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossUSA : public Boss
	{
	public:
		BossUSA(int health);
		void Init() override;
		void Update(const Player &player) override;
	};
}
