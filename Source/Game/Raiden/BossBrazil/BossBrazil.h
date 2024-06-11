#pragma once
#include "../Boss/Boss.h"

namespace Raiden
{
	class BossBrazil : public Boss
	{
	public:
		void Attack(const Player &player) override;

	};
}
