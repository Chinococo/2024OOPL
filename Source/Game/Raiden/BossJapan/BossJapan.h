#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossJapan : public Boss
	{
	public:
		BossJapan(int health);
		void Init() override;
		void Update(const Player &player, bool start_attack) override;
	};
}
