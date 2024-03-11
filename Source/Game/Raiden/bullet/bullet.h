#pragma once
#include "../../../Library/gameutil.h"
#include "../CollisionBox/CollisionBox.h"
namespace Raiden {
	class Bullet :game_framework::CMovingBitmap
	{
		public:
			Bullet();
			void Init();
			void Update();
			void Show();
		private:
			CollisionBox* collisionBox;
	};

}