#pragma once
#include <StdAfx.h>
#include "TextGraphics.h"
#include <string>
#include <ddraw.h>
#include "../../../Library/gameutil.h"
#include "../../../Library/gamecore.h"
namespace Raiden
{
	void TextGraphics::Write(int left, int top, std::string text)
	{
		CDC *p_dc = game_framework::CDDraw::GetBackCDC();
		game_framework::CTextDraw::ChangeFontLog(p_dc, 30, "Times New Roman", RGB(255, 255, 255));
		game_framework::CTextDraw::Print(p_dc, left, top, text);
		game_framework::CDDraw::ReleaseBackCDC();
	}
}
