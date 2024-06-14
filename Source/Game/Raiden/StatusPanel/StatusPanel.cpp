#include "stdafx.h"
#include "../../../Library/gameutil.h"
#include "StatusPanel.h"
#include <chrono>
#include <string>
namespace Raiden {
	void StatusPanel::Init(TextGraphics& text_graphics) {
		this->health = 3;
		this->score = 3;
		this->bomb_count = 3;
		this->health_pos = { 0, 0 };
		this->score_pos = { 200, 0 };
		this->bomb_count_pos = { 400, 0 };
		this->health_text_id = -1;
		this->score_text_id = -1;
		this->bomb_count_text_id = -1;
		this->status_image.LoadBitmapByString({ "Resources/StatusPanel/RedDot20x20.bmp" }, RGB(255, 255, 255));
		health_text_id = text_graphics.RegisterText(-1, health_pos, "LIFE");
		score_text_id = text_graphics.RegisterText(-1, score_pos, "SCORE");
		bomb_count_text_id = text_graphics.RegisterText(-1, bomb_count_pos, "BOMB COUNT");
		score_count_id = text_graphics.RegisterText(-1, { 0, 0 }, std::to_string(score));
	}

	void StatusPanel::SetHealth(int health) {
		this->health = health;
	}

	void StatusPanel::SetScore(int score) {
		this->score = score;
	}

	void StatusPanel::SetBombCount(int bomb_count) {
		this->bomb_count = bomb_count;
	}

	void StatusPanel::Show(TextGraphics& text_graphics) {

		health_text_id = text_graphics.RegisterText(-1, health_pos, "LIFE");
		for (int i = 0; i < this->health; i++) {
			status_image.SetTopLeft(health_pos.x + i * status_image.GetWidth(), health_pos.y + text_graphics.GetTextSize());
			status_image.ShowBitmap();
		}

		score_text_id = text_graphics.RegisterText(-1, score_pos, "SCORE");
		const CPoint score_count_pos = { score_pos.x, score_pos.y + text_graphics.GetTextSize() };
		score_count_id = text_graphics.RegisterText(-1, score_count_pos, std::to_string(score));

		bomb_count_text_id = text_graphics.RegisterText(-1, bomb_count_pos, "BOMB COUNT");
		for (int i = 0; i < this->bomb_count; i++) {
			status_image.SetTopLeft(bomb_count_pos.x + i * status_image.GetWidth(), bomb_count_pos.y + text_graphics.GetTextSize());
			status_image.ShowBitmap();
		}
	}
}
