#include "stdafx.h"
#include "Background.h"
#include "../config.h"
#include <ctime>

namespace Raiden
{
	Background::Background() : LEFT_MARGIN(-5), SCROLL_STEP(10), SCROLL_INTERVAL_SEC(1) {}
	
	void Background::Init()
	{
		part1.LoadBitmapByString({ "Resources/Backgrounds/Stage1Part1.bmp" });
		part2.LoadBitmapByString({ "Resources/Backgrounds/Stage1Part2.bmp" });
		part1.SetTopLeft(LEFT_MARGIN, SIZE_Y - part1.GetHeight());
		part2.SetTopLeft(LEFT_MARGIN, part1.GetTop() - part2.GetHeight());
	}

	void Background::Update()
	{
		if ((std::clock() - scroll_clock) / CLOCKS_PER_SEC < SCROLL_INTERVAL_SEC)
			return;

		if (part1.GetTop() >= SIZE_Y)
			part1.SetTopLeft(LEFT_MARGIN, part2.GetTop() - part1.GetHeight());

		if (part2.GetTop() >= SIZE_Y)
			part2.SetTopLeft(LEFT_MARGIN, part1.GetTop() - part2.GetHeight());

		part1.SetTopLeft(LEFT_MARGIN, part1.GetTop() + SCROLL_STEP);
		part2.SetTopLeft(LEFT_MARGIN, part2.GetTop() + SCROLL_STEP);
	}

	void Background::Show()
	{
		part1.ShowBitmap();
		part2.ShowBitmap();
	}
}
