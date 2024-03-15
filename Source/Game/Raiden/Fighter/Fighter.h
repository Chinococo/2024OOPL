#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"
#include "../Collidable/Collidable.h"

namespace Raiden
{
	class Fighter : public Collidable
	{
	public:
		void Init(int left, int top);
		void Update(const Player &player);
		void Show();
		void Destroy();
		bool IsAlive() const;

	private:
		game_framework::CMovingBitmap sprite;
		int health = 10;
		bool alive = true;
	};
}
