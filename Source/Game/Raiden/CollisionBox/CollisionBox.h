#pragma once
#include "../../../Library/gameutil.h"
namespace Raiden {
	class CollisionBox{
	public:
		CollisionBox(vector<tuple<int, int, int, int>>);
	private:
		HBITMAP CreateNewBitMap(HDC, int);
		game_framework::CMovingBitmap _display;
		vector<tuple<int, int, int, int>> _boxCollisionBox;
		int width = 0;
		int height = 0;
	};
}