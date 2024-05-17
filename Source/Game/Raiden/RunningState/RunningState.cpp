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
						items.push_back(new Item());
						items[items.size() - 1]->Init(CPoint(fighters->operator[](j)->GetLeft(), fighters->operator[](j)->GetTop() ));
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
					//player.Damage();
					text_graphics.RegisterText(death_message_id, player.GetLifeCount() > 0 ? "" : "YOU ARE DEAD");
				}
				for (size_t i = 0; i < items.size();) {
					CollisionBox& item_CollisionBox = items[i]->GetCollisionBox();

					if (item_CollisionBox.IsCollisionBoxOverlap(player_collision_boxfighters)) {
						items.erase(items.begin() + i);
					}
					i++;
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
				auto enemy = fighters->GetPoolVecPos();
				/*
				if (boss->IsAlive()) {
					enemy.push_back(boss->GetTopLeft());
				}
				*/
				test[i]->Update(player.GetTopLeft(), enemy);
			}
			for (size_t i = 0; i < items.size();i++) {
				items[i]->Update();
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
		for (size_t i = 0; i < items.size(); i++) {
			items[i]->Show();
		}
	}

	bool RunningState::Over() {
		return stage_manager.Over();
	}
}
