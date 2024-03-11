#pragma once
#include "../../../Library/gameutil.h"
namespace Raiden {
	/*
	 * Class Name¡GCollisionBox
	 * Class Purpose¡GDisplay CollisionBox and Create CollisionBox image
	 * Member Variables¡G
	 * game_framework::CMovingBitmap _display;
	 *	 - vector<tuple<int, int, int, int>> _boxCollisionBox;  CollisionBox vector of box,
			first and second data in tuple  is  TopLeft of  CollisionBox 
	 * 	 - int width;  CollisionBox image Width
	 * 	 - int height;  CollisionBox image Height
	 * Member Functions
	 *   - CollisionBox ¡GConstructors Function
	 *   - Update  : Update position of this object
	 *   - Show   ¡GDisplay Object
	 * Constructors¡G
	 *   - Bullet¡GNeed vector<tuple<int, int, int, int>> to create CollisionBox image
	 * Destructor¡G
	 *  None
	*/
	class CollisionBox{
		public:
			CollisionBox();
			void Init(vector<tuple<int, int, int, int>>);
			void Update(int, int);
			void Show();
			void SetTopLeft(int, int);
			bool IsCollisionBoxOverlap(CollisionBox&);
			pair<int, int> GetTopLeft();
			vector<tuple<int, int, int, int>> GetBoxCollisionBox();
		private:
			HBITMAP CreateCollisionBoxBitmap(HDC, int);
			game_framework::CMovingBitmap display;
			vector<tuple<int, int, int, int>> box_collision_box;
			int width = 0;
			int height = 0;
		};
}