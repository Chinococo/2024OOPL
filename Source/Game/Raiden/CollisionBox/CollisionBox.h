#pragma once
#include "../../../Library/gameutil.h"

namespace Raiden
{
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
	class CollisionBox
	{
	public:
		CollisionBox();
		void Init(std::vector<std::tuple<int, int, int, int>>);
		void Show();
		void SetTopLeft(int, int);
		bool IsCollisionBoxOverlap(CollisionBox &);
		std::pair<int, int> GetTopLeft();
		std::vector<std::tuple<int, int, int, int>> GetBoxCollisionBox();

	private:
    void CreateCollisionBoxBitmap(int,std::string);
		HBITMAP CreateCollisionBoxBitmap(HDC, int);
		game_framework::CMovingBitmap display;
		std::vector<std::tuple<int, int, int, int>> box_collision_box;
    void CollisionBox::SaveBitmapToFile(HBITMAP , const std::string&);
		void CollisionBox::DrawBorder(HDC, RECT, int, COLORREF);
		int width = 0;
		int height = 0;
	};
}