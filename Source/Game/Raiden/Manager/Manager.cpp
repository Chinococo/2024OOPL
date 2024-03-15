#include <StdAfx.h>
#include "Manager.h"
#include "../Key/Key.h"
#include <set>

namespace Raiden
{
	void Manager::Init()
	{
		stageManager.Init();
		player.Init();
		statusPanel.Init();
	}

	void Manager::Update(const std::set<Key> &keys)
	{
		player.Update(keys);
		stageManager.Update(player);
		statusPanel.Update(player);
	}

	void Manager::Show()
	{
		stageManager.Show();
		player.Show();
		statusPanel.Show();
	}

	bool Manager::Over() const
	{
		return stageManager.Over();
	}
}
