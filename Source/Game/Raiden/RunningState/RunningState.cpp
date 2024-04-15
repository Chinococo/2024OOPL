#include "stdafx.h"
#include "RunningState.h"

namespace Raiden
{
	void RunningState::InitDerived()
	{
		stage_manager.Init(xml_reader.ParseStages(), fighters,bullets);
		player.Init(xml_reader.ParsePlayer(), bullets);
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
		bullets->Update();
		for (size_t i = 0; i < bullets->GetSize(); i++) {
			auto test = *bullets;
			test[i]->Update();
		}
			
		status_panel.Update(player, text_graphics);
	}

	void RunningState::Show()
	{
		stage_manager.Show();
		player.Show();
		status_panel.Show();
		text_graphics.Show();
		bullets->Show();
		fighters->Show();
	}

	bool RunningState::Over()
	{
		return stage_manager.Over();
	}
}
