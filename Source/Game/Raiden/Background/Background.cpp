#include "stdafx.h"
#include "Background.hpp"
#include "../../config.h"
#include <ctime>
#include <vector>
#include <string>
#include <exception>

namespace Raiden
{
	Background::Background() : LEFT_MARGIN(-5), SCROLL_INTERVAL_MILLI(33) {}
	
	void Background::Init(std::vector<std::string> paths)
	{
		part1.LoadBitmapByString({ paths[0] });
		part2.LoadBitmapByString({ paths[1] });
		part1.SetTopLeft(LEFT_MARGIN, SIZE_Y - part1.GetHeight());
		part2.SetTopLeft(LEFT_MARGIN, part1.GetTop() - part2.GetHeight());
	}

	void Background::Update(int scroll_step = 10)
	{
		if ((std::clock() - scroll_clock) / CLOCKS_PER_SEC < SCROLL_INTERVAL_MILLI / 1000)
			return;

		scroll_clock = std::clock();

		if (part1.GetTop() >= SIZE_Y)
			part1.SetTopLeft(LEFT_MARGIN, part2.GetTop() - part1.GetHeight());

		if (part2.GetTop() >= SIZE_Y)
			part2.SetTopLeft(LEFT_MARGIN, part1.GetTop() - part2.GetHeight());

		part1.SetTopLeft(LEFT_MARGIN, part1.GetTop() + scroll_step);
		part2.SetTopLeft(LEFT_MARGIN, part2.GetTop() + scroll_step);
	}

	void Background::Show()
	{
		part1.ShowBitmap();
		part2.ShowBitmap();
	}
}
