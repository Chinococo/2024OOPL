#include "stdafx.h"
#include "CollisionBox.h"
#include <windows.h>
#include <gdiplus.h>
#include <iostream>
#include <atlimage.h>
#include "CollisionBox.h"
#pragma comment (lib,"Gdiplus.lib")
namespace Raiden{
		CollisionBox::CollisionBox() {
			HDC hdc = GetDC(NULL);
			HBITMAP hBmp = CreateNewBitMap(hdc, 100, 200,3);
			//HDC hMemDC = CreateCompatibleDC(hdc);
			//SelectObject(hMemDC, hBmp);
			//BitBlt(hdc, 0, 0, 100, 200, hMemDC, 0, 0, SRCCOPY);
			CImage image;
			image.Attach(hBmp);
			CString str = L"test.bmp";
			image.Save(str);
			image.Detach();
		}
		HBITMAP CollisionBox::CreateNewBitMap(HDC hdc, int iWidth, int iHeight, int borderWidth) {
			HBITMAP hBmp = CreateCompatibleBitmap(hdc, iWidth, iHeight);
			HDC hMemDC = CreateCompatibleDC(hdc);
			SelectObject(hMemDC, hBmp);
			SetBkColor(hMemDC, TRANSPARENT);

			// Fill the entire bitmap with a transparent color
			RECT rc = { 0, 0, iWidth, iHeight };
			HBRUSH hbTransparent = ::CreateSolidBrush(RGB(255, 255, 255)); // White color for transparency
			FillRect(hMemDC, &rc, hbTransparent);
			DeleteObject(hbTransparent);

			// Draw the border
			HBRUSH hbBorder = ::CreateSolidBrush(RGB(0, 255, 0)); // Green color for border
			// Draw the top border
			RECT rcTop = { borderWidth, 0, iWidth - borderWidth, borderWidth };
			FillRect(hMemDC, &rcTop, hbBorder);
			// Draw the bottom border
			RECT rcBottom = { borderWidth, iHeight - borderWidth, iWidth - borderWidth, iHeight };
			FillRect(hMemDC, &rcBottom, hbBorder);
			// Draw the left border
			RECT rcLeft = { 0, borderWidth, borderWidth, iHeight - borderWidth };
			FillRect(hMemDC, &rcLeft, hbBorder);
			// Draw the right border
			RECT rcRight = { iWidth - borderWidth, borderWidth, iWidth, iHeight - borderWidth };
			FillRect(hMemDC, &rcRight, hbBorder);
			DeleteObject(hbBorder);

			DeleteDC(hMemDC);
			return hBmp;
		}

}