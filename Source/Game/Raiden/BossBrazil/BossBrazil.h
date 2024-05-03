#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossBrazil : public Boss
	{
	public:
		BossBrazil(int health) : Boss(health) {};
		void Attack(const Player &player) override;
	};
}
