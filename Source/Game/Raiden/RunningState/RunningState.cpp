#include "stdafx.h"
#include "RunningState.h"
#include "../../config.h"

namespace Raiden {
	void RunningState::CollisionEvent() {
		/*物體碰撞*/
		auto player_collision_boxfighters = player.GetCollisionBox();
		for (size_t j = 0; j < fighters->GetSize(); j++) {
			if (!player.IsInvincible() && fighters->operator[](j)->IsCollisionBoxOverlap(player)) {
				player.Damage();
				playdamage.PlayAudio();
				return;
			}
		}
		if (!player.IsInvincible() && boss->IsCollisionBoxOverlap(player)) {
			player.Damage();
			playdamage.PlayAudio();
			return;
		}

		for (size_t i = 0; i < bullets->GetSize(); i++) {
			if (bullets->operator[](i)->IsFriendly()) {//我方子彈
				for (size_t j = 0; j < fighters->GetSize(); j++) {
					if (!fighters->operator[](j)->IsAlive()) {
						continue;
					}
					auto fighter_collision_boxfighters = fighters->operator[](j)->GetCollisionBox();
					if (bullets->operator[](i)->IsCollisionBoxOverlap(fighter_collision_boxfighters)) {
						if (std::rand() % 100 < 100) {
							items.push_back(new Item());
							items[items.size() - 1]->Init(CPoint(fighters->operator[](j)->GetLeft(), fighters->operator[](j)->GetTop()));
						}
						bullets->operator[](i)->Destroy();
						fighters->operator[](j)->Destroy();
						player.IncreaseScore(100);
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
					death.PlayAudio();
					
					break;
				}
				if (!player.IsInvincible()&&bullets->operator[](i)->IsCollisionBoxOverlap(player_collision_boxfighters)) {
					bullets->operator[](i)->Destroy();
					player.Damage();
					playdamage.PlayAudio();
				}
				for (size_t i = 0; i < items.size();) {
					CollisionBox& item_CollisionBox = items[i]->GetCollisionBox();

					if (item_CollisionBox.IsCollisionBoxOverlap(player_collision_boxfighters)) {
						items.erase(items.begin() + i);
						player.Upgrage();
						reload.PlayAudio();
					}
					i++;
				}
				if (!this->bomb.IsComplte()) {
					for (size_t j = 0; j < fighters->GetSize(); j++) {
						auto bomb_collision_boxfighters = this->bomb.GetCollisionBox();
						if (bullets->operator[](i)->IsCollisionBoxOverlap(bomb_collision_boxfighters)) {
							fighters->operator[](j)->Destroy();
							continue;
						}
					}

				}

				
			}
		}
	}

	void RunningState::InitDerived() {
		bomb.Init();
		stage_manager.Init(xml_reader.ParseStages(), fighters, bullets, boss);
		player.Init(xml_reader.ParsePlayer(), bullets);
		status_panel.Init(text_graphics);
		opening.PlayAudio();
		death_message_id = text_graphics.RegisterText(-1, { 0, 0 }, "");
	}

	void RunningState::KeyUp(Control &control) {
		// Do nothing
	}

	void RunningState::Update(Control &control) {
		bomb.update();
		this->UpdateDeathMessage();
		if (control.mode == ControlMode::KEYBOARD) {
			if (control.keys.count(Key::dDEBUG) && std::clock() - debug_timer >= 500) {
				this->debug = !this->debug;
				debug_timer = std::clock();
			}
		}
		if (player.GetLifeCount() > 0) {
			if (control.mode == ControlMode::KEYBOARD) {
				if (control.keys.count(Key::BOMB)) {
					int a = player.GetBombCount();
					if (a > 0 && bomb.Start()) {
						explosion.PlayAudio();
						player.fdajklgasjklsra();
					}

				}
			}
			player.Update(control);
			if (player.IsAttacking()) {
				laser.PlayAudio();
			}
			stage_manager.Update(player);
			boss = stage_manager.GetBoss();
			for (size_t i = 0; i < bullets->GetSize(); i++) {
				auto enemy = fighters->GetPoolVecPos();
				if ( bullets->operator[](i)->GetLeft() < 0 || SIZE_X <bullets->operator[](i)->GetLeft()  ||
					bullets->operator[](i)->GetLeft() < 0 || SIZE_Y < bullets->operator[](i)->GetLeft()) {
					bullets->operator[](i)->Destroy();
					continue;
				}
				bullets->operator[](i)->Update(player.GetTopLeft(), enemy);
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
		status_panel.SetHealth(player.GetLifeCount());
		status_panel.SetScore(player.GetScore());
		status_panel.SetBombCount(player.GetBombCount());
	}

	void RunningState::UpdateDeathMessage() {
		CPoint position = { SIZE_X / 2 - 100 , SIZE_Y / 2 };
		std::string death_message = player.GetLifeCount() > 0 ? "" : "YOU ARE DEAD";
		text_graphics.RegisterText(death_message_id, position, death_message);
	}

	void RunningState::Show() {
		stage_manager.Show(debug);
		player.Show(debug);
		bullets->Show(debug);
		fighters->Show(debug);
		status_panel.Show(text_graphics);
		text_graphics.ShowTexts();
		text_graphics.ClearTextData();
		for (size_t i = 0; i < items.size(); i++) {
			items[i]->Show();
		}
		bomb.Show(debug);
	}

	bool RunningState::Over() {
		return stage_manager.Over();
	}
}
