#pragma once
#include "../../../Library/gameutil.h"
#include "../CollisionBox/CollisionBox.h"
namespace Raiden {
	/*
	 * Class Name：Bullet
	 * Class Purpose：Display bullet
	 * Member Variables：
	 *   - CollisionBox* collisionBox; Show collisionBox of this object
	 * Member Functions
	 *   - Bullet ：Constructors Function
	 *   - Init    ：Initial all setting and LoadBitMap
	 *   - Update  : Update position of this object
	 *   - Show   ：Display Object
	 * Constructors：
	 *   - Bullet： Top and Left
	 * Destructor：
	 *   - ~Bullet:Free collisionBox;
	*/
	class Bullet :game_framework::CMovingBitmap
	{
		public:
			Bullet();
			void Init(int,int);
			void Update(int deltaX, int deltaY);
			void Show();
			CollisionBox& GetCollisionBox();
			bool IsCollisionBoxOverlap(Bullet&);
		private:
			CollisionBox collisionBox;
	};

}