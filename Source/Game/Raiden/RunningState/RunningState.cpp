#include "stdafx.h"
#include "RunningState.h"
#include "../../config.h"

namespace Raiden {
	void RunningState::CollisionEvent() {
		auto player_collision_boxfighters = player.GetCollisionBox();
		for (size_t i = 0; i < bullets->GetSize(); i++) {
			if (bullets->operator[](i)->IsFriendly()) {//我方子彈
				for (size_t j = 0; j < fighters->GetSize(); j++) {
					if (!fighters->operator[](j)->IsAlive()) {
						continue;
					}
					auto fighter_collision_boxfighters = fighters->operator[](j)->GetCollisionBox();
					if (bullets->operator[](i)->IsCollisionBoxOverlap(fighter_collision_boxfighters)) {
						bullets->operator[](i)->Destroy();
						fighters->operator[](j)->Destroy();
						break;
					}
				}
				if (this->boss != nullptr && this->boss->IsAlive()) {
					auto boss_collision_boxfighters = this->boss->GetCollisionBox();
					if (bullets->operator[](i)->IsCollisionBoxOverlap(boss_collision_boxfighters)) {
						bullets->operator[](i)->Destroy();
						this->boss->Damage(1);
						break;
					}
				}
			}
			else {//敵方子彈
				if (player.GetLifeCount() <= 0) {
					break;
				}
				if (bullets->operator[](i)->IsCollisionBoxOverlap(player_collision_boxfighters)) {
					bullets->operator[](i)->Destroy();
					player.Damage();
					if (player.GetLifeCount() <= 0) {
						text_graphics.Register({ SIZE_X / 2 - 100 , SIZE_Y / 2 }, "You Are Dead");//失敗
					}
				}
			}
		}
	}

	void RunningState::InitDerived() {
		stage_manager.Init(xml_reader.ParseStages(), fighters, bullets, boss);
		player.Init(xml_reader.ParsePlayer(), bullets);
		status_panel.Init(text_graphics);
	}

	void RunningState::KeyUp(Control &control) {
		// Do nothing
	}

	void RunningState::Update(Control &control) {
		if (player.GetLifeCount() > 0) {
			player.Update(control);
			stage_manager.Update(player);
			boss = stage_manager.GetBoss();
			bullets->Update();
			for (size_t i = 0; i < bullets->GetSize(); i++) {
				auto test = *bullets;
				test[i]->Update();
			}
			CollisionEvent();
			status_panel.Update(player, text_graphics);
		}
		else {
			if (control.mode == ControlMode::KEYBOARD) {
				if (control.keys.count(Key::RESET)) {
					player.Init(xml_reader.ParsePlayer(), bullets);
					//fighters->Clear();
					//bullets->Clear();
					//text_graphics.Clear();
					//status_panel.Init(text_graphics);
					//InitDerived();
				}
			}
			else {
				// To-do
			}
		}
	}

	void RunningState::Show() {
		stage_manager.Show();
		player.Show();
		status_panel.Show();
		text_graphics.Show();
		bullets->Show();
		fighters->Show();
		text_graphics.Show();
	}

	bool RunningState::Over() {
		return stage_manager.Over();
	}
}
