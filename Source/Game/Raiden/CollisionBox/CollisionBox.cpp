#include "stdafx.h"
#include "CollisionBox.h"
#include <windows.h>
#include <gdiplus.h>
#include <iostream>
#include <atlimage.h>
#include "CollisionBox.h"
#include <string>
#pragma comment (lib,"Gdiplus.lib")

namespace Raiden
{
	std::pair<int, int> AddPairs(const std::pair<int, int> &pair1, const std::pair<int, int> &pair2)
	{
		int sum_first = pair1.first + pair2.first;
		int sum_second = pair1.second + pair2.second;
		return std::make_pair(sum_first, sum_second);
	}

	void CollisionBox::Init(std::vector<std::tuple<int, int, int, int>> box_collision_box)
	{
		this->box_collision_box = box_collision_box;
		std::string path = "Resources/CollisionBox/";

		// To Get Largest Width and Height to Set Panel Size
		for (const auto &item : box_collision_box) {
			// Make path string to save image
			path += to_string(abs(get<0>(item) - get<2>(item))) + "x" + to_string(abs(get<1>(item) - get<3>(item))) + "+";
			width = max(width, max(get<0>(item), get<2>(item)));
			height = max(height, max(get<1>(item), get<3>(item)));
		}

		path[path.size() - 1] = '.';
		path += "bmp";

		FILE *file = fopen(path.c_str(), "r");

		//Check file exitst
		if (file == NULL) // Check if the file does not exist
		{
			HDC hdc = GetDC(NULL);
			HBITMAP h_bmp = CreateCollisionBoxBitmap(hdc, 3); // Create a bitmap compatible with the device context

			if (h_bmp != NULL)
			{
				CImage image;
				image.Attach(h_bmp);

				CString str = path.c_str();

				// Save the image to file
				HRESULT result = image.Save(str);
				image.Detach();

				// Clean up bitmap object
				DeleteObject(h_bmp);
			}

			ReleaseDC(NULL, hdc);
		}
		else
		{
			fclose(file);
		}

		display.LoadBitmapByString({ path }, RGB(255, 255, 255));
	}

	void CollisionBox::Show()
	{
		display.ShowBitmap();
	}

	void CollisionBox::SetTopLeft(int left, int top)
	{
		display.SetTopLeft(left, top);
	}

	HBITMAP CollisionBox::CreateCollisionBoxBitmap(HDC hdc, int border_width)
	{
		HBITMAP h_bmp = CreateCompatibleBitmap(hdc, width, height);
		HDC h_mem_dc = CreateCompatibleDC(hdc);
		SelectObject(h_mem_dc, h_bmp);
		SetBkColor(h_mem_dc, TRANSPARENT);

		// Fill the entire bitmap with a transparent color
		RECT rc = { 0, 0, width, height };

		// White color for transparency
		HBRUSH hb_transparent = ::CreateSolidBrush(RGB(255, 255, 255));
		FillRect(h_mem_dc, &rc, hb_transparent);
		DeleteObject(hb_transparent);

		// Create by boxCollisionBox item 
		for (const auto &box : box_collision_box)
		{
			// Draw the border
			HBRUSH hb_border = ::CreateSolidBrush(RGB(0, 255, 0)); // Green color for border

			// Draw the top border
			RECT rc_top = { get<0>(box),get<1>(box),get<2>(box),get<1>(box) + border_width };
			FillRect(h_mem_dc, &rc_top, hb_border);

			// Draw the bottom border
			RECT rc_bottom = { get<0>(box),get<3>(box) - border_width, get<2>(box),get<3>(box) };
			FillRect(h_mem_dc, &rc_bottom, hb_border);

			// Draw the left border
			RECT rc_left = { get<0>(box),get<1>(box), get<0>(box) + border_width, get<3>(box) };
			FillRect(h_mem_dc, &rc_left, hb_border);

			// Draw the right border
			RECT rc_right = { get<2>(box) - border_width, get<1>(box),get<2>(box), get<3>(box) };
			FillRect(h_mem_dc, &rc_right, hb_border);
			DeleteObject(hb_border);
		}

		DeleteDC(h_mem_dc);
		return h_bmp;
	}

	bool CollisionBox::IsCollisionBoxOverlap(CollisionBox &othres)
	{
		std::pair<int, int> this_top_left = GetTopLeft();
		std::pair<int, int> other_top_left = othres.GetTopLeft();
		std::vector<std::tuple<int, int, int, int>>  others_collision_box = othres.GetBoxCollisionBox();

		std::pair<int, int> top_left;
		std::pair<int, int> right_bottom;
		std::pair<int, int> this_box_top_left, this_box_right_bottom, other_box_top_left, other_box_right_bottom;

		for (std::size_t i = 0; i < box_collision_box.size(); i++)
		{
			for (std::size_t j = 0; j < others_collision_box.size(); j++)
			{
				// 自己的其中一個碰撞箱
				top_left = { get<0>(box_collision_box[i]), get<1>(box_collision_box[i]) };
				this_box_top_left = AddPairs(this_top_left, top_left);
				right_bottom = { get<2>(box_collision_box[i]), get<3>(box_collision_box[i]) };
				this_box_right_bottom = AddPairs(this_top_left, right_bottom);

				// 別人的其中一個碰撞箱
				top_left = { get<0>(others_collision_box[j]), get<1>(others_collision_box[j]) };
				other_box_top_left = AddPairs(other_top_left, top_left);
				right_bottom = { get<2>(others_collision_box[j]), get<3>(others_collision_box[j]) };
				other_box_right_bottom = AddPairs(other_top_left, right_bottom);

				if (this_box_top_left.first > other_box_right_bottom.first || other_box_top_left.first > this_box_right_bottom.first)
					continue;

				if (this_box_top_left.second > other_box_right_bottom.second || other_box_top_left.second > this_box_right_bottom.second)
					continue;

				return true;
			}
		}

		return false;
	}

	std::pair<int, int> CollisionBox::GetTopLeft()
	{
		return { display.GetLeft(), display.GetTop() };
	}

	std::vector<std::tuple<int, int, int, int>> CollisionBox::GetBoxCollisionBox()
	{
		return box_collision_box;
	}
}