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
	 *   - Bullet：No Parmamter。
	 * Destructor：
	 *   - ~Bullet:Free collisionBox;
	*/
	class Bullet :game_framework::CMovingBitmap
	{
		public:
			Bullet();
			~Bullet();
			void Init();
			void Update();
			void Show();

		private:
			CollisionBox* collisionBox;
	};

}