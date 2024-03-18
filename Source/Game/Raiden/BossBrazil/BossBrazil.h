#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossBrazil : public Boss
	{
	public:
		BossBrazil(int health);
		void Init() override;
		void Update(const Player &player) override;
	};
}
