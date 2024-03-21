#pragma once
#include "../StageManager/StageManager.h"
#include "../Player/Player.h"
#include "../StatusPanel/StatusPanel.h"
#include "../Key/Key.h"
#include "../TextGraphics/TextGraphics.h"
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
		StageManager stage_manager;
		Player player;
		StatusPanel status_panel;
		TextGraphics text_graphics;
	};
}
