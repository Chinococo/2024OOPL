#include "stdafx.h"
#include "Background.hpp"
#include "../../config.h"
#include <ctime>
#include <vector>
#include <string>
#include <exception>
#include <string>
namespace Raiden
{
	Background::Background() : LEFT_MARGIN(-5), SCROLL_STEP(10), SCROLL_INTERVAL_MILLI(33) {}
	
	void Background::Init()
	{
		paths.push_back({ "Resources/Background/Stage1Part1.bmp", "Resources/Background/Stage1Part2.bmp" });
		// paths.push_back({ "Resources/Background/Stage2Part1.bmp", "Resources/Background/Stage2Part2.bmp" });
		// paths.push_back({ "Resources/Background/Stage3Part1.bmp", "Resources/Background/Stage3Part2.bmp" });
		Switch(0);
	}

	void Background::Update()
	{
		if ((double)(std::clock() - scroll_clock) / CLOCKS_PER_SEC < (double)SCROLL_INTERVAL_MILLI / 1000)
			return;
		//std::wstring info = L"Output" + to_wstring((double)(std::clock() - scroll_clock) / CLOCKS_PER_SEC) + L"\n";
		//OutputDebugStringW(info.c_str());
		scroll_clock = std::clock();

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

	void Background::Switch(std::size_t id)
	{
		if (id >= paths.size())
			throw std::invalid_argument("Invalid background id.");

		part1.LoadBitmapByString({ paths[id][0] });
		part2.LoadBitmapByString({ paths[id][1] });
		part1.SetTopLeft(LEFT_MARGIN, SIZE_Y - part1.GetHeight());
		part2.SetTopLeft(LEFT_MARGIN, part1.GetTop() - part2.GetHeight());
	}
}
