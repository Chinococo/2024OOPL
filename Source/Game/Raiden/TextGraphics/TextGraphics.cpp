#include "stdafx.h"
#include "TextGraphics.h"
#include <ddraw.h>
#include "../../../Library/gameutil.h"
#include "../../../Library/gamecore.h"

namespace Raiden
{
	std::size_t TextGraphics::Register(int left, int top, std::string text)
	{
		points.push_back({ left, top });
		texts.push_back(text);
		return points.size() - 1;
	}

	void TextGraphics::UpdateText(std::size_t id, std::string text)
	{
		if (id < 0 || id >= points.size())
			return;

		texts[id] = text;
	}

	void TextGraphics::Show() const
	{
		CDC *p_dc = game_framework::CDDraw::GetBackCDC();
		game_framework::CTextDraw::ChangeFontLog(p_dc, 30, "Times New Roman", RGB(255, 255, 255));

		for (std::size_t i = 0; i < points.size(); i++)
			game_framework::CTextDraw::Print(p_dc, points[i].x, points[i].y, texts[i]);

		game_framework::CDDraw::ReleaseBackCDC();
	}
}
