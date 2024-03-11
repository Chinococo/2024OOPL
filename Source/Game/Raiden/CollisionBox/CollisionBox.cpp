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
		CollisionBox::CollisionBox(vector<tuple<int, int,int,int>> boxCollisionBox) {
			this->_boxCollisionBox = boxCollisionBox;
			string path = "Resources/CollisionBox/";
			for (auto item : _boxCollisionBox) {
				path += to_string(abs(get<0>(item)- get<2>(item))) + "x" + to_string(abs(get<1>(item) - get<3>(item))) + "+";
				width = max(width, max(get<0>(item), get<2>(item)));
				height = max(height, max(get<1>(item), get<3>(item)));
			}
			path[path.size() - 1] = '.';
			path += "bmp";
			FILE* file = fopen(path.c_str(), "r");
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


}