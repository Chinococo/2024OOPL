﻿#pragma once
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
	enum bullet_type{ straight_bullet,simple_track_bullet,track_bullet};
	class Bullet
	{
	public:
		void Init(bool friendly);
		void SetTopLeft(CPoint &&point);
		void ApplyForce(CPoint &&force);
		void Update();
		void Show();
		CollisionBox &GetCollisionBox();
		bool IsCollisionBoxOverlap(CollisionBox& other);
		void Destroy();
		bool IsAlive();
		bool IsFriendly();
	private:
		bool alive = true;
		game_framework::CMovingBitmap sprite;
		CollisionBox collisionBox;
		int delta_left = 0;
		int delta_top = 0;
		bool friendly;
	};
}
