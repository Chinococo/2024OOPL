#include "stdafx.h"
#include "Background.h"
#include "../../config.h"
#include <ctime>
#include <vector>
#include <string>
#include <exception>
#include <string>

namespace Raiden
{
	Background::Background() : SCROLL_STEP(3), SCROLL_INTERVAL_MILLI(33) {}

	void Background::Init(std::vector<std::string> &&paths)
	{
		part1.LoadBitmapByString({ paths[0] });
		part2.LoadBitmapByString({ paths[1] });
		part1.SetTopLeft(BACKGROUND_MARGIN, SIZE_Y - part1.GetHeight());
		part2.SetTopLeft(BACKGROUND_MARGIN, part1.GetTop() - part2.GetHeight());
		this->paths = std::move(paths);
	}

	void Background::Update()
	{
		if (Over())
			return;

		if (static_cast<double>(std::clock() - scroll_clock) / CLOCKS_PER_SEC < static_cast<double>(SCROLL_INTERVAL_MILLI) / 1000)
			return;
    
		scroll_clock = std::clock();

		if (part1.GetTop() >= SIZE_Y)
			part1.SetTopLeft(BACKGROUND_MARGIN, part2.GetTop() - part1.GetHeight());

		if (part2.GetTop() >= SIZE_Y)
			part2.SetTopLeft(BACKGROUND_MARGIN, part1.GetTop() - part2.GetHeight());

		part1.SetTopLeft(BACKGROUND_MARGIN, part1.GetTop() + SCROLL_STEP);
		part2.SetTopLeft(BACKGROUND_MARGIN, part2.GetTop() + SCROLL_STEP);
	}

	void Background::Show()
	{
		part1.ShowBitmap();
		part2.ShowBitmap();
	}

	bool Background::Over()
	{
		return part1.GetTop() >= 0;
	}

	int Background::GetScrolledDistance()
	{
		return part1.GetTop() - SIZE_Y + part1.GetHeight();
	}
}
