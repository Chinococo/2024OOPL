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
	enum bullet_type{ straight_bullet,track_bullet};
	
	class Bullet
	{
	public:
		void Init(bool friendly);
		void Init(bool friendly,int type);
		void SetTopLeft(CPoint &&point);
		void ApplyForce(CPoint &&force);
		void Update();
		void Update(CPoint &&player_pos,vector<CPoint>& enemy);
		void UpdatePlayerBullet(vector<CPoint>& enemy);
		void UpdateFighterBullet(CPoint &player_pos);
		void Show(bool debug);
		CollisionBox &GetCollisionBox();
		bool IsCollisionBoxOverlap(CollisionBox& other);
		void Destroy();
		bool IsAlive();
		bool IsFriendly();
		int GetLeft();
		int GetTop();

	private:
		bool alive = true;
		game_framework::CMovingBitmap sprite;
		CollisionBox collisionBox;
		int delta_left = 0;
		int delta_top = 0;
		bool friendly;
		int type=0;
		int bullet_speed;
		time_t last_track_time = clock();
	};
}
