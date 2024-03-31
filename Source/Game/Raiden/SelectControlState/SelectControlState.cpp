#include "stdafx.h"
#include "SelectControlState.h"
#include "../Key/Key.h"
#include "../../config.h"
#include <string>

namespace Raiden
{
	void SelectControlState::InitDerived()
	{
		std::vector<std::string> paths;
		paths.push_back("Resources/Background/TitleScreenSelectControl.bmp");

		for (int i = 4; i <= 6; i++)
			paths.push_back("Resources/Background/TitleScreen" + std::to_string(i) + ".bmp");

		background.LoadBitmapByString(paths);
		background.SetTopLeft(BACKGROUND_MARGIN, BACKGROUND_MARGIN);
		background.SetAnimation(BACKGROUND_ANIMATION_DELAY_MILLI, true);
		selection_line.LoadBitmapByString({ "Resources/Background/SelectionLine.bmp" });
		selection_line_position.push_back({ 130, 480 });
		selection_line_position.push_back({ 320, 480 });
		selection_line.SetTopLeft(selection_line_position[selection_index].x, selection_line_position[selection_index].y);
	}

	void SelectControlState::KeyUp(Control &control)
	{
		if (control.keys.count(Key::LEFT))
			selection_index--;

		if (control.keys.count(Key::RIGHT))
			selection_index++;

		selection_index = selection_index % 2;
		selection_line.SetTopLeft(selection_line_position[selection_index].x, selection_line_position[selection_index].y);

		if (control.keys.count(Key::FIRE))
		{
			background.ToggleAnimation();
			mode_selected = true;
			control.mode = selection_index ? ControlMode::MOUSE : ControlMode::KEYBOARD;
		}
	}

	void SelectControlState::Update(Control &control)
	{
		// 如果未來想要作用滑鼠互動的話，可以考慮加上 CPoint 與長方形碰撞箱的互動，偵測玩家是否點在長方形內
	}

	void SelectControlState::Show()
	{
		background.ShowBitmap();

		if (!mode_selected)
			selection_line.ShowBitmap();
	}

	bool SelectControlState::Over()
	{
		return mode_selected && background.IsAnimationDone();
	}
}
