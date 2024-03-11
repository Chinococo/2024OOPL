#include <StdAfx.h>
#include <ctime>
#include <vector>
#include <string>
#include <exception>
#include "../../config.h"
#include "Background.hpp"

namespace Raiden
{
	Background::Background() : LEFT_MARGIN(-10) {}
	
	void Background::Init(std::vector<std::string> paths)
	{
		part1.LoadBitmapByString({ paths[0] });
		part2.LoadBitmapByString({ paths[1] });
		part1.SetTopLeft(LEFT_MARGIN, SIZE_Y - part1.GetHeight());
		part2.SetTopLeft(LEFT_MARGIN, part1.GetTop() - part2.GetHeight());
	}

	void Background::Update(int scroll_step)
	{
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
