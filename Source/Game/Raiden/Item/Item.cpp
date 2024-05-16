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
		// �ͦ� 0 �� RAND_MAX �������H�����
		int rand_num = rand();

		// �N�H������ഫ���B�I�ơA�ìM�g�� 0 �� 2*pi ���������׽d��
		double angle = static_cast<double>(rand_num) / RAND_MAX * 2 * M_PI;

		// �p�⨤�׹����� x �M y ��V�W�������q
		double del_x = cos(angle) * 5; // �N���׬M�g�� x ��V�W�������q
		double del_y = sin(angle) * 5; // �N���׬M�g�� y ��V�W�������q

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
