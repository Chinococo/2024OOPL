#include "stdafx.h"
#include "SelectControlState.h"
#include "../../config.h"
#include <string>

namespace Raiden
{
	void SelectControlState::Init()
	{
		std::vector<std::string> paths;
		paths.push_back("Resources/Background/TitleScreenSelectControl.bmp");

		for (int i = 4; i <= 6; i++)
			paths.push_back("Resources/Background/TitleScreen" + std::to_string(i) + ".bmp");

		background.LoadBitmapByString(paths);
		background.SetTopLeft(BACKGROUND_MARGIN, BACKGROUND_MARGIN);
		background.SetAnimation(BACKGROUND_ANIMATION_DELAY_MILLI, true);
	}

	void SelectControlState::Update(Control &&control)
	{
		// if (control.keys)
		// background.ToggleAnimation();
	}

	void SelectControlState::Show()
	{
		background.ShowBitmap();
	}

	bool SelectControlState::Over()
	{
		return background.IsAnimationDone();
	}
}
