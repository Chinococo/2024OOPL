#pragma once
#include "Item.h"
#include "../Collidable/Collidable.h"
namespace Raiden
{
	class Item : public Collidable {
	public:
		void Init(CPoint& now);
		void Update();
		void Show();
	private:
		game_framework::CMovingBitmap sprite;
		int del_x;
		int del_y;
	};
}
