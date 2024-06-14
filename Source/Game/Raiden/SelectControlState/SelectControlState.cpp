#include "stdafx.h"
#include "SelectControlState.h"
#include "../Key/Key.h"
#include "../../config.h"
#include "../Xml/XmlReader.h"
#include <string>

namespace Raiden
{
	void SelectControlState::InitDerived()
	{
		background.ToggleAnimation();
		auto title_screen_data = xml_reader.ParseTitleScreen();
		background.LoadBitmapByString(title_screen_data.sprites);
		background.SetTopLeft(title_screen_data.left_margin, title_screen_data.left_margin);
		background.SetAnimation(title_screen_data.animation_delay_milli, true);

		selection_line.LoadBitmapByString(title_screen_data.selection_line_data.sprites);
		selection_line_position.push_back(title_screen_data.selection_line_data.positions[0]);
		selection_line_position.push_back(title_screen_data.selection_line_data.positions[1]);
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
			mode_selected = true;
			//control.mode = selection_index ? ControlMode::MOUSE : ControlMode::KEYBOARD;
			control.mode = selection_index ? ControlMode::KEYBOARD : ControlMode::KEYBOARD;
		}
	}

	void SelectControlState::Update(Control &control)
	{
		// 如果未來想要作用滑鼠互動的話，可以考慮加上 CPoint 與長方形碰撞箱的互動，偵測玩家是否點在長方形內
	}

	void SelectControlState::Show()
	{
		int frameIndex = background.GetFrameIndexOfBitmap();
		std::string frameIndexStr = std::to_string(frameIndex);
		OutputDebugStringA(frameIndexStr.c_str());
		background.ShowBitmap();

		if (!mode_selected)
			selection_line.ShowBitmap();
	}

	bool SelectControlState::Over()
	{
		return mode_selected && background.IsAnimationDone();
	}
}
