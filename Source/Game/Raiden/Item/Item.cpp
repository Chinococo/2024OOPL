#pragma once
#include "stdafx.h"
#include "Item.h"
#include "../Collidable/Collidable.h"
#include "../../config.h"
#include <cmath>
#include <cstdlib>
#define M_PI 3.1415926
namespace Raiden
{
	void Item::Init(CPoint& now)
	{
		this->sprite.LoadBitmapByString({ "Resources/Item/0.bmp" },RGB(0,0,0));
		this->sprite.SetTopLeft(now.x, now.y);
		InitCollisionBox(sprite.GetWidth(), sprite.GetHeight());
		int rand_num = rand();
		double random_fraction = static_cast<double>(rand_num) / RAND_MAX;

		// 將 0 到 1 之間的隨機數映射到 30 度到 150 度（即 π/6 到 5π/6 弧度）之間
		double angle = (random_fraction * (5.0 / 6.0 * M_PI - M_PI / 6.0)) + M_PI / 6.0;

		del_x = static_cast<int>(cos(angle) * 5);
		del_y = static_cast<int>(sin(angle) * 5);

	}
	void Item::Update()
	{
		sprite.SetTopLeft(sprite.GetLeft()+ del_x, sprite.GetTop()+ del_y);
		UpdateCollisionBox(sprite.GetLeft(), sprite.GetTop());
	}
	void Item::Show()
	{
		this->sprite.ShowBitmap();
	}
}
