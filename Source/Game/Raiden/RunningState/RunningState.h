#pragma once
#include "../State/State.h"
#include "../StageManager/StageManager.h"
#include "../Player/Player.h"
#include "../StatusPanel/StatusPanel.h"
#include "../TextGraphics/TextGraphics.h"
#include "../Control/Control.h"
#include "../Key/Key.h"
#include "../GameObjectPool/GameObjectPool.h"
#include "../Bullet/Bullet.h"
namespace Raiden
{
	class RunningState : public State
	{
	public:
		void InitDerived() override;
		void KeyUp(Control &control) override;
		void Update(Control &control) override;
		void Show() override;
		bool Over() override;

	private:
		StageManager stage_manager;
		Player player;
		StatusPanel status_panel;
		TextGraphics text_graphics;
		GameObjectPool<Bullet> bullets;
	};
}
