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
	void Background::Init(BackgroundData background_data)
	{
		scroll_step = background_data.scroll_step;
		scroll_interval_milli = background_data.scroll_interval_milli;

		part1.LoadBitmapByString({ background_data.sprites[0] });
		part2.LoadBitmapByString({ background_data.sprites[1] });
		part1.SetTopLeft(BACKGROUND_MARGIN, SIZE_Y - part1.GetHeight());
		part2.SetTopLeft(BACKGROUND_MARGIN, part1.GetTop() - part2.GetHeight());
	}

	void Background::Update()
	{
		if (Over())
			return;

		if (static_cast<double>(std::clock() - scroll_clock) / CLOCKS_PER_SEC < static_cast<double>(scroll_interval_milli) / 1000)
			return;
    
		scroll_clock = std::clock();

		if (part1.GetTop() >= SIZE_Y)
			part1.SetTopLeft(BACKGROUND_MARGIN, part2.GetTop() - part1.GetHeight());

		if (part2.GetTop() >= SIZE_Y)
			part2.SetTopLeft(BACKGROUND_MARGIN, part1.GetTop() - part2.GetHeight());

		part1.SetTopLeft(BACKGROUND_MARGIN, part1.GetTop() + scroll_step);
		part2.SetTopLeft(BACKGROUND_MARGIN, part2.GetTop() + scroll_step);
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
