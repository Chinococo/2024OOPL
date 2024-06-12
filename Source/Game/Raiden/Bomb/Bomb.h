#pragma once

#include "../Collidable/Collidable.h"
namespace Raiden
{
	class Bomb : public Collidable {
	public:
		void Init();
		bool Start();
		void update();
		void Show();
	private:
		game_framework::CMovingBitmap sprite;
		bool complte = true;
	};
}
