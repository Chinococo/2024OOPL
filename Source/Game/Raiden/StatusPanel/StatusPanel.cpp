#include "stdafx.h"
#include "../../../Library/gameutil.h"
#include "StatusPanel.h"
#include <chrono>
#include <string>
namespace Raiden {
	StatusPanel::StatusDatum::StatusDatum(const std::string text, const std::string image_path, const int initial_count, const CPoint position)
		: text(text), image_path(image_path), count(initial_count), position(position) {}
	void StatusPanel::InitializeStatus() {
		const std::string image_path = "Resources/StatusPanel/RedDot20x20.bmp";
		const int initial_count = 5;
		this->status_data.insert({ StatusType::LIFE, StatusDatum("LIFE", image_path, initial_count, CPoint(0, 0)) });
		this->status_data.insert({ StatusType::SCORE, StatusDatum("SCORE", image_path, initial_count, CPoint(200, 0)) });
		this->status_data.insert({ StatusType::BOMB_COUNT, StatusDatum("BOMB COUNT", image_path, initial_count, CPoint(400, 0)) });
		for (std::pair<const StatusType, StatusDatum>& status_pair : this->status_data) {
			StatusDatum& status_datum = status_pair.second;
			image_paths.push_back(status_datum.image_path);
		}
		display.LoadBitmapByString(image_paths, RGB(255, 255, 255));
	}
	void StatusPanel::SetStatusCount(const StatusType status_type, const int count) {
		this->status_data.at(status_type).count = count;
	}
	void StatusPanel::DecreaseStatusCount(const StatusType status_type) {
		int& status_count = this->status_data.at(status_type).count;
		if (status_count > 0) {
			status_count--;
		}
	}
	void StatusPanel::ShowStatus(TextGraphics& text_graphics) {
		auto start_time = std::chrono::steady_clock::now();
		for (std::pair<const StatusType, StatusDatum>& status_pair : this->status_data) {
			StatusDatum& status_datum = status_pair.second;
			// Compute text position
			const CPoint& text_position = status_datum.position;
			text_graphics.RegisterText(text_position, status_datum.text);
			//Compute leftmost bitmap positionr
			const CPoint text_bitmap_margin(0, text_graphics.GetTextSize());
			const CPoint bitmap_position = text_position + text_bitmap_margin;
			// Load bitmap
			
			// Store image width in advance
			const int image_width = display.GetWidth();
			// Show same bitmaps sequentially
			for (int i = 0; i < status_datum.count; i++) {
				display.SetFrameIndexOfBitmap(i);
				display.SetTopLeft(bitmap_position.x + i * image_width, bitmap_position.y);
				display.ShowBitmap();
			}
		}
	}
}
