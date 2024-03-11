#include "stdafx.h"
#include "CollisionBox.h"
#include <windows.h>
#include <gdiplus.h>
#include <iostream>
#include <atlimage.h>
#include "CollisionBox.h"
#include <string>
#pragma comment (lib,"Gdiplus.lib")
namespace Raiden{
		std::pair<int, int> addPairs(const std::pair<int, int>& pair1, const std::pair<int, int>& pair2) {
			int sum_first = pair1.first + pair2.first;
			int sum_second = pair1.second + pair2.second;
			return std::make_pair(sum_first, sum_second);
		}
		void CollisionBox::Init(vector<tuple<int, int,int,int>> boxCollisionBox) {
			this->_boxCollisionBox = boxCollisionBox;
			string path = "Resources/CollisionBox/";
			// To Get Largest Width and Height to Set Panel Size
			for (auto item : _boxCollisionBox) {
				// Make path string to save image
				path += to_string(abs(get<0>(item)- get<2>(item))) + "x" + to_string(abs(get<1>(item) - get<3>(item))) + "+";
				width = max(width, max(get<0>(item), get<2>(item)));
				height = max(height, max(get<1>(item), get<3>(item)));
			}
			path[path.size() - 1] = '.';
			path += "bmp";
			FILE* file = fopen(path.c_str(), "r");
			//Check file exitst
			if (file == NULL) { // Check if the file does not exist
				HDC hdc = GetDC(NULL);
				HBITMAP hBmp = CreateCollisionBoxBitMap(hdc, 3); // Create a bitmap compatible with the device context
				if (hBmp != NULL) {
					CImage image;
					image.Attach(hBmp);
					CString str = path.c_str();
					HRESULT result = image.Save(str); // Save the image to file
					image.Detach();
					DeleteObject(hBmp); // Clean up bitmap object
				}
				ReleaseDC(NULL, hdc);
			}
			else {
				fclose(file);
			}
			_display.LoadBitmapByString({ path },RGB(255,255,255));
		}
		CollisionBox::CollisionBox()
		{
		}
		void CollisionBox::Update(int top, int left)
		{
			_display.SetTopLeft(top, left);
		}
		void CollisionBox::Show()
		{
			_display.ShowBitmap();
		}
		HBITMAP CollisionBox::CreateCollisionBoxBitMap(HDC hdc, int borderWidth) {
			HBITMAP hBmp = CreateCompatibleBitmap(hdc, width, height);
			HDC hMemDC = CreateCompatibleDC(hdc);
			SelectObject(hMemDC, hBmp);
			SetBkColor(hMemDC, TRANSPARENT);
			// Fill the entire bitmap with a transparent color
			RECT rc = { 0, 0, width, height };
			HBRUSH hbTransparent = ::CreateSolidBrush(RGB(255, 255, 255)); // White color for transparency
			FillRect(hMemDC, &rc, hbTransparent);
			DeleteObject(hbTransparent);
			// Create by boxCollisionBox item 
			for (auto box : _boxCollisionBox) {
				// Draw the border
				HBRUSH hbBorder = ::CreateSolidBrush(RGB(0, 255, 0)); // Green color for border
				// Draw the top border
				RECT rcTop = {get<0>(box),get<1>(box),get<2>(box),get<1>(box)+borderWidth};
				FillRect(hMemDC, &rcTop, hbBorder);
				// Draw the bottom border
				RECT rcBottom = { get<0>(box),get<3>(box) - borderWidth, get<2>(box),get<3>(box)};
				FillRect(hMemDC, &rcBottom, hbBorder);
				// Draw the left border
				RECT rcLeft = { get<0>(box),get<1>(box), get<0>(box)+borderWidth, get<3>(box)};
				FillRect(hMemDC, &rcLeft, hbBorder);
				// Draw the right border
				RECT rcRight = { get<2>(box) - borderWidth, get<1>(box),get<2>(box), get<3>(box) };
				FillRect(hMemDC, &rcRight, hbBorder);
				DeleteObject(hbBorder);
			}
			DeleteDC(hMemDC);
			return hBmp;
		}
		bool CollisionBox::IsCollisionBoxOverlap(CollisionBox& othres) {
			pair<int,int> thisTopLeft = this->GetTopLeft();
			pair<int, int> otherTopLeft = othres.GetTopLeft();
			vector<tuple<int, int, int, int>>  othersCollisionBox = othres.GetBoxCollisionBox();
			
			pair<int, int> TopLeft;
			pair<int, int> RightBottom;
			pair<int, int> thisBoxTopLeft, thisBoxRightBottom, otherBoxTopLeft, otherBoxRightBottom;
			for(size_t i=0;i<_boxCollisionBox.size();i++)
				for (size_t j = 0; j < othersCollisionBox.size(); j++) {
					// 自己的其中一個碰撞箱
					TopLeft = { get<0>(_boxCollisionBox[i]), get<1>(_boxCollisionBox[i]) };
					thisBoxTopLeft = addPairs( thisTopLeft, TopLeft);
					RightBottom = { get<2>(_boxCollisionBox[i]), get<3>(_boxCollisionBox[i]) };
					thisBoxRightBottom = addPairs(thisTopLeft, RightBottom);

					// 別人的其中一個碰撞箱
					TopLeft = { get<0>(othersCollisionBox[j]), get<1>(othersCollisionBox[j]) };
					otherBoxTopLeft = addPairs(otherTopLeft, TopLeft);
					RightBottom = { get<2>(othersCollisionBox[j]), get<3>(othersCollisionBox[j]) };
					otherBoxRightBottom = addPairs(otherTopLeft, RightBottom);

					if (thisBoxTopLeft.first > otherBoxRightBottom.first || otherBoxTopLeft.first > thisBoxRightBottom.first)
						continue;
					if (thisBoxTopLeft.second > otherBoxRightBottom.second || otherBoxTopLeft.second > thisBoxRightBottom.second)
						continue;
					return true; 
				}
			return false;
		}
		pair<int, int>  CollisionBox::GetTopLeft() {
			return { this->_display.GetLeft() , this->_display.GetTop() };
		}
		vector<tuple<int, int, int, int>>  CollisionBox::GetBoxCollisionBox() {
			return this->_boxCollisionBox;
		}
		
}