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
					text_graphics.RegisterText(death_message_id, player.GetLifeCount() > 0 ? "" : "YOU ARE DEAD");
				}
			}
		}
	}

	void RunningState::InitDerived() {
		stage_manager.Init(xml_reader.ParseStages(), fighters, bullets, boss);
		player.Init(xml_reader.ParsePlayer(), bullets);
		status_panel.InitializeStatus();
		death_message_id = text_graphics.RegisterText({ SIZE_X / 2 - 100 , SIZE_Y / 2 }, ""); // 失敗
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
				test[i]->Update(/*player,fighters->GetPoolVec()*/);
			}
			CollisionEvent();
			this->UpdateStatusPanel();
		}
		else {
			if (control.mode == ControlMode::KEYBOARD) {
				if (control.keys.count(Key::RESET)) {
					player.Init(xml_reader.ParsePlayer(), bullets);
					text_graphics.ChangeText(death_message_id, "");
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

	void RunningState::UpdateStatusPanel() {
		status_panel.SetStatusCount(StatusType::LIFE, player.GetLifeCount());
		status_panel.SetStatusCount(StatusType::SCORE, player.GetScore());
		status_panel.SetStatusCount(StatusType::BOMB_COUNT, player.GetBombCount());
	}

	void RunningState::Show() {
		stage_manager.Show();
		player.Show();
		bullets->Show();
		fighters->Show();
		status_panel.ShowStatus(text_graphics);
		text_graphics.ShowTexts();
		text_graphics.ClearTextData();
	}

	bool RunningState::Over() {
		return stage_manager.Over();
	}
}
