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
#include "../Fighter/Fighter.h"
#include "../Boss/Boss.h"
#include "../Item/Item.h"
#include "../BossJapan/BossJapan.h"
#include "../PlayAudio/AudioPlayer.h"
#include "../Bomb/Bomb.h"
namespace Raiden
{
	class RunningState : public State
	{
	public:
		void CollisionEvent();
		void InitDerived() override;
		void KeyUp(Control &control) override;
		void Update(Control &control) override;
		void Show() override;
		bool Over() override;

	private:
		void UpdateStatusPanel();
		void UpdateDeathMessage();
		StageManager stage_manager;
		Player player;
		StatusPanel status_panel;
		TextGraphics text_graphics;
		std::shared_ptr<GameObjectPool<Bullet>> bullets = std::shared_ptr<GameObjectPool<Bullet>>(new GameObjectPool<Bullet>());
		std::shared_ptr<GameObjectPool<Fighter>> fighters = std::shared_ptr<GameObjectPool<Fighter>>(new GameObjectPool<Fighter>());
		std::shared_ptr<Boss> boss;
		std::size_t death_message_id;
		std::vector<Item*> items;
		AudioPlayer opening = AudioPlayer("Resources/audio/Opening.mp3", true);
		AudioPlayer laser = AudioPlayer("Resources/audio/laser.mp3", false);
		AudioPlayer explosion = AudioPlayer("Resources/audio/explosion.mp3", false);
		AudioPlayer reload = AudioPlayer("Resources/audio/reload.mp3", false);
		Bomb bomb;
	}; 
}
