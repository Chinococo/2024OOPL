#pragma once
#include "../Enemy/Enemy.h"
#include "../Player/Player.h"

namespace Raiden
{
	class Fighter : public Enemy
	{
	public:
		Fighter(int health);
		void Init() override;
		void Update(const Player &player) override;
	};
}
