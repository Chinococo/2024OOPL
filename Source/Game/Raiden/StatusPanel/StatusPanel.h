#pragma once
#include "../TextGraphics/TextGraphics.h"
#include <map>

namespace Raiden {
	enum class StatusType {
		LIFE,
		SCORE,
		BOMB_COUNT
	};
	class StatusPanel {
	public:
		void InitializeStatus();
		void SetStatusCount(const StatusType, const int);
		void DecreaseStatusCount(const StatusType);
		void ShowStatus(TextGraphics& text_graphics);
	private:
		struct StatusDatum {
			StatusDatum(const std::string text, const std::string image_path, const int initial_count, const CPoint position);
			const std::string text;
			const std::string image_path;
			int count;
			const CPoint position;
		};
		std::map<const StatusType, StatusDatum> status_data;
		game_framework::CMovingBitmap display;
		vector<string> image_paths;
	};
}
