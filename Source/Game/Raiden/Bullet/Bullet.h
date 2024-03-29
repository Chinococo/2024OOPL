#pragma once
#include "../../../Library/gameutil.h"
#include "../CollisionBox/CollisionBox.h"
#include <atltypes.h>

namespace Raiden
{
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
	class Bullet
	{
	public:
		void Init();
		void SetTopLeft(CPoint &&point);
		void ApplyForce(CPoint &&force);
		void Update();
		void Show();
		CollisionBox &GetCollisionBox();
		bool IsCollisionBoxOverlap(Bullet &);
		void Destroy();
		bool IsAlive();

	private:
		bool alive = true;
		game_framework::CMovingBitmap sprite;
		CollisionBox collisionBox;
		int delta_left = 0;
		int delta_top = 0;
	};
}
