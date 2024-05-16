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
		InitCollisionBox(sprite.GetWidth(), sprite.GetHeight());
		// 生成 0 到 RAND_MAX 之間的隨機整數
		int rand_num = rand();

		// 將隨機整數轉換成浮點數，並映射到 0 到 2*pi 之間的角度範圍內
		double angle = static_cast<double>(rand_num) / RAND_MAX * 2 * M_PI;

		// 計算角度對應的 x 和 y 方向上的偏移量
		double del_x = cos(angle) * 5; // 將角度映射到 x 方向上的偏移量
		double del_y = sin(angle) * 5; // 將角度映射到 y 方向上的偏移量

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
