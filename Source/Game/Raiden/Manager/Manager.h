#pragma once
#include "../StageManager/StageManager.h"
#include "../Player/Player.h"
#include "../StatusPanel/StatusPanel.h"
#include "../Key/Key.h"
#include <set>

namespace Raiden
{
	class Manager
	{
	public:
		void Init();
		void Update(const std::set<Key> &keys);
		void Show();
		bool Over() const;

	private:
		StageManager stageManager;
		Player player;
		StatusPanel statusPanel;
	};
}
