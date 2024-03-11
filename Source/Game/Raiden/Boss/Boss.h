#pragma once
#include "../Enemy/Enemy.h"
#include "../Player/Player.h"

namespace Raiden
{
	class Boss : public Enemy
	{
	public:
		Boss(int health);
		virtual ~Boss() = default;
		void Update(const Player &player) override;
		bool Dead() const;
	};
}
