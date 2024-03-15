#pragma once
#include "../../../Library/gameutil.h"
#include "../CollisionBox/CollisionBox.h"

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
		void Init(int left, int top);
		void Update(int delta_x, int delta_y);
		void Show();
		void Destroy();
		const CollisionBox &GetCollisionBox();
		bool IsCollisionBoxOverlap(const Bullet &);
		bool IsAlive();

	private:
		bool alive = true;
		game_framework::CMovingBitmap sprite;
		CollisionBox collision_box;
	};
}
