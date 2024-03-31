#include "stdafx.h"
#include "RunningState.h"

namespace Raiden
{
	void RunningState::InitDerived()
	{
		stage_manager.Init();
		player.Init(xml_reader.ParsePlayerData());
		status_panel.Init(text_graphics);
	}

	void RunningState::KeyUp(Control &control)
	{
		// Do nothing
	}

	void RunningState::Update(Control &control)
	{
		player.Update(control);
		stage_manager.Update(player);
		status_panel.Update(player, text_graphics);
	}

	void RunningState::Show()
	{
		stage_manager.Show();
		player.Show();
		status_panel.Show();
		text_graphics.Show();
	}

	bool RunningState::Over()
	{
		return stage_manager.Over();
	}
}
