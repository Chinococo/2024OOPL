#include <StdAfx.h>
#include "Manager.h"
#include "../Key/Key.h"
#include <set>

namespace Raiden
{
	void Manager::Init()
	{
		stage_manager.Init();
		player.Init();
		status_panel.Init(text_graphics);
	}

	void Manager::Update(const std::set<Key> &keys)
	{
		player.Update(keys);
		stage_manager.Update(player);
		status_panel.Update(player, text_graphics);
	}

	void Manager::Show()
	{
		stage_manager.Show();
		player.Show();
		status_panel.Show();
		text_graphics.Show();
	}

	bool Manager::Over() const
	{
		return stage_manager.Over();
	}
}
