#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossBrazil : public Boss
	{
	public:
		void Init() override;
		void Update(const Player &player, bool start_attack) override;
	};
}
