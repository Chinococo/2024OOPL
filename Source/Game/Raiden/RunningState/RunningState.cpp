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
				if (this->boss != nullptr&&this->boss->IsAppear()) {
					auto boss_collision_boxfighters = this->boss->GetCollisionBox();
					if (bullets->operator[](i)->IsCollisionBoxOverlap(boss_collision_boxfighters)) {
						bullets->operator[](i)->Destroy();
						this->boss->Damage(10);
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
						player.Upgrage();
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
		play_audio.PlayAudio("Resources/audio/Opening.mp3");
	}

	void RunningState::KeyUp(Control &control) {
		// Do nothing
	}

	void RunningState::Update(Control &control) {
		if (player.GetLifeCount() > 0) {
			player.Update(control);
			stage_manager.Update(player);
			boss = stage_manager.GetBoss();
			for (size_t i = 0; i < bullets->GetSize(); i++) {
				auto test = *bullets;
				auto enemy = fighters->GetPoolVecPos();
				if ( bullets->operator[](i)->GetLeft() < 0 || SIZE_X <bullets->operator[](i)->GetLeft()  ||
					bullets->operator[](i)->GetLeft() < 0 || SIZE_Y < bullets->operator[](i)->GetLeft()) {
					bullets->operator[](i)->Destroy();
					continue;
				}
				test[i]->Update(player.GetTopLeft(), enemy);
			}
			for (std::size_t i = 0; i < fighters->GetSize(); i++)
			{
				if (fighters->operator[](i)->GetLeft() < 0 || fighters->operator[](i)->GetLeft() >= RESOLUTION_X) {
					fighters->operator[](i)->Destroy();
					continue;
				}

				if (fighters->operator[](i)->GetTop() < 0 || fighters->operator[](i)->GetTop() >= RESOLUTION_Y) {
					fighters->operator[](i)->Destroy();
					continue;
				}
			}
			for (size_t i = 0; i < items.size(); i++) {
				items[i]->Update();
			}
			bullets->Update();
			fighters->Update();
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
